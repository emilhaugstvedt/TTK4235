/**
 * @file fsm_elevator.h
 * @brief File that contains the functions deciding what the elevator should do in the differnt states.
 * 
 */

#ifndef FSM_ELEVATOR_H
#define FSM_ELEVATOR_H

#include "queue_handler.h"


/**
* @brief Function that takes care of everything happening while the elevator is in MOVE state.
* @param elevator_t Struct that contains all the information important for running the elevator.
*/
 void move_state(elevator_t *e);

/**
* @brief Function that takes care of everything happening while the elevator is in IDLE state.
* @param elevator_t Struct that contains all the information important for running the elevator.
*/
void idle_state(elevator_t *e);

/**
* @brief Function that takes care of everything happening while the elevator is in EMERGENCY_STOP state.
* @param elevator_t Struct that contains all the information important for running the elevator.
*/
void emergency_stop_state(elevator_t *e);

/**
* @brief Function that takes care of everything happening while the elevator is in DOOR_OPEN state.
* @param elevator_t Struct that contains all the information important for running the elevator.
*/
void door_state(elevator_t *e);


/**
 * @brief The main fsm function that makes the elevator work. It contains a switch and switches between the differnt functions
 * according to the elevators current state.
 * * @param elevator_t Struct that contains all the information important for running the elevator.
 */
void fsm_elevator_go(elevator_t *e);

#endif
