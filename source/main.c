
#include "elevator.h"
#include "fsm_elevator.h"
#include "hardware.h"
#include "elevator_driver.h"
#include "queue_handler.h"
#include "timer.h"

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

    elevator_t e;
    e.current_dir = HARDWARE_MOVEMENT_UP;
    e.current_state = MOVE;
    set_engine(&e);


  while (1) {

    if(hardware_read_stop_signal()){
      hardware_command_movement(HARDWARE_MOVEMENT_STOP);
      break;
        }
  }
}
//         if(hardware_read_floor_sensor(1) && x == 0){
//           hardware_command_movement(HARDWARE_MOVEMENT_STOP);
//           hardware_command_door_open(1);
//           sleep(3);
//           hardware_command_movement(HARDWARE_MOVEMENT_UP);
//
//         }
//
//         if(hardware_read_floor_sensor(0)){
//             hardware_command_movement(HARDWARE_MOVEMENT_UP);
//         }
//         if(hardware_read_floor_sensor(HARDWARE_NUMBER_OF_FLOORS - 1)){
//             hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
//         }
//     }
// }
