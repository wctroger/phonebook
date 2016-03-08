#include <stdlib.h>

#include "phonebook_opt.h"

entry *findName(char lastname[], entry *pHead)
{   
    while(pHead != NULL) {
        while(pHead->pPgdn != NULL && pHead->pPgdn->lastName[0] != lastname[0])
	    pHead = pHead->pPgdn;
	if(pHead->pPgdn == NULL)
	    return NULL;
	pHead = pHead->pPgdn;
	if(strcasecmp(lastname, pHead->lastName) == 0)
            return pHead;
	while(pHead->pNext != NULL){
            pHead = pHead->pNext;
	    if(strcasecmp(lastname, pHead->lastName) == 0)
		return pHead;
	}
	return NULL;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    entry *head = e;
    while(e->pPgdn != NULL && e->pPgdn->lastName[0] != lastName[0]){
	e = e->pPgdn;
    }
    if(e->pPgdn == NULL){
	e->pPgdn = (entry *) malloc(sizeof(entry));
	e = e->pPgdn;
	strcpy(e->lastName, lastName);
	e->pNext = NULL;
	e->pPgdn = NULL;
	return head;
    }
    e = e->pPgdn;
    while(e->pNext != NULL){
	entry *temp;
	temp = (entry *) malloc(sizeof(entry));
	strcpy(temp->lastName, lastName);
	temp->pPgdn = NULL;
	temp->pNext = e->pNext;
	e->pNext = temp;
	return head;
    }
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;
    e->pPgdn = NULL;
    return head;   
}

