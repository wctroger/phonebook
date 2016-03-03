#include <stdlib.h>

#include "phonebook_opt.h"

entry *findName(char lastname[], entry *pHead)
{
    /* TODO: implement */
    while(pHead != NULL) {
        if(strcasecmp(lastname, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}
/* add txt here to test github push */
entry *append(char lastName[], entry *e)
{
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;

    return e;
}

