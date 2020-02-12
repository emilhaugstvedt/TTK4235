#include "elevator.h"
#include "fsm_elevator.h"
#include "hardware.h"
#include "elevator_driver.h"
#include "queue_handler.h"
#include "timer.h"

void elevator_go(Elevator e){
  int default_floor = 0;
  go_to_default(default_floor);
  while(1){
    switch (e.current_state) {
      case MOVE:
        move_state(Elevator e);

      case IDLE:
        idle_state(Elevato);

      case EMERGENCY_STOP:
        emergency_state();

      case DOOR_OPEN:
        door_state();
    }
  }
};


void move_state(elevator_t *e) {
    if (hardware_read_stop_signal()){
        e->last_state = e->current_state;
        e->current_state = EMERGENCY_STOP;
    }

}

void emergency_state(elevator_t *e) {
    if (!hardware_read_stop_signal()){
        if (e->last_state == MOVE) {
            clear_queue(e);
        }
        else if ()
    }
}

void door_state(elevator_t e) {

}}