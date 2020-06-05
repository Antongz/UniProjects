// convert an abstract syntax tree for Hack Assembly language into machine code
#include "ast.h"
#include "symbols.h"
#include <bitset>
#include <iostream>
#include <stdlib.h>
#include <string>

// to make out programs a bit neater
using namespace std ;
static int loc=0;         //location counter
static int nextvar=16;   //next variable
//create symbol table
//create symbol table with int value
static symbol_table_int symtable ;
//create symbol table with string value
static symbol_table_string dest ;
static symbol_table_string alu_op;
static symbol_table_string jump;
static symbol_table_int label;


static void symbol_table()
{
    //create symbol table
    label = create_symbol_table_int();
    symtable = create_symbol_table_int() ;
    dest=create_symbol_table_string();
    alu_op=create_symbol_table_string();
    jump=create_symbol_table_string();
    
    //for symbol table int value
    symtable->insert("SP",0) ;
    symtable->insert("LCL",1) ;
    symtable->insert("ARG",2);
    symtable->insert("THIS",3);
    
    symtable->insert("R0",0) ;
    symtable->insert("R1",1) ;
    symtable->insert("R2",2) ;
    symtable->insert("R3",3) ;
    symtable->insert("R4",4) ;
    symtable->insert("R5",5) ;
    symtable->insert("R6",6) ;
    symtable->insert("R7",7) ;
    symtable->insert("R8",8) ;
    symtable->insert("R9",9) ;
    symtable->insert("R10",10) ;
    symtable->insert("R11",11) ;
    symtable->insert("R12",12) ;
    symtable->insert("R13",13) ;
    symtable->insert("R14",14) ;
    symtable->insert("R15",15) ;
    symtable->insert("SCREEN",16384);
    symtable->insert("KBD",24576);
    
    //for symbol table dest string value
    dest->insert("NULL","000");
    dest->insert("M","001");
    dest->insert("D","010");
    dest->insert("MD","011");
    dest->insert("A","100");
    dest->insert("AM","101");
    dest->insert("AD","110");
    dest->insert("AMD","111");
    
    //for symbol table alu_op string value
    alu_op->insert("0","0101010");
    
    alu_op->insert("1","0111111");
    alu_op->insert("-1","0111010");
    alu_op->insert("D","0001100");
    alu_op->insert("A","0110000");
    alu_op->insert("!D","0001101");
    alu_op->insert("!A","0110001");
    alu_op->insert("-D","0001111");
    alu_op->insert("-A","0110011");
    alu_op->insert("D+1","0011111");
    alu_op->insert("A+1","0110111");
    alu_op->insert("D-1","0001110");
    alu_op->insert("A-1","0110010");
    alu_op->insert("D+A","0000010");
    alu_op->insert("D-A","0010011");
    alu_op->insert("A-D","0000111");
    alu_op->insert("D&A","0000000");
    alu_op->insert("D|A","0010101");
    alu_op->insert("M","1110000");
    alu_op->insert("!M","1110001");
    alu_op->insert("-M","1110011");
    alu_op->insert("M+1","1110111");
    alu_op->insert("M-1","1110010");
    alu_op->insert("D+M","1000010");
    alu_op->insert("D-M","1010011");
    alu_op->insert("M-D","1000111");
    alu_op->insert("D&M","1000000");
    alu_op->insert("D|M","1010101");
    //for symbol table for jump
    jump->insert("NULL","000");
    jump->insert("JGT","001");
    jump->insert("JEQ","010");
    jump->insert("JGE","011");
    jump->insert("JLT","100");
    jump->insert("JNE","101");
    jump->insert("JLE","110");
    jump->insert("JMP","111");
    
    
    
}

//translation function for label
static void translate_label(an_label t)
{
    if(label->lookup(t->label)!= -1) fatal_error(0,"");
     label->insert(t->label,loc);
     string bin = bitset<16>(loc).to_string();

}
 


//translation function for A instruction name
static void translate_a_instr_name(an_a_instr_name t)
{
    
    int result =symtable->lookup(t->name);
    int res=label->lookup(t->name);

     if(res !=-1 && result ==-1)
   {
       string bin = bitset<16>(res).to_string();
       write_to_output(bin+"\n");
   
   }
     else if (res == -1 && result== -1)
    {
        symtable->insert(t->name,nextvar);
        string bin = bitset<16>(nextvar).to_string();
        write_to_output(bin+"\n");
        nextvar++;
    }
 
    
    else {
        
        string bin = bitset<16>(result).to_string();
        write_to_output(bin+"\n");
      
    }
}

    

//translation function for A instruction number
static void translate_an_a_instruction(an_a_instruction t)
{
    
    int num= atoi((t->number).c_str());
    string s=bitset<15>(num).to_string();
    write_to_output('0'+s+"\n");
    
}
//translation function for C instruction
static void translate_an_c_instruction(an_c_instruction t)
{
    //if the jump is null
    if(t->jump=="NULL")
    {
        write_to_output("111"+alu_op->lookup(t->alu_op)+dest->lookup(t->dest)+"000"+"\n");
    }else
    {
        write_to_output("111"+alu_op->lookup(t->alu_op)+"000"+jump->lookup(t->jump)+"\n");
    }
    
}



// the function asm_translator() is passed the abstract syntax tree constructed
// by an_parse_xml(), it walks the abstract syntax tree and produces the equivalent
// Hack machine code as output
void asm_translator(an_program the_program)
{
    symbol_table();
    // the_program contains a vector of instructions - translate them one at a time
    int ninstructions = the_program->size() ;
    //first pass
    for ( int i = 0 ; i < ninstructions ; i++ )
    {
        
        an_instruction instruction = the_program->get(i) ;
        
        switch(ast_kind_of(instruction))
        {
            case k_an_label:
                
                translate_label(to_an_label(instruction));
                
                break ;
            case k_an_a_instr_name:
               
            case k_an_a_instruction:
                //loc++;
                //break;
            case k_an_c_instruction:
                loc++;
                break ;
                
            default:
                
                write_to_errors("// bad node - expected an-label,an-a-instr-name,an-a-instruction or an-c-instruction\n") ;
                break ;
        }
        //loc++;
    }
    
    //second pass
    for ( int i = 0 ; i < ninstructions ; i++ )
    {
        
        an_instruction instruction = the_program->get(i) ;
        switch(ast_kind_of(instruction))
        {
            case k_an_label:
                break ;
            case k_an_a_instr_name:
                
                translate_a_instr_name(to_an_a_instr_name(instruction));
                break ;
            case k_an_a_instruction:
                
                translate_an_a_instruction(to_an_a_instruction(instruction));
                break ;
            case k_an_c_instruction:
                
                translate_an_c_instruction(to_an_c_instruction(instruction));
                break ;
            default:
                write_to_errors("// bad node - expected an-label,an-a-instr-name,an-a-instruction or an-c-instruction\n") ;
                break ;
        }
    }
}


// main program
int main(int argc,char **argv)
{
    // parse abstract syntax tree and pass to the translator
    asm_translator(an_parse_xml()) ;
    
    // flush output and errors
    print_output() ;
    print_errors() ;
}
