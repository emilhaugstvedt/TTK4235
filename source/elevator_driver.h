/**
 * @file elevator_driver.h
 * @brief File that contains the functions needed for driving the elevator and getting information from the differnt sensors to upfate the floor.
 */

#ifndef ELEVATOR_DRIVER_H
#define ELEVATOR_DRIVER_H
#define DEFAULT_FLOOR 0
#define TRUE 1
#define FALSE 0

#include "elevator.h"
/**
 * @brief Function that makes the elevator go in the direction current direction is. 
 * 
 * @param elevator_t Struct that contains all the information important for running the elevator.
 */
void elevator_driver_start(elevator_t *e);

/**
 * @brief Function that stops the elevator when called.
 */
void elevator_driver_stop();

/**
 * @brief Function that makes the elvator go to the default floor. Used before the other functions when starting the elevator.
 * @param elevator_t Struct that contains all the information important for running the elevator.
 */
void elevator_driver_default_floor(elevator_t *e);

/**
 * @brief Function that updates the current floor varible when a floor is passed. 
 * @param elevator_t Struct that contains all the information important for running the elevator.
 */
void elevator_driver_floor_passed(elevator_t *e);

/**
 * @brief Function that returns 1 if the elevator is at a floor. Used when deciding to open the doors or not.
 * @param elevator_t Struct that contains all the information important for running the elevator.
 */
int elevator_driver_at_floor(elevator_t *e);

/**
 * @brief Function that initializes the variables in the elevator.
 * @param elevator_t Struct that contains all the information important for running the elevator.
 */
void elevator_driver_initialize_elevator(elevator_t *e);

/**
 * @brief Function that stops the elevator if its on its way passed floor number 1 and 4.
 */
void elevator_driver_range_control();

#endif
