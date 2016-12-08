#include <omp.h>
#include <iostream>
using namespace std;

 main(int argc, char *argv[]) {

 int nthreads, tid;
 
 /* Fork a team of threads with each thread having a private tid variable */
 #pragma omp parallel private(tid)
 {
    

   /* Obtain and print thread id */
      tid = omp_get_thread_num();
      cout<<"Hello World from thread = "<<tid<<endl;	
//   printf("Hello World from thread = %d\n", tid);

   /* Only master thread does this */
      if (tid == 0) 
      {
	 nthreads = omp_get_num_threads();
	 cout<<"Number of threads ="<<nthreads<<endl; 
	 //printf("Number of threads = %d\n", nthreads);
      }

   }  /* All threads join master thread and terminate */

 }

