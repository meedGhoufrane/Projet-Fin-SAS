#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// create struct  task
struct task{ 
    int  id;
	char Titre[50];
	char Description[50]; 
	int  Deadline;
	char Statut[20];
    };  
  
    struct  task T[100];
 	int count = 0;

 	int i, j, test;
 	struct task n;
 
 // function add 
void add(){
 	
		printf("donner le Titre :");
		scanf("%s",T[count].Titre);
		printf("donner le Description :");
		scanf("%s",T[count].Description);
		printf("donner le Deadline :");
		scanf("%d",&(T[count].Deadline));
		printf("choisir status entre les [ a realiser ou  en cours de realisation ou  finalisee ]:");
		scanf("%s",T[count].Statut);
	//for(i=0;i<l.T.Statut;i++){
    //scanf("%s",l.T[l.count].Statut);
        T[count].id = count;
        count++;
}
/// Trier les tâches par ordre alphabétique
void Trieralpha(){
    i=0;
    do{
	test = 0;
        for(j = count-1 ; j > i;j--){
            if(strcmp(T[j].Titre,T[j-1].Titre) < 0){
                      n = T[j];
                      T[j] = T[j-1];
                      T[j-1] = n;
                      test = 1;
            }
        }
    }while(test == 1 && i < count);
}
// list afficher les tâches  
void afficher(){
    	int ch;
    	printf("liste de toutes les taches par :     \n");
 	    printf("[1]Trier les taches par ordre alphabetique.\n");
 	    printf("[2]Trier les taches par deadline.\n");
 	    printf("[3]Afficher les taches dont le deadline est dans 3 jours ou moins\n");
 	    printf("Tapez votre choix [1-3] : ");
        scanf("%d", &ch);
 	    switch(ch){
 	    	case 1:
 	    		Trieralpha();
 	    		break;
 	    	case 2:
 	    		
 	    		break;
 	    	case 3:
 	    		for(i=0;i<count;i++){
	    	      printf("le id  est %d le Titre est : %s , le Description est : %s ,le  Deadline est : %d ,le status est : %s\n",T[i].id,T[i].Titre,T[i].Description,T[i].Deadline,T[i].Statut);
		        }
 	    		break;
   		
   	    	default:
    			printf("Choix invalide. Veuillez choisir une option valide\n");
	    }
    }
    
    // list Rechercher
void Rechercher(){
    	int srch;
    	int id;
    	printf("Rechercher  les taches par :     \n");
 	    printf("[1]Rechercher une tâche par son Identifiant..\n");
 	    printf("[2]Rechercher une tâche par son Titre.\n");
 	    scanf("%d",&srch);
 	     switch(srch){
 	    	case 1:
 	    		printf("donner le id ");
 	    		scanf("%d",&id);
 	    		if(rechercherbyid(id) == -1){
 	    			printf("n existe pas \n");
				 }else{
				    for(i=0;i<count;i++){
	    	        printf("le Titre est : %s , le Description est : %s ,le  Deadline est : %d ,le status est : %s\n",T[i].Titre,T[i].Description,T[i].Deadline,T[i].Statut);
		        }
				 	
				 }
 	    		rechercherbyid();
 	    		
 	    		break;
 	    	case 2:
 	    		
 	    		break;
 	    	default:
    			printf("Choix invalide. Veuillez choisir une option valide\n");
	}
}
    
    //SEARCH BY ID
    rechercherbyid(int id){
    	int pos=-1;
    	for(i=0;i<T[count].id;i++){
    		if(id==T[i].id){
    			pos=i;
			}
		}
    	return pos;
	}
	    

  
int main(int argc, char *argv[]) {

    	count = 0;
    	int id;
    	int choice;
    	printf("            Menu d'application Gestion de Taches ToDo\n");
        printf("===================================\n");
        printf("[1] Ajouter une nouvelle tache \n");
        printf("[2] Ajouter plusieurs nouvelles taches \n");
        printf("[3] Afficher la liste de toutes les taches \n");
        printf("[4] Modifier une tache \n");
        printf("[5] Supprimer une tache par identifiant \n");
        printf("[6] Rechercher les Taches \n");
        printf("[7] Statistiques \n");
    	
	 do {
       
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
            case 4:
            		
                break;
            case 5:
            		
                break;
                
            case 6:
            		Rechercher();
                break;
            case 7:
            		
                break;
            default:
                	printf("Choix invalide. Veuillez choisir une option valide.\n");
        }
    } while (1);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
