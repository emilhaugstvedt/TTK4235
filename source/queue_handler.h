#ifndef QUEUE_HANDLER_H
#define QUEUE_HANDLER_H
#include "elevator.h"
#include "hardware.h"
#include "elevator_driver.h"
#include <stdlib.h>
/**
* @brief Function that clears the queue in case of emergency stop while moving.
*/
void queue_handler_clear_queue(elevator_t *e);

/**
 * @brief Function that searches for orders and updates queue when allowed.
 */
void queue_handler_update_queue(elevator_t *e);

/**
 * @brief Function that changes the current direction the the elevator.
 */
void queue_handler_choose_direction(elevator_t *e);

/**
 * @brief Function that changes the number in the queue from 1 to 0 after an order is complete.
 */
void queue_handler_order_complete(elevator_t *e);

/**
 * @brief Function that sets the floor for det next order.
 */
void queue_handler_set_floor(elevator_t *e);


#endif
