#include <cstdio>
#include <cstdlib>

class complex{
    private:
        double re, im;
    
    public:
        complex() : re(0.0), im(0.0){
            
        }

        complex(double _re, double _im) : re(_re), im(_im){

        }

        complex* add( const complex& second_number) const{
                complex* pSum = new complex;

                pSum->re = this->re  + second_number.re;
                pSum->im = this->im + second_number.im;

                return(pSum);
        }

        void show(const char* msg){
            if(msg)
                puts(msg);
            
            printf("(%.2lf) + im(%.2lf)\n", re, im);
        }
};

int main(void){
    complex c1(1.1, 2.2);
    complex c2(3.3, 4.4);
    complex c3(5.6, 7.8);

    c1.show("Showing C1");
    c2.show("Showing c2");

    complex* pSummation = c1.add(c2);
    pSummation->show("After Adding C1 and c2:");

    complex* pSummaton = (c1.add(c2))->add(c3);
    pSummaton->show("After Adding C1 & C2 with c3:");

    delete pSummation;
    pSummation = 0;

    return EXIT_SUCCESS;

}