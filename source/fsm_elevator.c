#include "elevator.h"
#include "fsm_elevator.h"
#include "hardware.h"
#include "elevator_driver.h"
#include "queue_handler.h"
#include "timer.h"
#define DEFAULT_FLOOR 0

void elevator_go(elevator_t *e){
  go_to_default(DEFAULT_FLOOR);
  while(1){
    switch (e->current_state) {
      case MOVE:
        move_state(e);

      case IDLE:
        idle_state(e);

      case EMERGENCY_STOP:
        emergency_state(e);

      case DOOR_OPEN:
        door_state(e);
    }
  }
}


void move_state(elevator_t *e) {
    queue_handler_update_queue(e);
    if (hardware_read_stop_signal()){
        e->last_state = e->current_state;
        e->current_state = EMERGENCY_STOP;
    }
    elevator_driver_go(e);
    if (hardware_read_floor_sensor(e->current_floor) == 1){
        elevator_driver_stop(e);
        e->last_state = e->current_state;
        e->current_state = IDLE;
    }
}

void idle_state(elevator_t *e) {
    queue_handler_update_queue(e);
    if (hardware_read_stop_signal()){
        e->last_state = e->current_state;
        e->current_state = EMERGENCY_STOP;
    }
    if (queue_hander_choose_direction(e)) {
        queue_handler_set_floor(e);
        elevator_driver_go(e);
        e->last_state = IDLE;
        e->current_state = MOVE;
    }
}

void emergency_state(elevator_t *e) {
    if (!hardware_read_stop_signal()){
        if (e->last_state == MOVE) {
            clear_queue(e);
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
    queue_handler_update_queue(e);
    if (!hardware_read_stop_signal() && e->current_state == EMERGENCY_STOP){

    }
}

void go_to_default(elevator_t *e) {
    if (hardware_read_floor_sensor(DEFAULT_FLOOR)){
        e->current_floor = IDLE;
    }

}
