#include<stdio.h>
#include<stdlib.h>

typedef size_t ssize_t;
char* join(char** pp_str, size_t N, char* join_string);
void test_join(void);
ssize_t cpa_strlen(const char* src);

int main(void)
{
    test_join();
    return(0);
}

char* join(char** pp_str, ssize_t N, char* join_string)
{
    char* result = NULL;
    ssize_t len_result_str = 0;
    ssize_t len_join_str;
    ssize_t len_curr_str;
    ssize_t old_len ;
    ssize_t i;
    ssize_t k;

    len_join_str = strlen(join_string);
    if(len_join_str == 0)
    {
        puts("Error in join string");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < N-1; ++i)
    {
        len_curr_str = cpa_strlen(pp_str[i]);
        result = (char*)realloc(result, len_result_str + len_curr_str + len_join_str);
        if(result == NULL)
        {
            puts("Error in allocating memory");
            exit(EXIT_FAILURE);
        }

        old_len = len_result_str;
        len_result_str += (len_curr_str + len_join_str);

        for(k = 0; k < len_curr_str; ++k)
            result[old_len + k] = pp_str[i][k];
        for(k = 0; k < len_join_str; ++k)
            result[old_len + len_curr_str + k] = join_string[k];
    }
    
        len_curr_str = strlen(pp_str[i]);
        result = (char*)realloc(result, len_result_str + len_curr_str + 1);
        if(result == NULL)
        {
            puts("Error in allocating memory");
            exit(EXIT_FAILURE);
        }
    
        old_len = len_result_str;
        len_result_str += (len_curr_str);

        for(k = 0; k < len_curr_str; ++k)
            result[old_len + k] = pp_str[i][k];
        result[old_len + k] = '\0';

        return(result);
}


void test_join(void)
{
    char* result  = NULL;
    char* strings[] = {
        "Aniket",
        "Sopan", 
        "Abuj"
    };

    char* join_string = "#$#";

    result = join(strings, 3, join_string);
    printf("join_string = %s", result);

    result = NULL;
    free(result);
}

ssize_t cpa_strlen(const char* src)
{
    ssize_t i ;
    ssize_t len ;

    i = 0;
    len = 0;

    while(src[i] != '\0')
    {
        ++i;
        ++len;
    }

    return(len);
}