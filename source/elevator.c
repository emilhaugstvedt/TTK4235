
#include "hardware.h"
#include "timer.h"
#include "elevator.h"

void elevator_lights(elevator_t *e) {

    for (int floor = BOTTOM_FLOOR; floor < TOP_FLOOR + 1; floor++){
      if(e->queue[floor][ORDER_UP]){
        hardware_command_order_light(floor, HARDWARE_ORDER_UP, 1);
      }
      else{
        hardware_command_order_light(floor, HARDWARE_ORDER_UP, 0);
      }
      if(e->queue[floor][ORDER_DOWN]){
        hardware_command_order_light(floor, HARDWARE_ORDER_DOWN, 1);
      }
      else{
        hardware_command_order_light(floor, HARDWARE_ORDER_DOWN, 0);
      }
      if(e->queue[floor][ORDER_INSIDE]){
        hardware_command_order_light(floor, HARDWARE_ORDER_INSIDE, 1);
      }
      else{
        hardware_command_order_light(floor, HARDWARE_ORDER_INSIDE, 0);
      }
    }

  if(hardware_read_stop_signal()){
    hardware_command_stop_light(1);
    }
  else {
    hardware_command_stop_light(0);
    }


  if (hardware_read_floor_sensor(0)) {
    hardware_command_floor_indicator_on(e->current_floor);
  }
  if (hardware_read_floor_sensor(1)) {
    hardware_command_floor_indicator_on(e->current_floor);
  }
  if (hardware_read_floor_sensor(2)) {
    hardware_command_floor_indicator_on(e->current_floor);
  }
  if (hardware_read_floor_sensor(3)) {
    hardware_command_floor_indicator_on(e->current_floor);
  }
}

void elevator_clear_all_lights(){
  hardware_command_order_light(1, HARDWARE_ORDER_DOWN, 0);
  hardware_command_order_light(2, HARDWARE_ORDER_DOWN, 0);
  hardware_command_order_light(3, HARDWARE_ORDER_DOWN, 0);
  hardware_command_order_light(0, HARDWARE_ORDER_UP, 0);
  hardware_command_order_light(1, HARDWARE_ORDER_UP, 0);
  hardware_command_order_light(2, HARDWARE_ORDER_UP, 0);
  hardware_command_order_light(0, HARDWARE_ORDER_INSIDE, 0);
  hardware_command_order_light(1, HARDWARE_ORDER_INSIDE, 0);
  hardware_command_order_light(2, HARDWARE_ORDER_INSIDE, 0);
  hardware_command_order_light(3, HARDWARE_ORDER_INSIDE, 0);
}

