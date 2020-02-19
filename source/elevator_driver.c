#include "hardware.h"
#include "elevator.h"
#include "elevator_driver.h"
#include <stdlib.h>

void elevator_driver_set_engine(elevator_t *e) {
    switch (e->current_state)
    {
    case MOVE:
        elevator_driver_set_engine(e);
        break;
    case IDLE:
    case DOOR_OPEN:
    case EMERGENCY_STOP:

    default:
        break;
    }
}

void elevator_driver_go(elevator_t *e) {
  if (e -> current_dir == HARDWARE_MOVEMENT_UP) {
    for (int floor = e -> last_floor; floor < e -> current_floor; floor++) {
      if (e -> queue[floor][ORDER_UP] == 1) {
        e -> current_floor = floor;
      }
    }
    hardware_command_movement(e->current_dir);
  }
  if (e -> current_dir == HARDWARE_MOVEMENT_DOWN) {
    for (int floor = e -> current_floor ; floor > 0; floor-- ){
      if (e->queue[floor][ORDER_DOWN] == 1){
        e->current_floor = floor;
      }
    }
    hardware_command_movement(e->current_dir);
  }
}


void elevator_driver_stop(elevator_t *e) {
  hardware_command_movement(HARDWARE_MOVEMENT_STOP);
  }


void elevator_driver_init_floor(elevator_t *e){
    hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
    while(1){
      if(hardware_read_floor_sensor(INIT_FLOOR)){
        hardware_command_movement(HARDWARE_MOVEMENT_STOP);
        break;
    }
    }
  }

void elevator_driver_open_door(){
  hardware_command_door_open(1);
  //timer_wait_for_three();
  hardware_command_door_open(0);
}
