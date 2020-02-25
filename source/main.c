
#include "fsm_elevator.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

    int error = hardware_init();
    if(error != 0){
        fprintf(stderr, "Unable to initialize hardware\n");
        exit(1);
    }

    printf("=== Example Program ===\n");
    printf("Press the stop button on the elevator panel to exit\n");

elevator_driver_clear_all_lights();

elevator_t elev;
elevator_t *e = &elev;

elevator_driver_init_floor(e);

elevator_driver_initialize_elevator(e);

fsm_elevator_go(e);
// while(!hardware_read_stop_signal()){
//   if (hardware_read_order(3, HARDWARE_ORDER_INSIDE)){
//     printf("%d", 3);
//   }
//     if (hardware_read_order(2, HARDWARE_ORDER_INSIDE)){
//     printf("%d", 2);
//   }
//     if (hardware_read_order(1, HARDWARE_ORDER_INSIDE)){
//     printf("%d", 1);
//   }
//     if (hardware_read_order(0, HARDWARE_ORDER_INSIDE)){
//     printf("%d", 0);
//   }
// }
for(int floor = 0; floor < 4; floor++) {
  for (int order = 0; order < 2; order ++) {
    printf("%d \n", e->queue[floor][order]);
  }}


}
