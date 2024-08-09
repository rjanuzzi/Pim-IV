#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "loginregister.h"

int logged = 0;

void registro()
{
    FILE *log;
    log=fopen("login12.txt", "w") ;
    struct login logreg;

    printf("Insira seu primeiro nome: ");scanf("%s", logreg.fname) ;

    printf("Insira seu sobrenome: ");scanf("%s", logreg.lname) ;

    printf("Insira seu usuario: ");scanf("%s", logreg.username) ;
    printf("Insira sua senha: ");scanf("%s", logreg.password) ;
    fwrite(&logreg,sizeof(logreg),1,log) ;

    fclose(log) ;

    printf("Cadastro realizado com sucesso!\n");
    printf("\nPressione alguma tecla para continuar...");
    getch();
    system("CLS");
    login ();
}

 void login()
 {
    char username[200],password[20];
    FILE *log;
    log=fopen("login12.txt", "r");
    struct login logreg;
    printf("UserID: ");
    scanf("%s", &username);
    printf("Password: ");
    scanf("%s", &password);

    while(fread(&logreg,sizeof(logreg),1,log))
    {
     if(strcmp(username,logreg.username)==0 && strcmp(password,logreg.password)==0)
    {
        printf("Logado com sucesso\n");
        logged = 1;
        system("CLS");
    }
    else {
        system("CLS");
        printf("Por favor insira corretamente seu usuario e senha\n");
        logged = 0;
        login();
    }
    }
    fclose(log);
 }
