#include <stdio.h> 
#include <stdlib.h> 
#include <getopt.h> 

void help(void); 
void version(void); 

int main(int argc, char* argv[]){
    int ret; 

    if(argc == 1){
        help(); 
        exit(EXIT_SUCCESS); 
    }

    while((ret = getopt(argc, argv, "hv")) != -1){
        switch((char)ret){
            case 'h':
                help(); 
                break; 
            case 'v': 
                version(); 
                break; 
            default: 
                help(); 
                exit(EXIT_FAILURE); 
        }
    }

    exit(EXIT_SUCCESS); 
    
}

void help(void){
    char* str_help = "./app [-h/-v]\
-h : for printing help\
-v : for printing version"; 
    puts(str_help); 
}

void version(void){
    puts("0.1"); 
}
