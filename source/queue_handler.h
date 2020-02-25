#ifndef QUEUE_HANDLER_H
#define QUEUE_HANDLER_H
#include "elevator.h"
#include "hardware.h"
#include "elevator_driver.h"
#include <stdlib.h>
/**
* @brief Function that clears the queue in case of emergency stop while moving.
* @param elevator_t Struct that contains all the information important for running the elevator.
*/
void queue_handler_clear_queue(elevator_t *e);

/**
 * @brief Function that searches for orders and updates queue when allowed.
 * @param elevator_t Struct that contains all the information important for running the elevator.
 */
void queue_handler_update_queue_outside(elevator_t *e);

/**
 * @brief Function that changes the current direction the the elevator.
 */
int queue_handler_change_dir(elevator_t *e);

/**
 * @brief Function that changes the number in the queue from 1 to 0 after an order is complete.
 * @param elevator_t Struct that contains all the information important for running the elevator.
 */
void queue_handler_order_complete(elevator_t *e);

/**
 * @brief Function that sets the floor for det next order.
 * @param elevator_t Struct that contains all the information important for running the elevator.
 */
void queue_handler_set_floor(elevator_t *e);

/**
 * @brief Function that searches for orders from inside the elevator
 * @param elevator_t Struct that contains all the information important for running the elevator.
 */
void queue_handler_update_queue_inside(elevator_t *e);

void queue_handler_current_floor(elevator_t *e);

int queue_handler_stop(elevator_t *e);

void queue_handler_lights(elevator_t *e);

#endif
