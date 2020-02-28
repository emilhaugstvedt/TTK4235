/**
 * @file queue_handler.h
 * @author your name (you@domain.com)
 * @brief Function that contains all the different operations performed on the queue matrix.
 */


#ifndef QUEUE_HANDLER_H
#define QUEUE_HANDLER_H
#include "elevator_driver.h"

#define TRUE 1
#define FALSE 0

/**
* @brief Function that clears the queue matrix in case of emergency stop while moving.
* @param elevator_t Struct that contains all the information important for running the elevator.
*/
void queue_handler_clear_queue(elevator_t *e);

/**
 * @brief Function that searches for orders and updates the queue.
 * @param elevator_t Struct that contains all the information important for running the elevator.
 */
void queue_handler_update_queue_outside(elevator_t *e);

/**
 * @brief Function that changes the current direction the the elevator.
 * 
 * If current direction is up, the function will first search for orders above before searching for orders below afterwards.
 * Likewise, if current direction is down, the functtion first search for orders below, before searching for orders above.
 * When the elevator is in idle state it will switch between searching for orders above and below and return 1 as long as no order
 * is found. When an order is found it wil return 0. This means that as long as the elevator returns 1 it has not found an order. 
 * @param elevator_t Struct that contains all the information important for running the elevator.
 * @return 1 if the elevator should change direction and 0 if not. 
 */
int queue_handler_change_dir(elevator_t *e);

/**
 * @brief Function that changes the number in the queue from 1 to 0 after an order is complete.
 * 
 * If any type of order at current floor the function will remove the order from the order matrix.
 * @param elevator_t Struct that contains all the information important for running the elevator.
 */
void queue_handler_order_complete(elevator_t *e);

/**
 * @brief Function that searches for orders from inside the elevator and updates the queue matrix
 * if any orders. 
 * @param elevator_t Struct that contains all the information important for running the elevator.
 * 
 */
void queue_handler_update_queue_inside(elevator_t *e);

/**
 * @brief Function that returns 1 if the elevator should stop at current floor, and 0 if not. 
 * 
 * The function first check if the current floor is top or bottom floor and if there is an order
 * at one of these floors. It returns 1 if both is true. Afterwards, if the elevator is moving upwards, it 
 * searches for orders up or inside above the current floor before stopping for order down. 
 * Likewise, if the elevator is moving downwards, it searches for orders down or inside below the
 * current floor before stopping for order up.
 * 
 * @param elevator_t Struct that contains all the information important for running the elevator.
 * @returns 1 if the elevator should stop and 0 otherwise.
 */
int queue_handler_stop(elevator_t *e);

/**
 * @brief Function that checks if there is an order of any type at the current floor. 
 * @param elevator_t Struct that contains all the information important for running the elevator.
 * @returns 1 if there is an order at the floor, 0 otherwise.
 * 
 */
int queue_handler_order_at_current_floor(elevator_t *e);


/**
 * @brief Function for chosing the next direction for the elevator when the elevator is between floors in emergency state.
 * 
 * If the elevator stops between floors we need to have a differnt function to choose direction. For example if we are between the first
 * and second floor with current direction upwards and an order is made in the first floor, the elevator does not know it is between floors
 * and not at the first floor, as the variable current_floor says. Therefore the functtion needs to change the current floor from first
 * to second and also change current direction to down. The same applies to other direction and floors. 
 * 
 * @returns 1 if direction and floor is set as it should, and 0 otherwise.
 */
int queue_handler_emergency(elevator_t *e);

/**
 * @brief Function that decides if the elevator should pass a floor due to orders above or not.
 * 
 * If the elevator is moving upwards, the function will first iterate through the above floors searching for floors with orders in the oposite
 * direction and no orders in the current direction, if any the function returns 1. And moving downwards the function will, likewise, search for orders below and if there are
 * any floors with orders up and no orders down it will return 1. Otherwise it returns 0.
 * 
 * @param elevator_t Struct that contains all the information important for running the elevator.
 * @returns returns 1 if the elevator should pass the floor, 0 if not. 
 */
int queue_handler_pass_floor(elevator_t *e);

/**
 * @brief Function that iterates through the above floors and searches for orders of any type. 
 * 
 * @param elevator_t Struct that contains all the information important for running the elevator.
 * @return 1 if there are an order of any type in one of the above floors. 0 otherwise.
 */
int queue_handler_order_above(elevator_t *e);

/**
 * @brief Function that iterates through the below floors and searches for orders of any type. 
 * 
 * @param elevator_t Struct that contains all the information important for running the elevator.
 * @return 1 if there are an order of any type in one of the below floors. 0 otherwise.
 */
int queue_handler_order_below(elevator_t *e);


#endif
