#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Stack.h"

int main()
{

    int znacznik=1;
    int wybor;
    int element;

    stos stosMain;
    
    init(&stosMain);
    

    while(znacznik==1)
    {

        printf("PROGRAM STOS ZREALIZOWANY W C \n");
        printf("--------------------------------\n");
        printf("1 - ZNISZCZ STOS\n");
        printf("2 - DODAJ ELEMENT\n");
        printf("3 - USUN ELEMENT\n");
        printf("4 - CZY PUSTY?\n");
        printf("5 - WYCZYSC STOS\n");
        printf("6 - WYLACZ PROGRAM\n");

        scanf("%d", &wybor);


        switch(wybor)
        {
                case 1:
                    {
                        destroy(&stosMain);
                        printf("Stos usuniety.\n");
                    }
                    break;

                case 2:
                    {
                        printf("Nowy element: ");
                        scanf("%d", &element);
                        push(&stosMain, element);
                    }
                    break;

                case 3:
                    {
                        element = pop(&stosMain);
                        printf("\nZdjety element: %d\n\n", element);
                    }
                    break;

                case 4:
                    {
                        if(isempty(&stosMain)==1)
                        {
                          printf("Pusty stos.\n");
                        }
                        else
                        {
                            printf("Niepusty stos.\n");
                        }
                    }
                    break;

                case 5:
                    {
                        clear(&stosMain);
                        
                    }
                    break;

                case 6:
                    {
                        znacznik=0;
                    }
                    break;
                default:
                {
                    printf("Brak opcji w menu.");
                }
        }
    }

    destroy(&stosMain);
	return 0;
}
