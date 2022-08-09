#include <stdio.h>
#include "menu.h"

int menu()
{
    int scelta,i;
    
    printf("-------------------------------------------------\n");
    printf("PROGRAMMA PER LA GESTIONE DI CONTI CORRENTI\n\n");
    printf("1. Inserisci una docente \n");
    printf("2. Promozione docente\n");
    printf("3. Cerca docente con stipendio superiore ad una data cifra\n");
    printf("4. Stampa a video delle pubblicazioni\n");
    printf("0. EXIT\n\n");
    printf("-------------------------------------------------\n");
    printf("Selezionare la scelta [0-4]: ");
    scanf("%d", &scelta);
    while((scelta<0)||(scelta>4)){
       printf("ERRORE! valore non consentito\n");                        
       printf("Selezionare la scelta [0-4]: ");
       scanf("%d", &scelta);
    }
    return scelta;

   pause();
}

void clear_screen()
{
   system("CLS");
}

void pause()
{
   system("pause");
}
