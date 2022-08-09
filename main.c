#include <stdio.h>
#include "tree.h"
#include "info.h"
#include "bool.h"
#include "menu.h"
#include "gestione_docenti.h"

int main() {
    int scelta, inserimento, risultato;
    float stip;
    TTree universita;
    TNode *node;

    /* Inizializzo l'albero */
    universita = tree_create();
    
    scelta = 1;
    while(scelta){
        scelta = menu();
        if(scelta == 1){
            int inserimento = inserisci_docente (&universita);
            if(inserimento == 1)
                printf("Inserimento andato a buon fine.\n");
            else
                printf("ERRORE.\n");
        }else if(scelta == 2){
            int promozione = promozione_docente (universita);
            if(promozione == -1)
                printf("ERRORE.\n");
            else
                printf("Codice: %d.\n",promozione);
        }else if(scelta == 3){
            float stip;
            printf("Inserisci stipendio:\n");
            scanf("%f",&stip);
            TNode* node = cerca_stipendio_superiore(universita,stip);
            if(node == NULL){
                printf("ERRORE.\n");
            }else{
                print_info(node->info);
            }
        }else if(scelta == 4){
            stampa_docenti (universita);

        }
    }
    
    /* Scelta della funzione per gestire l'archivio */

}
