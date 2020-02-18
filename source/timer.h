#ifndef TIMER_H
#define TIMER_H
#include <time.h>
#include "elevator.h"

//void timer_wait_for_three();

void timer_start_time(elevator_t *e);

int timer_time_out(elevator_t *e);
#endif
