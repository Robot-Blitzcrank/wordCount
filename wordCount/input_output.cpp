#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
using namespace std;


int main(int argc, char *argv[])
{
    int m,n;
    string msg;
    int i;
	fstream infile(argv[2],ios::in);
	fstream outfile(argv[4],ios::out);
    infile>>msg;
    
    if(argv[6]=="-n")
    {
	    n=atoi(argv[7]);
		m=0;
		
    }
    else
    if(argv[7]=="-n"&&argv[8]==NULL)
    {
    	m=atoi(argv[6]);
    	n=0;
    }
    else
    {
        m = atoi(argv[6]);
        n = atoi(argv[8]);
    }
    outfile<<msg;
    return 0;
}

