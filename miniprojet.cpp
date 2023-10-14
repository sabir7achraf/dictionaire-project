#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct date{
	int j,mois,a;
}date;
/********************************************/
typedef struct mot{
	char Mot[27];
	char def[100];
	int code;
	int lang;
	date d;
	mot*suivant;
}mot;
/*******************************************************/
typedef struct liste {
mot *premier;
}liste;
/**************** alloumot********************************/
mot *Allouemot(){
 	mot *m;
 	m=(mot*)malloc(sizeof(mot));
 	m->suivant=NULL;
 	return m;
 }
 /******************************* saisiemot*****************************/
 void SaisieMot(mot *m){
 	printf("LE MOT \n");
 	scanf("%s",m->Mot);
 	printf("ENTRER 1 POUR ANGLAIS 2 ARABE 3 FRANCAIS 4 ESPAGNOL \n");
 	scanf("%d",&m->lang);
 	printf("LA DATE \n");
 	scanf("%d%d%d",&m->d.a,&m->d.mois,&m->d.j);
 	printf("le code \n");
 	scanf("%d",&m->code);
 	printf("LA defenition \n");
 	scanf("%s",m->def);
 	
 }
 /*********************initialiser (dicomult)*****************/
 liste*initilaiser(){
 	liste *l;
 	l=(liste*)malloc(sizeof(liste));
 	l->premier=NULL;
 	return l;
 }
 /***********************ajouter*********************/
  void ajouter(liste *l){
 	mot *el;
 	el=Allouemot();
 
 if(l->premier==NULL){
 	l->premier=el;
 	el->suivant=NULL;
 }
 else {
 	el->suivant=l->premier;
 	l->premier=el;
 }
SaisieMot(el);
 }
 /***************************afficher*************************/
 void afficher(liste *l){
 	mot *m;
 	int i=1;
 	m=l->premier;
 	while(m!=NULL){
 		printf("****************mot %d*******************************",i);
 	printf("LE MOT EST %s \n",m->Mot);
 	printf("LA DEFINITION EST %s \n",m->def);
 	printf("LA DATE EST %d/%d/%d \n",m->d.a,m->d.mois,m->d.j);
 	printf("LE CODE EST %d \n",m->code);
 	if(m->lang==1){
 		printf("ANGLAIS \n");
	 }
	  	if(m->lang==2){
 		printf("ARABE \n");
	 }
	  	if(m->lang==3){
 		printf("FRANCAIS \n");
	 }
	  	if(m->lang==4){
 		printf("ESPAGNOL \n");
	 }
	 m=m->suivant;
	 i++;
	 }
 }
 /********************* chercher*************************************/
 mot*chercher(liste *l){
 	char name[27];
 	mot *m;
 	printf("entrer le mot que tu veux trouver   \n");
 	scanf("%s",name);
 	m=l->premier;
 	while(m!=0){
 		if(strcmp(m->Mot,name)==0){
 return m;
 break;
		 }
		 m=m->suivant;
	 }
	 return NULL;	
 }
 /************************** suprimer*********************************/
 liste *supprimer(liste *l){

 	char name[27];
 	mot *m,*r,*c;
 	printf("*************************************************** \n");
 	printf("Entrez le mot que vous voulez supprimer : \n");	
 	scanf("%s", name);
 	m=l->premier;
 	r=NULL;
 	
 	while(m!=NULL){
 		if(strcmp(m->Mot,name) == 0){
 		r=m;
 		break;
 	     }
 		m=m->suivant;
 	}
 	if(r==NULL){
 		printf("Le mot n'a pas été trouvé dans le dictionnaire.\n");
 		return l;
 	}
 	c=l->premier;
 	if(c==r){
 		l->premier=r->suivant;
 		free(r);
 	}
 	else {
 		while(c!=NULL){
 			if(c->suivant==r){
 		c->suivant=r->suivant;
 		free(r);
 		break;
 		}
 		c=c->suivant;
 	}
 	}
 	return l;
} /***************************supprimerdictionaire*******************************************/
void supdic(liste*l){
mot	*sup,*utile;
	sup=l->premier;
	while(sup!=NULL){
		utile=sup;
		utile=utile->suivant;
		free(sup);
	}
}
/***********************enregistrement*********************************************/
void enregistrement(liste*l){
	FILE *ptr;
	int i=1;
	mot *m;
	m=l->premier;
	
	ptr=fopen("dictionaire.txt","w+");
while(m!=NULL){
			fprintf(ptr,"le mot %d est : %s \n",i,m->Mot);
		fprintf(ptr,"la definition est %s \n",m->def);
		fprintf(ptr,"le code est  est %d \n",m->code);
 	if(m->lang==1){
 		fprintf(ptr," lalangue est ANGLAIS \n");
	 }
	  	if(m->lang==2){
 		fprintf(ptr," lalangue est arabe \n");
	 }
	  	if(m->lang==3){
 		fprintf(ptr," lalangue est francai \n");
	 }
	  	if(m->lang==4){
  		fprintf(ptr," lalangue est ANGLAIS \n");
	 }
	  	fprintf(ptr,"LA DATE EST %d/%d/%d \n",m->d.a,m->d.mois,m->d.j);
	  	m=m->suivant;
}

	fclose(ptr);
}
/******************** tri_a_bull**********************/
void tri_liste(liste *l) {
    int w=0;
     mot*c;
     mot*pre;
    c=l->premier;
    w=0;
    while (c!=NULL) {
        w++;
        c=c->suivant;
    }
for (int i=0;i<w-1;i++){
c=l->premier;
  while (c->suivant!=NULL) {
if (c->code > c->suivant->code) {
 pre= c->suivant;
  c->suivant = pre->suivant;
 pre->suivant = c;
  if (c=l->premier)
      l->premier= pre;
    else {
      mot *h;
     h=l->premier;
      while (h->suivant != c)
       h= h->suivant;
    h->suivant=pre;
   }
   c=pre;
  }
     else {
   c=c->suivant;
 }
 }
}
}
 int main(){
 	int i,n;
 	mot *m;
 	liste *l;
 	l=initilaiser();
 	printf("combient de mots vous vouler enregistrer \n ");
 	scanf("%d",&n);
 	for(i=0;i<n;i++){
 		 ajouter(l);
	 }
	tri_liste(l);
 	afficher(l);
 	printf("*************************************************** \n");
 	printf(" l'adreese de la structure de cette mot est %d \n ",chercher(l));
 	l=supprimer(l);
 	afficher(l);
 	enregistrement(l);
	supdic(l);
 	return 0;
 }

 
 
 
