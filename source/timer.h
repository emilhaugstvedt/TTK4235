#ifndef TIMER_H
#define TIMER_H
#include <time.h>
#include <stdlib.h>


/**
 * @brief Function that takes in a time and waits three seconds from that time.
 */
int timer_wait_for_three();

/**
 * @brief Function that returns a start time. Used for saving a timestamp in the elevator.
 */
time_t timer_start_time();


#endif
