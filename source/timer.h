#ifndef TIMER_H
#define TIMER_H
#include <time.h>
#include <stdlib.h>

/**
 * @brief Function that returns current time.
 */
time_t timer_start_time();

/**
 * @brief Function that returns 1 if three seconds is passed. 
 * 
 * THe function takes in a time and returns 1 when the differnce between stat_time and current time is bigger or equal to three. 
 */
int timer_three_seconds(time_t start_time);


#endif
