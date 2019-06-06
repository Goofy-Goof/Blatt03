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
        printf("Task 1 startet um 0, dauert 4\n");
        printf("Task 2 startet um 5, dauert 8\n");
        printf("Task 3 startet um 7, dauert 8\n");
        printf("Task 4 startet um 8, dauert 3\n");
        printf("Task 5 startet um 9, dauert 2\n");
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
        exit(1);
    }
}
    
    void test_LCFS_PR(){
        if (init_LCFS_PR() == 0) {
            printf("LCFS_PR\n");
            printf("Task 1 startet um 0, dauert 4\n");
            printf("Task 2 startet um 2, dauert 2\n");
            printf("Task 3 startet um 5, dauert 3\n");
            printf("Task 4 startet um 7, dauert 1\n");
            printf("Task 5 startet um 10, dauert 2\n");
            arrive_LCFS_PR(1, 4);
            tick_LCFS_PR();
            print_job();
            tick_LCFS_PR();
            print_job();
            arrive_LCFS_PR(2, 2);
            tick_LCFS_PR();
            print_job();
            tick_LCFS_PR();
            print_job();
            tick_LCFS_PR();
            print_job();
            arrive_LCFS_PR(3, 3);
            tick_LCFS_PR();
            print_job();
            tick_LCFS_PR();
            print_job();
            arrive_LCFS_PR(4, 1);
            tick_LCFS_PR();
            print_job();
            tick_LCFS_PR();
            print_job();
            tick_LCFS_PR();
            print_job();
            arrive_LCFS_PR(5, 2);
            tick_LCFS_PR();
            print_job();
            tick_LCFS_PR();
            print_job();
            tick_LCFS_PR();
            print_job();
            tick_LCFS_PR();
            print_job();
            tick_LCFS_PR();
            print_job();
            tick_LCFS_PR();
            print_job();
            tick_LCFS_PR();
            print_job();
            tick_LCFS_PR();
            print_job();
            free_LCFS_PR();
        }else{
            perror("Failed to initialize LCFS_PR\n");
            exit(1);
        }
    }
void test_SRTN(){
    if (init_SRTN() == 0) {
        printf("SRTN\n");
        printf("Task 1 startet um 0, dauert 5\n");
        printf("Task 2 startet um 2, dauert 2\n");
        printf("Task 3 startet um 5, dauert 7\n");
        printf("Task 4 startet um 7, dauert 1\n");
        printf("Task 5 startet um 10, dauert 2\n");
        arrive_SRTN(1, 5);
        tick_SRTN();
        print_job();
        tick_SRTN();
        print_job();
        arrive_SRTN(2, 2);
        tick_SRTN();
        print_job();
        tick_SRTN();
        print_job();
        tick_SRTN();
        print_job();
        arrive_SRTN(3, 7);
        tick_SRTN();
        print_job();
        tick_SRTN();
        print_job();
        arrive_SRTN(4, 1);
        tick_SRTN();
        print_job();
        tick_SRTN();
        print_job();
        tick_SRTN();
        print_job();
        arrive_SRTN(5, 2);
        tick_SRTN();
        print_job();
        tick_SRTN();
        print_job();
        tick_SRTN();
        print_job();
        tick_SRTN();
        print_job();
        tick_SRTN();
        print_job();
        tick_SRTN();
        print_job();
        free_SRTN();
        tick_SRTN();
        print_job();
        tick_SRTN();
        print_job();
        tick_SRTN();
        print_job();
        tick_SRTN();
        print_job();
        tick_SRTN();
        print_job();
        free_SRTN();
        
    }else{
        perror("Failed to initialize SRTN\n");
        exit(1);
    }
}
void test_RR(int time_step){
    if (init_RR(time_step) == 0) {
        printf("RR, time step : %d\n", time_step);
        printf("Task 1 startet um 0, dauert 5\n");
        printf("Task 2 startet um 2, dauert 2\n");
        printf("Task 3 startet um 5, dauert 7\n");
        printf("Task 4 startet um 7, dauert 1\n");
        printf("Task 5 startet um 10, dauert 2\n");
        arrive_RR(1, 5);
        tick_RR();
        print_job();
        tick_RR();
        print_job();
        arrive_RR(2, 2);
        tick_RR();
        print_job();
        tick_RR();
        print_job();
        tick_RR();
        print_job();
        arrive_RR(3, 7);
        tick_RR();
        print_job();
        tick_RR();
        print_job();
        arrive_RR(4, 1);
        tick_RR();
        print_job();
        tick_RR();
        print_job();
        tick_RR();
        print_job();
        arrive_RR(5, 2);
        tick_RR();
        print_job();
        tick_RR();
        print_job();
        tick_RR();
        print_job();
        tick_RR();
        print_job();
        tick_RR();
        print_job();
        tick_RR();
        print_job();
        tick_RR();
        print_job();
        free_RR();
    } else {
        perror("Failed to initialize RR\n");
        exit(1);
    }
}
    void test_MLF(int time_step, int num_queues){
        if (init_MLF(time_step, num_queues) == 0) {
            printf("MLF, time step : %d, number of queues : %d\n", time_step, num_queues);
            printf("Task 1 startet um 0, dauert 5\n");
            printf("Task 2 startet um 2, dauert 2\n");
            printf("Task 3 startet um 5, dauert 7\n");
            printf("Task 4 startet um 7, dauert 1\n");
            printf("Task 5 startet um 10, dauert 2\n");
            arrive_MLF(1, 5);
            tick_MLF();
            print_job();
            tick_MLF();
            print_job();
            arrive_MLF(2, 2);
            tick_MLF();
            print_job();
            tick_MLF();
            print_job();
            tick_MLF();
            print_job();
            arrive_MLF(3, 7);
            tick_MLF();
            print_job();
            tick_MLF();
            print_job();
            arrive_MLF(4, 1);
            tick_MLF();
            print_job();
            tick_MLF();
            print_job();
            tick_MLF();
            print_job();
            arrive_MLF(5, 2);
            tick_MLF();
            print_job();
            tick_MLF();
            print_job();
            tick_MLF();
            print_job();
            tick_MLF();
            print_job();
            tick_MLF();
            print_job();
            tick_MLF();
            print_job();
            tick_MLF();
            print_job();
            tick_MLF();
            print_job();
            tick_MLF();
            print_job();
            tick_MLF();
            print_job();
            free_MLF();
        }else{
            perror("Failed to initialize MLF\n");
            exit(1);
        }
    }


