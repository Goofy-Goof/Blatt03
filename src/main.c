#include <stdio.h>
#include <stdlib.h>

#include "../include/task.h"
#include "../include/MLF.h"
#include "../include/Queue.h"
#include "../include/RR.h"
#include "../include/SJN.h"
#include "../include/LCFS-PR.h"
#include "../include/SRTN.h"
#include "../include/test.h"


int main(int argc, char** argv)
{
    test_SJN();
    test_LCFS_PR();
    test_SRTN();
    
    
	return 0;
}
