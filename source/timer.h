#ifndef TIMER_H
#define TIMER_H
#include <time.h>
#include <stdlib.h>

/**
 * @brief
 */
time_t timer_start_time();

/**
 * @brief Function that returns a start time. Used for saving a timestamp in the elevator.
 */
int timer_three_seconds(time_t start_time);


#endif
