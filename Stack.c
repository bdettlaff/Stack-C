#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Stack.h"

void init(stos *stosStack)
{
	stosStack->dane=(int*)malloc(sizeof(int));
	stosStack->rozmiar=1;
}

void destroy(stos *stosStack)
{
	free(stosStack->dane);
	free(stosStack);
}

void push(stos *stosStack, int element)
{
    int *nowy;
    if(stosStack->szczyt + 1 < stosStack->rozmiar)
    {  
        stosStack->szczyt= 1;
        stosStack->dane[stosStack->szczyt] = element;
    }
    else
    {
	    stosStack->rozmiar *= 2;
        nowy = (int*)realloc(stosStack->dane, (stosStack->rozmiar * sizeof(int)));
        if(nowy == NULL)
        {
            printf("Blad alokacji pamieci!\n");
            destroy(stosStack);
            exit(1);
        }
	    stosStack->dane=nowy;
        stosStack->szczyt += 1;
        stosStack->dane[stosStack->szczyt] = element;

    }
    printf("Element dodany!\n");
}

int pop(stos *stosStack)
{
	if(stosStack->szczyt==0)
	{
		printf("Nie ma nic na stosie");
        return 0;
	}
	else
	{
		stosStack->szczyt--;
		return stosStack->dane[stosStack->szczyt];
	}
}

bool isempty(stos *stosStack)
{
	if(stosStack->szczyt>0)
	{
	   return false;
    }
	else
	{
	   return true;
	}
}

void clear(stos *stosStack)
{
	stosStack->szczyt=0;
}

