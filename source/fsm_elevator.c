#include "elevator_driver.h"
#include "queue_handler.h"
#include "elevator.h"
#include "fsm_elevator.h"
#include <stdio.h>

#include <stdlib.h>
#define DEFAULT_FLOOR 0

void fsm_elevator_go(elevator_t *e){
  while(!hardware_read_stop_signal()){
    switch (e->current_state) {
      case MOVE:
        move_state(e);
        break;

      case IDLE:
        idle_state(e);
        break;

      case EMERGENCY_STOP:
        emergency_state(e);
        break;

      case DOOR_OPEN:
        door_state(e);
        break;
    }
  }
  hardware_command_movement(HARDWARE_MOVEMENT_STOP);
}


void move_state(elevator_t *e) {
  printf("%s\n","move" );
    queue_handler_update_queue(e);
    if (hardware_read_stop_signal()){
        e->last_state = e->current_state;
        e->current_state = EMERGENCY_STOP;
    }
    elevator_driver_go(e);
    elevator_driver_floor_passed(e);
    if (e->last_floor = e->current_floor){
      elevator_driver_stop(e);
      if(e->next_dir == HARDWARE_MOVEMENT_UP){
        e->queue[e->current_floor][ORDER_UP] = 0;
        hardware_command_order_light(e->current_floor, HARDWARE_ORDER_UP,0);
      }
      if(e->next_dir == HARDWARE_MOVEMENT_DOWN){
        e->queue[e->current_floor][ORDER_DOWN] = 0;
        hardware_command_order_light(e->current_floor, HARDWARE_ORDER_DOWN,0);
      }
      e->last_state = e->current_state;
      e->current_state = DOOR_OPEN;
      e->time = timer_start_time();
    }
}

void idle_state(elevator_t *e) {
    printf("%s\n","idle" );
    queue_handler_update_queue(e);
    queue_handler_inside_order(e);
    if (hardware_read_stop_signal()){
        e->last_state = e->current_state;
        e->current_state = EMERGENCY_STOP;
    }
    queue_handler_set_floor(e);
    queue_handler_choose_direction(e);
    if (e->current_dir != HARDWARE_MOVEMENT_STOP){
      elevator_driver_go(e);
      e->current_dir = e->next_dir;
      e->last_state = IDLE;
      e->current_state = MOVE;
    }
  }

void emergency_state(elevator_t *e) {
    if (!hardware_read_stop_signal()){
        if (e->last_state == MOVE) {
            queue_handler_clear_queue(e);
            e->last_state = EMERGENCY_STOP;
            e->current_state = IDLE;
        }
        else if (e->last_state == IDLE){
            e->last_state = e->current_state;
            e->current_state = DOOR_OPEN;
        }
    }
}

void door_state(elevator_t *e) {
  printf("%s\n","door");
    queue_handler_update_queue(e);
    if (!hardware_read_stop_signal() && e->current_state == EMERGENCY_STOP){
    }
    hardware_command_door_open(1);
    if(timer_wait_for_three(e->time)){
      hardware_command_door_open(0);
      e->last_state = e->current_state;
      e->current_state = IDLE;
  }
}
