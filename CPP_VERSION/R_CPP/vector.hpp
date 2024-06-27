#ifndef _VECTOR_HPP
#define _VECTOR_HPP

const int SUCCESS = 1;
const int VECTOR_INDEX_ERROR = -1;

class vector{
    private:
        int* p_array;
        int N;
    
    public:
        vector();
        ~vector();
        void push_back(int new_data);
        void show(const char* msg) const;
        int size() const;
        int get(int index, int* p_data)const;
        int set(int index, int new_value);
};

#endif