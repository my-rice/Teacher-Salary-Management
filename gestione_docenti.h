#ifndef GESTIONE_DOCENTI_H
#define GESTIONE_DOCENTI_H

#include "tree.h"

/*La funzione legge il dato TInfo e inserisce un nuovo nodo nell'albero binario.
  La funzione restituisce 1 se l'inserimento va a buon fine, -1 altrimenti.*/
int inserisci_docente (TTree *universita);

/*La funzione legge il codice fiscale del docente. Successivamente cerca il nodo
  relativo al docente, se non viene trovato si restituisce -1. Se il nodo viene
  trovato si verifica la tipologia di docente, se il docente appartiene alla tipologia
  RI, si pone la tipologia a PA, si aumenta lo stipendio del 5% e si restituisce 1;
  se il docente appartiene alla tipologia PA, si pone la tipologia a PO, si aumenta
  lo stipendio del 10% e si restituisce 2; se il docente appartiene alla tipologia PO,
  non si effettua alcuna operazione e si restituisce 0.*/
int promozione_docente (TTree universita);

/*La funzione ricerca il docente che abbia stipendio immediatamente superiore a stip.
  La funzione restituisce il nodo trovato (ricorsiva).*/
TNode* cerca_stipendio_superiore(TTree universita, float stip);

/*La funzione stampa, le informazioni di tutti i docenti in archivio. La funzione
  non restituisce alcun valore. (La funzione viene già fornita)*/
void stampa_docenti (TTree universita);

#endif
