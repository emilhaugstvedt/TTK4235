#include "elevator.h"
#include "fsm_elevator.h"
#include "hardware.h"
#include "elevator_driver.h"
#include "queue_handler.h"
#include "timer.h"

void set_engine(elevator_t *e) {
    switch (e->current_state)
    {
    case MOVE:
        set_engine(e);
        break;
    case IDLE:
    case DOOR_OPEN:
    case EMERGENCY_STOP:

    default:
        break;
    }
}

void run_do_do_do_do_do_do(elevator_t *e) {
  hardware_command_movement(HARDWARE_MOVEMENT_UP);
  while(1){
  if(hardware_read_floor_sensor(2)){
    hardware_command_movement(HARDWARE_MOVEMENT_STOP);
    break;
  }
  }
}
