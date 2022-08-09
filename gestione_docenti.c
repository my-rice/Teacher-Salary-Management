#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestione_docenti.h"

/*La funzione legge il dato TInfo e inserisce un nuovo nodo nell'albero binario.
  La funzione restituisce 1 se l'inserimento va a buon fine, -1 altrimenti.*/
int inserisci_docente (TTree *universita)
{
    TInfo docente =  read_info();
    TNode* node =  tree_search(*universita, docente.key);
    if(node == NULL){
        return -1;
    }
    *universita =  tree_insert( *universita, docente);
    return 1;
}

/*La funzione legge il codice fiscale del docente. Successivamente cerca il nodo
  relativo al docente, se non viene trovato si restituisce -1. Se il nodo viene
  trovato si verifica la tipologia di docente, se il docente appartiene alla tipologia
  RI, si pone la tipologia a PA, si aumenta lo stipendio del 5% e si restituisce 1;
  se il docente appartiene alla tipologia PA, si pone la tipologia a PO, si aumenta
  lo stipendio del 10% e si restituisce 2; se il docente appartiene alla tipologia PO,
  non si effettua alcuna operazione e si restituisce 0.*/
int promozione_docente (TTree universita)
{
    TKey key = read_key();
    TNode* node = tree_search(universita, key);
    if(node == NULL){
        return -1;
    }
    if(strcmp(node->info.satellite.tipologia,"RI") == 0){
        strcpy(node->info.satellite.tipologia,"PA");
        node->info.satellite.stipendio = node->info.satellite.stipendio + (0.05)*(node->info.satellite.stipendio);
        return 1;
    }else if(strcmp(node->info.satellite.tipologia,"PA") == 0){
        strcpy(node->info.satellite.tipologia,"PO");
        node->info.satellite.stipendio = node->info.satellite.stipendio + (0.1)*(node->info.satellite.stipendio);
        return 2;
    }else
        return 0;
    
}

/*La funzione ricerca il docente che abbia stipendio immediatamente superiore a stip.
  La funzione restituisce il nodo trovato (ricorsiva).*/
TNode* imm_sup(TNode *a,TNode *b,float stip){
    if(a == NULL && b == NULL){
        return NULL;
    }
    if( (a == NULL || a->info.satellite.stipendio <= stip) && b->info.satellite.stipendio >stip){
        return b;
    }
    if( (b == NULL || b->info.satellite.stipendio <= stip) && a->info.satellite.stipendio >stip){
        return a;
    }
    if(a->info.satellite.stipendio>stip && b->info.satellite.stipendio >stip){
        if(a->info.satellite.stipendio > b->info.satellite.stipendio){
            return b;
        }else{
            return a;
        }
    }else
        return NULL;
}

TNode* cerca_stipendio_superiore(TTree universita, float stip)
{
    if(universita == NULL){
        return NULL;
    }
    TNode *l = cerca_stipendio_superiore(universita->left,stip);
    TNode *r = cerca_stipendio_superiore(universita->right,stip);
    
    return imm_sup(universita,imm_sup(l,r,stip),stip);
}


/* //versione migliore
TNode *min(TTree a, TTree b){
    if(a==NULL)
        return b;
    if(b==NULL)
        return a;
    if(a->info.satellite.stipendio<b->info.satellite.stipendio)
        return a;
    else
        return b;
}

 

TNode* cerca_stipendio_superiore(TTree universita, float stip) {
    if(universita==NULL)
        return NULL;
    TNode* l=cerca_stipendio_superiore(universita->left, stip);
    TNode* r=cerca_stipendio_superiore(universita->right, stip);
    
    if(universita->info.satellite.stipendio>stip)
        return min(universita,min(l,r));
    else
        return min(l,r);
}
*/

/*La funzione stampa, le informazioni di tutti i docenti in archivio. La funzione
  non restituisce alcun valore. (La funzione viene gi� fornita)*/
void stampa_docenti (TTree universita)
{
   tree_print(universita);
}
