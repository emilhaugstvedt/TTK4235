#include "elevator.h"
#include "fsm_elevator.h"
#include "hardware.h"
#include "elevator_driver.h"
#include "queue_handler.h"
#include "timer.h"

void set_engine(elevator_t *e) {
    hardware_command_movement(e->current_dir);
}
