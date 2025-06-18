#ifndef LOG_H_INCLUDED
#define LOG_H_INCLUDED

void Charge_log(char *f_log){

FILE *ev;
char aff_log[555];

ev= fopen(f_log, "r");
  if(ev==NULL){
   printf("Erreur d'ouverture de fichier '%s'  !",f_log);
   return ;
  }
     while(fscanf(ev," %[^\n]s",aff_log)==1 ) {
         printf(" %s \n\n",aff_log);
     }

    fclose(ev);
}
int nbr_Totl(char *f_log){
int cmp=0;
FILE * fr2 ;
fr2= fopen(f_log, "r");

char ligne_pre[250];

  if(fr2==NULL){
    printf("\n --> Erreur d'ouverture de fichier  '%s'  !",f_log);
    return ;
  }
   while(!feof(fr2)){
  fscanf(fr2," %[^\n]s",ligne_pre);
   fscanf(fr2," %[^\n]s",ligne_pre);
    fscanf(fr2," %[^\n]s",ligne_pre);
     fscanf(fr2," %[^\n]s",ligne_pre);
       fscanf(fr2," %[^\n]s",ligne_pre);
       cmp++ ;
   }
     fclose(fr2);
    return cmp ;
}

float Mont_Totl(char *f_log,float *s){
int cmp=0 ;
float mont,sr,montR;
FILE * fr2 ;
fr2= fopen(f_log, "r");

char ligne_pre[250];

  if(fr2==NULL){
    printf("\n -->Erreur d'ouverture de fichier '%s'  !",f_log);
    return ;
  }
  *s=0 ;
  sr=0 ;
   while(!feof(fr2)){
  fscanf(fr2," %[^\n]s",ligne_pre);
   fscanf(fr2," %[^\n]s",ligne_pre);
    fscanf(fr2," %[^\n]s",ligne_pre);

     fscanf(fr2," %s",ligne_pre);
        fscanf(fr2," %s",ligne_pre);
         fscanf(fr2,"%s",ligne_pre);
         if(strcmp(ligne_pre,"Retrait")==0){
         fscanf(fr2," %s",ligne_pre);
             fscanf(fr2,"%s",ligne_pre);
                fscanf(fr2," %f",&montR);
       sr=sr+montR ;
         }
         else{
         fscanf(fr2," %s",ligne_pre);
             fscanf(fr2,"%s",ligne_pre);
                fscanf(fr2," %f",&mont);
       *s=*s+mont ;
         }

       cmp++ ;
       if(nbr_Totl(f_log)==cmp)
        break ;
   }
     fclose(fr2);
    return sr ;
}

float Max_fmnt(char *F_log){
    char ligne_pre[250];
    float mont ;
    FILE * fr2 ;
fr2= fopen(F_log, "r");
 fscanf(fr2," %[^\n]s",ligne_pre);
   fscanf(fr2," %[^\n]s",ligne_pre);
    fscanf(fr2," %[^\n]s",ligne_pre);
     fscanf(fr2," %[^\n]s",ligne_pre);
       fscanf(fr2," %s",ligne_pre);
             fscanf(fr2,"%s",ligne_pre);
                fscanf(fr2," %f",&mont);
                  fclose(fr2);
                return mont ;
}
float max_DepRet(char *f_log,float *Max){
int cmp=0 ;
float mont,Maxr,montR;
FILE * fr2 ;
fr2= fopen(f_log, "r");

char ligne_pre[250];

  if(fr2==NULL){
    printf("\n -->Erreur d'ouverture de fichier '%s'  !",f_log);
    return ;
  }
   Maxr=0;
  *Max=0 ;
   while(!feof(fr2)){
  fscanf(fr2," %[^\n]s",ligne_pre);
   fscanf(fr2," %[^\n]s",ligne_pre);
    fscanf(fr2," %[^\n]s",ligne_pre);

     fscanf(fr2," %s",ligne_pre);
        fscanf(fr2," %s",ligne_pre);
         fscanf(fr2,"%s",ligne_pre);
    if(strcmp(ligne_pre,"Retrait")==0){
         fscanf(fr2," %s",ligne_pre);
             fscanf(fr2,"%s",ligne_pre);
                fscanf(fr2," %f",&montR);
             if(Maxr<montR)
          Maxr=montR ;

         }
         else{
         fscanf(fr2," %s",ligne_pre);
             fscanf(fr2,"%s",ligne_pre);
                fscanf(fr2," %f",&mont);

      if(*Max<mont)
          *Max=mont ;

         }

       cmp++ ;
       if(nbr_Totl(f_log)==cmp)
        break ;
   }
     fclose(fr2);
    return Maxr ;
}
float Max_Mont(char *f_log){
int cmp=0 ;
float Max,mont;

Max=Max_fmnt(f_log);
FILE * fr2 ;
fr2= fopen(f_log, "r");

char ligne_pre[250];

  if(fr2==NULL){
    printf("\n -->Erreur d'ouverture de fichier '%s'  !",f_log);
    return ;
  }

   while(!feof(fr2)){
  fscanf(fr2," %[^\n]s",ligne_pre);
   fscanf(fr2," %[^\n]s",ligne_pre);
    fscanf(fr2," %[^\n]s",ligne_pre);
     fscanf(fr2," %[^\n]s",ligne_pre);
       fscanf(fr2," %s",ligne_pre);
             fscanf(fr2,"%s",ligne_pre);
                fscanf(fr2," %f",&mont);


         if(Max<mont){
          Max=mont ;
         }

       cmp++ ;
       if(nbr_Totl(f_log)==cmp)
        break ;
   }
   fclose(fr2);
    return Max ;
}
void Afficher_Statiques(char *f_log){


float s ,sr;
 printf("\n\n -------------------------> Statistiques <------------------------------------- :\n\n");
//nobmre total :
int  nb ;
nb = nbr_Totl(f_log);
if(nb==0){
 printf(" \n --->  Il n'existe aucune transactions bancaires (c-a-d :'0') \n  ") ;
 return ;
}
else
    printf("-->Nombre total de transactions : %d\n",nb);

//Mon=t total ;
 sr= Mont_Totl(f_log,&s);
    printf("-->Montant total des retraits : %.2f\n", sr) ;
    printf("-->Montant total des depots : %.2f\n",s );
//max dep et retrait
float Max ,maxr ;
maxr=max_DepRet(f_log,&Max) ;
    printf("-->Plus grande transaction (retrait) : %.2f\n",maxr);
    printf("-->Plus grande transaction (depot) : %.2f\n",Max);
 // max total :
 float  tmax =Max_Mont(f_log);
    printf("-->La transaction la plus frequente par montant : %.2f\n",tmax);
}

#endif // LOG_H_INCLUDED
