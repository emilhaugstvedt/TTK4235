#ifndef QUEUE_HANDLER_H
#define QUEUE_HANDLER_H


typedef struct order {
    int floor;
    int dir;
} order_t;


/**
* @brief Function that clears the queue in case of emergency stop while moving.
*/
void clear_queue(elevator_t *e);

/**
 * @brief Function that searches for orders and updates queue when allowed.
 */
void update_queue(elevator_t *e);

int get_next_order(elevator_t *e);

order_t order_queue(elevator_t *e);


#endif
