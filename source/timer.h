#ifndef TIMER_H
#define TIMER_H
#include <time.h>
#include <stdlib.h>

//void timer_wait_for_three();

time_t timer_start_time();

int timer_time_out(time_t start_time);

#endif
