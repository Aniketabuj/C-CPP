#include<iostream>
#include<cstdio>
#include<cstdlib>

class Date{
    private:
        int day;
        int month;
        int year;
        static bool is_valid(int dd, int mm, int yy){

                return(true);
        }
    
    public:
        Date() : day(1), month(1), year(1970){
        }

        Date(int _dd, int _mm, int _yy) : day(_dd), month(_mm), year(_yy){

        }

        int get_day(){
            return(this->day);
        }

        int get_month(){
            return(this->month);
        }

        int get_year(){
            return(this->year);
        }

        bool set_day(int new_day){
            if(!is_valid(new_day, this->month, this->year))
                return false;
            day = new_day;
            return true;
        }

        bool set_month(int new_month){
            if(!is_valid(this->day, new_month, this->year))
                return false;
            month = new_month;
            return true;
        }

        bool set_year(int new_year){
            if(!is_valid(this->day, this->month, new_year))
                return false;
            year = new_year;
            return true;
        }

        void show(){
            printf("%d-%d-%d\n", this->day, this->month, this->year);
        }
};

int main(void){
    Date myDate(20, 4, 1985);

    myDate.show();
    int day = myDate.get_day();
    int month= myDate.get_month();
    int year = myDate.get_year();

    printf("INIT Date: %d-%d-%d\n", day, month, year);
    myDate.set_day(6);
    myDate.set_month(8);
    myDate.set_year(2023);

    day = myDate.get_day();
    month = myDate.get_month();
    year = myDate.get_year();

    return EXIT_SUCCESS;
}