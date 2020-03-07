#include<iostream>
using namespace std;

template<typename T>class List;
template<typename T>class Node{
    T info;
    Node<T> *link;
    public:
        Node();
        Node(const T & data);
};

template <typename T> Node<T> :: Node()
{
    link = NULL;
}

template <typename T> Node<T> ::Node(const T & data)
{
    info = data;
    link = NULL;
} 

//define the linkedlist

template <typename T> class List{
    Node<T> *head;          //define linkedlist head pointer and tail pointer
    public:
        List();             //Constructor to generate a header (empty list)
        ~list();
}