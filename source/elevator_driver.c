#include "elevator.h"
#include "fsm_elevator.h"
#include "hardware.h"
#include "elevator_driver.h"
#include "queue_handler.h"
#include "timer.h"

void set_engine(elevator_t *e) {
    switch (e->current_state)
    {
    case MOVE:
        set_engine(e);
        break;
    case IDLE:
    case DOOR_OPEN:
    case EMERGENCY_STOP:

    default:
        break;
    }
}

void elevator_driver_go(elevator_t *e) {
  if (e -> current_dir == 1) {
    for (int floor = e -> last_floor; floor < e -> current_floor; floor++) {
      if (e -> queue[floor][ORDER_UP] == 1) {
        e -> current_floor = floor;
      }
    }
    hardware_command_movement(HARDWARE_MOVEMENT_UP);
  }
  if (e -> current_dir == 0) {
    for (int floor = e -> ; floor > e->current_floor; floor++ ){
      if (e->queue[floor][ORDER_DOWN] == 1){
        e->current_floor == floor;
      }
    }
    hardware_command_movement(HARDWARE_ORDER_DOWN);
}
}


void elevator_driver_stop(elevator_t *e) {
  hardware_command_movement(HARDWARE_MOVEMENT_STOP);
  }