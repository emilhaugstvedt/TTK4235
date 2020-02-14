#include "elevator.h"
#include "fsm_elevator.h"
#include "hardware.h"
#include "elevator_driver.h"
#include "queue_handler.h"
#include "timer.h"

// void set_engine(elevator_t *e) {
//     switch (e->current_state)
//     {
//     case MOVE:
//         set_engine(e);
//         break;
//     case IDLE:
//     case DOOR_OPEN:
//     case EMERGENCY_STOP:
//
//     default:
//         break;
//     }
// }
//
// void go_to_floor(elevator_t *e) {
//     if (e->current_floor < e)
// }
