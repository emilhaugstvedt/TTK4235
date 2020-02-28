#include "elevator.h"
#include "hardware.h"
#include "elevator_driver.h"
#include "queue_handler.h"
#include <stdlib.h>
#include <stdio.h>

void queue_handler_clear_queue(elevator_t *e){
    for (int floor = 0; floor < HARDWARE_NUMBER_OF_FLOORS; floor++) {
        for (int order = 0; order < NUMBER_OF_ORDERS; order++) {
            e->queue[floor][order] = 0;
        }
    }
}

void queue_handler_update_queue_outside(elevator_t *e){
        if (hardware_read_order(0, HARDWARE_ORDER_UP)){
            e->queue[0][ORDER_UP] = 1;
            printf("%d", 1);
            hardware_command_order_light(0, HARDWARE_ORDER_UP, 1);
        }
        if (hardware_read_order(1, HARDWARE_ORDER_UP)){
            e->queue[1][ORDER_UP] = 1;
            printf("%d",2);
            hardware_command_order_light(1, HARDWARE_ORDER_UP, 1);
        }
        if (hardware_read_order(1, HARDWARE_ORDER_DOWN)){
            e->queue[1][ORDER_DOWN] = 1;
            printf("%d",2);
            hardware_command_order_light(1, HARDWARE_ORDER_DOWN, 1);
        }
        if (hardware_read_order(2, HARDWARE_ORDER_UP)){
            e->queue[2][ORDER_UP] = 1;
            printf("%d",2);
            hardware_command_order_light(2, HARDWARE_ORDER_UP, 1);
        }
        if (hardware_read_order(2, HARDWARE_ORDER_DOWN)){
            e->queue[2][ORDER_DOWN] = 1;
            printf("%d",2);
            hardware_command_order_light(2, HARDWARE_ORDER_DOWN, 1);
        }
        if (hardware_read_order(3, HARDWARE_ORDER_DOWN)){
            e->queue[3][ORDER_DOWN] = 1;
            printf("%d",3);
            hardware_command_order_light(3, HARDWARE_ORDER_DOWN, 1);
        }
      }

  void queue_handler_update_queue_inside(elevator_t *e){
          if (hardware_read_order(0, HARDWARE_ORDER_INSIDE)){
              e->queue[0][ORDER_INSIDE] = 1;
              printf("%d", 0);
          }
          if (hardware_read_order(1, HARDWARE_ORDER_INSIDE)){
            e->queue[1][ORDER_INSIDE] = 1;
            printf("%d", 0);
          }
          if (hardware_read_order(2, HARDWARE_ORDER_INSIDE)){
            e->queue[2][ORDER_INSIDE] = 1;
            printf("%d", 0);
          }
          if(hardware_read_order(3, HARDWARE_ORDER_INSIDE)){
            e->queue[3][ORDER_INSIDE] = 1;
            printf("%d", 0);
          }
  }


int queue_handler_change_dir(elevator_t *e){
  int change_dir = 0;

  if (e->current_dir == HARDWARE_MOVEMENT_UP){
    change_dir = 1;
    for(int floor = e->current_floor; floor < HARDWARE_NUMBER_OF_FLOORS; floor++){
      if(e->queue[floor][ORDER_UP] ||  e->queue[floor][ORDER_INSIDE] || e->queue[TOP_FLOOR][ORDER_DOWN]) {
        change_dir = 0;
      }
      if (change_dir){
        if(queue_handler_order_above(e)) {
            e->current_dir = HARDWARE_MOVEMENT_UP;
            change_dir = 0;
          }
        if(queue_handler_order_below) {
            e->current_dir = HARDWARE_MOVEMENT_DOWN;
            change_dir = 1;
          }
      }
    }
    return change_dir;
  }


  if(e->current_dir == HARDWARE_MOVEMENT_DOWN){
      change_dir = 1;
      for(int floor = e->current_floor; floor >= BOTTOM_FLOOR; floor-- ){
        if(e->queue[floor][ORDER_DOWN] ||  e->queue[floor][ORDER_INSIDE] || e->queue[BOTTOM_FLOOR][ORDER_UP]) {
          change_dir = 0;
        }
      }
        if (change_dir){
          if(queue_handler_order_above(e)) {
              e->current_dir = HARDWARE_MOVEMENT_UP;
              change_dir = 1;
          }
          if(queue_handler_order_below) {
              e->current_dir = HARDWARE_MOVEMENT_DOWN;
              change_dir = 0;
          }
        }
      return change_dir;
      }
      return 0;
    }

int queue_handler_stop(elevator_t *e){

  if(e->current_floor == TOP_FLOOR && e->queue[TOP_FLOOR][ORDER_DOWN]){
    return 1;
  }

  if(e->current_floor == BOTTOM_FLOOR && e->queue[BOTTOM_FLOOR][ORDER_UP]){
    return 1;
  }

  if (e->current_dir == HARDWARE_MOVEMENT_UP){
    if (queue_handler_pass_floor(e) && !e->queue[e->current_floor][ORDER_UP]) {
        return 0;
    }
    else if (e->queue[e->current_floor][ORDER_UP] || e->queue[e->current_floor][ORDER_INSIDE]){
      return 1;
    }
    else if(e->queue[e->current_floor][ORDER_DOWN]){
      return 1;
  }
}

  if (e->current_dir == HARDWARE_MOVEMENT_DOWN) {
    if (queue_handler_pass_floor(e) && !e->queue[e->current_floor][ORDER_DOWN]) {
      return 0;
    }
    else if (e->queue[e->current_floor][ORDER_DOWN] || e->queue[e->current_floor][ORDER_INSIDE]){
      return 1;
    }
    else if (e->queue[e->current_floor][ORDER_UP]){
      return 1;
    }
  }
  return 0;
}


void queue_handler_order_complete(elevator_t *e){
    e->queue[e->current_floor][ORDER_UP] = 0;
    e->queue[e->current_floor][ORDER_INSIDE] =0;
    e->queue[e->current_floor][ORDER_DOWN] = 0;
}


int queue_handler_order_at_current_floor(elevator_t *e) {
  if(e->queue[e->current_floor][ORDER_UP] || e->queue[e->current_floor][ORDER_DOWN] || e->queue[e->current_floor][ORDER_INSIDE]) {
    return 1;
  }
  return 0;
}

int queue_handler_emergency(elevator_t *e) {
  int change_dir = 1;
  
  if(e->current_dir == HARDWARE_MOVEMENT_UP) {
    if(queue_handler_order_at_current_floor(e)){
      e->current_dir = HARDWARE_MOVEMENT_DOWN;
      e->current_floor += 1;
      change_dir = 0;
      return change_dir;
    }
    else {
      if(queue_handler_order_below(e)) {
          change_dir = 0;
          e->current_dir = HARDWARE_MOVEMENT_DOWN;
          return change_dir;
        }
      if(queue_handler_order_above(e)) {
          change_dir = 0;
          e->current_dir = HARDWARE_MOVEMENT_UP;
          return change_dir;
        }
    }
  }

  if(e->current_dir == HARDWARE_MOVEMENT_DOWN) {
    if(queue_handler_order_at_current_floor(e)){
      e->current_dir = HARDWARE_MOVEMENT_UP;
      e->current_floor -= 1;
      change_dir = 1;
      return change_dir;
    }
    else {
      if(queue_handler_order_below) {
        change_dir = 0;
        e->current_dir = HARDWARE_MOVEMENT_DOWN;
        return change_dir;
        }
      if(queue_handler_order_above(e)) {
        change_dir = 0;
        e->current_dir = HARDWARE_MOVEMENT_UP;
        return change_dir;
      }
    }
  }
  return change_dir;
}

int queue_handler_pass_floor(elevator_t *e) {
  if(e->current_dir == HARDWARE_MOVEMENT_UP){
    for (int floor = e->current_floor +1 ; floor < TOP_FLOOR; floor++) {
      if(e->queue[floor][ORDER_DOWN] && !e->queue[floor][ORDER_UP])
        return 1;
    }
    if (e->queue[TOP_FLOOR][ORDER_DOWN] && e->current_floor != TOP_FLOOR) {
      return 1;
    }
    return 0;
  }

  if(e->current_dir == HARDWARE_MOVEMENT_DOWN){
    for (int floor = e->current_floor - 1 ; floor > BOTTOM_FLOOR; floor--) {
      if(e->queue[floor][ORDER_UP] && !e->queue[floor][ORDER_DOWN])
        return 1;
      }
    if (e->queue[BOTTOM_FLOOR][ORDER_UP] && e->current_floor != BOTTOM_FLOOR) {
      return 1;
    }
  return 0;
  }
}

int queue_handler_order_above(elevator_t *e){
  for(int floor = e->current_floor + 1; floor < HARDWARE_NUMBER_OF_FLOORS; floor++){
    if(e->queue[floor][ORDER_UP] ||  e->queue[floor][ORDER_INSIDE] || e->queue[floor][ORDER_DOWN]) {
       return 1;
    }
  }
  return 0;
}

int queue_handler_order_below(elevator_t *e){
  for(int floor = e->current_floor - 1; floor > BOTTOM_FLOOR; floor--){
    if(e->queue[floor][ORDER_UP] ||  e->queue[floor][ORDER_INSIDE] || e->queue[floor][ORDER_DOWN]) {
      return 1;
    }
  }
  return 0;
}