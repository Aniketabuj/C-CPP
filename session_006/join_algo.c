#include<stdio.h>
#include<stdlib.h>

typedef size_t ssize_t;

char* join(char** pp_str, ssize_t N, char* join_str);
void test_join(void);
ssize_t len_str(const char* src);

int main(void)
{
    test_join();
    return(0);
}

char* join(char** pp_str, ssize_t N, char* join_str)
{
    char* result = NULL;
    ssize_t len_result_str = 0;
    ssize_t len_curr_str;
    ssize_t len_join_str;
    ssize_t old_len;
    ssize_t i;
    ssize_t k;

    len_join_str = len_str(join_str);
    if(len_join_str == 0)
    {
        puts("Error in join_str");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < N-1; i++)
    {
        len_curr_str = len_str(pp_str[i]);
        result = (char*)realloc(result, len_result_str + len_curr_str + len_join_str);
        if(result == NULL)
        {
            puts("error in allocating the memory");
            exit(EXIT_FAILURE);
        }

        old_len = len_result_str;
        len_result_str += (len_curr_str + len_join_str);

        for(k = 0; k < len_curr_str; ++k)
            result[old_len + k] = pp_str[i][k];
        for(k = 0; k < len_join_str; ++k)
            result[old_len + len_curr_str + k] = join_str[k];
    }

        len_curr_str = len_str(pp_str[i]);
        result = (char*)realloc(result, len_result_str + len_curr_str + 1);
        if(result == NULL)
        {
            puts("error in allocating the memory");
            exit(EXIT_FAILURE);
        }

        old_len = len_result_str;
        len_result_str += (len_curr_str);

        for(k = 0; k < len_curr_str; ++k)
            result[old_len + k]= pp_str[i][k];
        
        result[old_len + k] = '\0';
        return(result);
}

void test_join(void)
{
    char* result = NULL;
    char* join_str = "#@#";

    char* string[] = {
        "Aniket",
        "Sopan",
        "Abuj"
    };

    result = join(string, 3, join_str);

    printf("join_str = %s", result);

    free(result);
    result = NULL;
}

ssize_t len_str(const char* src)
{
    ssize_t i = 0;
    ssize_t len = 0;

    while(src[i] != '\0')
    {
        ++i;
        ++len;
        
    }

    return(len);
}