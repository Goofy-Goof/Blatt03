#include "RR.h"
#include "../include/task.h"
#include "Queue.h"
#include <stdlib.h>

Queue* all_tasks;
int c_time_step;
int time_on_running_task;
int comparator_RR(const def_task *a, const def_task *b){
    return 0;
}
def_task* task_constructor_RR(int id, int length){
    def_task* task = malloc(sizeof(task));
    task->id = id;
    task->length = length;
    return task;
}
int init_RR(int time_step)
{
    // TODO
    c_time_step = time_step;
    all_tasks = queue_new(comparator_RR);
    time_on_running_task = 0;
	return 0;
}

void free_RR()
{
    // TODO
    if(queue_size(all_tasks) != 0){
    queue_free(all_tasks);
    }
    switch_task(NULL);
}

void arrive_RR(int id, int length)
{
    // TODO
    def_task* new_task = task_constructor_RR(id, length);
    queue_push_to_front(all_tasks, new_task);
    
}

def_task *tick_RR()
{
    // TODO
    if (running_task == NULL) {
        if (queue_size(all_tasks) == 0) {
            return NULL;
        }else{
            switch_task(queue_poll(all_tasks));
            return running_task;
        }
    }else{
        time_on_running_task++;
        if (running_task->length == time_on_running_task) {
            finish_task_RR();
            switch_task(NULL);
            time_on_running_task = 0;
            if (queue_size(all_tasks) == 0 ){
                return NULL;
            } else {
                switch_task(queue_poll(all_tasks));
                return running_task;
            }
        }else{
            //time out
            if (time_on_running_task == c_time_step) {
                running_task->length = running_task->length - time_on_running_task;
                time_on_running_task = 0;
                if (queue_size(all_tasks) == 0 ){
                    return running_task;
                } else {
                    def_task* old_task = switch_task(queue_poll(all_tasks));
                    queue_offer(all_tasks, old_task);
                    return running_task;
                }
            } else {
                return running_task;
            }
        }
    }
}

void finish_task_RR()
{
    // TODO optional
    free(running_task);
}
