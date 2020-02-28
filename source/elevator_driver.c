#include "hardware.h"
#include "elevator.h"
#include "elevator_driver.h"
#include <stdlib.h>

void elevator_driver_start(elevator_t *e) {
  hardware_command_movement(e->current_dir);
}

void elevator_driver_stop() {
  hardware_command_movement(HARDWARE_MOVEMENT_STOP);
  }


void elevator_driver_floor_passed(elevator_t *e){
  if (hardware_read_floor_sensor(0)) {
    e->current_floor = 0;
  }
  if (hardware_read_floor_sensor(1)) {
    e->current_floor = 1;
  }
  if (hardware_read_floor_sensor(2)) {
    e->current_floor = 2;
  }
  if (hardware_read_floor_sensor(3)) {
    e->current_floor = 3;
    elevator_driver_stop();
  }
}

int elevator_driver_at_floor(elevator_t *e) {
  if (hardware_read_floor_sensor(0)) {
    return TRUE;
  }
  else if (hardware_read_floor_sensor(1)) {
    return TRUE;
  }
  else if (hardware_read_floor_sensor(2)) {
    return TRUE;
  }
  else if (hardware_read_floor_sensor(3)) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}

void elevator_driver_initialize_elevator(elevator_t *e){
  elevator_clear_all_lights();
  e->current_state = IDLE;
  e->last_state = DOOR_OPEN;
  e->current_dir = HARDWARE_MOVEMENT_DOWN;
  e->current_floor = 0;
  e->time = 0;
  for(int floor = 0; floor < HARDWARE_NUMBER_OF_FLOORS; floor++) {
    for (int order = 0; order < 3; order ++) {
      e->queue[floor][order] = 0;
    }
  }
}

void elevator_driver_default_floor(elevator_t *e){
    hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
    while(1){
      if(hardware_read_floor_sensor(DEFAULT_FLOOR)){
        hardware_command_movement(HARDWARE_MOVEMENT_STOP);
        break;
    }
    }
  }

void elevator_driver_range_control(){
  if (hardware_read_floor_sensor(HARDWARE_NUMBER_OF_FLOORS - 1)){
    hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
  }
  else if (hardware_read_floor_sensor(0)){
    hardware_command_movement(HARDWARE_MOVEMENT_UP);
  }
}
