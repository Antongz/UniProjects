#include"Node.h"

using namespace std;

//node stored data
Node::Node()
{
    data=0;
    next=NULL;
}

//set data
void Node::set_data(int new_data)
{
    data=new_data;
}

//get data
int Node::get_data()
{
    return data;
}

//set next data
void Node::set_next(node* new_node)
{
    next=new_code;
}

//get next node
node* Node::get_next()
{
    return next;
}
