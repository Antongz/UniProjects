#include "ast.h"
#include <string>
#include <iostream>
using namespace std;
static tokeniser the_tokeniser = nullptr ;

// the current token being read
static Token token ;

// function to read the next token
static void nextToken()
{
    token = the_tokeniser->next_token() ;
}

// for all syntax errors - do not report an error just die!
static void *fatal_error()
{
    exit(0) ;
}

// token must be expected, if it is then read next token otherwise it is a fatal error
static void mustbe(TokenKind expected)
{
     if ( expected != token.token ) fatal_error() ;
     nextToken();
}
static bool have(TokenKind expected)
{
    if ( expected != token.token )
    return false ;
    nextToken() ;
    return true ;
}

//declare the create function's var
static string class_name;
static string vtype;
static string function_name;
static string method_name;
static string segment;
static string name;
static int offset=0;
static string type;
jn_var var;
jn_expr expr;
jn_let letp=jn_let_create(var,expr);
jn_return returnp =jn_return_create();
// forward declare parsing functions - one per rule


jn_var_decs vardecs_parser();
jn_var_decs bodyvardecs_parser();
jn_var_dec vardec_parser();
jn_subr_decs subr_decs_parser();
jn_subr subr_parser();
jn_subr constructor_parser();
jn_subr function_parser();
jn_subr method_parser();
jn_param_list param_list_parser();
jn_subr_body subr_body_parser();
jn_statements statements_parser();
jn_statement statement_parser();
jn_let let_parser();
jn_let_array let_array_parser();
jn_if if_parser();
jn_if_else if_else_parser();
jn_while while_parser();
jn_do do_parser();
//jn_return return_parser();
jn_return_void return_void_parser();
jn_return_expr return_expr_parser();
jn_expr expr_parser();
jn_int int_parser();
jn_string string_parser();
jn_bool bool_parser();
jn_null null_parser();
jn_this this_parser();
jn_var var_parser();
jn_array_index array_index_parser();
jn_unary_op unray_op_parser();
jn_infix_op infix_ip_parser();
jn_call call_parser();
jn_subr_call subr_call_parser();
jn_method_call method_call_parser();


//var decs
jn_var_decs bodyvardecs_parser()

{
  jn_var_decs vardecsp2 = jn_var_decs_create();

    mustbe(jk_lcb);
    
    while(have(jk_var)){
    vardecsp2->append(vardec_parser());
    }
     nextToken();
    return vardecsp2;
}
//var decs
jn_var_decs vardecs_parser()
{
    jn_var_decs vardecsp = jn_var_decs_create();
    nextToken();
    return vardecsp;
}
//sub body decs
jn_subr_decs subr_decs_parser()
{
   
  jn_subr_decs subr_decsp = jn_subr_decs_create();
    // nextToken();
    if(token.kind==jk_keyword)
    {
    switch(token.token)
    {
        case jk_function:
      
            subr_decsp->append(function_parser());
            break;
    
        case jk_constructor:
            
            subr_decsp->append(method_parser());
            break;
        case jk_method:
          
            subr_decsp->append(function_parser());
            break;
        default:
            subr_decsp->append(function_parser());
          
            break;
    }
    }

     nextToken();

    return subr_decsp;
}
//function parser
jn_subr function_parser()
{
   

    vtype=token.spelling;
    
    nextToken();

    function_name=token.spelling;

    mustbe(jk_identifier);

    mustbe(jk_lrb);

    jn_param_list params =param_list_parser();

    jn_subr_body body=subr_body_parser();
   
    jn_function function =jn_function_create(vtype,function_name,params,body);
    
    jn_subr subr_function;
    subr_function = to_jn_subr(function);

    nextToken();
    return subr_function;
  
}
//method parser
jn_subr method_parser()
{
    vtype=token.spelling;
    
    nextToken();
    
   method_name=token.spelling;

    mustbe(jk_identifier);

    mustbe(jk_lrb);
    
    jn_param_list params =param_list_parser();
    
    jn_subr_body body=subr_body_parser();
    
    jn_method method =jn_method_create(vtype,method_name,params,body);
    
    jn_subr subr_method;
    subr_method = to_jn_subr(method);
    
    nextToken();
    return subr_method;
    
}

//var dec
jn_var_dec vardec_parser()
{
   

    
    segment="local";

    type=token.spelling;
   
    nextToken();
    name=token.spelling;
    jn_var_dec var_dec=jn_var_dec_create(segment,name,offset,type);
    nextToken();
    mustbe(jk_semi);
    offset++;
    return var_dec;
 
  
}
jn_param_list param_list_parser()
{
    jn_param_list param_listp=jn_param_list_create();
    nextToken();
    return param_listp;
}
//statements
jn_statements statements_parser()
{
    nextToken();
    
    jn_statements statementp= jn_statements_create() ;
  
    statementp->append(statement_parser());

    return  statementp;
}
//statment
jn_statement statement_parser()
{
    nextToken();
    
        jn_return returnp =jn_return_create();
        return to_jn_statement(returnp);

  while(have(jk_let))
            {
               return  to_jn_statement(letp);
            }
}
//return statement
//jn_return return_parser()
//{
//    nextToken();
//
//    return returnp;
//}
//subr body
jn_subr_body subr_body_parser()
{
    jn_var_decs var_decsp = bodyvardecs_parser();
    jn_statements statsp = statements_parser();
    nextToken();
 
    return jn_subr_body_create(var_decsp,statsp);
}
//main function
jn_class jack_parser()
{
    
    mustbe(jk_class);
    class_name=token.spelling;
    mustbe(jk_identifier);
     mustbe(jk_lcb);
    jn_var_decs decs = vardecs_parser();
   jn_subr_decs subrs = subr_decs_parser();
    nextToken();
    return jn_class_create(class_name, decs, subrs);

}


int main(int argc,char **argv)
{
    the_tokeniser=j_tokeniser();
    nextToken();
    // parse a class and print the abstract syntax tree as XML
    jn_print_as_xml(jack_parser(),4) ;

    // flush the output and any errors
    print_output() ;
    print_errors() ;
}

