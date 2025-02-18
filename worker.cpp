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
};

//logic for shared memory

int main(int argc, char** argv){
	if(argc !=3){
		cout<<"Error please use three arguments for:"<< argv[0] <<"\n";
		return EXIT_FAILURE;
	}


//start parseing time

int Secval = atoi(argv[1]);
int Nanoval = atoi(argv[2]);

//shared memory key

const char* ftokPath = "/tmp";
key_t key = ftok(ftokPath, 'R');
if(key == -1){
perror("ftok");
return EXIT_FAILURE;
}

//access to shared memory

int shmid = shmget(key, sizeof(ClockDigi), 0666);
if(shmid < 0){
	perror("shmget");
	return EXIT_FAILURE;
}

ClockDigi* clockVal = (ClockDigi*) shmat(shmid, nullptr, 0);
if (clockVal == (void*) -1){
	perror("shmat");
	return EXIT_FAILURE;
}

//start reading from simulated clock 

int stRdSec = clockVal->sysClockS;
int stRdNano = clockVal->sysClockNano;

//termination

int termSec = stRdSec + Secval;
int termNano = stRdNano + Nanoval;

if(termNano >= 1000000000){
	termSec += termNano / 1000000000;
	termNano = termNano % 1000000000;
}

//outputs

cout << "WORKER PID:" << getpid()
         << " PPID:" << getppid()
         << " SysClockS:" << clockData->sysClockS
         << " SysclockNano:" << clockData->sysClockNano
         << " TermTimeS:" << clockData->termTimeS
         << " TermTimeNano:" << clockData->termTimeNano << "\n";
         cout << "--Just Starting" << "\n";

//checks
  

    cout << "WORKER PID:" << getpid()
         << " PPID:" << getppid()
         << " SysClockS:" << clockData->sysClockS
         << " SysclockNano:" << clockData->sysClockNano
         << " TermTimeS:" << clockData->termTimeS
         << " TermTimeNano:" << clockData->termTimeNano << "\n";
    cout << " seconds have passed since starting" << "\n";


    //checks
   
  
    cout << "WORKER PID:" << getpid()
         << " PPID:" << getppid()
         << " SysClockS:" << clockData->sysClockS
         << " SysclockNano:" << clockData->sysClockNano
         << " TermTimeS:" << clockData->termTimeS
         << " TermTimeNano:" << clockData->termTimeNano << "\n";
    cout << "--Terminating" << "\n";

    
    shmdt(clockVal);

    return EXIT_SUCCESS;
}

