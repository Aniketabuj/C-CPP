#include<cstdlib>
#include<cstdio>

class complex{
    private:
        double re, im;
    
    public:
        complex() : re(0.0), im(0.0){

        }

        complex(double _re, double _im) : re(_re), im(_im){

        }

        complex add(complex second_number) const{
            complex summation_object;

            summation_object.re = this->re + second_number.re;
            summation_object.im = this->im + second_number.im;

            return(summation_object);
        }

        void show(const char* msg) const{
            if(msg)
                puts(msg);

            printf("(%.2lf) + (%.2lf)\n", this->re, this->im);
        }
};

int main(void){
    complex c1(1.1, 2.2);
    complex c2(3.3, 4.4);

    c1.show("showing c1");
    c2.show("showing c2");

    complex sum;

    sum = c1.add(c2);
    sum.show("Showing summation of c1 and c2");

    return EXIT_SUCCESS;
}