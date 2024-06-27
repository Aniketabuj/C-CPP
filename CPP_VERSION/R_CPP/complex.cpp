#include <cstdio>
#include<cstdlib>

class complex{
    private:
        double re, im;
    
    public:
        complex() : re(0.0), im(0.0){

        }

        complex(double _re, double _im) : re(_re), im(_im){

        }

        complex add(const complex& second_number) const;
        complex sub(const complex& second_number) const;
        complex mul(const complex& second_number) const;
        complex div(const complex& second_number) const;

        void show(const char* msg) const{
            if(msg)
                puts(msg);
            
            printf("(%.2lf) + im(%.2lf)\n", re, im);
        }
};

complex complex::add(const complex& second_number)const{
    complex summation;

    summation.re = re + second_number.re;
    summation.im = im + second_number.im;

    return(summation);
}

complex complex::sub(const complex& second_number) const{
    complex subtraction;

    subtraction.re = re - second_number.re;
    subtraction.im = im - second_number.im;

    return subtraction;
}

complex complex::mul(const complex& second_number) const{
    complex multiplication;

    multiplication.re = re * second_number.re;
    multiplication.im = im * second_number.im;

    return(multiplication);
}

complex complex:: div(const complex& second_number) const{
    complex division;

    division.re = re / second_number.re;
    division.im = im / second_number.im;

    return(division);
}



int main(void){
    complex c1(1.1, 2.2);
    complex c2(3.3, 4.4);

    complex sum, sub, div, mul;

    sum = c1.add(c2);
    sum.show("After adding c1 & c2:");

    sub = c1.sub(c2);
    sub.show("After subtractib c1 & c2");

    mul = c1.mul(c2);
    mul.show("After multiplying c1 & c2");

    div = c1.div(c2);
    div.show("After dividing c1 & c2");

    return EXIT_SUCCESS;
}