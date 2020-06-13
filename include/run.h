#ifndef TEST_H_
#define TEST_H_

//functions to test scheduler, so
//main wont be big af
/*
 arguments
 int job[] - job id
 int time[] - length of each job
 int appears[] - time when job appears
 int num - number of jobs
 int duration - number of ticks in the test 
 */
void run_SJN(int job[], int time[], int apears[], int num, int duration);

void run_SRTN(int job[], int time[], int apears[], int num, int duration);

void run_LCFS_PR(int job[], int time[], int apears[], int num, int duration);

void run_RR(int time_step, int job[], int time[], int apears[], int num, int duration);

void run_MLF(int time_step_one, int num_queues, int job[], int time[], int apears[], int num, int duration);

void print_job();
#endif
