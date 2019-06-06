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
typedef enum { false, true } bool;
bool new_task_arr;
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
    time_steps = malloc(sizeof(int) * num_queues-1);
    time_steps[0] = time_step;
    for (int i = 1; i != num_queues-1; i++) {
        time_steps[i] = time_steps[i-1] * 2;
    }
    current_queue = 0;
    new_task_arr = false;
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
    switch_task(NULL);
}

void arrive_MLF(int id, int length)
{
	// TODO
    def_task* new_task = task_constructor_MLF(id, length);
    queue_offer(all_tasks[0], new_task);
    //new_task_arr = true;
}

def_task* next_avaible_task_MLF(){
    for(int i = 0; i != mlf_num_queues; i++){
        if (queue_size(all_tasks[i]) != 0 ) {
            current_queue = i;
            return queue_poll(all_tasks[current_queue]);
        }
    }
    return NULL;
}

bool task_finished_MLF(){
    if (running_task->length == time_on_running_task) {
        finish_task_MLF();
        return true;
    }else return false;
}
bool time_out_MLF(){
    if (time_on_running_task == time_steps[current_queue]) {
        return true;
    }else return false;
}








def_task *tick_MLF()
{
    // TODO
    if (running_task != NULL) {
        if (current_queue == mlf_num_queues-1) {
            //Fifo
            time_on_running_task++;
            if (task_finished_MLF()) {
                switch_task(next_avaible_task_MLF());
                time_on_running_task = 0;
                return running_task;
            }else{
                return running_task;
            }
        }else{
            //RR
            
            time_on_running_task++;
            if (task_finished_MLF()) {
                def_task* new_task = next_avaible_task_MLF();
                switch_task(new_task);
                time_on_running_task = 0;
                return running_task;
            }else{
                if (time_out_MLF()) {
                    //switch to next task
                    def_task* next_task = next_avaible_task_MLF();
                    if (next_task == NULL) {
                        return running_task;
                    }else{
                        def_task* old_task = running_task;
                        old_task->length = old_task->length - time_on_running_task;
                        queue_offer(all_tasks[current_queue+1], old_task);
                        switch_task(next_task);
                        time_on_running_task = 0;
                        return running_task;
                    }
                }else{
                    return running_task;
                }
            }
        }
    }else{
        switch_task(next_avaible_task_MLF());
        time_on_running_task = 0;
        return running_task;
    }
    
    
    
}

void finish_task_MLF()
{
    // TODO optional
    time_on_running_task = 0;
    free(running_task);
}
