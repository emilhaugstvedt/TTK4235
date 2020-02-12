#ifndef ELEVATOR_H
#define ELEVATOR_H
#define QUEUE_FLOOR 4
#define QUEUE_ORDERS 2
#include "hardware.h"
#include "fsm_elevator.h"


/**
 * @brief Struct that describes the elevator. It contains all the important variables for the process
 */
typedef struct elevator {
  state_t current_state;
  state_t last_state;
  int floor;
  int queue[QUEUE_FLOOR][QUEUE_ORDERS];
  HardwareMovement current_dir;
  int allow_order_search;
} elevator_t;

#endif
