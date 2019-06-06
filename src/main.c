#include <stdio.h>
#include <stdlib.h>

#include "../include/task.h"
#include "../include/MLF.h"
#include "../include/Queue.h"
#include "../include/RR.h"
#include "../include/SJN.h"
#include "../include/LCFS-PR.h"
#include "../include/SRTN.h"
#include "../include/run.h"


int main(int argc, char** argv)
{
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
	return 0;
}
