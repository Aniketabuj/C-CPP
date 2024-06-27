#include <cstdlib>
#include <cstdio>

class complex{
    private:
        double re, im;
    
    public:
        complex() : re(0.0), im(0.0){

        }

        complex(double _re, double _im) : re(_re), im(_im){

        }

        complex& add(const complex& second_number) const{
           static complex summation;

            summation.re = re+ second_number.re;
            summation.im = im + second_number.im;
            return(summation);
        }

        void show(const char* msg) const{
            if(msg)
                puts(msg);
            
            printf("(%.2lf) + im(%.2lf)\n", re, im);
        }
        
};

int main(void){
    complex c1(1.1, 2.2);
    complex c2(3.3, 4.4);

    c1.show("Showing c1");
    c2.show("Showing c2");

    complex& sum = c1.add(c2) ;
    sum.show("Adding c1 and c2:");

    return EXIT_SUCCESS;
}