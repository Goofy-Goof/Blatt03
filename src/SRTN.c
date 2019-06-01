#include "SRTN.h"
#include "../include/task.h"
#include "../include/Queue.h"
#include <stdlib.h>
#include <stdio.h>


Queue* all_tasks;

def_task* task_constructor_SRTN(int id, int length){
    def_task* task = malloc(sizeof(task));
    task->id = id;
    task->length = length;
    return task;
}
int comparator_SRTN(const def_task *a, const def_task *b){
    int val1 = a->length;
    int val2 = b->length;
    /*
     return negative value if a is shorter than b
     */
    return val1 - val2;
    
}
int init_SRTN()
{
    // TODO
    all_tasks = queue_new(comparator_SRTN);
    return 0;
}

void free_SRTN()
{
    // TODO
    if (queue_size(all_tasks) != 0) {
        queue_free(all_tasks);
    }
    
}

void arrive_SRTN(int id, int length)
{
    // TODO
    def_task *new_task = task_constructor_SRTN(id, length);
    queue_offer(all_tasks, new_task);
}

def_task *tick_SRTN()
{
    if (running_task == NULL) {
        if (queue_size(all_tasks) == 0) {
            return NULL;
        }else{
            switch_task(queue_poll(all_tasks));
            return running_task;
        }
    }else{
        running_task->length = running_task->length -1;
        if (running_task->length == 0) {
            if (queue_size(all_tasks) == 0) {
                finish_task_SRTN();
                switch_task(NULL);
                return NULL;
            }else{
                switch_task(queue_poll(all_tasks));
                return running_task;
            }
        }else{
            if (queue_size(all_tasks) == 0) {
                return running_task;
            }else{
                if (queue_peek(all_tasks)->length < running_task->length) {
                    def_task* old_task = switch_task(queue_poll(all_tasks));
                    queue_offer(all_tasks, old_task);
                    return running_task;
                }else{
                    return running_task;
                }
            }
        }
    }
}

void finish_task_SRTN()
{
    // TODO optional
    free(running_task);
}
