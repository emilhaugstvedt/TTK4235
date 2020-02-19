#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "hardware.h"
#include "timer.h"


#define QUEUE_FLOOR 4
#define QUEUE_ORDERS 2
#define ORDER_UP 1
#define ORDER_DOWN 0
#define MAX_ORDER_AMOUNT 6

typedef enum {
  IDLE,
  MOVE,
  EMERGENCY_STOP,
  DOOR_OPEN
} elevator_state_t;

/**
 * @brief Struct that describes the elevator. It contains all the important variables for the process
 */
typedef struct {
  elevator_state_t current_state;
  elevator_state_t last_state;
  int current_floor;
  int last_floor;
  int queue[QUEUE_FLOOR][QUEUE_ORDERS];
  HardwareMovement current_dir;
  HardwareMovement next_dir;
  int allow_order_search;
  time_t time;
} elevator_t;

#endif
