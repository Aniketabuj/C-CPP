#include<stdio.h>
#include<stdlib.h>

typedef long long int ssize_t;

ssize_t partition(int* a, ssize_t p, ssize_t r){
    ssize_t i, j;
    ssize_t q;
    int tmp, pivot;

    pivot = a[r];
    i = p-1;
    for(j = p; j < r; ++j){
        if(a[j] <= pivot){
            i = i + 1;
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }
    tmp = a[i+1];
    a[i+1] = a[r];
    a[r] = tmp;

    return(i+1);
}

ssize_t partition(int* a, ssize_t p, ssize_t r){
    ssize_t i, j;
    int tmp, pivot;

    pivot = a[r];

    i = p-1;
    for(j = p; j <r; ++j){
        if(a[j] <= pivot){
        i = i+1;
        tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
        }
    }
    tmp = a[i+1];
    a[i+1] = a[r];
    a[r] = tmp;

    return(i+1);
}

ssize_t partiton(int* a, ssize_t p, ssize_t r){
    ssize_t i, j;
    int tmp, pivot;

    pivot = a[r];

    i = p-1;
    for(j = p; j < r; ++j){
        if(a[j] <= pivot){
            i = i+1;
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }
    tmp = a[i+1];
    a[i+1] = a[r];
    a[r] = tmp;
    return(i+1);
}

ssize_t partition(int* a, ssize_t p, ssize_t r){
    ssize_t i, j;
    int tmp, pivot;

    pivot = a[r];

    i = p-1;
    for(j = p; j < r; j++){
        if(a[j] <= pivot){
            i = i+1;
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }

    tmp = a[i+1];
    a[i+1] = a[r];
    a[r] = tmp;
    return(i+1);
}