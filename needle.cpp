#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <math.h>

using namespace std;

double PI = acos(-1.0); 

double x; // x coordinate of needle's center 
double k; // angle between vertical position and needle
double l; // lenght of the needle
double n; // amount of trials
double p; // positive trials
double y; // sin(angle) * l
double pi;
long i; // loop counter

void lanzar();

int main(int args, char* argv[]){
    n = 100000;

    srand(time(NULL));


    p = 0;
    l = 1;

    struct timeval start;
    struct timeval end;
    double milisecs;
    long seconds, useconds;

    gettimeofday(&start, 0);
    for(i=0; i<n; i++){
        lanzar();
    }
    gettimeofday(&end, 0);

    seconds  = end.tv_sec  - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;
    milisecs = ((seconds) * 1000 + useconds/1000.0);
    cout<< "n" <<"\t"<< "Acier" <<"\t"<< "time" << "\t"<< "pi"<<endl;
	cout<< n <<"\t"<< p << "\t";
    pi = (l/p)*(n);
    cout<< milisecs << "\t" <<pi <<endl;

}

void lanzar(){
    k = (double)rand()/(RAND_MAX)*360;       // random angle
    x = (double)rand()/(RAND_MAX*2);         // random x (0 do 1)
    y = (l/2) * sin (k);

    if (x<=y)                                    
    {
        p++;                                    
    }
}


