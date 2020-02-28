
#include "timer.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>


time_t timer_start_time(){
  return time(NULL);
}

int timer_three_seconds(time_t start_time){
  if (time(NULL) - start_time >=3){
    return TRUE;
  }
  return FALSE;
}
