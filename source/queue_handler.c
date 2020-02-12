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
    if (e->allow_order_search){
        if (hardware_read_order(0, HARDWARE_ORDER_UP){
            hardware_
            e->queue[0][0] = 1;
        }
        if (hardware_read_order(0, HARDWARE_ORDER_DOWN)){
            e->queue[0][1] = 1;
        }
        if (hardware_read_order(1, HARDWARE_ORDER_UP)){
            e->queue[1][0] = 1;
        }
        if (hardware_read_order(1, HARDWARE_ORDER_DOWN)){
            e->queue[1][1] = 1;
        }
        if (hardware_read_order(2, HARDWARE_ORDER_UP)){
            e->queue[2][0] = 1;
        }
        if (hardware_read_order(2, HARDWARE_ORDER_DOWN)){
            e->queue[2][1] = 1;
        }
        if (hardware_read_order(3, HARDWARE_ORDER_UP)){
            e->queue[3][0] = 1;
        }
        if (hardware_read_order(3, HARDWARE_ORDER_DOWN)){
            e->queue[3][1] = 1;
        }
    }
}