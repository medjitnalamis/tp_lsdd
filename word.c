#include "word.h"
// creates a new cell and stores its address in p
void Allocate(pwd *p) {
    *p = (struct wordnode *) malloc(sizeof(struct wordnode ));
      (*p)->word = NULL; // because char* is a pointer and if we dont do it , it will conatains garbage 
    (*p)-> next = NULL ; // now we know p points to nothing — safe
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
        p=
    }
}

