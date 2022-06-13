#ifndef SCHEDULING_H_
#define SCHEDULING_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct{
  char process_name[20];
  int arrival_time;
  int processing_time;
  int processing_start_time;
  int processing_complete_time;
  int turn_around_time;
  int progress;
  int state;
  /*
      0:waiting state
      1:ready state
      2:running state
      -1:complete state
  */
}process_t;

void fcfs(int, process_t*);
void spts(int, process_t*);
void round_robin(int, int, process_t*);

#endif /*SCHEDULING_H_*/
