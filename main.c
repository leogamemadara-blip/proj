#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct routes routes;
typedef routes *liste;
typedef struct routes{
int id;
int bus_id;
char T[200];
liste next;
liste previous;
}routes;
/*************************************************/
// je vais travailler avec LSL
typedef struct buses buses;
typedef buses *next;
typedef struct buses{
int bus_id;
char Matricule[100];
int capacite;
next suiv;
}buses;
next insererT(next l,int v,char T[],int capa){
next p;
p=malloc(sizeof(buses));
p->bus_id =v;
strcpy(p->Matricule,T);
p->capacite=capa;
p->suiv=l;
return p;
}

void afficherREC(next l){
    if(l!=NULL){
 printf("le bus d'id %d a la capcaite de %d eleve  ",l->bus_id,l->capacite);
 printf("son matricule est : ");
 puts(l->Matricule);
 afficherREC(l->suiv);}
}

next insererF(next l,int v,char T[],int capa){
    if(l==NULL)
        return insererT(l,v,T,capa);
    else {
next p,q;
p=malloc(sizeof(buses));
p->bus_id =v;
strcpy(p->Matricule,T);
p->capacite=capa;
p->suiv=NULL;
q=l;
while((q->suiv)!=NULL){
    q=q->suiv;
}
q->suiv=p;
return l;
    }
}

/*************************************************/
typedef struct DLIST{
 int length;
 liste beg;
 liste end;
}*DOUBLE;
/****************************************/
/**RETOURNER LISTE VIDE**/
DOUBLE newdlisrt(void){
 return NULL;
}
/****************************************/
/**LISTE VIDE OU PAS**/
int estvide(DOUBLE L){
 return L==NULL;
}
/****************************************/
/**RECUPERER LA LONGUEUR**/
int longueur(DOUBLE L){
return L->length;
}
/****************************************/
/**AFFICHAGE**/
void afficher(DOUBLE L){
 if(estvide(L))
    printf("LISTE VIDEEEEE");
 else{
    liste q=L->beg;
    while(q!=NULL){
        printf("l'tineraire du bus %d de la route %d a un itinairere : ",q->bus_id,q->id);
        puts(q->T);
        q=q->next;
    }
 }
}
/****************************************/
/**AFFICHAGE INVERSE**/
void afficherinverse(DOUBLE L){
 if(estvide(L))
    printf("LISTE VIDEEEEE");
 else{
    liste q=L->end;
    while(q!=NULL){
        printf("la route %d du bus %d a un itinairere : ",q->id,q->bus_id);
        puts(q->T);
        q=q->previous;
    }
 }
}
/****************************************/
DOUBLE insererFin(DOUBLE L, int v,int bus,char T[]){
 if(estvide(L)){
       //  L=malloc(sizeof(struct DLIST));
       /**************************/
    L=malloc(sizeof(*L));
    L->end=NULL;
    L->beg=NULL;
    liste p=malloc(sizeof(routes));
    p->id=v;
    p->bus_id=bus;
     strcpy(p->T,T);
    p->next=NULL;
   p->previous=L->end;
    L->beg=p;
    L->end=p;
    L->length=0;

 }
else{
          liste p=malloc(sizeof(routes));
     p->id=v;
    p->bus_id=bus;
  strcpy(p->T,T);
    p->previous=L->end;
    p->next=NULL;
    L->end->next=p;
    L->end=p;

}
 L->length++;
return L;
}
/**********************************************************/
void clear_screen() {
    system("cls");
}
/***********************************************************/
int main()
{
    int n;
int BUSES_ID[n];
printf("combien de bus ? : ");
scanf("%d",&n);
    next L=NULL;
    char MA[100],r;
    int capacite,bus_id;
    int c=0;
    while(c<n){
    printf("voulez inserer un bus (o/n) : ");
    scanf(" %c",&r);
    if(r=='o'){
             int i=0;
    printf("le bus id : ");
   scanf("%d",&bus_id);
    BUSES_ID[i++]=bus_id;
   printf("donner la capacite du bus  : ");
   scanf("%d",&capacite);
   getchar();
    printf("la matricule : ");
   gets(MA);
         L=insererF(L,bus_id,MA,capacite);
     c++;
    do{

    printf("voulez inserer un autre bus (o/n) : ");
    scanf(" %c",&r);
        if(r=='o'){
    printf("le bus id : ");
   scanf("%d",&bus_id);
    BUSES_ID[i++]=bus_id;
   printf("donner la capacite du bus  : ");
   scanf("%d",&capacite);
   getchar();
    printf("la matricule : ");
   gets(MA);
        L=insererF(L,bus_id,MA,capacite);
     c++;
}
    }while(r=='o' && c<n);
    }
    }
    clear_screen();
    if(L){
    printf("les buses disponibles : \n");
    afficherREC(L);
    }
    else
        printf("pas de buses disponible\n");
    printf("passons aux routes\n");
    DOUBLE R=NULL;
    char T[100];
    int id,bus_idr;
    printf("voulez inserer une route (o/n) : ");
    scanf(" %c",&r);
    if(r=='o'){
    printf("donner l'id de la route : ");
   scanf("%d",&id);
    if(n){
   int v=0;
   do{
    int i=0;
   printf("donner le bus id : ");
   scanf("%d",&bus_idr);
   while(i<n){
    if(BUSES_ID[i]!=bus_idr)
        i++;
    else{
     v=1;
     break;
    }
   }
  if(!v)
        printf("le buses id n'existe pas\n");
   }while(v==0);
    }
   getchar();
    printf("l'itineraire : ");
   gets(T);
   if(!n)
    bus_idr=0;
        R=insererFin(R,id,bus_idr,T);

    do{
    printf("voulez inserer une autre route (o/n) : ");
    scanf(" %c",&r);
        if(r=='o'){
   printf("donner l'id de la route : ");
   scanf("%d",&id);
  if(n){
  int v=0;
do{
    int i=0;
   printf("donner le bus id : ");
   scanf("%d",&bus_idr);
   while(i<n){
    if(BUSES_ID[i]!=bus_idr)
        i++;
    else{
     v=1;
     break;
    }
   }
  if(!v)
        printf("le buses id n'existe pas\n");
   }while(v==0);
  }
   getchar();
    printf("l'itineraire : ");
   gets(T);
   if(!n)
    bus_idr=0;
        R=insererFin(R,id,bus_idr,T);
}
    }while(r=='o');
    }
    printf("Hello world!\n");
    afficher(R);
    printf("\nla taile est %d\n",R->length);
    return 0;
}
