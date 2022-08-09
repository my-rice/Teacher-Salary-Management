#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "info.h"

TInfo read_info()
{
   TInfo info;

   info.key = read_key();
   info.satellite = read_satellite();

   return info;
}


int equal(TKey x, TKey y)
{
   if (strcmp(x, y) == 0)
      return 1;
   else
      return 0;
}

int greater(TKey x, TKey y)
{
   if (strcmp(x, y) == 1)
      return 1;
   else
      return 0;
}

void print_info(TInfo x)
{
   print_key(x.key);
   print_satellite(x.satellite);   
   printf("\n");
}

void print_key(TKey k)
{
   printf("%17s  ", k);
}

void print_satellite(TSatellite s)
{
   printf("%3s  %16s  %16s  %7.2f  %3d", s.tipologia, s.cognome, s.nome, s.stipendio, s.corsi);
}



TSatellite read_satellite()
{
   TSatellite sat;

   int saldo;

   do{
   printf ("Inserisci la tipologia del docente [PO/PA/RI] ");
   scanf ("\n%s", sat.tipologia);
   } while (strcmp(sat.tipologia, "PO")!=0 && strcmp(sat.tipologia, "PA")!=0 && strcmp(sat.tipologia, "RI")!=0);

   printf ("Inserisci il cognome del docente ");
   scanf ("%s", sat.cognome);

   printf ("Inserisci il nome del docente ");
   scanf ("%s", sat.nome);

   do{
   printf ("Inserisci lo stipendio mensile del docente [>0] ");
   scanf ("%f", &sat.stipendio);
   } while (sat.stipendio <= 0);

   do{
   printf ("Inserisci numero di corsi [> 0] ");
   scanf ("%d", &sat.corsi);
   }while (sat.corsi <= 0);
   
   return sat;
}


TKey read_key()
{
   TKey key;
   char tmp[MAXKEY];

   do
   {
   printf ("Inserisci il codice fiscale (16 caratteri): ");
   scanf ("%s", tmp);
   } while (strlen (tmp)!=MAXKEY-1);

   key = (TKey)malloc(MAXKEY*sizeof(TKey));
   strcpy (key, tmp);

   return key;

}

