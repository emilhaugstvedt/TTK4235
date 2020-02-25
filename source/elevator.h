#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "hardware.h"
#include "timer.h"


#define ORDER_UP 0
#define ORDER_DOWN 1
#define ORDER_INSIDE 2
#define NUMBER_OF_ORDERS 3

/**
 * @brief Enum used to define the different states of the elevator.
 */
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
  int queue[HARDWARE_NUMBER_OF_FLOORS][NUMBER_OF_ORDERS];
  HardwareMovement current_dir;
} elevator_t;

#endif
