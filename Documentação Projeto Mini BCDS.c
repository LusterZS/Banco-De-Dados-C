#include <stdio.h>
#include <locale.h>
#include <string.h>
 
#define MenuPrincipal "MENU DE LOGIN BASICO V1\n"
void ResetBancodedados(){
	FILE *reset;
	 reset = fopen("/home/luster/Documentos/PROJETOBDD/BDD_DADOS/Usuarios.txt", "w");
	 fclose(reset);
	}
void AddNewUser(char *n, int *s){
	FILE *users;
 users = fopen("/home/luster/Documentos/PROJETOBDD/BDD_DADOS/Usuarios.txt", "a");
 fprintf(users, "%s ", n );
 fprintf(users, "\n");
 fprintf(users, "%d ", *s);
 fprintf(users, "\n");
  fclose(users);
}
void LOGIN(char *usrdigit, int *sndigit){
	FILE *login;
	login = fopen("/home/luster/Documentos/PROJETOBDD/BDD_DADOS/Usuarios.txt", "r");
	
	char linhas[200];
	char usuario[100];
	int senha;
	
	 while(fgets(linhas, 200, login)) {
		 //passa a leitura no arquivo e recebe os valores
		 sscanf(linhas, "%s %d", usuario, &senha);
		 if (strcmp(usuario, usrdigit) == 0){
			 printf("\n");
			 printf("login aprovado");	 
		 }	  
	 }
}
int main(){
	 while(1){
	char Nome[20];	 
	int E1; 
	int senha;
	printf(MenuPrincipal);
	  printf("Selecione a Opção Desejada\n");
	   printf("(01) Registrar\n"); 
	    printf("(02) Login\n");
	scanf("%d", &E1);
	getchar();
	switch (E1) {
		case 01:
		 printf("Digite Seu Nome De Usuario: ");
		  scanf("%s", Nome);
		   printf("Digite Sua Senha: \n");
		   scanf("%d", &senha);
		   getchar();  
		   AddNewUser(Nome, &senha);  
		   return 0; 
	break;
	case 02:
	char Nome[50];
	int senha;
	printf("Digite Seu User: ");
	 scanf("%s", Nome);
	 LOGIN(Nome, &senha);
	 
	 
   }
    
   break;
   
  }
 }
 


