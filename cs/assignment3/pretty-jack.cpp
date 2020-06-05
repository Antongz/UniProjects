#include "ast.h"


//declare function
void jack_var_decs(jn_var_decs t) ;
void jack_var_dec(jn_var_dec t) ;
void jack_subr_decs(jn_subr_decs t) ;
void jack_subr_dec(jn_subr t) ;
void jack_param_list(jn_param_list t) ;
void jack_subr_body(jn_subr_body t) ;
void jack_statements(jn_statements t) ;
void jack_statement(jn_statement t);
void jack_let(jn_let t) ;
void jack_if(jn_if t) ;
void jack_while(jn_while t) ;
void jack_call(jn_call t) ;
void jack_do(jn_do t) ;
void jack_return(jn_return t) ;
void jack_int(jn_int t) ;
void jack_string(jn_string t) ;
void jack_bool(jn_bool t) ;
void jack_array_index(jn_array_index t) ;
void jack_unary_op(jn_unary_op t) ;
void jack_infix_op(jn_infix_op t) ;
void jack_var(jn_var t) ;
void jack_expr(jn_expr t) ;
void jack_expr_list(jn_expr_list t) ;
void jack_function(jn_subr t);

//jack pretty class
void jack_pretty(jn_class t)
{
     string n=t->class_name;
     write_to_output("class "+n+"\n{");
     jack_var_decs(t->decs) ;
      jack_subr_decs(t->subrs) ;
      write_to_output("}\n");
}

//var decs
void jack_var_decs(jn_var_decs t)
 {
     int num=t->size();
     for(int i=0;i<num;i++)
     {
         jn_var_dec dec=t->get(i);
         jack_var_dec(dec) ;
     }
  }
//subr decs
void jack_subr_decs(jn_subr_decs t)
{
    int num=t->size();
    for(int i=0;i<num;i++)
    {
      
    jn_subr subr=t->get(i);
        
    switch(ast_kind_of(subr))
        {
            case k_jn_function:
            jack_function(to_jn_function(subr));
                break;
        }
    }
}
//var dec
void jack_var_dec(jn_var_dec t)
{
    write_to_output("\n");
    write_to_output("        var "+t->type+" "+t->name);
    write_to_output(" ;");
    
}
//function pretty
void jack_function(jn_subr t)
{
    string vtype=t->vtype;
    string name=t->name;
    jn_param_list params;
   
    write_to_output("\n    function "+vtype+" Main."+name+"()"+"\n    {");
    jack_subr_body(t->body);
     write_to_output("\n    }\n");
}
//statements
void jack_statements(jn_statements t)
{
    int num=t->size();
    for(int i=0;i<num;i++)
    {
        
        jn_statement state=t->get(i);
        
        switch(ast_kind_of(state))
        {
            case k_jn_return:
                jack_return(to_jn_return(state));
                break;
            case k_jn_while:
                jack_while(to_jn_while(state)) ;
                break;
        }
    }
    
}
//while
void jack_while(jn_while t)
{
   
    jack_statements(t->body);
}
//return
void jack_return(jn_return t)
{
     write_to_output("\n        return ;");
}
//subr body
void jack_subr_body(jn_subr_body t)
{
    
    jack_var_decs(t->decs);
 
    jack_statements(t->body);
    
}

int main(int argc,char **argv)
{
    // parse an AST in XML and pretty print as Jack
    jack_pretty(jn_parse_xml()) ;

    // flush the output and any errors
    print_output() ;
    print_errors() ;
}

