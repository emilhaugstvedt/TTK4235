#ifndef FSM_ELEVATOR_H
#define FSM_ELEVATOR_H

typedef enum {
  IDLE,
  MOVE,
  EMERGENCY_STOP,
  DOOR_OPEN
} State;

void move_state(Elevator e);

void idle_state(Elevator e);

void emergency_state(Elevator e);

void door_state(Elevator e);

State get_current_state(Elevator e);

void go_to_default(Elevator e);

#endif
