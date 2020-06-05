/*
 prac7
 a1711972 yongxin hu
 */
//link list node

#ifndef NODE_H
#define NODE_H
#include <iostream>

class Node
{
   
    int data;//node stored data
    Node* next;//next node
    Node();//node
    Node(int n);
    
    void set_data(int new_data);//set data
    int get_data();//get data
    void set_next(Node* new_node);//set next data
    Node *get_next();//get next node
};
#endif

