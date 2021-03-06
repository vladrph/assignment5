//
// Created by Vladimir Petit-Homme on 10/19/2021.
//

#ifndef ASSIGNMENT5_STACK_H
#define ASSIGNMENT5_STACK_H


#include <iostream>
#include <string>

using namespace std;

typedef string stack_element;

class stack_node
{
public:
    stack_element data;
    stack_node *next;
};

class stack
{
public:
    stack(){/*cout<<"Inside Default Constructor\n"*/;s_top=0;}
    ~stack();
    stack(const stack &);
    stack_element top();
    void pop();
    void push(const stack_element &);
    void print();


private:

    stack_node *s_top;
};

#endif //ASSIGNMENT5_STACK_H
