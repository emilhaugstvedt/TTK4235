#ifndef FSM_ELEVATOR_H
#define FSM_ELEVATOR_H
#include "elevator.h"

typedef enum states{
  IDLE,
  MOVE,
  EMERGENCY_STOP,
  DOOR_OPEN
} state_t;

// void move_state(elevator_t *e);
//
// void idle_state(elevator_t *e);
//
// void emergency_state(elevator *e);
//
// void door_state(elevator_t *e);
//
// State get_current_state(elevator_t *e);
//
// void go_to_default(elevator_t *e);
//
// void elevator_go(elevator_t *e);

#endif
