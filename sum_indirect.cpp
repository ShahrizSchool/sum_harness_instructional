#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>
#include <string.h>



void 
setup(int64_t N, uint64_t A[])
{
   printf(" inside sum_indirect problem_setup, N=%lld \n", N);

   for(int i = 0; i < N - 1; i++){
      A[i] = lrand48() % N;
   }

   int64_t Nloops = 0;
   for(int i = 0; i < N; i++){
      Nloops ++;
   }
   printf("Nloops is: ", Nloops);
}

int64_t
sum(int64_t N, uint64_t A[])
{
   printf(" inside sum_indirect perform_sum, N=%lld \n", N);

   int64_t sum = 0;
   
   int64_t indx = A[0];

   for (int i = 0; i < N; i++){
      sum += A[indx];
      indx = A[indx];
   }

   return sum;
}

