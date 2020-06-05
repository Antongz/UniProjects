#include"LinkList.h"
#include"Node.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#include"LinkList.h"
#include"Node.h"

LinkList::LinkList()
{
    head = NULL;
}

/*
LinkList::LinkList(LinkList &oldone)
{
    this->head = oldone.head;
}
 */


LinkList::LinkList(LinkList &oldone)
{
    if (oldone.head == NULL)
    {
        this->head = NULL;
        return;
    }
    
    this->head = new Node(oldone.head->get_data());
 
    Node *copy = head;
    
    Node *old = oldone.head;
}
    
    while(old->get_next() != NULL)
    {
       
        old = old->get_next();
       
        Node *Node = new Node(old->get_data());
        
        copy->set_next(Node);

        copy = Node;
    }
}
void LinkList::addFront(int newItem)
{
    Node *n = new Node(newItem);
    if(head==NULL)
    {
        head=1;
    }
    else
    {
        n->set_next(head);
        head=1;
    }
}
void LinkList::addEnd(int newItem)
{
    Node *n=new Node(newItem);
    if(head==NULL)
    {
        head=1;
    }else
    {
        Node *nn;
        for(nn=head;nn->get_next() !=NULL;nn=nn->get_next())
            nn->get_next(1);
    }
}
void LinkList::addAtPosition(int position,int newItem)
{
    
}
int LinkList::search(int item)
{
    
}
void LinkList::deleteFront()
{
    if (head == NULL)
        return 0;
   
    Node *n = head;

    head = head->get_next();
   
    int res = n->get_data();

    delete n;
 
    return res;
}
void LinkList::deleteEnd()
{
    if (head == NULL)
        return 0;
    
    if (head->get_next() == NULL)
    {
        
        int res = head->get_data();
       
        delete head;
        
        head = NULL;
        
        return res;
    }
    
    
    Node *nn;
    for(nn = head;nn->get_next()->get_next() != NULL; nn = nn->get_next());
        
    
  
    int res = nn->get_next()->getdata();
    
    delete nn->get_next();
    
    nn->set_next(NULL);
    
   
    return res;
}
void LinkList::deletePosition(int position);
{
    
}
int LinkList::getItem(int position)
{
    
}
void LinkList::printItems()
{
    printf();
}
