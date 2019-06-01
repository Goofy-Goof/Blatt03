#include <stdio.h>
#include <stdlib.h>
#include "../include/test.h"
#include "../include/task.h"
#include "../include/MLF.h"
#include "../include/Queue.h"
#include "../include/RR.h"
#include "../include/SJN.h"
#include "../include/LCFS-PR.h"
#include "../include/SRTN.h"

void print_job(){
    if (running_task == NULL) {
        printf("No task is running now\n");
    }else{
        printf("Running tasks id: %i\n", running_task->id);
    }
}
void test_SJN(){
    if (init_SJN() == 0)
    {
        printf("SJN\n");
        arrive_SJN(1, 4);
        tick_SJN();
        print_job();
        tick_SJN();
        print_job();
        tick_SJN();
        print_job();
        tick_SJN();
        print_job();
        tick_SJN();
        print_job();
        arrive_SJN(2, 8);
        tick_SJN();
        print_job();
        tick_SJN();
        print_job();
        arrive_SJN(3, 8);
        tick_SJN();
        print_job();
        arrive_SJN(4, 3);
        tick_SJN();
        print_job();
        arrive_SJN(5, 2);
        tick_SJN();
        print_job();
        tick_SJN();
        print_job();
        tick_SJN();
        print_job();
        tick_SJN();
        print_job();
        tick_SJN();
        print_job();
        tick_SJN();
        print_job();
        tick_SJN();
        print_job();
        tick_SJN();
        print_job();
        tick_SJN();
        print_job();
        tick_SJN();
        print_job();
        tick_SJN();
        print_job();
        tick_SJN();
        print_job();
        tick_SJN();
        print_job();
        tick_SJN();
        print_job();
        tick_SJN();
        print_job();
        tick_SJN();
        print_job();
        tick_SJN();
        print_job();
        tick_SJN();
        print_job();
        tick_SJN();
        print_job();
        tick_SJN();
        print_job();
        tick_SJN();
        print_job();
        tick_SJN();
        print_job();
        tick_SJN();
        print_job();
        tick_SJN();
        print_job();
        tick_SJN();
        print_job();
        tick_SJN();
        print_job();
        tick_SJN();
        free_SJN();
    }else{
        perror("Failed to initialize SJN!\n");
    }
}
