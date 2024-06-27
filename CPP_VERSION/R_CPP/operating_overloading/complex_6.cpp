#include<cstdio>
#include<cstdlib>

class complex{
    private:
        double re, im;
    
    public:
        complex() : re(0.0), im(0.0){

        }

        complex(double _re, double _im): re(_re), im(_im){

        }

        complex& add(const complex& second_number) const{
            complex* sum = new complex;

            sum->re = re + second_number.re;
            sum->im = im + second_number.im;

            return(*sum);
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
    complex c3(5.5, 6.6);

    c1.show("Showing c1");
    c2.show("showing c2:");

    complex& refsum = c1.add(c2);
    refsum.show("After adding c1 & c2");

    complex& refsum1 = refsum.add(c3);
    refsum1.show("After ading refsum am=nd c3");
    
    delete &refsum;
    delete &refsum1;

    return EXIT_SUCCESS;
}