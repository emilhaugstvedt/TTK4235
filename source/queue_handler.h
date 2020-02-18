#ifndef QUEUE_HANDLER_H
#define QUEUE_HANDLER_H

/**
* @brief Function that clears the queue in case of emergency stop while moving.
*/
void clear_queue(elevator_t *e);

/**
 * @brief Function that searches for orders and updates queue when allowed.
 */
void update_queue(elevator_t *e);

/**
 * @brief Function that changes the current direction the the elevator. Retruns 1 if there is a state change. 
 */
int queue_hander_choose_direction(elevator_t *e);

/**
 * @brief Function that changes the number in the queue from 1 to 0 after an order is complete.
 */
void queue_handler_order_complete(elevator_t *e);


#endif
