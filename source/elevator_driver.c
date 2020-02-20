#include "hardware.h"
#include "elevator.h"
#include "elevator_driver.h"
#include <stdlib.h>

void elevator_driver_go(elevator_t *e) {
  if (e -> current_dir == HARDWARE_MOVEMENT_UP) {
    for (int floor = e -> current_floor; floor > e -> last_floor; floor--) {
      if (e -> queue[floor][ORDER_UP] == 1) {
        e -> current_floor = floor;
      }
    }
    hardware_command_movement(HARDWARE_MOVEMENT_UP);
  }
  if (e -> current_dir == HARDWARE_MOVEMENT_DOWN) {
    for (int floor = 0 ; floor < e->last_floor; floor++){
      if (e->queue[floor][ORDER_DOWN] == 1){
        e->current_floor = floor;
      }
    }
    hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
  }
}


void elevator_driver_stop() {
  hardware_command_movement(HARDWARE_MOVEMENT_STOP);
  }


void elevator_driver_init_floor(elevator_t *e){
    hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
    while(1){
      if(hardware_read_floor_sensor(INIT_FLOOR)){
        hardware_command_movement(HARDWARE_MOVEMENT_STOP);
        e->current_floor = 0;
        e->last_floor = 0;
        break;
    }
    }
  }

void elevator_driver_floor_passed(elevator_t *e){
  if (hardware_read_floor_sensor(0)) {
    e->last_floor = 0;
    hardware_command_floor_indicator_on(e->last_floor);
  }
  if (hardware_read_floor_sensor(1)) {
    e->last_floor = 1;
    hardware_command_floor_indicator_on(e->last_floor);
  }
  if (hardware_read_floor_sensor(2)) {
    e->last_floor = 2;
    hardware_command_floor_indicator_on(e->last_floor);
  }
  if (hardware_read_floor_sensor(3)) {
    e->last_floor = 3;
    hardware_command_floor_indicator_on(e->last_floor);
    elevator_driver_stop(e);
  }
}


void elevator_driver_clear_lights(elevator_t *e) {
      if(e->next_dir == HARDWARE_MOVEMENT_UP){
        e->queue[e->current_floor][ORDER_UP] = 0;
        hardware_command_order_light(e->current_floor, HARDWARE_ORDER_UP,0);
        hardware_command_order_light(e->current_floor, HARDWARE_ORDER_INSIDE, 0);
      }
      if(e->next_dir == HARDWARE_MOVEMENT_DOWN){
        e->queue[e->current_floor][ORDER_DOWN] = 0;
        hardware_command_order_light(e->current_floor, HARDWARE_ORDER_DOWN,0);
        hardware_command_order_light(e->current_floor, HARDWARE_ORDER_INSIDE, 0);
      }
}

int elevator_driver_at_floor(elevator_t *e) {
  if (hardware_read_floor_sensor(0)) {
    return 1;
  }
  else if (hardware_read_floor_sensor(1)) {
    return 1;
  }
  else if (hardware_read_floor_sensor(2)) {
    return 1;
  }
  else if (hardware_read_floor_sensor(3)) {
    return 1;
  }
  else {
    return 0;
  }
}