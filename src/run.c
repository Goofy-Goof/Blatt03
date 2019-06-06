#include <stdio.h>
#include <stdlib.h>
#include "../include/run.h"
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
void run_SJN(int job[], int time[], int apears[], int num, int duration){
    if ( sizeof(job) != sizeof(time) || sizeof(time) != sizeof(apears)) {
        perror("Invalid input\n");
        exit(1);
    }
    if (init_SJN() == 0)
    {
        printf("SJN\n");
        for(int i = 0; i != num; i++){
            printf("Task %d dauert %d und startet um %d\n", job[i], time[i], apears[i]);
        }
        printf("\n");
        for (int i = 0, job_arrived = 0; i != duration; i++) {
            if (apears[job_arrived] == i) {
                arrive_SJN(job[job_arrived], time[job_arrived]);
                job_arrived++;
            }else{
                tick_SJN();
                print_job();
            }
        }
        free_SJN();
    }else{
        perror("Failed to initialize SJN!\n");
        exit(1);
    }
}
    
    void run_LCFS_PR(int job[], int time[], int apears[], int num, int duration){
        if ( sizeof(job) != sizeof(time) || sizeof(time) != sizeof(apears)) {
            perror("Invalid input\n");
            exit(1);
        }
        if (init_LCFS_PR() == 0)
        {
            printf("LCFS_PR\n");
            for(int i = 0; i != num; i++){
                printf("Task %d dauert %d und startet um %d\n", job[i], time[i], apears[i]);
            }
            printf("\n");
            for (int i = 0, job_arrived = 0; i != duration; i++) {
                if (apears[job_arrived] == i) {
                    arrive_LCFS_PR(job[job_arrived], time[job_arrived]);
                    job_arrived++;
                }else{
                    tick_LCFS_PR();
                    print_job();
                }
            }
            free_LCFS_PR();
        }else{
            perror("Failed to initialize LCSF_PR!\n");
            exit(1);
        }
        
    }
void run_SRTN(int job[], int time[], int apears[], int num, int duration){
    if ( sizeof(job) != sizeof(time) || sizeof(time) != sizeof(apears)) {
        perror("Invalid input\n");
        exit(1);
    }
    if (init_SRTN() == 0)
    {
        printf("SRTN\n");
        for(int i = 0; i != num; i++){
            printf("Task %d dauert %d und startet um %d\n", job[i], time[i], apears[i]);
        }
        printf("\n");
        for (int i = 0, job_arrived = 0; i != duration; i++) {
            if (apears[job_arrived] == i) {
                arrive_SRTN(job[job_arrived], time[job_arrived]);
                job_arrived++;
            }else{
                tick_SRTN();
                print_job();
            }
        }
        free_SRTN();
    }else{
        perror("Failed to initialize SRTN!\n");
        exit(1);
    }
    
}
void run_RR(int time_step, int job[], int time[], int apears[], int num, int duration){
    if ( sizeof(job) != sizeof(time) || sizeof(time) != sizeof(apears)) {
        perror("Invalid input\n");
        exit(1);
    }
    if (init_RR(time_step) == 0)
    {
        printf("RR\n");
        for(int i = 0; i != num; i++){
            printf("Task %d dauert %d und startet um %d\n", job[i], time[i], apears[i]);
        }
        printf("\n");
        for (int i = 0, job_arrived = 0; i != duration; i++) {
            if (apears[job_arrived] == i) {
                arrive_RR(job[job_arrived], time[job_arrived]);
                job_arrived++;
            }else{
                tick_RR();
                print_job();
            }
        }
        free_RR();
    }else{
        perror("Failed to initialize SJN!\n");
        exit(1);
    }
    
}
    void run_MLF(int time_step, int num_queues, int job[], int time[], int apears[], int num, int duration){
        if ( sizeof(job) != sizeof(time) || sizeof(time) != sizeof(apears)) {
            perror("Invalid input\n");
            exit(1);
        }
        if (init_MLF(time_step, num_queues) == 0)
        {
            printf("MLF\n");
            for(int i = 0; i != num; i++){
                printf("Task %d dauert %d und startet um %d\n", job[i], time[i], apears[i]);
            }
            printf("\n");
            for (int i = 0, job_arrived = 0; i != duration; i++) {
                if (apears[job_arrived] == i) {
                    arrive_MLF(job[job_arrived], time[job_arrived]);
                    job_arrived++;
                }else{
                    tick_MLF();
                    print_job();
                }
            }
            free_MLF();
        }else{
            perror("Failed to initialize SJN!\n");
            exit(1);
        }
        
    }


