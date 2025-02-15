#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <csignal>
#include <sys/types.h>
#include <sys/wait.h>
#include <string>

using namespace std;

void signal_handler(int sig) {
    // code to send kill signal to all children based on their PIDs in process table

    // code to free up shared memory

    exit(1);
}

int main() {
    // Turn on alarm handler
    signal(SIGALRM, signal_handler);

    // Set up the alarm call (fires in 60 seconds)
    alarm(60);

    // Optionally, wait indefinitely so that the process remains active until the signal occurs.
    while (true) {
        pause();  // Suspends the process until a signal is caught
    }

    return 0;
}

//adding command line args for parse
int main( int argc, char *argv[]){
	
	int n_case = 0;
	int s_case = 0;
	int t_case = 0;
	bool n_var = false, s_var = false, t_var = false;
	int opt;

//setting up the parameters for h,n,s,t
	while ((opt = getopt(argc, argv, "hn:s:t:")) != -1) {
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

			default:
				cout<< "invalid";

			return EXIT_FAILURE;
		}
	}

//only allow all three to be used together and not by itself 	
	if(!n_var || !s_var || !t_var){
		cout<<"ERROR: You cannot do one alone please do -n, -s, and -t together.\n";
			return EXIT_FAILURE;
	}
