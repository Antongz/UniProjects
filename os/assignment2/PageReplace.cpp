#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include<map>
#include<math.h>

using namespace std;

struct Node{
  int Page_id;
  int dirty;
  unsigned int shiftRegister;
  int used_time;
  Node* next;
};

struct fifo{
    long address;
    int Page_id;
    fifo* next;
};
struct lru{
    long address;
    int Page_id;
    fifo* next;
};
struct arb{
    long address;
    int Page_id;
    unsigned int shiftRegister;
    arb* next;
};
struct wsarb{
    long address;
    int Page_id;
    unsigned int shiftRegister;
    arb* next;
};


class Linklist{
    public:
        Node* head;
        int len;
    public:

        Linklist(int Page_id);
        int check(int Page_id);
        void makedirty(int Page_id);
      //  void add(int Page_id,string s,int dirty);
      void add(int Page_id,string s);
        Node* remove(int Page_id);
       void update_Order(int Page_id);
        int pop_head();
        void add_head(int Page_id,string s);
        void remove_tail();
        void update_lru(int Page_id);
        int remove_back();
        Node* remove_least(unsigned int bit);
        Node* remove_sr(unsigned int min);
        Node* find(int Page_id);
        void set_num(int address,int sr_bit);
        void update(int bit);
        void print_list();
        void set_use_time(int Page_ids);
      };



class FIFO{
    public:
        int Page_size;
        int Page_id;
        int current_num;

        fifo* head;
        Linklist* fifo_list;

    public:
        FIFO(int Page_id);
        int paging(long address,string s,int* read_num,int* write_num);
};
unsigned int find_min(int num)
{

}

class LRU{
    public:
        int Page_size;
        int Page_id;
        int current_num;
        int used_time;
        lru* head;
        Linklist* lru_list;
    public:
        LRU(int Page_id);
        int paging(long address,string s,int* read_num, int* write_num);


};

class ARB{
    public:
      int Page_size;
      int Page_id;
      int current_num;
         int sr_bit;
        int interval;
        unsigned int shiftRegister;
        arb* head;
        Linklist* arb_list;


    public:
        ARB(int page_id,int sr_bit,int interval);
        int paging(long address,string s,int rs_bit,int* read_num, int* write_num);


};

/**LINKList structure FOR FIFO LRU ARB**/

Linklist::Linklist(int len)
{
  head = NULL;
  this->len = len;
}

int Linklist::check(int Page_id)
{
  Node* h=head;
  int i =0;
  while(h)
  {
    if(h->Page_id==Page_id)
    {
      return i;
    }
    i++;
    h=h->next;
  }
  return -1;
}

  void Linklist::print_list()
  {
      Node* h=head;
      while(h)
      {
      cout<<endl;
     cout<<" id "<<h->Page_id<<" ("<<h->shiftRegister<<") ";
           h=h->next;

      }

cout << endl;
  }

void Linklist::makedirty(int Page_id)
{
  Node* h;
  h=head;
  while(h)
  {
  if(h->Page_id == Page_id)
  {
    h->dirty=1;
//    break;
  }
  h=h->next;
  }
}

void Linklist::add(int Page_id,string s)
{
  if(head==NULL)
  {
    Node* temp = new Node();
    temp->next = NULL;
    temp->Page_id = Page_id;
  if(s.compare("W")==0)
  {
    temp->dirty=1;
  }else
  {
    temp->dirty=-1;
  }

    temp->shiftRegister = 0;
    head = temp;
    return ;
  }
  Node* h=head;
  //node指向最后一个
  while(h->next)
  {
    h=h->next;
  }


  Node* temp = new Node();
  temp->next = NULL;
  temp->Page_id = Page_id;
  if(s.compare("W")==0)
  {
    temp->dirty=1;
  }else
  {
    temp->dirty=-1;
  }

  temp->shiftRegister = 0;
  h->next = temp;
}

Node* Linklist::remove(int Page_id)
{
  Node* p,*q;

  if(head == NULL){
      return NULL;
  }


  if(head->Page_id  == Page_id ){
      p = head;
      head = p->next;

      return p;
  }


  p = head->next;
  q = head;

  while(p->next){
      if(p->Page_id  == Page_id ){
          break;
      }
      q = q->next;
      p = p->next;
  }

  q->next = p->next;

  return p;
}
//for fifo&...
void Linklist::set_use_time(int Page_ids)
{
  // Node*p;
  // p = head;
  // while(p){
  //     if(p->Page_id == Page_ids){
  //         p->used_time = p->used_time+1;
  //
  //     }
  //
  //     p = p->next;
  // }
}

void Linklist::update_Order(int Page_id)
{
  Node* p = head;
  Node* last_node = NULL;
       while(p){
           if(p -> Page_id == Page_id){
               Node* next_node = p -> next;
               p -> next = head;
               if(last_node){
                   last_node -> next = next_node;
               }head = p;
               break;
           }
           last_node = p;
           p = p -> next;
       }
}
int Linklist::pop_head()
{
  Node* h;
  if(head == NULL){
      return -1;
  }
  h = head->next;

  delete head;
  head = h;
  return 1;
}

//
int Linklist::remove_back()
{
  Node* h;
  if(head == NULL){
      return -1;
  }

  h = head;
  while(h->next){
      h = h->next;
  }

  delete h;

  return 1;
}

Node* Linklist::remove_least(unsigned int bit)
{
  char a[bit];
  a[0]='1';
  for(int i=1;i<bit;i++)
  {
    a[i]='0';
  }
  int x;
  x=atoi(a);
          unsigned int min=x;
           Node* p,*q;
           p = head;

           while(p){
             if(p->shiftRegister < min){
                 min = p->shiftRegister;
             }
               p = p->next;
           }


           p = head;
           q = p;
           //删除值最小的节点
           while(p){
               int tempMin =p->shiftRegister;
               if( tempMin == min){
                   q = p->next;

                   if(q == NULL){
                       return p;
                       break;
                   }
                   Node* pt = new Node();
                    pt->shiftRegister = p->shiftRegister;
                   pt->Page_id = p->Page_id;
                   pt->dirty = p->dirty;

                    p->shiftRegister = q->shiftRegister;
                   p->Page_id = q->Page_id;
                   p->dirty = q->dirty;
                   p->next = q->next;

                   delete q;
                   return pt;
               }else{
                   p = p->next;
               }
           }
           return NULL;


}
void Linklist::add_head(int Page_id,string s)
{
  // Node* new_node;
  // new_node->Page_id=Page_id;
  // Node* temp=head;
  // head=new_node;
  // head->next=temp;
}


void Linklist::remove_tail()
{
  // assert(NULL != head);
  // Node* h=head;
  // Node* last_node=NULL;
  // while(h)
  // {
  //   if(h->next==NULL)
  //   {
  //     h->Page_id=-1;
  //     if(last_node)
  //     last_node -> next = NULL;
  //     else{
  //                  head = NULL;
  //          }
  //   }
  //   last_node=h;
  //   h=h->next;
  // }
}
void Linklist::update_lru(int Page_id)
{
  // Node* h=head;
  // Node* last=NULL;
  // while(h)
  // {
  //   if(h->Page_id==Page_id)
  //   {
  //     Node* next_node=h->next;
  //     h->next=head;
  //     if(last){
  //       last->next=next_node;
  //     }head=h;
  //     break;
  //   }
  //   last=h;
  //   h=h->next;
  //}
}
//for arb
Node* Linklist::remove_sr(unsigned int min)
{

  Node *h;
  Node *n;
  h=head;
  while(h){
    if(h->shiftRegister<min)
    {
      min=h->shiftRegister;
    }
    h=h->next;
  }
  h=head;
  n=h;
  while(h){
    int temp=h->shiftRegister;
    if(temp == min){
      n=h->next;
      if(n==NULL)
      {
        return h;
        break;
      }
      Node* h_temp=new Node();
      h_temp->shiftRegister = h->shiftRegister;
      h_temp->Page_id = h->Page_id;
      h_temp->dirty = h->dirty;

      h->shiftRegister = n->shiftRegister;
      h->Page_id = n->Page_id;
      h->dirty = n->dirty;
      h->next = n->next;

      delete n;
      return h_temp;
    }else
    {
      h=h->next;
    }
  }
  return NULL;
}


//
Node* Linklist::find(int Page_id)
{
  Node* h;
  h=head;
  while(h)
  {
    if(h->Page_id==Page_id)
    {
      return h;
    }
    h=h->next;
  }
  return NULL;
}
//for resgister
  void Linklist::set_num(int address,int bit)
  {
    char a[bit];
    a[0]='1';
    for(int i=1;i<bit;i++)
    {
      a[i]='0';
    }
    int x;
    x=atoi(a);

    Node* p;
    p = head;

    while(p){
        if(p->Page_id == address){
            p->shiftRegister = p->shiftRegister | x;
        }

        p = p->next;
    }
  }


//for resgister
void Linklist::update(int bit)
{
string s="";

  for(int i=0;i<=bit;i++)
  {
    s+="1";
  }
//  int x;
//  x=atoi(a);
    int num = 0;
  for (int i = 0; i < s.length(); i++)
  {
      if (s[i] == '1')
      {
          num += pow(2,s.length()-i-1);
      }
  }
  Node* p;
  p = head;
  while(p){

        p->shiftRegister =(p->shiftRegister >> 1);
        p->shiftRegister = p->shiftRegister & num;
        p = p->next;
  }

}


FIFO::FIFO(int Page_id)
{
  this->Page_size=Page_size;
  this->Page_id=Page_id;
  this->current_num=0;
  this->head=NULL;
  this->fifo_list=new Linklist(Page_id);
}



/*对于fifo，建立一个queue，按照驻留内存的时间排序，
首最长，尾最短，当缺页的时候，选择链首置换，新页面加到尾部。
*/



int FIFO::paging(long address,string s,int* read_num, int* write_num)
{

    int num = fifo_list->check(address);
     if(s.compare("W") == 0)
     {
        fifo_list->makedirty(address);
      }
      if(num==-1)//意思是不zai内存
      {
    //    cout << "MISS:     page " << address << endl;

        if(current_num < Page_id)//还有空间直接写
        {

          //  fifo_list->add(address,s,0);
            fifo_list->add(address,s);
            this->current_num ++;
           (*read_num)++;
        }else{//内存不够，就需要替换

                if(fifo_list->head->dirty == 1)
                {
            //      cout << "REPLACE:  page " << fifo_list->head->Page_id << " (DIRTY)" << endl;
                    (*write_num) ++ ;
                }
                // else{
                // //    cout << "REPLACE:  page " << fifo_list->head->Page_id << endl;
                // }

            fifo_list->pop_head();//删掉第一个，因为第一个是最老的
        //    fifo_list->add(address,s,0);//加入，加到了队尾
        fifo_list->add(address,s);//加入，加到了队尾
      (*read_num) ++;
        }
    }else{
    //    cout << "HIT:      page " << address << endl;
        return 1;
    }
    return num;
}


/*对于lru，建立一个链表，按照最近一次访问时间排序，
首节点：刚刚用过的页面，
尾节点：醉酒未使用页面，
访问内存时，找到相应页面，并且把它移到首部，
缺页时，置换尾节点页面
*/


LRU::LRU(int Page_id)
{
  this->Page_size=Page_size;
  this->Page_id=Page_id;
  this->current_num=0;
  this->used_time=0;
    this->head=NULL;
  this->lru_list=new Linklist(Page_id);
}

/*对于fifo，建立一个queue，按照驻留内存的时间排序，
首最长，尾最短，当缺页的时候，选择链首置换，新页面加到尾部。
*/
/*对于lru，建立一个链表，按照最近一次访问时间排序，
首节点：刚刚用过的页面，
尾节点：最近未使用页面，
访问内存时，找到相应页面，并且把它移到首部，
缺页时缺页时，置换尾节点页面
*/



int LRU::paging(long address,string s,int* read_num, int* write_num){
  int num = lru_list->check(address);

   if(s.compare("W") == 0)
   {
      lru_list->makedirty(address);
    }
    if(num==-1)//意思是不在内存
  {
//  cout << "MISS:     page " << address << "  ";
      if(current_num < Page_id)//还有空间直接写
      {
          //lru_list->add(address,s,0);
                  lru_list->add(address,s);
          this->current_num ++;
         (*read_num)++;
}else{//内存不够，就需要替换


      //
     if(lru_list->head->dirty==1)
        {
        //      cout << "REPLACE:  page " << lru_list->head->Page_id << " (DIRTY)" << endl;
          (*write_num)++;

        }
        // else
        // {
        //     cout << "REPLACE:  page " << lru_list->head->Page_id << endl;
        // }
          lru_list->pop_head();
          //lru_list->add(address,s,0);
          lru_list->add(address,s);
            (*read_num) ++;


        //lru_list->remove_tail();



      }
  }else{//在内存
  //  cout << "HIT:      page " << address << endl;
       Node* temp2 = lru_list->find(address);
       int dirty_bit=temp2->dirty;
        Node* temp=lru_list->remove(address);
    //
      //  lru_list->add(address,s,0);
        lru_list->add(address,s);
        lru_list->find(address)->dirty=dirty_bit;


    // //  lru_list->update_lru(address);
  // lru_list->update_Order(address);
        return 1;

  }
  return num;
}

ARB::ARB(int Page_id,int sr_bit,int interval)
{


  this->Page_size=Page_size;
  this->Page_id=Page_id;
  this->current_num=0;
  this->sr_bit=sr_bit;
  this->interval=interval;
  this->head=NULL;
  this->arb_list=new Linklist(Page_id);
}
int ARB::paging(long address,string s,int rs_bit,int* read_num, int* write_num)
{

  int num = arb_list->check(address);

   if(s.compare("W") == 0)
   {
      arb_list->makedirty(address);
    }
    if(num == -1)//意思是不在内存
  {
// cout << "MISS:     page " << address << "  ";

      if(current_num < Page_id)//还有空间直接写
      {
          arb_list->add(address,s);
          arb_list->set_num(address,rs_bit);
          this->current_num ++;
         (*read_num)++;
}else{//内存不够，就需要替换

      Node* temp = arb_list->remove_least(rs_bit);
      //
      if(temp->dirty==1)
        {
      // cout << "REPLACE:  page " << temp->Page_id << " (DIRTY)" << endl;
          (*write_num)++;

        }
//         else
//         {
//           cout << "REPLACE:  page " << temp->Page_id << endl;
//
//         }
      arb_list->add(address,s);
      arb_list->set_num(address,rs_bit);


     (*read_num) ++;

      }
  }else{//在内存
  // cout << "HIT:      page " << address << endl;
    arb_list->set_num(address,rs_bit);

        return 1;
  }
  return num;
}

int reading_data(string line, string &type, long* address, int pageSize){
    string* s = new string[2];
    int len = strlen(line.c_str());
    char temp[len+1];
    line.copy(temp,len);
    temp[len] = '\0';

    char* p;
    p = strtok(temp," ");

    int i=0;
    while(p){
        if(strcmp(p,"#")==0){
            p = strtok(NULL," ");
            sscanf(p,"%ld",address);
            return 1;
        }
        s[i] = p;
        p = strtok(NULL," ");
        i++;

    }

    type = s[0];
    sscanf(s[1].c_str(),"%lx",address);

    long pageid = (long)((*address)/pageSize);
    *address = pageid;
    return 0;

}

int main(int argc,char * argv[])
{
//读取文件
//./PageReplacement input.txt 4096 32 WSARB 8 3 11
//./PageReplacement input.txt 4096 32 ARB 3 3
//a [1,8] b [1,10] r[1,20]
ifstream file(argv[1]);

string here=argv[2];
int page_size=atoi(here.c_str());
here=argv[3];
int page_memory=atoi(here.c_str());
string algroithm =argv[4];
int argc_num;
argc_num = argc;
int totalEvent = 0;
int read_num = 0;
int write_num = 0;
int pageFaults = 0;
int sr_num=0;
int interval_num=0;
int working_set_num=0;

if(argc_num==7)
{
here=argv[5];
sr_num=atoi(here.c_str());
here=argv[6];
interval_num=atoi(here.c_str());
}else if(argc_num==8)
{
  here=argv[5];
  sr_num=atoi(here.c_str());
  here=argv[6];
  interval_num=atoi(here.c_str());
  here=argv[7];
  working_set_num=atoi(here.c_str());
}



if(algroithm == "FIFO")
{
    FIFO fifo_alg(page_memory);
     string line;
     string type = "0";
     long address = 0 ;
     while(getline(file,line)){

         int flag = reading_data(line,type,&address,page_size);

         if(flag == 1){
             continue;
         }
         totalEvent ++;
           int f = fifo_alg.paging(address,type,&read_num,&write_num);

           if(f == -1){
               pageFaults ++;
           }

       }
}else if(algroithm == "LRU")
{
        LRU lru_alg(page_memory);
          string line;
          string type = "0";
          long address = 0 ;


          while(getline(file,line)){


              int flag = reading_data(line,type,&address,page_size);
              if(flag == 1){
                  continue;
              }

              totalEvent ++;
            int f = lru_alg.paging(address,type,&read_num,&write_num);
          if(f == -1){
                pageFaults ++;
           }

          }
}else if(argc_num ==7||algroithm=="ARB")
{
  ARB arb_alg(page_memory,sr_num,interval_num);
  string line;
  string type = "0";
  long address = 0 ;
  int timer = 0;
  while(getline(file,line)){

  int flag = reading_data(line,type,&address,page_size);

      if(flag == 1){
          continue;
      }
      timer ++;
      totalEvent ++;
      int f=arb_alg.paging(address,type,sr_num,&read_num,&write_num);
      //arb_alg.arb_list->print_list();
      if(f == -1){
          pageFaults ++;
      }
      if(timer == interval_num){
          arb_alg.arb_list->update(sr_num);
          timer = 0;
      }
    }

}else if(argc_num ==8||algroithm=="WSARB")
{
  ARB arb_alg(page_memory,sr_num,interval_num);
  string line;
  string type = "0";
  long address = 0 ;
  int timer = 0;
  while(getline(file,line)){

  int flag = reading_data(line,type,&address,page_size);

      if(flag == 1){
          continue;
      }
      timer ++;
      totalEvent ++;
      int f=arb_alg.paging(address,type,sr_num,&read_num,&write_num);
      if(f == -1){
          pageFaults ++;
      }
      if(timer == interval_num){
          arb_alg.arb_list->update(sr_num);
          timer = 0;
      }
    }


}


cout << "events in trace:    "<<totalEvent << endl;
cout << "total disk reads:   " << read_num << endl;
cout << "total disk writes:  " << write_num <<endl;
cout << "page faults:        " << pageFaults << endl;
return 0;
}
