#ifndef ELEVATOR_DRIVER_H
#define ELEVATOR_DRIVER_H
#define INIT_FLOOR 0

#include "elevator.h"


void elevator_driver_set_engine(elevator_t *e);

/**
 * @brief
 *
 */
void elevator_driver_go(elevator_t *e);

/**
 * @brief Function that stops the elevator when called.
 */
void elevator_driver_stop(elevator_t *e);

void elevator_driver_init_floor(elevator_t *e);

void elevator_driver_open_door();

#endif
