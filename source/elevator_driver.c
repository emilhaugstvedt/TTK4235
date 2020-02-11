#include "hardware.h"
#include "elevator.h"
#include "fsm_elevator.h"

void set_engine(Elevator e) {
  switch (e->current_state){
    case MOVE:
      hardware_command_movement(e.current_dir);
    }
}
