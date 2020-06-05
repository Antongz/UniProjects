#include<iostream>
#include <sstream>
using namespace std;


class avltree
{
public:

    int data;
    struct avltree *left;
    struct avltree *right;
    int height;
    

    avltree* getmin(avltree* pnode);
    avltree* getmax(avltree* pnode);
    int getheight(avltree *pnode);
    int getBalance(avltree *balancenode);
    
    avltree *RR(avltree *nodeC);
    avltree *LR(avltree *nodeC);;

    avltree* insertpnode(avltree* pnode, int value);
    avltree* deletepnode(avltree* root, int value);
   
    void pre_order(avltree *root);
    void post_order(avltree *root);
    void in_order(avltree *root);
};



int avltree::getheight(avltree *pnode)
{
    if (pnode != NULL)
         return pnode -> height;
        return 0;
}



avltree* avltree::RR(avltree *nodeC)
{
  
    avltree *rootA = nodeC->left;
    avltree *rootB = rootA->right;

    rootA->right = nodeC;
    nodeC->left = rootB;
    
   nodeC->height = max(getheight(nodeC->left), getheight(nodeC->right))+1;
    rootA->height = max(getheight(rootA->left), getheight(rootA->right))+1;

    return rootA;
}


avltree*avltree::LR(avltree *nodeC)
{

    avltree *rootA = nodeC->right;
    avltree *rootB = rootA->left;

    rootA->left = nodeC;
    nodeC->right = rootB;

    nodeC->height = max(getheight(nodeC->left), getheight(nodeC->right))+1;
    rootA->height = max(getheight(rootA->left), getheight(rootA->right))+1;

    return rootA;
}


int avltree::getBalance(avltree *balancenode)
{
    if (balancenode == NULL)
        return 0;
    return getheight(balancenode->left) - getheight(balancenode->right);
}


avltree* avltree::insertpnode(avltree* pnode, int value)
{
    if (pnode == NULL)
    {
    avltree* pnode = new avltree;
    pnode->data = value;
    pnode->left = NULL;
    pnode->right = NULL;
    pnode->height = 1;

    return(pnode);
    }
    
    if (value < pnode->data)
      
        pnode->left = insertpnode(pnode->left, value);
  
    else if (value > pnode->data)

        pnode->right = insertpnode(pnode->right, value);
    else
        return pnode;
    
  
    pnode->height = 1 + max(getheight(pnode->left),getheight(pnode->right));

    int balance = getBalance(pnode);


    if (balance > 1 && value < pnode->left->data)
        return RR(pnode);

    if (balance < -1 && value > pnode->right->data)
        return LR(pnode);
 
    if (balance > 1 && value > pnode->left->data)
    {
        pnode->left = LR(pnode->left);
        return RR(pnode);
    }
    

    if (balance < -1 && value < pnode->right->data)
    {
        pnode->right = RR(pnode->right);
        return LR(pnode);
    }

    return pnode;
}


avltree * avltree::getmin(avltree* pnode)
{
    avltree* nodeD = pnode;

    while (nodeD->left != NULL)
       nodeD = nodeD->left;

    return nodeD;
}

avltree * avltree::getmax(avltree* pnode)
{
    avltree* nodeD = pnode;
    
    while (nodeD->right != NULL)
        nodeD = nodeD->right;
        return nodeD;
}

avltree* avltree::deletepnode(avltree* root, int value)
{

    if (root == NULL)
        return root;
    

    if ( value < root->data )
        root->left = deletepnode(root->left, value);
    
    else if( value > root->data)
        root->right = deletepnode(root->right, value);

    else
    {
        
       
        if( (root->left == NULL) || (root->right == NULL) )
        {
            avltree *nodeC = root ->left?root->left:root->right;
         
            
            if (nodeC == NULL)
            {
                nodeC = root;
                root = NULL;
            }
         
            else
            {
             *root = *nodeC;
             free(nodeC);
            }
        }
        else
        {
            avltree* nodeC = getmax(root->left);

            root->data = nodeC->data;
    
            root->left = deletepnode(root->left, nodeC->data);
        }
    }
 
    if (root == NULL)
        return root;

    root->height = 1 + max(getheight(root->left), getheight(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return RR(root);

    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = LR(root->left);
        return RR(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return LR(root);
   
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = RR(root->right);
        return LR(root);
    }
    
    return root;
}

void avltree::pre_order(avltree *root)
{

    if(root != NULL)
    {
        cout<<root->data<<" ";
        pre_order(root->left);
        pre_order(root->right);
        
    }
}


void avltree::post_order(avltree *root)
{

    if(root != NULL)
    {
        
        post_order(root->left);
        post_order(root->right);
          cout<<root->data<<" ";
 
    }
}



void avltree::in_order(avltree *root)
{

    if (root != NULL)
    {

        in_order(root->left);
        cout<<root->data<<" ";
        in_order(root->right);
    }
}
int main()
{
    avltree *Root = NULL;
    string line;
    int num;
    getline(cin,line);
    
    
    for(int i=0;i<line.length();i++)
    {
        
        if(line.at(i)=='A')
        {
            int pos2 = line.find(" ");
            string s=line.substr(i+1,pos2);
            
            num=stoi(s);
            
            Root=Root->insertpnode(Root,num);

        }  else if(line.at(i) == 'D')
            
        {

            int pos2 = line.find(" ");
            string s=line.substr(i+1,pos2);
            num=stoi(s);

            Root=Root->deletepnode(Root,num);

            
        }
        else if(line.at(i) == 'I')
            
        {
            
            if(Root == NULL)
                
            cout<<"\n EMPTY";
            
            Root->in_order(Root);
            
        }
        
        
        
        else if(line.at(i) == 'P' )
            
        {
            
            
            if(line.at(i+1) == 'R')
                
            {
                
                if(Root == NULL)
                    
                    cout<<"\n EMPTY";
                
                Root->pre_order(Root);
                
            }
            
            else if(line.at(i+1) == 'O')
                
            {
                
                if(Root == NULL)
                    cout<<"\n EMPTY";
                
                Root->post_order(Root);
                
            }
            
        }
        
        else if(line.at(i) == ' ')
            ;
        
    }
    return 0;
    
}





