#include "word.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef int boolean;
#define False 0
#define true 1
// creates a new cell and stores its address in p
void Allocate(pwd *p) {
    *p = (struct wordnode *) malloc(sizeof(struct wordnode ));
      (*p)->word = NULL; // because char* is a pointer, and if we don't do it, it will contain garbage 
    (*p)-> next = NULL; // now we know p points to nothing — safe
} 
 // frees the node 
void Free_node (pwd p) {
    free(p->word); // free the word sting 
    free(p);// frees the node
}

// assigns a word to the cell p
void Ass_word(pwd p, string v) {
    p->word = (string)malloc(strlen(v) + 1);
    strcpy(p->word, v);
}

// links cell p to cell q
void Ass_adr(pwd p, pwd q) {
    p->next = q;
}

// returns the content of cell p
string content(pwd p) {
    return p->word;
}

// returns the next cell after p
pwd Next(pwd p) {
    return p->next ;
}   

void display_word(pwd head){
pwd p ;
p = head ;
     while ( p != NULL)
{
    printf("%s -->  " , content(p));
    p = Next(p);
}
}
// frees all the linked list
void freeWordList(pwd head) {
    pwd p = head;
    pwd temp;
    while (p != NULL) {
        Free_node(p);
        temp=Next(p); 
        Free_node(p);
        p=temp ;
    }
}

pwd insert(pwd *head , string new )
{
    boolean found = 0 ; 
    pwd p = *head  ; 
    char *d = new ;
    pwd n ; 
    while( p != NULL)
    {
        //we should check that the new word doesn't exist + stay in the sorted list 
     if ( strcmp(content(p),new) == 0 )
     return *head ;
     else p = Next(p);
    }
    p = *head ; 
    //create the new node 
     Allocate(&n);
     // case the list is empty 
     if (*head == NULL )
     {
         Ass_word(n,new);
        *head=n;
        return *head;
     } 
     // insert befor the head 
      if ( strcmp(content(*head),new) > 0)
        {
            found = 0 ;
            Ass_word(n,new); 
            Ass_adr(n,*head);
            *head = n ; 
            return *head ; 
        }
    
     else
     {
     while ((p != NULL) && !found)
     { 
        
        if ( Next(p) != NULL  && (strcmp(content(Next(p)),d) > 0 )  )// we find the right position 
        {
        found = 1 ; 
        Ass_adr(n,Next(p));
        Ass_adr(p,n);
        }
        else // we didn't find the perfect position 
        p = Next(p);
     }
    
    if ( (strcmp(content(p),d)<0) ) // we insert in the  end  of the list 
    {
        Ass_word(n,new);
        Ass_adr(p,n);
        Ass_adr(n,NULL); 
    }
    return *head ; 
}
}
   
