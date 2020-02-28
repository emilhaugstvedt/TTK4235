
#include "fsm_elevator.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

int error = hardware_init();
if(error != 0){
    fprintf(stderr, "Unable to initialize hardware\n");
    exit(1);
}

elevator_t elev;
elevator_t *e = &elev;

elevator_driver_initialize_elevator(e);

elevator_driver_default_floor(e);

printf("PLING!\n");
printf("Heisen er nå klar til bruk. Enjoy!\n");

fsm_elevator_go(e);


}
