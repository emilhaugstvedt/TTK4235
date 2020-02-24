
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

hardware_command_order_light(1, HARDWARE_ORDER_DOWN, 0);
hardware_command_order_light(2, HARDWARE_ORDER_DOWN, 0);
hardware_command_order_light(3, HARDWARE_ORDER_DOWN, 0);
hardware_command_order_light(0, HARDWARE_ORDER_UP, 0);
hardware_command_order_light(1, HARDWARE_ORDER_UP, 0);
hardware_command_order_light(2, HARDWARE_ORDER_UP, 0);
hardware_command_order_light(0, HARDWARE_ORDER_INSIDE, 0);
hardware_command_order_light(1, HARDWARE_ORDER_INSIDE, 0);
hardware_command_order_light(2, HARDWARE_ORDER_INSIDE, 0);
hardware_command_order_light(3, HARDWARE_ORDER_INSIDE, 0);

elevator_t elev;
elevator_t *e = &elev;
elevator_driver_init_floor(e);
e->current_state = IDLE;
e->current_dir = HARDWARE_MOVEMENT_STOP;
e->next_dir = HARDWARE_MOVEMENT_STOP;
e->time = 0;
for(int floor = 0; floor < 4; floor++) {
  for (int order = 0; order < 2; order ++) {
    e->queue[floor][order] = 0;
  }
}
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
