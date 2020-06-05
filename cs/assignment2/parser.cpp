// convert Hack Assembly Language into an abstract syntax tree
#include "ast.h"

// to make out programs a bit neater
using namespace std ;

// the tokeniser being used
static tokeniser the_tokeniser = nullptr ;

// the current token being read 
static Token token ;

// function to read the next token
static void next_token()
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
    if ( token.kind != expected ) fatal_error() ;
    next_token() ;
}


// grammer to be parsed:
// a_program ::= instruction* eoi
// instruction ::= label | a_instr_name | a_instruction | c_instruction
// c_instruction ::= [c_destination equals] c_alu_op [ semi c_jump]
// c_alu_op ::= register | aluop
// c_destination ::= null | dest | register
// c_jump ::= null | jump

// forward declare parsing functions - one per rule
an_program parse_program() ;
an_instruction parse_instruction() ;
an_label parse_label() ;
an_a_instr_name parse_a_instr_name() ;
an_a_instruction parse_a_instruction() ;
an_c_instruction parse_c_instruction() ;

// Note: always read one token after the one recognised

// a_program ::= instruction* eoi
an_program parse_program()
{
    an_program the_program = an_program_create() ;

    // we stop when we see the EOI token
    // this may be end of input or an error
    // we cannot tell so treat both as end of input
    // every new assembler instruction we find is appended to the_program
    while ( token.kind != ak_eoi )
    {
        the_program->append(parse_instruction()) ;
        // this call to next_token must be removed when the parsing functions start reading their own tokens
       //    next_token() ;
    }


    return the_program ;
}

/*****************   REPLACE THE FOLLOWING CODE  ******************/

// a_program ::= instruction* eoi
an_instruction parse_instruction()
{
    // inspect the token to see what it might start
    switch(token.kind)
    {
    case ak_label:
        return to_an_instruction(parse_label()) ;
    case ak_address:
        if ( token.token == ak_name )
        {
            return to_an_instruction(parse_a_instr_name()) ;
        }
        return to_an_instruction(parse_a_instruction()) ;
    case ak_dest:
    case ak_register:
    case ak_alu_op:
    default:
        return to_an_instruction(parse_c_instruction()) ;
    }
}

// label is a primitive token for '(' label ')'
an_label parse_label()
{
    // ...
   string label = token.spelling ;
    next_token();
   an_label lab= an_label_create(label);
    return lab;
 
}

// special case for '@' name
an_a_instr_name parse_a_instr_name()
{
    // ...
 string name = token.spelling ; 
   next_token();
    an_a_instr_name ainstr=an_a_instr_name_create(name);
   return ainstr;

}

// special case for '@' number
an_a_instruction parse_a_instruction()
{
    // ...
string number = token.spelling;
next_token();
an_a_instruction ainstrn=an_a_instruction_create(number);
return ainstrn;

}

// c_instruction ::= [c_destination equals] c_alu_op [ semi c_jump]
an_c_instruction parse_c_instruction()
{

    string alu_op;
    string dest;
    string jump;
    
  if(token.kind== ak_alu_op | token.kind==ak_register|token.kind==ak_dest)
  {
    alu_op =token.spelling;
    dest=  token.spelling;
    next_token();
  
  if(token.kind ==ak_assign)
  {
   next_token();
   alu_op =token.spelling;
  }
  else if(token.kind ==ak_semi)
  {
    dest="NULL";
  }
}
    next_token();
if(token.kind==ak_jump)
{
    jump=token.spelling;
    next_token();
}
else
{
    jump="NULL";
}
an_c_instruction cinstr=an_c_instruction_create(alu_op,dest,jump);
return cinstr;
}

/*****************        DOWN TO HERE         ******************/


// main program
int main(int argc,char **argv)
{ 
    // initialise the tokeniser by reading the first token
    the_tokeniser = a_tokeniser() ;
    next_token() ;

    // parse a class and print the abstract syntax tree as XML
    an_print_as_xml(parse_program(),4) ;

    // flush the output and any errors
    print_output() ;
    print_errors() ;
}

