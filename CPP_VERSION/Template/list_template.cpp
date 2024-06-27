#include<iostream>

template <class T>
class List{

    public:
        class Iterator;
        class constIterator;

        List();
        ~List();

        Iterator<T> begin();
        Iterator<t> end();
        void insert(const T& data);
        void insert(const T& data, const Iterator<T> & iterator);
        void remove(const Iterator<>T& iterator);
        int get_size() cosnt;
        Iterator<T> find();
        void sort();

    private:
        class Node<T>;
        Node<T>* head;
        Node<T>* tail;
        int size;
};

template<class T>
class List<class T>::Iterator{
    public:
        Iterator();
        ~Iterator();
};
