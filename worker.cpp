//Written by Yosef Alqufidi

#include <iostream>
#include <unistd.h>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv) {
    if (argc != 2) return EXIT_FAILURE;

    int SysClockS = atoi(argv[1]);
    int SysclockNano = atoi(argv[1]);
    int TermTimeS = atoi(argv[1]);
    int TermTimeNano = atoi(argv[1]);
	
//Start the for loop to display the user pid, the parent pid and iterations.      
    for (int i = 1; i <= ; ++i) {

//Will display user pid and parent pid before sleeping and then after sleeping 	    
        cout << "WORKER PID:" 
		<< getpid() 
		<< " PPID:" 
		<< getppid() 
		<<" SysClockS:" 
		<< SC
		<< "SysclockNano:"
		<< SCN
		<<"TermTimeS:"
		<< TTS
		<<"TermTimeNano:"
		<< TTN ;

    }

    return EXIT_SUCCESS;
}
