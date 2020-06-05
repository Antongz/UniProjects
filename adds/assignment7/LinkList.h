/*
 prac7
 a1711972 yongxin hu
 */
//link list 


#ifndef LINKLIST_H
#define LINKLIST_H
#include"Node.h"
#include <iostream>
class LinkList
{
    
Node *head;
Node *tail;

LinkList();
LinkList(LinkList &oldone);
    
void addFront(int newItem);//add front node
void addEnd(int newItem);//add end node
void addAtPosition(int position,int newItem);//add position node
int search(int item);//serch node
void deleteFront();//delete front node
void deleteEnd();//delete end node
void deletePosition(int position);//delete postion node
int getItem(int position);// get position node
void printItems();//print output
};
#endif
