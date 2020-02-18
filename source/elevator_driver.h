#ifndef ELEVATOR_DRIVER_H
#define ELEVATOR_DRIVER_H

void set_engine(elevator_t *e);

/**
 * @brief 
 * 
 */
void elevator_driver_go(elevator_t *e);

/**
 * @brief Function that stops the elevator when called.
 */
void elevator_driver_stop(elevator_t *e);

#endif
