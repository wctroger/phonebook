#include <stdlib.h>

#include "phonebook_opt.h"

entry *findName(char lastname[], entry *pHead)
{
    while(pHead != NULL){
	if(strcasecmp(lastname, pHead->lastName) == 0)
	    return pHead;
	pHead = pHead->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;

    return e;
}

/*  Unfinished code QAQ  
entry *findName(char lastname[], entry *pHead)
{
   
    while(pHead != NULL) {
        while(strcasecmp(lastname[0],pHead->lastName[0]) != 0){
	    if(pHead->pNext != NULL)
		pHead = pHead->pNext;
	    else if(pHead->pPgdn == NULL)
		return NULL;
	    else
		pHead = pHead->pPgdn;
	}
	if(strcasecmp(lastname, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e, entry *pHead)
{
    if(pHead->pNext == NULL){
	pHead->pNext = (entry *) malloc(sizeof(entry));
	e = pHead->pNext;
	strcpy(e->lastName, lastName);
	e->pNext = NULL;
	e->pPgdn = NULL;
	return e;
    }
    entry *tmp = pHead->pNext;
    while(strcasecmp(lastName[0], tmp->lastName[0]) != 0 && tmp->pPgdn != NULL){
	tmp = tmp->pPgdn;
    }
    
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;
    e->pPgdn = NULL;

    return e;
    
}
*/
