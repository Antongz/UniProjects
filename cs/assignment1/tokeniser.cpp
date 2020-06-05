/*
 Course:computer science
 Author:Samantha(Yongxin Hu)
 Student:1711972
 Description:Tokeniser milestone work
 */


// a skeleton implementation of a tokeniser

#include "tokeniser.h"
#include <iostream>
#include <ctype.h>

// to shorten the code
using namespace std ;

////////////////////////////////////////////////////////////////////////

// the current input character, initiliased to ' ' which we ignore
// it is an int so that the EOF marker is not confused with a legal character
static int ch = ' ' ;

// the current line number and column, initialised to line 1 column 0
static int line_num = 1 ;
static int column_num = 0 ;

// the line number and column for the first character in the current token
static int start_line = 0 ;
static int start_column = 0 ;

// the ivalue is for the integer token check,if its int token ,it will return the value, if not,return 0
static int ivalue=0;
static double dvalue=0.0;
static string value="";//for the double value

// read next character if not at the end of input
// and update the line and column numbers
static void nextch()
{
    extern int read_char() ;
    
    if ( ch == EOF ) return ;
    
    if ( ch == '\n' )                         // if last ch was newline ...
    {
        line_num++ ;                          // increment line number
        column_num = 0 ;                      // reset column number
    }
    
    ch = read_char() ;                        // read the next character
    column_num++ ;                            // increment the column number
}

////////////////////////////////////////////////////////////////////////


// isalpha returns true if passed a letter
// isdigit returns true if passed a digit
// isalnum returns true if passed a letter or a digit

// return true if c can start an identifier, ie it is a letter or '_'
static bool is_idstart(int c)
{
    return isalpha(c) || c == '_' ;
}


// return true if c can be inside an identifier, ie it is a letter, digit or '_'
static bool is_inid(int c)
{
    return isalnum(c) || c == '_' ;
}

// return true if c is a digit from '1' to '9'
static bool is_digit19(int c)
{
    return c >= '1' && c <= '9' ;
}
static bool is_digit(int c)
{
     
    return c >= '0' && c <= '9' ;
}
// return a token - including current line and column numbers
static Token new_token(TokenKind kind,string value)
{
    Token t = { kind,kind,value,0,0.0,start_line,start_column } ;
    return t ;
}
//return a token for special symbol token -including token class and kind .
static Token new_symbol_token(TokenKind kind2,TokenKind kind3,string value)
{
    Token t={ kind2,kind3,value,0,0.0,start_line,start_column};
    return t;
}
//return a token for the int token-include the ivalue to check if its int.
static Token new_int_token(TokenKind kind,string value,int ivalue)
{
    Token t = { kind,kind,value,ivalue,0.0,start_line,start_column };
    return t ;
}
//return a token for the double token -include the dvalue to check if its double
static Token new_double_token(TokenKind kind,string value,double dvalue)
{
    Token t = { kind,kind,value,0,dvalue,start_line,start_column };
    return t ;
}
//return a token for the key token -include the kind and value
static Token new_key_token(TokenKind kind,string value)
{
    Token t = { KEYWORD,kind,value,0,0.0,start_line,start_column } ;
    return t ;
}


////////////////////////////////////////////////////////////////////////

// return the next token object by reading more of the input
Token next_token()
{
    // you must read input using the nextch() function
    // the last character read is in the static variable ch
    // always read one character past the end of the token being returned

     while ( ch != EOF )
      {
              start_line = line_num ;                  // remember current position in case we find a token
              start_column = column_num ;
              
              switch(ch)                               // ch is always the next char to read
              {
                                                       // ignore space, tab, CR and LF
                  case ' ':
                      nextch();                        // read one more character and try again
                      break;
                  case '\t':
                      nextch();
                      break;
                  case '\r':
                      nextch();
                      break;
                  case '\n':
                      nextch() ;
                      break ;
                      
                      //speical symbol
                  case '@':
                      nextch();
                      return new_symbol_token(SYMBOL,AT_SYMBOL,"@");
                      break ;
                      
                  case ';':
                      nextch();
                      return new_symbol_token(SYMBOL,SEMI_SYMBOL,";");
                      break;
                      // This file is part of www.nand2tetris.org
                      // and the book "The Elements of Computing Systems"
                      // by Nisan and Schocken, MIT Press.
                      // File name: projects/06/add/Add.asm

                      // Computes R0 = 2 + 3



                  case ':':
                      nextch();
                      return new_symbol_token(SYMBOL,COLON_SYMBOL,":");
                      break;
                      
                  case'!':
                      nextch();
                      return new_symbol_token(SYMBOL,NOT_SYMBOL,"!");
                      break;
                      
                  case',':
                      nextch();
                      return new_symbol_token(SYMBOL,COMMA_SYMBOL,",");
                      break;
                      
                  case '.':

                      nextch();
                      if(!is_digit(ch)||ch==' ')
                      {
                      return new_symbol_token(SYMBOL,STOP_SYMBOL,".");
                      }
                      break;
                      
                  case '=':
                      nextch();
                      return new_symbol_token(SYMBOL,EQUALS_SYMBOL,"=");
                      break;
                      
                  case '{':
                      nextch();
                      return new_symbol_token(SYMBOL,LCB_SYMBOL,"{");
                      break;
                    
                  case '}':
                      nextch();
                      return new_symbol_token(SYMBOL,RCB_SYMBOL,"}");
                      break;
                      
                  case '(':
                      nextch();
                      return new_symbol_token(SYMBOL,LRB_SYMBOL,"(");
                      break;
                      
                  case')':
                      nextch();
                      return new_symbol_token(SYMBOL,RRB_SYMBOL,")");
                      break;
                  case '[':
                      nextch();
                      return new_symbol_token(SYMBOL,LSB_SYMBOL,"[");
                      break;
                      
                  case ']':
                      nextch();
                      return new_symbol_token(SYMBOL,RSB_SYMBOL,"]");
                      break;
                  case '0':
                    value="0.";
                    nextch();            
                      if(ch!='.')
                        {
                          return new_int_token(INT,"0",0);
                        }
                      else if(ch=='.')
                        {
                           nextch();

                          while(isdigit(ch))
                       {   
                           value +=ch;  
                           nextch();
               
                         }
                          return new_double_token(DOUBLE,value,0);
                       }

          
           
              
                
        default:
         
                   if(ch=='/')
                 {
                     
                  nextch();
                 
                  if(ch=='/')
                 {    
                       nextch();
                      string value="";
                      while(ch!='\n')
                  {
                                       
                       value +=ch;
                       nextch();
                                     
                  }
                  return new_token(ONELINE_COMMENT,value);
                             
                 }    
                           
                  if(ch=='*')
                  {
                     nextch();
                 
                  string value="";
             
                 
                  while(ch!='/')
                   {
                       value +=ch;
                        nextch();
                   }
                   char check=value.back();           
                 if(check=='*')
                  {
                    value.erase(value.end()-1);
                    nextch();               
                  return new_token(MULTILINE_COMMENT,value);
                  }
                  }

                 }  
               
            
               if(isdigit(ch)&&ch!='0')
                {
                 string spelling="";
                       
                while(isdigit(ch)||ch!='.')
                 {  
                     spelling +=ch;
                  nextch();
                if(!isdigit(ch)&&ch!='.')
                 {
                  ivalue=stoi(spelling);
                  return new_int_token(INT,spelling,ivalue);
                              
                 }
                 }
                    while(ch=='.'||isdigit(ch))
                   {   
                     spelling +=ch;  
                     nextch();
                               
                  if(!isdigit(ch)&&ch!='.')
                   {   
                        dvalue=stod(spelling);
                     return new_double_token(DOUBLE,spelling,dvalue);
                             
                   }
                 }
               }
                 

                  // for the identifier for alpha
                     if(is_idstart(ch))
                      {
                         string value="";
                        
                          while(is_inid(ch))
                             {
                                value+=ch;
                                nextch();
                        
                             }
                  TokenKind k=string_to_token(value,OOPS);

                           

                          
                        if(k!=OOPS)
                    {
                        return new_key_token(k,value);

                    }

                         return new_token(IDENTIFIER,value);
                       
                    }
          
                ch = EOF ;                                       // simulate EOI
                return new_token(BAD,"") ;                       // the next character cannot start a token, return a BAD token
              
           }
    }
   
                start_line = line_num ;                          // remember current position so EOI token is correct
                start_column = column_num ;

                return new_token(EOI,"") ;                       // return an EOI token

    
     }