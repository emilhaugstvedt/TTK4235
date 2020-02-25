
#include "timer.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#define DURATION 3

static time_t end_time;
int timer_enable;

/*
void timer_wait_for_three(){
  int start_time = time(NULL);
  int counter_time = time(NULL);
  if (counter_time - start_time < 3 ){
    counter_time = time(NULL);
  }
}
*/

void timer_end_time(){
  end_time = time(NULL) + DURATION;
  timer_enable = 1;
}

int timer_time_out(time_t start_time){
  if (end_time < time(NULL)){
    return 1;
  }
  return 0;
}
