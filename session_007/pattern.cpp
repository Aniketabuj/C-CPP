#include<iostream>
using namespace std;

int main(void)
{
    int N = 6;

    int i, j;

    for(i = 0; i < N; i++){
        cout<<"1";

        for(j = 0; j < i; j++)
        {
            cout<<" 0";
            
        }

        cout<<endl;
    }

    return(0);
}
