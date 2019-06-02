#include "MLF.h"
#include "../include/task.h"
#include "Queue.h"
#include <stdlib.h>
#include <stdio.h>
int mlf_num_queues;
Queue** all_tasks;
int* time_steps;
int current_queue;
int time_on_running_task;
int comparator_MLF(const def_task *a, const def_task *b){
    return 0;
}
def_task* task_constructor_MLF(int id, int length){
    def_task* task = malloc(sizeof(task));
    task->id = id;
    task->length = length;
    return task;
}
int init_MLF(int time_step, int num_queues)
{
    // TODO
    mlf_num_queues = num_queues;
    all_tasks = malloc(sizeof(Queue)*num_queues);
    for (int i = 0; i != num_queues; i++) {
        all_tasks[i] = queue_new(comparator_MLF);
    }
    time_steps = malloc(sizeof(int) * num_queues);
    time_steps[0] = time_step;
    for (int i = 1; i != num_queues; i++) {
        time_steps[i] = time_steps[i-1] * 2;
    }
    current_queue = 0;
	return 0;
}

void free_MLF()
{
    // TODO
    free(time_steps);
    for (int i = 0; i != mlf_num_queues; i++) {
        if (queue_size(all_tasks[i]) != 0) {
            free(all_tasks[i]);
        }
    }
}

void arrive_MLF(int id, int length)
{
	// TODO
    def_task* new_task = task_constructor_MLF(id, length);
    queue_push_to_front(all_tasks[0], new_task);
    current_queue = 0;
}

def_task *tick_MLF()
{
    // TODO
    if (current_queue < mlf_num_queues-1) {
        //RR
    }else{
        //Fifo
    }
}

void finish_task_MLF()
{
    // TODO optional
    free(running_task);
}
