#include "elevator.h"
#include "fsm_elevator.h"
#include "hardware.h"
#include "elevator_driver.h"
#include "queue_handler.h"
#include "timer.h"

void clear_queue(elevator_t *e){
    for (int floor = 0; floor < QUEUE_FLOOR; floor++) {
        for (int order = 0; order < QUEUE_ORDERS; order++) {
            e->queue[floor][order] = 0;
        }
    }
}

void update_queue(elevator_t *e){
        if (hardware_read_order(0, HARDWARE_ORDER_UP)){
            e->queue[0][ORDER_UP] = 1;
            hardware_command_order_light(0, HARDWARE_ORDER_UP, 1);
        }
        if (hardware_read_order(1, HARDWARE_ORDER_UP)){
            e->queue[1][ORDER_UP] = 1;
            hardware_command_order_light(1, HARDWARE_ORDER_UP, 1);
        }
        if (hardware_read_order(1, HARDWARE_ORDER_DOWN)){
            e->queue[1][ORDER_DOWN] = 1;
            hardware_command_order_light(1, HARDWARE_ORDER_DOWN, 1);
        }
        if (hardware_read_order(2, HARDWARE_ORDER_UP)){
            e->queue[2][ORDER_UP] = 1;
            hardware_command_order_light(2, HARDWARE_ORDER_UP, 1);
        }
        if (hardware_read_order(2, HARDWARE_ORDER_DOWN)){
            e->queue[2][ORDER_DOWN] = 1;
            hardware_command_order_light(2, HARDWARE_ORDER_DOWN, 1);
        }
        if (hardware_read_order(3, HARDWARE_ORDER_DOWN)){
            e->queue[3][ORDER_DOWN] = 1;
            hardware_command_order_light(3, HARDWARE_ORDER_DOWN, 1);
        }
      }




void choose_direction(elevator_t *e){
    if (e->current_dir == 1 ) {
      e->current_dir = 0;
      for (int floor = 0 + e->current_floor; floor < QUEUE_FLOOR; floor ++) {
        if (e->queue[floor][ORDER_UP] == 1) {
          e->current_dir = 1;

      }
    }
    if (e->current_dir == 0) {
      e->current_dir = 1; {
        for (int floor = e->current_floor; floor > 0; floor--){
          if (e->queue[floor][ORDER_DOWN] == 0) {
            e->current_dir = 0;
          }
        }
      }
    }
  }
}
