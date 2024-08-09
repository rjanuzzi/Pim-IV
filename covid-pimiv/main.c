#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include "loginregister.h"
#include "registroPaciente.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int cho;
    printf("Digite 1 para registrar \nDigite 2 para fazer login\n\n");
    scanf("%d", &cho);
    if(cho == 1)
    {
        system("CLS");
        registro();
    }
    else if(cho == 2)
    {
        system("CLS");
        login ();
    }

    FILE *arquivo;
    int op = 1;

    if (logged == 1) {
        int optionInt;
        printf("========== MENU PRINCIPAL ==========\n");
        printf("1. Cadastrar paciente: \n");
        printf("2. Excluir dados dos pacientes: \n");
        printf("3. Sair do sistema: \n\n");
        printf("Digite a opçao: ");
        scanf("%d", &optionInt);
        while(optionInt != 3) {
            switch(optionInt) {
            case 1:
                cadastroPaciente(arquivo, op);
                optionInt = 0;
                exit(0);
                break;
            case 2:
                arquivo = fopen("cadastro.txt", "w");
                if (arquivo) {
                    printf("\nDados deletados com sucesso!\n");
                    fclose(arquivo);
                    printf("\nRetorno: %d\n", remove(arquivo));
                } else {
                    printf("\nErro ao abrir o arquivo!\n");
                }
                optionInt = 0;
                exit(0);
                break;
            }
        }
    }

    return 0;
}
