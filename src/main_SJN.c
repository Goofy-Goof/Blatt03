#include <stdio.h>
#include <stdlib.h>

#include "../include/task.h"
#include "../include/MLF.h"
#include "../include/Queue.h"
#include "../include/RR.h"
#include "../include/SJN.h"
#include "../include/LCFS-PR.h"
#include "../include/SRTN.h"

int main(int argc, char** argv)
{
    if (init_SJN() == 0)
    {
        printf("SJN\n");
        arrive_SJN(1, 4);
        tick_SJN();
        printf("%i\n", running_task == NULL ? -1 : running_task->id);
        tick_SJN();
        printf("%i\n", running_task == NULL ? -1 : running_task->id);
        tick_SJN();
        printf("%i\n", running_task == NULL ? -1 : running_task->id);
        tick_SJN();
        printf("%i\n", running_task == NULL ? -1 : running_task->id);
        tick_SJN();
        printf("%i\n", running_task == NULL ? -1 : running_task->id);
        arrive_SJN(2, 8);
        tick_SJN();
        printf("%i\n", running_task == NULL ? -1 : running_task->id);
        tick_SJN();
        printf("%i\n", running_task == NULL ? -1 : running_task->id);
        arrive_SJN(3, 8);
        tick_SJN();
        printf("%i\n", running_task == NULL ? -1 : running_task->id);
        arrive_SJN(4, 3);
        tick_SJN();
        printf("%i\n", running_task == NULL ? -1 : running_task->id);
        arrive_SJN(5, 2);
        tick_SJN();
        printf("%i\n", running_task == NULL ? -1 : running_task->id);
        tick_SJN();
        printf("%i\n", running_task == NULL ? -1 : running_task->id);
        tick_SJN();
        printf("%i\n", running_task == NULL ? -1 : running_task->id);
        tick_SJN();
        printf("%i\n", running_task == NULL ? -1 : running_task->id);
        tick_SJN();
        printf("%i\n", running_task == NULL ? -1 : running_task->id);
        tick_SJN();
        printf("%i\n", running_task == NULL ? -1 : running_task->id);
        tick_SJN();
        printf("%i\n", running_task == NULL ? -1 : running_task->id);
        tick_SJN();
        printf("%i\n", running_task == NULL ? -1 : running_task->id);
        tick_SJN();
        printf("%i\n", running_task == NULL ? -1 : running_task->id);
        tick_SJN();
        printf("%i\n", running_task == NULL ? -1 : running_task->id);
        tick_SJN();
        printf("%i\n", running_task == NULL ? -1 : running_task->id);
        tick_SJN();
        printf("%i\n", running_task == NULL ? -1 : running_task->id);
        tick_SJN();
        printf("%i\n", running_task == NULL ? -1 : running_task->id);
        tick_SJN();
        printf("%i\n", running_task == NULL ? -1 : running_task->id);
        tick_SJN();
        printf("%i\n", running_task == NULL ? -1 : running_task->id);
        tick_SJN();
        printf("%i\n", running_task == NULL ? -1 : running_task->id);
        tick_SJN();
        printf("%i\n", running_task == NULL ? -1 : running_task->id);
        tick_SJN();
        printf("%i\n", running_task == NULL ? -1 : running_task->id);
        tick_SJN();
        printf("%i\n", running_task == NULL ? -1 : running_task->id);
        tick_SJN();
        printf("%i\n", running_task == NULL ? -1 : running_task->id);
        tick_SJN();
        printf("%i\n", running_task == NULL ? -1 : running_task->id);
        tick_SJN();
        printf("%i\n", running_task == NULL ? -1 : running_task->id);
        tick_SJN();
        printf("%i\n", running_task == NULL ? -1 : running_task->id);
        tick_SJN();
        printf("%i\n", running_task == NULL ? -1 : running_task->id);
        tick_SJN();
        printf("%i\n", running_task == NULL ? -1 : running_task->id);
        tick_SJN();
        printf("%i\n", running_task == NULL ? -1 : running_task->id);
        tick_SJN();
        
        free_SJN();
        
    }
	return 0;
}
