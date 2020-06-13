#include <stdio.h>
#include <stdlib.h>
//used to redirest stdout, to comfotably compare output with other
#include <fcntl.h>
#include <unistd.h>
//schedulers
#include "../include/task.h"
#include "../include/MLF.h"
#include "../include/Queue.h"
#include "../include/RR.h"
#include "../include/SJN.h"
#include "../include/LCFS-PR.h"
#include "../include/SRTN.h"
//used to comfotably test
#include "../include/run.h"
//#define LOG

int main(int argc, char** argv)
{
#ifdef LOG
    //create log files
    int out = open("cout.log", O_RDWR|O_CREAT|O_APPEND, 0600);
    if (-1 == out) { perror("opening cout.log"); return 255; }
    int err = open("cerr.log", O_RDWR|O_CREAT|O_APPEND, 0600);
    if (-1 == err) { perror("opening cerr.log"); return 255; }
    
    //close stdin and stdout
    int save_out = dup(fileno(stdout));
    int save_err = dup(fileno(stderr));
    //reditecting
    if (-1 == dup2(out, fileno(stdout))) { perror("cannot redirect stdout"); return 255; }
    if (-1 == dup2(err, fileno(stderr))) { perror("cannot redirect stderr"); return 255; }
#endif
    
    int job[] = {1, 2, 3, 4, 5};
    int time[] = {5, 3, 3, 4, 2};
    int apears[] = {1, 3, 6, 10, 11};
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
    //put streams back to normal
    fflush(stdout); close(out);
    fflush(stderr); close(err);
    
    dup2(save_out, fileno(stdout));
    dup2(save_err, fileno(stderr));
    
    close(save_out);
    close(save_err);
    
#endif
	return 0;
}
