
#include "timer.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

/*
void timer_wait_for_three(){
  int start_time = time(NULL);
  int counter_time = time(NULL);
  if (counter_time - start_time < 3 ){
    counter_time = time(NULL);
  }
}
*/

time_t timer_start_time(){
  return time(NULL);
}

int timer_wait_for_three(time_t start_time){
  printf("%s", "TARTIDEN!!!");
  time_t temp_time = time(NULL);
  if (temp_time - start_time >= 3){
    return 1;
  }
  return 0;
}
