#include "LCFS-PR.h"
#include "../include/task.h"
#include "../include/Queue.h"
#include <stdlib.h>
#include <stdio.h>

typedef enum { false, true } bool;
Queue* all_tasks;
bool new_task_arrived;
int comparator_LCFS_PR(const def_task *a, const def_task *b){
    return 0;
}


def_task* task_constructor_LCFS_PR(int id, int length){
    def_task* task = malloc(sizeof(task));
    task->id = id;
    task->length = length;
    return task;
}


int init_LCFS_PR()
{
    // TODO
    all_tasks = queue_new(comparator_LCFS_PR);
    new_task_arrived = false;
    return 0;
}

void free_LCFS_PR()
{
    // TODO
    queue_free(all_tasks);
}

void arrive_LCFS_PR(int id, int length)
{
    // TODO
    def_task* new_task = task_constructor_LCFS_PR(id, length);
    queue_push_to_front(all_tasks, new_task);
    new_task_arrived = true;
}

def_task *tick_LCFS_PR()
{
    // TODO
    if (running_task != NULL) {
        running_task->length = running_task->length -1;
        if (running_task->length == 0) {
            finish_task_LCFS_PR();
            if (queue_size(all_tasks) != 0) {
                switch_task(queue_poll(all_tasks));
                new_task_arrived = false;
                return running_task;
            }else{
                switch_task(NULL);
                return NULL;
            }
        }else{
            if (new_task_arrived == true) {
                def_task *old_task = switch_task(queue_poll(all_tasks));
                queue_offer(all_tasks, old_task);
                new_task_arrived = false;
                return running_task;
            }else{
                return running_task;
            }
        }
    }else{
        if (queue_size(all_tasks) != 0) {
            switch_task(queue_poll(all_tasks));
            new_task_arrived = false;
            return running_task;
        }else{
            return NULL;
        }
    }
    
}

void finish_task_LCFS_PR()
{
    // todo optional
    free(running_task);
    
}
