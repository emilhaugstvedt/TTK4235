#ifndef FSM_ELEVATOR_H
#define FSM_ELEVATOR_H

#include "elevator_driver.h"
#include "queue_handler.h"
#include "elevator.h"

#include <stdlib.h>


/**
* @brief Function that takes care of everything happening while the elevator is in MOVE state.
*/
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


/**
 * @brief The main fsm function that makes the elevator work. It contains a switch and switches between the differnt functions
 * according to the elevators current state.
 */
void fsm_elevator_go(elevator_t *e);

#endif
