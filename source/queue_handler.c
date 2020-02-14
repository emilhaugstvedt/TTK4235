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
}

// //void execute_order(elevator_t *e){
//     // Oppdaterer køen før hver kjøring og endrer rekkefølge etter hva som er i den retningen vi skal.
//     // order 1: 1. etasje opp -> skal til 4. etasje
//     // order 2: 2. etasje ned
//     // order 3: 2. etasje opp
//     // order 4: 3. etasje ned
//     // [1,2,3,4,0,0] -> alle bestillingene i køen
//     // kjører orderen og endrer da køen slik at den ser slik ut:
//     // [3,2,4,0,0,0] -> Fordi bestilling 3 er på veien.
//
// }
//
// //int get_order_floor(elevator_t *e, int floor, int dir) {
//     if (e->queue[floor][dir] == 1) {
//         e->current_dir = 1;
//     }
//
// //order_t order_queue(elevator_t *e) {
//
// }
