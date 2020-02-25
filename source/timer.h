#ifndef TIMER_H
#define TIMER_H
#include <time.h>
#include <stdlib.h>


extern int timer_enable;
/**
 * @brief
 */
void timer_end_time();

/**
 * @brief Function that returns a start time. Used for saving a timestamp in the elevator.
 */
int timer_time_out();


#endif
