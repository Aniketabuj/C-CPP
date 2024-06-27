#define _CRT_RAND_S
#include<iostream>
#include<stdexcept>
#include<cstdlib>

class array{
    private:
        int* pa;
        long long N;
        int cpa;

        static void insertion_sort(int* a, long long N){
            long long i, j;
            int key;

            for(j = 1; j < N; j++){
                key = a[j];
                for(i = j-1; i > -1 && a[i] > key; --i)
                    a[i + 1] = a[i];
                a[i+1] = key;
            }
        }
};
