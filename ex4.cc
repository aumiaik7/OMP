#include <omp.h>
#include <iostream>


using namespace std;



  main(int argc, char *argv[]) {

     int x;
     x = 0;


#pragma omp parallel shared(x) 
     {

#pragma omp critical 
	x = x + 1;

     }  /* end of parallel region */
     cout<<x<<endl;
	
 }


