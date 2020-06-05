#include "ast.h"
using namespace std ;


//declare function
void codegen_var_decs(jn_var_decs t) ;
void codegen_var_dec(jn_var_dec t) ;
void codegen_subr_decs(jn_subr_decs t) ;
void codegen_subr_dec(jn_subr t) ;
void codegen_param_list(jn_param_list t) ;
void codegen_subr_body(jn_subr_body t) ;
void codegen_statements(jn_statements t) ;
void codegen_statement(jn_statement t) ;
void codegen_function(jn_function t);
void codegen_let(jn_let t) ;
void codegen_if(jn_if t) ;
void codegen_if_else(jn_if_else t);
void codegen_while(jn_while t) ;
void codegen_call(jn_call t) ;
void codegen_do(jn_do t) ;
void codegen_return(jn_return t) ;
void codegen_int(jn_int t) ;
void codegen_string(jn_string t) ;
void codegen_bool(jn_bool t) ;
void codegen_array_index(jn_array_index t) ;
void codegen_unary_op(jn_unary_op t) ;
void codegen_infix_op(jn_infix_op t) ;
void codegen_var(jn_var t) ;
void codegen_expr(jn_expr t) ;
void codegen_expr_list(jn_expr_list t) ;
void codegen_function(jn_function t);


//declare variable
static string classname;
static int varnum; 
static int vardecnum;
static int whilenum=0;
static int ifnum=0;
static int ifelsenum=0;
//vardecs
void codegen_var_decs(jn_var_decs t) 
{   
    varnum=0;    
   int num=t->size();
   for(int i=0;i<num;i++)
     {
         jn_var_dec dec=t->get(i);
         codegen_var_dec(dec) ;
         
     }
   varnum=num;
}
//var dec
void codegen_var_dec(jn_var_dec t) 
{
    
}
//subr decs
void codegen_subr_decs(jn_subr_decs t) 
{
    int num=t->size();

    for(int i=0;i<num;i++)
    {
      
    jn_subr subr=t->get(i);
        
    switch(ast_kind_of(subr))
        {
            case k_jn_function:
           codegen_function(to_jn_function(subr));

        }
    }
}
//function
void codegen_function(jn_function t)
{
   
    cout<<"function"<<" Main."<<t->name<<" "<<t->body->decs->size()<<endl;
    codegen_param_list(t->params);
     codegen_subr_body(t->body) ;
    
   
}
//return
void codegen_return(jn_return t) 
{
       cout<<"push constant 0"<<endl;
    cout<<"return"<<endl;
}
//subr body
void codegen_subr_body(jn_subr_body t) 
{
 
   codegen_var_decs(t->decs) ;

   codegen_statements(t->body) ;
  

}
//if
void codegen_if(jn_if t) 
{
    int ifn=ifnum;
      ifnum++;
     codegen_expr(t->cond);
    
     cout<<"if-goto IF_TRUE"<<ifn<<endl;
     cout<<"goto IF_FALSE"<<ifn<<endl;
     cout<<"label IF_TRUE"<<ifn<<endl;
     cout<<"label IF_FALSE"<<ifn<<endl;

 
}
//if else
void codegen_if_else(jn_if_else t)
{
     int ifn=ifnum;
     ifnum++;
     codegen_expr(t->cond); 
     cout<<"if-goto IF_TRUE"<<ifn<<endl;
     cout<<"goto IF_FALSE"<<ifn<<endl;
     cout<<"label IF_TRUE"<<ifn<<endl;
      codegen_statements(t->if_true); 
     cout<<"goto IF_END"<<ifn<<endl;
     cout<<"label IF_FALSE"<<ifn<<endl;
     codegen_statements(t->if_false); 
     cout<<"label IF_END"<<ifn<<endl;
    
}
//array index
void codegen_array_index(jn_array_index t) 
{
    cout<<t->var<<"where"<<endl;
    cout<<t->index<<endl;
}
//while
void codegen_while(jn_while t) 
{
     int storenum;
     storenum=whilenum;
      whilenum++;
    cout<<"label WHILE_EXP"<<storenum<<endl;
    codegen_expr(t->cond);
    cout<<"not"<<endl;
    cout<<"if-goto WHILE_END"<<storenum<<endl;
    codegen_statements(t->body);
    cout<<"goto WHILE_EXP"<<storenum<<endl;
    cout<<"label WHILE_END"<<storenum<<endl;
   
}
//let
void codegen_let(jn_let t) 
{
    codegen_var(t->var) ;
    codegen_expr(t->expr);
}
//bool
void codegen_bool(jn_bool t) 
{
    if(t->tf)
    {
      cout<<"push constant 0"<<endl;
       cout<<"not"<<endl;
    }else
    {
      cout<<"push constant 0"<<endl;
    }
}
void codegen_int(jn_int t)
{
    cout<<"push constant"<<t->ic<<endl;
}
//expr
void codegen_expr(jn_expr t) 
{

   switch(ast_kind_of(t))
   {
   case k_jn_bool:
   codegen_bool(to_jn_bool(t)) ;
   break;
   case k_jn_array_index:
    codegen_array_index(to_jn_array_index(t));
    break;
    case k_jn_var:
    codegen_var(to_jn_var(t));
    break; 
    case k_jn_int:
    codegen_int(to_jn_int(t));
    break;
    case k_jn_infix_op:
    codegen_infix_op(to_jn_infix_op(t));
    break;
   }
    
}
//var
void codegen_var(jn_var t) 
{

    cout<<"push"<<" "<<t->segment<<" "<<1<<endl;
    
}

//param list
void codegen_param_list(jn_param_list t) 
{
    int num=t->size();
    for(int i=0;i<num;i++)
    {
      vardecnum++;
   jn_var_dec vardec=t->get(i);
     codegen_var_dec(vardec) ;
   
    }
}
//statements
void codegen_statements(jn_statements t) 
{
    int num=t->size();
    for(int i=0;i<num;i++)
    {
      
    jn_statement body=t->get(i);

    switch(ast_kind_of(body))
        {
            case k_jn_while:
            codegen_while(to_jn_while(body)) ;
            break;
           case k_jn_return:
           codegen_return(to_jn_return(body));
            break;
            case k_jn_if:
            codegen_if(to_jn_if(body));
            break;
            case k_jn_if_else:
            codegen_if_else(to_jn_if_else(body));
            break;
            case k_jn_let:
            codegen_let(to_jn_let(body));
            break; 
           


        }
    }
}
//infix op
void codegen_infix_op(jn_infix_op t) 
{
    codegen_expr(t->lhs);
    string s=t->op;
    if(s=="+")
    {
        cout<<"add"<<endl;
    }
   
    codegen_expr(t->rhs);
}
//class
void codegen_codegen(jn_class t)
{
   classname=t->class_name;
   codegen_var_decs(t->decs) ;
   codegen_subr_decs(t->subrs);

}
int main(int argc,char **argv)
{
    // parse an AST in XML and print VM code
    codegen_codegen(jn_parse_xml()) ;

    // flush the output and any errors
    print_output() ;
    print_errors() ;
}

