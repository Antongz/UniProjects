#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <stdio.h>
#include <iomanip>
#include <stdlib.h>
#include <cstring>
#include <list>

using namespace std;

struct Customer {
    int arrival_time;
    int ticket_num;
    int running_time = 0;
    int runs=0;
    int running_timeInProcessOne = 0;
    int rest_time = 0;
    int waiting_time = 0;
    int age = 0;
    int end = 0;
    int priority;
    int ready_time = -1;
    string ID;
};

class Process {
public:

    Customer* pop_front();
    void tailInsert(Customer*);
    Customer* getHead();
    void remove_front();
    bool Empty();
    void insertCustomerq1(Customer*);
    void insertCustomerq2(Customer*);
    void ageing();
    void promote(Process*);
    void insertCustomerwaitq(Customer*);
    void CalWaiting(int);
     vector<Customer*> queue;
    
};




 void porcessing();
  void init(string line);
  void printResult();
 void insert_from_waitq();
    Process pro1;
    Process pro2;
    Process waitp;
    vector<Customer*> finalq;

int timer = 0;


void init(string line) {
  

    char *new1 = new char[line.length()+1];
            strcpy(new1,line.c_str());
            const char sp[2] = " ";
    

       Customer * proc =  new Customer;

                        proc->ID        = strtok(new1,sp);
                        proc->arrival_time = atoi(strtok(NULL,sp));
                        proc->priority = atoi(strtok(NULL,sp));
                        proc->age  = atoi(strtok(NULL,sp));

                        proc->ticket_num= atoi(strtok(NULL,sp));
    


        if (proc->arrival_time == 0) {
            if (proc->priority <= 3) {
                pro1.insertCustomerq1(proc);
            } else {
                proc->rest_time = 100;
                pro2.insertCustomerq2(proc);
            }
        } else {
               waitp.insertCustomerwaitq(proc);
        }
    


}



void porcessing() {
    while (!pro1.Empty() || !pro2.Empty() || !waitp.Empty()) {
        int processTime = 0;
        Customer *inProcessCustomer, *newOne;
        while (!pro1.Empty()) {
            processTime = 0;
            inProcessCustomer = pro1.pop_front();
            if (inProcessCustomer->ready_time == -1) {inProcessCustomer->ready_time = timer;}
            while (inProcessCustomer->ticket_num > 0 && processTime < (8-inProcessCustomer->priority)*10) {timer += 5;inProcessCustomer->ticket_num -= 1;processTime += 5;

                insert_from_waitq();
            }
            inProcessCustomer->running_time += processTime;
            inProcessCustomer->running_timeInProcessOne += processTime;
            inProcessCustomer->runs +=1;
 
           pro1.CalWaiting(processTime);
            pro2.CalWaiting(processTime);
            pro2.ageing();
            if (inProcessCustomer->ticket_num != 0) {
                if (inProcessCustomer->runs == 3) {inProcessCustomer->priority += 1;
                    if (inProcessCustomer->priority > 3) {
                        inProcessCustomer->rest_time = 100;
                     pro2.tailInsert(inProcessCustomer);
        
                    } else {
                        pro1.insertCustomerq1(inProcessCustomer);
                    }
                } else {
                    pro1.insertCustomerq1(inProcessCustomer);
                }
            } else {
                inProcessCustomer->end = timer;
               inProcessCustomer->waiting_time=inProcessCustomer->end-inProcessCustomer->running_time-inProcessCustomer->ready_time;
                finalq.insert(finalq.end(), inProcessCustomer);
            }

            pro2.promote(&pro1);

         
        }

        while (!pro2.Empty() && pro1.Empty()) {
            processTime = 0;
            inProcessCustomer = pro2.pop_front();
            if (inProcessCustomer->ready_time == -1) {
                inProcessCustomer->ready_time = timer;
            }
     
            while (inProcessCustomer->ticket_num > 0 && inProcessCustomer->rest_time > 0 && pro1.Empty()) {
                timer += 5;
                processTime += 5;
                inProcessCustomer->ticket_num -= 1;
                inProcessCustomer->rest_time -= 5;

                insert_from_waitq();

            }
            inProcessCustomer->running_time += processTime;
            pro2.CalWaiting(processTime);
            pro2.ageing();

            if (inProcessCustomer->ticket_num != 0) {

                    inProcessCustomer->rest_time = 100;
   
                pro2.tailInsert(inProcessCustomer);

            } else {
                inProcessCustomer->end = timer;
               inProcessCustomer->waiting_time=inProcessCustomer->end-inProcessCustomer->running_time-inProcessCustomer->ready_time;
                finalq.insert(finalq.end(), inProcessCustomer);
            }

            pro2.promote(&pro1);

      
            
        }
        

        if (pro1.Empty() && pro2.Empty() && !waitp.Empty()) {
            newOne = waitp.getHead();
          timer= newOne->arrival_time;
            do {
                if (newOne->priority <= 3) {
                    pro1.insertCustomerq1(newOne);
                } else {
                    pro2.insertCustomerq2(newOne);
                }
                waitp.remove_front();
                newOne = waitp.getHead();
            } while (newOne->arrival_time == timer);

        }
    }
}

void insert_from_waitq() {
    Customer *newCustomer;

    while (!waitp.Empty()) {
        newCustomer = waitp.getHead();
        if (newCustomer->arrival_time == timer) {
            if (newCustomer->priority <= 3) {
                pro1.insertCustomerq1(newCustomer);
            } else {
                newCustomer->rest_time = 100;
                pro2.insertCustomerq2(newCustomer);
            }
            waitp.remove_front();
        } else {
            break;
        }
    }
}


void printResult() {
cout<<"name"<<"\t" <<"arrival"<<"\t" <<"end"<<"\t" <<"ready"<<"\t" <<"running"<<"\t" <<"waiting"<<"\n";
for(int i =0;i<finalq.size();i++)
{

cout<<finalq[i]->ID<<"\t" <<finalq[i]->arrival_time<<"\t" <<finalq[i]->end<<"\t" <<finalq[i]->ready_time<<"\t" <<finalq[i]->running_time<<"\t"<<finalq[i]->waiting_time<<"\n";
}
             }


void Process::insertCustomerq1(Customer *proc) {
    u_int i = 0;
    if (queue.size() > 0) {
        while (i < queue.size() && queue[i]->priority <= proc->priority) {
            i += 1;
        }
    }

    if (i == 0) {
        queue.insert(queue.begin(), proc);
    } else if (i == queue.size()) {
        queue.insert(queue.end(), proc);
    } else {
        queue.insert(queue.begin() + i, proc);
    }
}

void Process::insertCustomerq2(Customer *proc) {
    u_int i = 0;
    if (queue.size() > 0) {
        while (i < queue.size() && queue[i]->arrival_time <= proc->arrival_time) {
            i += 1;
        }
    }

    if (i == 0) {
        queue.insert(queue.begin(), proc);
    } else if (i == queue.size()) {

       queue.push_back(proc);
    } else {
        queue.insert(queue.begin() + i, proc);
    }
}

void Process::ageing() {
    u_int i = 0;
    if (queue.size() > 0) {
        while (i < queue.size()) {
            if (queue[i]->arrival_time != timer) {
                queue[i]->age += 1;
                if (queue[i]->age == 8) {
                    queue[i]->priority -= 1;
                    queue[i]->age = 0;
                }
            }
            i += 1;
        }
    }
}
void Process::promote(Process *pro1) {
    u_int i = 0;
    if (queue.size() > 0) {
        while (i < queue.size()) {
            if (queue[i]->priority <= 3) {
                (*pro1).insertCustomerq1(queue[i]);
                queue.erase(queue.begin() + i);
                i -= 1;
            }
            i += 1;
        }
    }
}

void Process::insertCustomerwaitq(Customer *proc) {
    u_int i = 0;
    if (queue.size() > 0) {
        while (i < queue.size() && queue[i]->arrival_time <= proc->arrival_time) {
            if (queue[i]->arrival_time == proc->arrival_time) {
                if ((queue[i]->ID).compare(proc->ID) > 0) {
                    break;
                }
            }
            i += 1;
        }
    }

    if (i == 0) {
        queue.insert(queue.begin(), proc);
    } else if (i == queue.size()) {
        queue.insert(queue.end(), proc);
    } else {
        queue.insert(queue.begin() + i, proc);
    }
}

bool Process::Empty() {
    bool empty = true;
    if (queue.size() > 0) {
        empty = false;
    }
    return empty;
}

Customer* Process::getHead() {
   Customer *proc = queue.front();
    return proc;
}
void Process::remove_front() {
  queue.erase(queue.begin());

}

Customer* Process::pop_front() {
    Customer *proc = queue.front();
    queue.erase(queue.begin());

    return proc;
}

void Process::tailInsert(Customer *proc) {
 queue.insert(queue.end(), proc);
}


void Process::CalWaiting(int time) {
    std::vector<Customer*>::iterator it;
    for (it = queue.begin(); it < queue.end(); it += 1) {
        if ((*it)->ready_time != -1) {
            (*it)->waiting_time += time;
        }
    }
}



int main(int argc, char *argv[]) {
   
    ifstream infile(argv[1]);
    string line;
   while(getline(infile,line)){
        istringstream iss(line);
        init(line);
    }
  
   porcessing();
   printResult();
   }
