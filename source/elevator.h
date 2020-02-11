#ifndef ELEVATOR_H
#define ELEVATOR_H

struct Elevator {
  State current_state;
  int floor;
  int qeue[4][3];
  Direction current_dir;
};

#endif
