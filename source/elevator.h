#ifndef ELEVATOR_H
#define ELEVATOR_H
#define QUEUE_FLOOR 4
#define QUEUE_ORDERS 2
#include "hardware.h"
#include "fsm_elevator.h"

typedef struct elevator {
  state_t current_state;
  state_t last_state;
  int floor;
  int qeue[4][3];
  HardwareMovement current_dir;
  int allow_order_search;
} elevator_t;

#endif
