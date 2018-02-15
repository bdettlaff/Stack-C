#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

typedef struct{

    int *dane;
    int szczyt;
    int rozmiar;

}stos;

void init();
void destroy(stos* s);
void push(stos* s, int element);
int pop(stos* s);
void clear(stos* s);
bool isempty(stos* s);

#endif
