#include "elevator.h"
#include "fsm_elevator.h"


struct Elevator {
  State current_state;
  int floor;
  int qeue[4][3];
  HardwareMovement current_dir;
};
