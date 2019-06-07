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
int* interupts;
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
void interupt_pr(){
    //interupt array - represents already used time quantum for first element of each queue;
    interupts[current_queue] = time_on_running_task;
    queue_push_to_front(all_tasks[current_queue], running_task);
    switch_task(NULL);
    
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
    interupts = calloc(10, sizeof(int));
    current_queue = 0;
    new_task_arr = false;
	return 0;
}

void free_MLF()
{
    // TODO
    free(time_steps);
    free(interupts);
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
    if(running_task != NULL && current_queue>0)new_task_arr = true;
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
    if (running_task->length == time_on_running_task+interupts[current_queue]) {
        finish_task_MLF();
        return true;
    }else return false;
}
bool time_out_MLF(){
    if (time_on_running_task + interupts[current_queue] == time_steps[current_queue] ) {
        return true;
    }else return false;
}








def_task *tick_MLF()
{
    // TODO
    current_queue *=1;
    time_on_running_task *=1;
    if (running_task != NULL) {
        if (current_queue == mlf_num_queues-1) {
            //Fifo
            time_on_running_task++;
            if (task_finished_MLF()) {
                switch_task(next_avaible_task_MLF());
                time_on_running_task = 0;
                //new_task_arr = false;
                return running_task;
            }else{
                //new_task_arr = false;
                return running_task;
            }
        }else{
            //RR
            
            time_on_running_task++;
            if (task_finished_MLF()) {
                def_task* new_task = next_avaible_task_MLF();
                switch_task(new_task);
                time_on_running_task = 0;
                //wichtig
                new_task_arr = false;
                return running_task;
            }else{
                if (time_out_MLF()) {
                    //switch to next task
                    def_task* next_task = next_avaible_task_MLF();
                    if (next_task == NULL) {
                        new_task_arr = false;
                        return running_task;
                    }else{
                        def_task* old_task = running_task;
                        old_task->length = old_task->length - time_on_running_task;
                        queue_offer(all_tasks[current_queue+1], old_task);
                        switch_task(next_task);
                        time_on_running_task = 0;
                        new_task_arr = false;
                        return running_task;
                    }
                }else{
                    if (new_task_arr) {
                        //hier muss Verdrähung impelementiert werden
                        interupts[current_queue] += time_on_running_task;
                        def_task* old = switch_task(queue_poll(all_tasks[0]));
                        queue_push_to_front(all_tasks[current_queue], old);
                        current_queue = 0;
                        time_on_running_task = 0;
                        new_task_arr = false;
                        return running_task;
                    }else return running_task;
                    
                }
            }
        }
    }else{
        switch_task(next_avaible_task_MLF());
        time_on_running_task = 0;
        new_task_arr = false;
        return running_task;
    }
    
    
    
}

void finish_task_MLF()
{
    // TODO optional
    time_on_running_task = 0;
    interupts[current_queue] = 0;
    free(running_task);
}
