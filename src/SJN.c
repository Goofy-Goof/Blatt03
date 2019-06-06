#include "SJN.h"
#include "../include/task.h"
#include "../include/Queue.h"
#include <stdlib.h>
#include <stdio.h>


Queue* all_tasks;

def_task* task_constructor_SJN(int id, int length){
    def_task* task = malloc(sizeof(task));
    task->id = id;
    task->length = length;
    return task;
}
int comparator_SJN(const def_task *a, const def_task *b){
    int val1 = a->length;
    int val2 = b->length;
    /*
     return negative value if a is shorter than b
     */
    return val1 - val2;
    
}
int init_SJN()
{
    // TODO
    all_tasks = queue_new(comparator_SJN);
    return 0;
}
void free_SJN()
{
    // TODO
    if(queue_size(all_tasks) != 0){
    queue_free(all_tasks);
    }
    switch_task(NULL);
}

void arrive_SJN(int id, int length)
{
    // TODO
    def_task *new_task = task_constructor_SJN(id, length);
    queue_offer(all_tasks, new_task);
}

def_task *tick_SJN()
{
    if (running_task == NULL) {
        if (queue_size(all_tasks) == 0) {
            return NULL;
        }
        switch_task(queue_poll(all_tasks));
        return running_task;
    }
    running_task->length = running_task->length - 1;
    if (running_task->length == 0) {
        finish_task_SJN();
        if (queue_size(all_tasks) == 0) {
            switch_task(NULL);
            return NULL;
        }
        switch_task(queue_poll(all_tasks));
        return running_task;
    }
return running_task;
}

void finish_task_SJN()
{   
    free(running_task);
}
