#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>



/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// create struct  task
struct  task{
	char Titre[50];
	char Description[50]; 
	int Deadline[50];
	char Statut[20];
};
     

 struct list {  // declar list 
 	struct task T[100];
 	int count;
 };
 
  struct list l ;
 
 int i,j,test;
 
 // function add 
 void add(){
	printf("donner le Titre :");
	scanf("%s",l.T[l.count].Titre);
	printf("donner le Description :");
	scanf("%s",l.T[l.count].Description);
	printf("donner le Deadline :");
	scanf("%d",l.T[l.count].Deadline);
	printf("choisir entre les  [ a realiser ou  en cours de realisation ou  finalisee ]:");
	scanf("%s",l.T[l.count].Statut);
//	for(i=0;i<l.T.Statut;i++){
//	   scanf("%s",l.T[l.count].Statut);
//	}
       l.count++; 
}

// Trier alphabétique
//void Trier alpha(){
//	test = 0;
//	i=0;
//	do{
//		for(int j = l.count;j>0;j--){
//			
//		}
//		
		
		
//		
//	}
//}
//






 void afficher(){
 	int ch;
 	    printf("[1]Trier les tâches par ordre alphabétique.\n");
 	    printf("[2]Trier les tâches par deadline.\n");
 	    printf("[3]Afficher les tâches dont le deadline est dans 3 jours ou moins\n");
 	    printf("Tapez votre choix [1-3] : ");
        scanf("%d", &ch);
 	    switch(ch){
 	    	case 1:
 	    		
 	    		break;
 	    	case 2:
 	    		break;
 	    	case 3:
 	    		break;
 	    		
 	    		default:
 	    			printf("Choix invalide. Veuillez choisir une option valide\n");
		 }
// 	    for(i=0;i<l.count;i++){
// 	    	printf("le Titre est : %s , le Description est : %s ,le  Deadline est : %d ,le status est : %s\n",l.T[i].Titre,l.T[i].Description,l.T[i].Deadline,l.T[i].Statut);
//		 }
 }
 
int main(int argc, char *argv[]) {

    	l.count = 0;
    	int choice;
    	
	 do {
        printf("            Menu d'application Gestion de Taches ToDo\n");
        printf("===================================\n");
        printf("[1] Ajouter une nouvelle tache \n");
        printf("[2] Ajouter plusieurs nouvelles taches \n");
        printf("[3] Afficher la liste de toutes les taches \n");
        printf("[4] Modifier une tache \n");
        printf("[5] Supprimer une tache par identifiant \n");
        printf("[6] Rechercher les Taches \n");
        printf("[7] Statistiques \n");
        printf("Tapez votre choix [1-7] : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                   add();
                break;
            case 2:
            
            
                break;
            case 3:
            		afficher();
                break;

            default:
                	printf("Choix invalide. Veuillez choisir une option valide.\n");
        }
    } while (1);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
