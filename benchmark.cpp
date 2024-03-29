//
// (C) 2022, E. Wes Bethel
// benchmark-* harness for running different versions of the sum study
//    over different problem sizes
//
// usage: no command line arguments
// set problem sizes, block sizes in the code below

#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>
#include <string.h>


extern void setup(int64_t N, uint64_t A[]);
extern int64_t sum(int64_t N, uint64_t A[]);

/* The benchmarking program */
int main(int argc, char** argv) 
{
   std::cout << std::fixed << std::setprecision(2);

#define MAX_PROBLEM_SIZE 1 << 28  //  256M
   std::vector<int64_t> problem_sizes{ 1000000, 256000000 };
   
   std::vector<uint64_t> A(256000000);

   int64_t t;
   int n_problems = problem_sizes.size();

   /* For each test size */
   for (int64_t n : problem_sizes) 
   {
      printf("Working on problem size N=%d \n", n);

      // invoke user code to set up the problem
      setup(n, &A[0]);

      // insert your timer code here
      std::chrono::time_point<std::chrono::high_resolution_clock> start_time = std::chrono::high_resolution_clock::now();
      // invoke method to perform the sum
      // insert your end timer code here, and print out elapsed time for this problem size
      
      std::chrono::duration<double> elapsed = std::chrono::duration<double>::zero();

      int64_t num_iter = 0;
      while(elapsed.count() < 30.0){
         t = sum(n, &A[0]);
         num_iter++;

         std::chrono::time_point<std::chrono::high_resolution_clock> end_time = std::chrono::high_resolution_clock::now();
         elapsed = end_time - start_time;  
      }
   
      std::cout << " Elapsed time is fir N =" << n << elapsed.count() / num_iter << " seconds per iteration "  << std::endl;
      printf(" Sum result = %lld \n",t);

   } // end loop over problem sizes
}

// EOF
