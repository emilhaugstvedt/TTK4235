#ifndef ELEVATOR_DRIVER_H
#define ELEVATOR_DRIVER_H
#define INIT_FLOOR 0

#include "elevator.h"

/**
 * @brief
 *
 */
void elevator_driver_go(elevator_t *e);

/**
 * @brief Function that stops the elevator when called.
 */
void elevator_driver_stop();

/**
 * @brief Function that makes the elvator go to the initial floor, 1 atm. Used before the other functions when starting the elevator.
 */
void elevator_driver_init_floor(elevator_t *e);

/**
 * @brief Function that changes the last_floor variable in the elevator struct to the last floor passed by the elevator.
 */
void elevator_driver_floor_passed(elevator_t *e);

/**
 * @brief Function taht clears the lights of floor upon arrival.
 */
void elevator_driver_clear_lights(elevator_t *e);

/**
 * @brief Function that returns 1 if the elevator is at a floor. Used when deciding to open the doors or not.
 */
int elevator_driver_at_floor(elevator_t *e);

void elevator_driver_clear_all_lights();

void elevator_driver_initialize_elevator(elevator_t *e);

void elevator_driver_range_control();

#endif
