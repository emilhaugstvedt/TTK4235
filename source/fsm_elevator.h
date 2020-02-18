#ifndef FSM_ELEVATOR_H
#define FSM_ELEVATOR_H
#include "elevator.h"

typedef enum states{
  IDLE,
  MOVE,
  EMERGENCY_STOP,
  DOOR_OPEN
} state_t;

/**
//  * @brief Function that takes care of everything happening while the elevator is in MOVE state.
//  */
 void move_state(elevator_t *e);

/**
* @brief Function that takes care of everything happening while the elevator is in IDLE state.
*/
void idle_state(elevator_t *e);

/**
* @brief Function that takes care of everything happening while the elevator is in EMERGENCY_STOP state.
*/
void emergency_state(elevator_t *e);

/**
* @brief Function that takes care of everything happening while the elevator is in DOOR_OPEN state.
*/
void door_state(elevator_t *e);
//
// /**
//  * @brief Function that makes the elevator go to the default floor.
//  */
void go_to_default(elevator_t *e);
//
// /**
//  * @brief The main fsm function that makes the elevator work. It contains a switch and switches between the differnt functions
//  * according to the elevators current state.
//  */
void elevator_go(elevator_t *e);

#endif
