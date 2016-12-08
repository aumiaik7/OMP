#include <omp.h>
#include <iostream>
#define N 100


using namespace std;



 main(int argc, char *argv[]) {

 int i;
 float a[N], b[N], c[N], d[N];

 /* Some initializations */
 for (i=0; i < N; i++) {
   a[i] = i * 1.5;
   b[i] = i + 22.35;
   }

 #pragma omp parallel shared(a,b,c,d) private(i)
   {

   #pragma omp sections nowait
     {

     #pragma omp section
     for (i=0; i < N; i++)
     {
	c[i] = a[i] + b[i];
	cout<<"Section1: c[i]: "<<c[i]<<endl;
     }

     #pragma omp section
     for (i=0; i < N; i++)
     {
	d[i] = a[i] * b[i];
	cout<<"Section2: "<<i<<" "<<d[i]<<endl;
     }

     }  /* end of sections */

   }  /* end of parallel region */

 }
