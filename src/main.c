#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h> 
#include "../include/task.h"
#include "../include/MLF.h"
#include "../include/Queue.h"
#include "../include/RR.h"
#include "../include/SJN.h"
#include "../include/LCFS-PR.h"
#include "../include/SRTN.h"
#include "../include/run.h"
#define LOG

int main(int argc, char** argv)
{
#ifdef LOG
    int out = open("cout.log", O_RDWR|O_CREAT|O_APPEND, 0600);
    if (-1 == out) { perror("opening cout.log"); return 255; }
    
    int err = open("cerr.log", O_RDWR|O_CREAT|O_APPEND, 0600);
    if (-1 == err) { perror("opening cerr.log"); return 255; }
    
    int save_out = dup(fileno(stdout));
    int save_err = dup(fileno(stderr));
    
    if (-1 == dup2(out, fileno(stdout))) { perror("cannot redirect stdout"); return 255; }
    if (-1 == dup2(err, fileno(stderr))) { perror("cannot redirect stderr"); return 255; }
#endif
    
    int job[] = {1, 2, 3, 4, 5};
    int time[] = {5, 2, 7, 1, 2};
    int apears[] = {0, 2, 5, 7, 10};
    run_SJN(job, time, apears, sizeof(job)/sizeof(int), 20);
    printf("\n\n\n\n\n");
    run_LCFS_PR(job, time, apears, sizeof(job)/sizeof(int), 20);
    printf("\n\n\n\n\n");
    run_SRTN(job, time, apears, sizeof(job)/sizeof(int), 20);
    printf("\n\n\n\n\n");
    run_RR(2, job, time, apears, sizeof(job)/sizeof(int), 20);
    printf("\n\n\n\n\n");
    run_MLF(2, 3, job, time, apears, sizeof(job)/sizeof(int), 20);
    
    
#ifdef LOG
    fflush(stdout); close(out);
    fflush(stderr); close(err);
    
    dup2(save_out, fileno(stdout));
    dup2(save_err, fileno(stderr));
    
    close(save_out);
    close(save_err);
    
#endif
	return 0;
}
