#include "scheduling.h"
void sort_processes(int, process_t*);
void print_result(int, process_t*);
void init_processes(int, process_t*);

int main() {
  int number_of_processes, scheduling_algoritms, time_slice;

  /* input of various information */
  printf("Please select scheduling algorithms\n"
           "1:First Come First Served (input 1)\n"
           "2:Shortest Processing Time First (input 2)\n"
           "3:Round Robin (input 3)\n");
  scanf("%d", &scheduling_algoritms);
  printf("Please input the number of processes\n");
  scanf("%d", &number_of_processes);
  process_t* process_list = (process_t*)malloc(sizeof(process_t) * number_of_processes);
  /* processes initialization*/
  init_processes(number_of_processes, process_list);
  printf("Please input each of the following\n"
           "Process_name Arrival_time Processing_time\n");
  for (int i = 0; i < number_of_processes; i++) {
    scanf("%s %d %d",
             process_list[i].process_name, &process_list[i].arrival_time, &process_list[i].processing_time);
    process_list[i].state = 0;
  }
  if (scheduling_algoritms == 3){
    printf("Time slice? : ");
    scanf("%d", &time_slice);
  }

  /* sort processes by arrival time */
  sort_processes(number_of_processes, process_list);

  switch (scheduling_algoritms) {
    /* First Come First Served */
    case 1:
      printf("Algorithm:First Come First Served\n");
      fcfs(number_of_processes, process_list);
      break;
    /* Shortest Processing Time First */
    case 2:
      printf("Algorithms:Shortest Processing Time First\n");
      spts(number_of_processes, process_list);
      break;
    /* Round Robin*/
    case 3:
      printf("Algorithms:Round Robin\n");
      round_robin(number_of_processes, time_slice, process_list);
      break;
    default:
      printf("Improper input\n");
      return 0;
  }

  /* display result*/
  print_result(number_of_processes, process_list);

  free(process_list);
  return 0;
}

void init_processes(int number_of_processes, process_t* process_list){
  for (int i = 0; i < number_of_processes; i++) {
    process_list[i].state = 0;
    process_list[i].progress = 0;
  }
  return;
}

void sort_processes(int number_of_processes, process_t* process_list){
  for (int i = 0; i < number_of_processes; i++) {
    for (int j = 0; j < number_of_processes; j++) {
      if (process_list[i].arrival_time < process_list[j].arrival_time) {
        process_t tmp = process_list[i];
        process_list[i] = process_list[j];
        process_list[j] = tmp;
      }
    }
  }
  return;
}

void print_result(int number_of_processes, process_t* process_list){
  int sum = 0;
  printf("\nRESULT\n");
  printf("Process_Name|Arrival_Time|Processing_Time|Complete_Time|Turn_Around_Time\n");
  for (int i = 0; i < 72; i++)
    printf("-");
  printf("\n");
  for (int i = 0; i < number_of_processes; i++) {
    printf("%12s|%12d|%15d|%13d|%16d\n",
             process_list[i].process_name, process_list[i].arrival_time, process_list[i].processing_time,
             process_list[i].processing_complete_time, process_list[i].turn_around_time);
    sum += process_list[i].turn_around_time;
  }
  printf("\nAverage_Turn_Around_Time : %g\n", (double)sum / number_of_processes);
  return;
}
