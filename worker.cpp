//Written by Yosef Alqufidi

#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <cstdio>

using namespace std;

//Shared memory clock structure

struct ClockDigi{
	int sysClocks;
	int sysClockNano;
	int yermTimeS;
	int termTimeNano;
};

//logic for shared memory
//
//
//


//start capturing

int startCount = clockDigi->sysClocks;

cout << "WORKER PID:" << getpid()
         << " PPID:" << getppid()
         << " SysClockS:" << clockData->sysClockS
         << " SysclockNano:" << clockData->sysClockNano
         << " TermTimeS:" << clockData->termTimeS
         << " TermTimeNano:" << clockData->termTimeNano << "\n";
         cout << "--Just Starting" << "\n";

//checks
    while (clockData->sysClockS < startSeconds + 1) {
    }

    cout << "WORKER PID:" << getpid()
         << " PPID:" << getppid()
         << " SysClockS:" << clockData->sysClockS
         << " SysclockNano:" << clockData->sysClockNano
         << " TermTimeS:" << clockData->termTimeS
         << " TermTimeNano:" << clockData->termTimeNano << "\n";
    cout << "--1 seconds have passed since starting" << "\n";


    //checks
    while (clockData->sysClockS < clockData->termTimeS) {
         }
  
    cout << "WORKER PID:" << getpid()
         << " PPID:" << getppid()
         << " SysClockS:" << clockData->sysClockS
         << " SysclockNano:" << clockData->sysClockNano
         << " TermTimeS:" << clockData->termTimeS
         << " TermTimeNano:" << clockData->termTimeNano << "\n";
    cout << "--Terminating" << "\n";

    
    shmdt(clockData);

    return EXIT_SUCCESS;
}

