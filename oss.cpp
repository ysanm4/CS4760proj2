#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <csignal>
#include <sys/types.h>
#include <sys/wait.h>
#include <string>

using namespace std;

//PCB tracking children

#define PROCESS_TABLE 20

struct PCB{
	int occupied;
	pid_t pid;
	int startSeconds;
	int startNano;
};

struct ClockDigi{
	int sysClockS;
	int sysClockNano;
};

PCB processTable[PROCESS_TABLE];

int shmid;
ClockDigi* clockVal = nullptr;






void signal_handler(int sig) {
    // code to send kill signal to all children based on their PIDs in process table
for(int i = 0; i < PROCESS_TABLE; i++){
	if(processTable[i].occupied){
		kill(processTable[i].pid, SIGKILL);
	}
}
    // code to free up shared memory
if(clockVal != nullptr){
	shmdt(clockVal);
}
shmctl(shmid, IPC_RMID, NULL);
    exit(1);
}

//int main() {
    // Turn on alarm handler
   // signal(SIGALRM, signal_handler);

    // Set up the alarm call (fires in 60 seconds)
   // alarm(60);

    // Optionally, wait indefinitely so that the process remains active until the signal occurs.
   // while (true) {
  //      pause();  // Suspends the process until a signal is caught
   // }

  //  return 0;
//}

//adding command line args for parse
int main( int argc, char *argv[]){
	
	int n_case = 0;
	int s_case = 0;
	int t_case = 0;
	int i_case = 0;
	bool n_var = false, s_var = false, t_var = false, i_var = false;
	int opt;

//setting up the parameters for h,n,s,t,i
	while ((opt = getopt(argc, argv, "hn:s:t:i: ")) != -1) {
		switch (opt){
			case 'h':
			cout<< "This is the help menu\n";
			cout<< "-h: shows help\n";
			cout<< "-n: processes\n";
			cout<< "-s: simultaneous\n";
			cout<< "-t: iterations\n";
			cout<< "To run try ./oss -n 1 -s 1 -t 1\n";

	return EXIT_SUCCESS;

			case 'n':
				n_case = atoi(optarg);
				n_var = true;
				break;

			case 's':
				s_case = atoi(optarg);
				s_var = true;
				break;

			case 't':
				t_case = atoi(optarg);
				t_var = true;
				break;

			case 'i':
				i_case = atoi(optarg);
				i_var = true;
				break;	

			default:
				cout<< "invalid";

			return EXIT_FAILURE;
		}
	}

//only allow all three to be used together and not by itself 	
	if(!n_var || !s_var || !t_var || !i_var){
		cout<<"ERROR: You cannot do one alone please do -n, -s, -t, and -i together.\n";
			return EXIT_FAILURE;
	}

//shared memory for clock

key_t key = 6321;

shmid = shmget(key, sizeof(ClockDigi), IPC_CREAT | 0666);
	if(shmid < 0){
		perror("shmget");
		return EXIT_FAILURE;
}

clockVal = (ClockDigi*) shmat(shmid, nullptr, 0);
	if(clockVal ==(void*) -1){
		perror("shmat");
		return EXIT_FAILURE;
	}

