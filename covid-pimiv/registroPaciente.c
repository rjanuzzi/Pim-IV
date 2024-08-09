#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "registroPaciente.h"

void cadastroPaciente(arquivo, op) {
    struct pacienteInfo pacInfo;
    do {
        arquivo = fopen("cadastro.txt", "a+");
        printf("\n Insira o nome do paciente: ");
        fflush(stdin);
        scanf("%[^\n]s", &pacInfo.nome);

        printf("\n Insira o CPF do paciente: ");
        fflush(stdin);
        scanf("%s", &pacInfo.cpf);

        printf("\n Insira o telefone do paciente: ");
        fflush(stdin);
        scanf("%s", &pacInfo.telefone);

        printf("\n Insira a rua da casa do paciente: ");
        fflush(stdin);
        scanf("%[^\n]s", &pacInfo.rua);

        printf("\n Insira o numero da casa do paciente: ");
        fflush(stdin);
        scanf("%s", &pacInfo.numero);

        printf("\n Insira o CEP do paciente: ");
        fflush(stdin);
        scanf("%s", &pacInfo.cep);

        printf("\n Insira o bairro do paciente: ");
        fflush(stdin);
        scanf("%[^\n]s", &pacInfo.bairro);

        printf("\n Insira a cidade do paciente: ");
        fflush(stdin);
        scanf("%[^\n]s", &pacInfo.cidade);

        printf("\n Insira o estado(uf) do paciente: ");
        fflush(stdin);
        scanf("%[^\n]s", &pacInfo.estado);

        printf("\n Insira o ano de nascimento do paciente: ");
        fflush(stdin);
        scanf("%s", &pacInfo.anoNasc);

        printf("\n Insira a data de nascimento do paciente: ");
        fflush(stdin);
        scanf("%s", &pacInfo.dataNasc);

        printf("\n Insira o email do paciente: ");
        fflush(stdin);
        scanf("%s", &pacInfo.email);

        printf("\n Insira a data do diagnostico: ");
        fflush(stdin);
        scanf("%s", &pacInfo.dataDiag);

        printf("\n Insira a comorbidade do paciente (caso tenha digite 1, senao 0): ");
        fflush(stdin);
        scanf("%[^\n]s", &pacInfo.comorbidade);

        int comorbidadeInt = atoi(pacInfo.comorbidade);

        if(comorbidadeInt == 1) {
            printf("\n Quais sao as comorbidades: ");
            fflush(stdin);
            scanf("%[^\n]s", &pacInfo.comorbidade);
        }

        fprintf(arquivo,"\n\nNome: %s\nCPF: %s\nTelefone: %s\nRua: %s\nNumero: %s\nCEP: %s\nBairro: %s\nCidade: %s\nEstado: %s\nData de nascimento: %s\nEmail: %s\nData do diagnostico: %s\nComorbidade: %s", pacInfo.nome, pacInfo.cpf, pacInfo.telefone, pacInfo.rua, pacInfo.numero, pacInfo.cep, pacInfo.bairro, pacInfo.cidade, pacInfo.estado, pacInfo.dataNasc, pacInfo.email, pacInfo.dataDiag, pacInfo.comorbidade);

        printf("\nContinuar? (0-nao / 1-sim): ");
        scanf("%d", &op);

        int anoInt = atoi(pacInfo.anoNasc);


        if(anoInt <= 1956 || comorbidadeInt == 1) {
            FILE *grupoRisco = fopen("gruporisco.txt", "a+");

            fprintf(grupoRisco, "\n\nCEP: %s\nIdade: %d", pacInfo.cep, 2021-anoInt);
        }

        if (op == 1) {
            fputs("\n", arquivo);
        }
    } while (op==1);
    fclose(arquivo);
}
