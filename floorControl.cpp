#include<iostream>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include<fstream>

using namespace std;

void reached();
void *worker_thread1(void *arg);
void go(int);
//floor 7
void *worker_thread(void *arg)
{
	 	//read currnet delay
	 	
		ifstream myReadFile1;
		myReadFile1.open("delay.txt");
		int delay;
		if (myReadFile1.is_open()) {
		while (!myReadFile1.eof()) {
		
		
		myReadFile1 >> delay;
		cout<<"current delay : " <<delay;
		
		
		}
		}
		myReadFile1.close();
		
	 	//read currnet floor
		ifstream myReadFile;
		myReadFile.open("current.txt");
		int output;
		if (myReadFile.is_open()) {
		while (!myReadFile.eof()) {		
		
		myReadFile >> output;
		cout<<output;
		
		}
		}
		myReadFile.close();
	
	if (output == 7){
	 cout << "Lift is on same floor" <<endl;
	}
	
	int i,ans = output;
	for(i = output ; i < (8-output); i ++){
		  
	      sleep(2);
		  ofstream myfile;
		  myfile.open ("current.txt");
		  myfile << "\n" << ans;
		  myfile.close();
		  cout<<"\nCurrent floor"<<ans << endl;
		  ans++;

	}
	if(ans== 8){
		reached();
	}
        pthread_exit(NULL);
}
int dest;
void reached(){
	cout << "\nPlease enter the elevator (5 seconds)..." << endl;
	sleep(5);
	
	cout << "\nEnter your destination floor no :" << endl;
	cin >> dest;
	int ret;
				 pthread_t my_thread;
	        ret =  pthread_create(&my_thread, NULL, &worker_thread1, NULL);
	        if(ret != 0) {
	                printf("Error: pthread_create() failed\n");
	                exit(EXIT_FAILURE);
	        }
			 
		pthread_exit(NULL);
}
void *worker_thread1(void *arg)
{
		cout << "Destination entered is : " << dest << endl;
		
	 	//read currnet floor
		ifstream myReadFile;
		myReadFile.open("current.txt");
		int output;
		if (myReadFile.is_open()) {
		while (!myReadFile.eof()) {
		
		
		myReadFile >> output;
		cout<<output;
		
		
		}
		}
		myReadFile.close();
	
	int a = output;
	if (dest == 7){
	 cout << "Lift is on same floor" <<endl;
	}
	
	int i,ans = output;
	for(i = a ; i > dest; i --){
		  
	    	sleep(2);
		  ofstream myfile;
		  myfile.open ("current.txt");
		  myfile << "\n" << ans;
		  myfile.close();
		  
		  ans--;
cout<<"\nCurrent floor"<<ans << endl;
	}
	cout<<"\nDestination reached"<< endl;
	if(ans== 8){
		reached();
	}
        pthread_exit(NULL);
}
int main()
{
        printf("My current floor : 7\n");
       
int i;
cout << "\n1. Call elevator" << endl;
cout << "\n2. Exit" << endl;
cin >> i;
switch(i){

	case 1 :
			int ret;
			pthread_t my_thread;
	        ret =  pthread_create(&my_thread, NULL, &worker_thread, NULL);
	        if(ret != 0) {
	                printf("Error: pthread_create() failed\n");
	                exit(EXIT_FAILURE);
	        }
			 
		pthread_exit(NULL);
		break;
case 2 : exit (0);
		 break;
default : cout << "Invalid input" << endl;
			main();
}
}
