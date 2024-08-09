#define SIZE 100

struct pacienteInfo {
    char nome[SIZE];
    char cpf[15];
    char telefone[SIZE];
    char rua[SIZE];
    char numero[SIZE];
    char cep[SIZE];
    char bairro[SIZE];
    char cidade[SIZE];
    char estado[SIZE];
    char anoNasc[SIZE];
    char dataNasc[SIZE];
    char email[SIZE];
    char dataDiag[SIZE];
    char comorbidade[SIZE];
};

void cadastroPaciente(arquivo, op);
