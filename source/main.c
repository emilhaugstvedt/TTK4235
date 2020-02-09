#include <stdio.h>
#include <stdlib.h>
#include "hardware.h"
#include <unistd.h>

typedef enum {IDLE, MOVE, EMERGENCY_STOP, DOOR_OPEN} State;


int main(){

  switch (State s) {
    case (IDLE):
    case (MOVE):
    case (EMERGENCY_STOP):
    case (DOOR_OPEN)
  }



    int error = hardware_init();
    if(error != 0){
        fprintf(stderr, "Unable to initialize hardware\n");
        exit(1);
    }

    printf("=== Example Program ===\n");
    printf("Press the stop button on the elevator panel to exit\n");

    hardware_command_movement(HARDWARE_MOVEMENT_UP);
    int x = 0;

    while(1){
        if(hardware_read_stop_signal()){
            hardware_command_movement(HARDWARE_MOVEMENT_STOP);
            break;
        }
        if(hardware_read_floor_sensor(1) && x == 0){
          hardware_command_movement(HARDWARE_MOVEMENT_STOP);
          hardware_command_door_open(1);
          sleep(3);
          hardware_command_movement(HARDWARE_MOVEMENT_UP);
          x = 1;
        }

        if(hardware_read_floor_sensor(0)){
            hardware_command_movement(HARDWARE_MOVEMENT_UP);
        }
        if(hardware_read_floor_sensor(HARDWARE_NUMBER_OF_FLOORS - 1)){
            hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
        }
    }
}
