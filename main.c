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
	time_t Deadline;
	char Statut[50];
    };  
    
    struct  task tasks[100];
 	int count = 0,todo = 0,doing = 0,done =0;
 	int i, j, test;
 	struct task n;
    char newdes[50];
 // function add ======================================
void add(){
 	
	printf("donner le Titre :");
	scanf(" %[^\n]",tasks[count].Titre);
	printf("donner le Description :");
	scanf(" %[^\n]",tasks[count].Description);
	printf("donner le Deadline :");
	scanf("%s",&(tasks[count].Deadline));
	printf("choisir status entre les : \n");
	printf("[1] T Do \n");
	printf("[2] Doing\n");
	printf("[3] Done \n");
	scanf("%s",tasks[count].Statut);
	if(strcmp(tasks[count].Statut,"1")==0){    // opration for count  the choice
		todo+=1;
	}else if(strcmp(tasks[count].Statut,"2")==0){
		doing +=1;
	}else if(strcmp(tasks[count].Statut,"3")==0){
		done +=1;
	}
	
	//for(i=0;i<l.T.Statut;i++){
    //scanf("%s",l.T[l.count].Statut);
        
   	count++;
    tasks[count].id = count;
}
// delete 
void deletet(int posid){
	for(i=posid ;i<tasks[count].id;i++){
		tasks[i] = tasks[i+1];
	}
	count--;
	tasks[count].id = count;
}

/// Trier les tâches par ordre alphabétique==========================================
void Trieralpha(){
    i=0;
    do{
		test = 0;
        for(j = count-1 ; j > i;j--){
            if(strcmp(tasks[j].Titre,tasks[j-1].Titre) < 0){
                n = tasks[j];
                tasks[j] = tasks[j-1];
                tasks[j-1] = n;
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
	    	      printf("le id  est %d le Titre est : %s , le Description est : %s ,le  Deadline est : %d ,le status est : %s\n",tasks[i].id,tasks[i].Titre,tasks[i].Description,tasks[i].Deadline,tasks[i].Statut);
		        }
 	    	break;
   		
   	    default:
    			  printf("Choix invalide. Veuillez choisir une option valide\n");
	    }
    }
    
    // list Rechercher=========================================================
void Rechercher(){
    	int srch;
    	int id;
    	char titre[50];
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
	    	        printf("le Titre est : %s , le Description est : %s ,le  Deadline est : %d ,le status est : %s\n",tasks[rechercherbyid(id)].Titre,tasks[rechercherbyid(id)].Description,tasks[rechercherbyid(id)].Deadline,tasks[rechercherbyid(id)].Statut);	
			}
 	    		
 	        break;
 	    case 2:
 	    		    printf("donner le Title ");
 	    		    scanf("%s",titre);
 	    	if(rechercherbyTitre(titre) == -1){
 	    			printf("n existe pas \n");
			}else{
	    	        printf("le Description est : %s ,le  Deadline est : %d ,le status est : %s\n",tasks[rechercherbyTitre(titre)].Description,tasks[rechercherbyTitre(titre)].Deadline,tasks[rechercherbyTitre(titre)].Statut);
		    }	
				  	    		
 	    		break;
 	    	default:
    			printf("Choix invalide. Veuillez choisir une option valide\n");
	}
}
    //SEARCH BY ID
    rechercherbyid(int id){
    	int posid=-1;
    	for(i=0;i<tasks[count].id;i++){
    		if(id == tasks[i].id){
    			posid=i;
			}
		}
    	return posid;
	}
	//SEARCH BY Titre
	int rechercherbyTitre(char titre[50]){
    	int post = -1;
    	for(i=0;i<tasks[count].id;i++){
    		if(strcmp(titre,tasks[i].Titre) == 0){
    			post = i;
			}
		}
    	return post;
	}
 //==================================================================================================================
// update tache
//
//void update(int posid){
//	    int id;
//		printf("donne le id :");
//        scanf("%d",&id);    	 
//	 for(i=0;i<tasks[count].id;i++){
//		if( posid == tasks[count].id ){
//		  printf("donne new dscr : \n");
//		  scanf(" %[^\n]",newdes);
//		  strcpy(tasks[count].Description,newdes);
//		}
//	      
//	}
//}
//void updateT(int id, char Statut){
//	 for(i=0;i<tasks[count].id;i++){
//	 	if(tasks[count].id==id){
//	 		strcpy(tasks[count].Description,newDescription);
//		 }
//	 }
//	 
//}


  
int main(int argc, char *argv[]) {
        char titre[50];
    	count = 0;
    	int id;
    	int choice,choi;
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
                update(id);
    
                break;
            case 5:
            	 printf("donne le id :");
            	 scanf("%d",&id);
            	 if(rechercherbyid(id) == -1){
            	 	printf("n existe pas \n");
				 }else{
				 	deletet(rechercherbyid(id));
				 }
                break;
                
            case 6:
            		Rechercher();
                break;
            case 7:
            	printf("[1] Afficher le nombre total des taches.\n");
            	printf("[2] Afficher le nombre de taches completes et incomplètes.\n");
            	printf("[3] Afficher le nombre de jours restants jusqu'au delai de chaque tache\n");
            	printf("Tapez votre choix :");
            	scanf("%d",&choi);
            	switch(choi){
            		case 1:
            			printf("le nombre total des taches : %d  \n ",count);
            		break;
            		case 2:
            			printf("le nombre de tâches complètes et incomplètes : %d , %d \n ",done,doing);
            		break;
            		case 3:
            			
            		break;
            		default:
                	printf("Choix invalide. Veuillez choisir une option valide.\n");
				}
            		
                break;
            default:
                	printf("Choix invalide. Veuillez choisir une option valide.\n");
        }
    } while (1);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
