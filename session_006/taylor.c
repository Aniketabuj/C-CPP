    #include<stdio.h>
    #include<Stdlib.h>
    #include<math.h>
    # define PI 3.14159265
    int main(void)
{
    float x;
    printf("Enter x(-1 < x < 1) = ");
    scanf("%f",&x);
    float sum = 0;
    float t0 = x;
    float t1 = (-1) * pow(x,3)/6;
    sum = sum + t0 + t1;
    float t2;
    for(int i=2; i<= 1000; i++)
    {        
        t2 = (-1) * t1 * (((x*x) * (2*i-1) * (2*i-1)) /((2*i+1) * (2*i)));             
        sum = sum + t2;
        t1 = t2; 
    }    
    printf("\nsinh-1 %0.2f = %f",x,sum);
}
