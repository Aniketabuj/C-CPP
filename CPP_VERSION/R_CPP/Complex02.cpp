#include<iostream>
#include<cstdio>

class complex{
    private:
        double re, im;

    public:
        complex() : re(0.0), im(0.0){

        }

        complex(double _re, double _im) : re(_re), im(_im){

        }

        void show(const char* msg) const{
            if(msg)
                puts(msg);
            
            printf("(%.3lf) + i(%.3lf)\n", re, im);
        }

        complex operator+( const complex& other)const{
            complex result;
            
            result.re = re + other.re;
            result.im = im + other.im;

            return (result);
        }

        complex operator-( const complex& other)const{
            complex result;
            
            result.re = re - other.re;
            result.im = im - other.im;

            return (result);
        }


};

int main(void){
    complex c1(1.1, 2.2);
    complex c2(3.3, 4.4);

    c1.show("C1:");
    c2.show("C2:");

    complex summation = c2 + c1;
    complex subtraction = c2 - c1;

    c1.show("C1:");
    c2.show("C2:");

    summation.show("Summation:");
    subtraction.show("Subtraction:");

    return(0);
}