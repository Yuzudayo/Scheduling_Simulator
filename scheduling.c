#include "scheduling.h"

/* First Come First Served */
void fcfs(int number_of_processes, process_t* process_list){
  int current_process = 0;
  printf("START!\n");
  for (int time = 0; current_process < number_of_processes; time++) {
    for (int i = 0; i < number_of_processes; i++) {
      /* confirmation of arrival */
      if (process_list[i].arrival_time == time) {
        process_list[i].state = 1;
      }
    }
    /* start processing*/
    if (process_list[current_process].state == 1) {
      process_list[current_process].processing_start_time = time;
      process_list[current_process].state = 2;
    }
    printf("%3d Task:%s", time + 1, (process_list[current_process].state == 2) ? process_list[current_process].process_name : "");
    /* complete processing*/
    if (process_list[current_process].state == 2 &&
      (process_list[current_process].processing_start_time + process_list[current_process].processing_time) == time + 1) {
      process_list[current_process].processing_complete_time = time + 1;
      process_list[current_process].turn_around_time = process_list[current_process].processing_complete_time
         - process_list[current_process].arrival_time;
      process_list[current_process].state = -1;
      current_process++;
      printf(" is completed");
    }
    printf("\n");
  }
  printf("END!\n");
  return;
}

/* Shortest Processing Time First */
void spts(int number_of_processes, process_t* process_list){
  int current_process = 0;
  bool chk_processing_time = true;
  printf("START!\n");
  for (int time = 0, count = 0; count < number_of_processes; time++) {
    for (int i = 0; i < number_of_processes; i++) {
      /* confirmation of arrival */
      if (process_list[i].arrival_time == time) {
        process_list[i].state = 1;
      }
    }

    if (chk_processing_time) {
      int min = INT_MAX;
      for (int i = 0; i < number_of_processes; i++) {
        if ((process_list[i].processing_time < min) && process_list[i].state == 1) {
          min = process_list[i].processing_time;
          current_process = i;
        }
      }
      chk_processing_time = false;
    }

    /* start processing*/
    if (process_list[current_process].state == 1) {
      process_list[current_process].processing_start_time = time;
      process_list[current_process].state = 2;
    }
    printf("%3d Task:%s", time + 1, (process_list[current_process].state == 2) ? process_list[current_process].process_name : "");
    /* complete processing*/
    if (process_list[current_process].state == 2 &&
      (process_list[current_process].processing_start_time + process_list[current_process].processing_time) == time + 1) {
      process_list[current_process].processing_complete_time = time + 1;
      process_list[current_process].turn_around_time = process_list[current_process].processing_complete_time
         - process_list[current_process].arrival_time;
      process_list[current_process].state = -1;
      chk_processing_time = true;
      count++;
      printf(" is completed");
    }
    printf("\n");
  }
  printf("END!\n");
  return;
}

/* Round Robin*/
void round_robin(int number_of_processes, int time_slice, process_t* process_list){
  int head = 0, tail = 0, current_process = -1, step = 0;
  int queue[number_of_processes];
  /* queue initialization*/
  for (int i = 0; i < number_of_processes; i++)
    queue[i] = -1;
  printf("START!\n");
  for (int time = 0, count = 0; count < number_of_processes; time++) {
    for (int i = 0; i < number_of_processes; i++) {
      /* confirmation of arrival */
      if (process_list[i].arrival_time == time) {
        process_list[i].state = 1;
        /* enqueue */
        tail = (tail + 1) % number_of_processes;
        queue[tail] = i;
      }
    }
    /* can execute the process */
    if (queue[(head + 1) % number_of_processes] != -1 || current_process != -1) {
      if (step % time_slice != 0) {
        process_list[current_process].progress++;
        step++;
      }
      /* swapping processes */
      else {
        if (current_process != -1) {
          tail = (tail + 1) % number_of_processes;
          queue[tail] = current_process;
          process_list[current_process].state = 1;
        }
        /* dequeue */
        head = (head + 1) % number_of_processes;
        current_process = queue[head];
        process_list[current_process].state = 2;
        queue[head] = -1;
        process_list[current_process].progress++;
        step++;
      }
    }
    printf("%3d Task:%s", time + 1, (process_list[current_process].state == 2) ? process_list[current_process].process_name : "");
    /* complete processing*/
    if (process_list[current_process].state == 2 &&
      process_list[current_process].progress == process_list[current_process].processing_time) {
      process_list[current_process].processing_complete_time = time + 1;
      process_list[current_process].turn_around_time = process_list[current_process].processing_complete_time
         - process_list[current_process].arrival_time;
      process_list[current_process].state = -1;
      count++;
      current_process = -1;
      /* go to next step */
      if (step % time_slice != 0)
        step = step + time_slice - (step % time_slice);
      printf(" is completed");
    }
    printf("\n");
  }
  printf("END!\n");
  return;
}
