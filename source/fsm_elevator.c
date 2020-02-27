#include "elevator_driver.h"
#include "queue_handler.h"
#include "elevator.h"
#include "fsm_elevator.h"
#include <stdio.h>

#include <stdlib.h>
#define DEFAULT_FLOOR 0

void fsm_elevator_go(elevator_t *e){
  while(!hardware_read_obstruction_signal()){
    switch (e->current_state) {
      case IDLE:
        idle_state(e);
        break;

      case MOVE:
        move_state(e);
        break;

      case EMERGENCY_STOP:
        emergency_stop_state(e);
        break;

      case DOOR_OPEN:
        door_state(e);
        break;
    }
  }
}

void idle_state(elevator_t *e) {
  queue_handler_update_queue_outside(e);
  queue_handler_update_queue_inside(e);
  elevator_lights(e);
  if(hardware_read_stop_signal() && elevator_driver_at_floor(e)){
    e->last_state = e->current_state;
    e->current_state = EMERGENCY_STOP;
  } 
  if(e->last_state == MOVE && !hardware_read_stop_signal()){
    printf("%s\n", "IDLE MOVE" );
    if (elevator_driver_at_floor(e)) {
      if(e->time == 0){
        e->time = timer_start_time();
        hardware_command_door_open(1);
        e->last_state = e->current_state;
        e->current_state = DOOR_OPEN;
      }
    }
  }
  else if(e->last_state == DOOR_OPEN && !hardware_read_stop_signal()){
    printf("%s\n", "IDLE DOOR");
    elevator_lights(e);
    if(queue_handler_order_at_current_floor(e)) {
      hardware_command_door_open(1);
      e->time = timer_start_time();
      e->last_state = e->current_state;
      e->current_state = DOOR_OPEN;
    }
    else if (queue_handler_change_dir(e) == 0){
      e->last_state = e->current_state;
      e->current_state = MOVE;
    }
  }
  else if (e->last_state == EMERGENCY_STOP) {
    if (queue_handler_emergency(e)) {
      e->last_state = e->current_state;
      e->current_state = MOVE;

    }
  }
  else if(!hardware_read_stop_signal()) {
    printf("%s\n", "IDLE ELSE" );
    elevator_driver_init_floor(e);
    elevator_driver_initialize_elevator(e);
  }
}


void move_state(elevator_t *e) {
  printf("%s\n", "MOVE" );
  elevator_driver_range_control();
  queue_handler_update_queue_outside(e);
  queue_handler_update_queue_inside(e);
  elevator_lights(e);
  elevator_driver_floor_passed(e);
  if(hardware_read_stop_signal()){
    e->last_state = e->current_state;
    e->current_state = EMERGENCY_STOP;
  }
  else if (queue_handler_stop(e) && elevator_driver_at_floor(e)){
    elevator_driver_stop();
    e->last_state = e->current_state;
    e->current_state = IDLE;
  }
  else {
    hardware_command_movement(e->current_dir);
  }
}


void door_state(elevator_t *e) {
  printf("%s\n", "DOOR" );
  queue_handler_update_queue_outside(e);
  queue_handler_update_queue_inside(e);
  elevator_lights(e);
  if(queue_handler_order_at_current_floor(e)){
    e->time = timer_start_time();
  }
  queue_handler_order_complete(e);
  if(hardware_read_stop_signal()){
    e->time = timer_start_time();
  }
  if(timer_three_seconds(e->time) && !hardware_read_obstruction_signal() && elevator_driver_at_floor(e)) {
    hardware_command_door_open(0);
    e->time = 0;
    e->last_state = e->current_state;
    e->current_state = IDLE;
  }

}

void emergency_stop_state(elevator_t *e) {
  elevator_lights(e);
  hardware_command_stop_light(1);
  hardware_command_movement(HARDWARE_MOVEMENT_STOP);
  if(e->last_state == MOVE) {
    queue_handler_clear_queue(e);
    printf("%s\n", "MOVE EMERGENCY!");
    e->last_state = e->current_state;
    e->current_state = IDLE;
  }
  else if(e->last_state == IDLE || e->last_state == DOOR_OPEN) {
    if(e->time == 0){
      hardware_command_door_open(1);
      e->time = timer_start_time();
      hardware_command_stop_light(0);
      e->last_state = e->current_state;
      e->current_state = DOOR_OPEN;
      }
  }
}
