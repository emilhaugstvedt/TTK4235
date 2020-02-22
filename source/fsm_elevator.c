#include "elevator_driver.h"
#include "queue_handler.h"
#include "elevator.h"
#include "fsm_elevator.h"
#include <stdio.h>

#include <stdlib.h>
#define DEFAULT_FLOOR 0

void fsm_elevator_go(elevator_t *e){
  while(1){
    switch (e->current_state) {
      case MOVE:
        move_state(e);
        break;

      case IDLE:
        idle_state(e);
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


void move_state(elevator_t *e) {
  printf("%s\n","move" );
    queue_handler_update_queue(e);
    if (hardware_read_stop_signal()){
        e->last_state = e->current_state;
        e->current_state = EMERGENCY_STOP;
    }
    elevator_driver_go(e);
    elevator_driver_floor_passed(e);
    if (e->last_floor == e->current_floor){
      elevator_driver_stop(e);
      elevator_driver_clear_lights(e);
      e->time = timer_start_time();
      e->current_dir = e->next_dir;
      e->last_state = e->current_state;
      e->current_state = DOOR_OPEN;
    }
}

void idle_state(elevator_t *e) {
    printf("%s\n","idle" );
    queue_handler_update_queue(e);
    if (hardware_read_stop_signal()){
        e->last_state = e->current_state;
        e->current_state = EMERGENCY_STOP;
    }
    queue_handler_set_floor(e);
    queue_handler_choose_direction(e);
    if (e->current_dir != HARDWARE_MOVEMENT_STOP){
      elevator_driver_go(e);
      e->last_state = IDLE;
      e->current_state = MOVE;
    }
  }

void door_state(elevator_t *e) {
  printf("%s\n","door");
    queue_handler_update_queue(e);
    if (hardware_read_stop_signal()){
      e->last_state = e->current_state;
      e->current_state = EMERGENCY_STOP;
    }
    if (elevator_driver_at_floor(e)){
      hardware_command_door_open(1);
    }
    queue_handler_inside_order(e);
    if(timer_wait_for_three(e->time) && !hardware_read_obstruction_signal()){
      hardware_command_door_open(0);
      e->last_state = e->current_state;
      e->current_state = IDLE;
  }
}

void emergency_stop_state(elevator_t *e) {
    elevator_driver_stop();
    if (!hardware_read_stop_signal()){
        if (e->last_state == MOVE) {
            queue_handler_clear_queue(e);
            e->last_state = EMERGENCY_STOP;
            e->current_state = IDLE;
        }
        else if (e->last_state == IDLE || e->last_state == DOOR_OPEN){
            e->time = timer_start_time();
            e->last_state = e->current_state;
            e->current_state = DOOR_OPEN;
        }

    }
}
