#include <time.h>
#include "timer.h"
#include "elevator.h"
/*
void timer_wait_for_three(){
  int start_time = time(NULL);
  int counter_time = time(NULL);
  if (counter_time - start_time < 3 ){
    counter_time = time(NULL);
  }
}
*/

void timer_start_time(elevator_t *e){
  e->time = time(NULL);
}

int timer_time_out(elevator_t *e){
  time_t temp_time = time(NULL);
  if (temp_time - e->time >= 3){
    return 1;
  }
  return 0;
}
