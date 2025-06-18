#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "log.h"
int main()
{
int num ;
   char f_log[50] ;
    while(num!=3){
      printf("--------------------------------MENU:----------------------------------------\n\n");
      printf("\t\t   1. Lecture du fichier de log des transactions .\n");
      printf("\t\t   2. Affichage des statistiques  .\n");
      printf("\t\t   3. Terminer . \n");
      printf("------------------------------------------------------------------------------\n\n");

 printf("-->Veuillez saisir un numero a partir de MENU (1,2...,7) :");
 scanf("%d",&num);
 printf("\n\n");
  switch(num){
    case 1:
        printf("-->Veuillez saisir le fichier pour le Chargement des informations !!(log.txt) :");
           scanf(" %[^\n]s",&f_log);
           printf("\n");
           Charge_log(f_log) ;
    break;

    case 2:
        printf("-->Veuillez saisir le fichier pour le Chargement des informations !!(log.txt) :");
           scanf(" %[^\n]s",&f_log);
           printf("\n");
        Afficher_Statiques(f_log) ;

    break;

    case 3:printf("----------------Au Revoir ;)!------------------\n") ;
    break;
    default :printf("\n (-_-)-->Ce numero n'existe pas dans le MENU \n\n") ;
  }
}

    return 0;
}
