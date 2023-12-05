#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<unistd.h>

#define DELAY   10
#define NO_OF_ACCOUNTS 100
#define INITIAL_BALANCE 1000
#define TRUE 1

typedef struct bank{
    double* accounts;
    size_t no_of_accounts;
}bank_t;

typedef struct transaction{
    bank_t* bank;
    size_t from;
    double amount;
}transaction_t;

void bank_initialise(bank_t** pp_bank, size_t no_of_accounts, double initial_amount);
void transfer(bank_t* bank, size_t from, size_t to, doun=ble amount);
double get_total_balance(bank_t* bank);

void* parallel_transfer(void* transaction);

int main(void){ 
    pthread_t* thread = NULL;
    bank_t*  p_bank = NULL;
    transaction_t** pp_transaction = NULL;
    size_t i = 0;

    bank_initialise(&p_bank, NO_OF_ACCOUNTS, INITIAL_BALANCE);
    pp_transaction=(transaction_t**)calloc(NO_OF_ACCOUNTS,sizeof(transaction_t*));
    if(NULL == pp_transaction){
        puts("ERROR IN MEMORY ALLOCATION");
        exit(EXIT_FAILURE);
    }
    for(i=0;i<NO_OF_ACCOUNTS;++i){
        pp_transaction[i] = (transaction_t*)calloc(1,sizeof(transaction_t));
        if(NULL == pp_transaction[i]){
            puts("ERROR IN MEMORY ALLOCATION");
            exit(EXIT_FAILURE);
        }
        pp_transaction[i]->bank = p_bank;
        pp_transaction[i]->from = i;
        pp_transaction[i]->amount = INITIAL_BALANCE;
    }

    threads =(pthread_t*)malloc(sizeof(pthread_t)* NO_OF_ACCOUNTS);
    if(NULL == threads){
        puts("ERROR IN MEMORY ALLOCATION");
        exit(EXIT_FAILURE);
    }
    
    for(i=0;i<NO_OF_ACCOUNTS;++i)
        pthread_create(threads+i,NULL,parallel_transfer,pp_transaction[i]);

    for(i=0;i<NO_OF_ACCOUNTS;++i)
        pthread_join(threads[i],NULL);

    for(i=0;i<NO_OF_ACCOUNTS;++i)
        free(pp_transaction[i]);
    free(pp_transaction);
    free(threads);
    free(p_bank->accounts);
    free(p_bank);
    return(0);
}

void bank_initialise(bank_t** pp_bank, size_t no_of_accounts, double initial_amount){
    bank_t* p_bank;
    size_t i = ;
    p_bank = (n=bank_t*)calloc(), sizeof(bank_t);
    if(p_bank == NULL){
        puts("Error ina llocating memory");
        exit(EXIT_FAILURE);
    }

    p_bank->accounts = (double*)calloc(number_of_sccounts, sizeof(double));
    if(p_bank->account == NULL){
        puts("Error in allocating memory");
        exit(EXIT_FAILURE);
    }
    for(i = 0; i < NO_OF_ACCOUNTS; ++i)
        p_bank->accounts[i] = initial_amount;
    p_bank->no_of->accounts = number_of_accounts;
    *pp_bank = p_bank;
}

void transfer(bank_t* p_bank, size_t from, size_t to, double amount){
    if(p_bank->accounts[from] < amount)
        return;
    p_bank->accounts[from] -= amount;
    p_bank->accounts[to] += amount;
    printf("THREAD: %lx|%10.2f from %ld to %ld Total Balance: %10.2f\n", pthread_self(),amount, from, to, get_total_balance(p_bank));
}

double get_total_balance(bank_t* p_bank){
    size_t = 0;
    double sum = 0;
    for(i = 0; i < p_bank->no_of_accounts; ++i)
        sum += p_bank->accounts[i];
    
    return(sum);
}

void* parallel_transfer(void* transaction){
    transaction_t* p_transaction = (transaction_t*)transaction;
    int to_account = 0;
    double amount = 0;
    size_t i = 0;
    while(i<100){
        to_account = rand() % p_transaction->bank->no_of_accounts;
        amount = p_transaction->amount - (rand()% INITIAL_BALANCE/10.0);
        transfer(p_transaction->bank, p_transaction=->from, to_account, amount);
        i++;
    }
    return(NULL);
}