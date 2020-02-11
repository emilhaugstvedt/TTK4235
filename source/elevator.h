#ifndef ELEVATOR_H
#define ELEVATOR_H
#include "hardware.h"
#include "fsm_elevator.h"

typedef struct elevator {
  state_t current_state;
  int floor;
  int qeue[4][3];
  HardwareMovement current_dir;
} elevator_t;

#endif
