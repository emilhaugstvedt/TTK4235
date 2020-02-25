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
  if(e->last_state == MOVE){
    printf("%s\n", "IDLE MOVE" );
    queue_handler_order_complete(e);
    if (elevator_driver_at_floor(e)) {
      timer_end_time();
      hardware_command_door_open(1);
      e->last_state = e->current_state;
      e->current_state = DOOR_OPEN;
    }
  }
  else if(e->last_state == DOOR_OPEN){
    printf("%s\n", "IDLE DOOR");
    if (queue_handler_change_dir(e) == 0){
      e->last_state = e->current_state;
      e->current_state = MOVE;
    }
  }
  else if(e->last_state == EMERGENCY_STOP){

  }
  else {
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
  elevator_driver_floor_passed(e);
  queue_handler_lights(e);
  if (!queue_handler_stop(e)){
    hardware_command_movement(e->current_dir);
  }
  else {
    elevator_driver_stop();
    e->last_state = e->current_state;
    e->current_state = IDLE;
  }
}


void door_state(elevator_t *e) {
  printf("%s\n", "DOOR" );
  queue_handler_update_queue_outside(e);
  queue_handler_update_queue_inside(e);
  queue_handler_lights(e);
  if(timer_time_out() && timer_enable) {
    hardware_command_door_open(0);
    timer_enable = 0;
    e->last_state = e->current_state;
    e->current_state = IDLE;
  }

}

void emergency_stop_state(elevator_t *e) {

}
