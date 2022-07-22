#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define TAM 5
#define MAX_NAME 50
struct pessoa_data {
    char nome[MAX_NAME];
    int rg;
    bool cadastrado;
};
struct pessoa_data pessoa[10];

int getRg(const int vaga) {
    return pessoa[vaga].rg;
}

int getName(const int vaga, char *namevar) {
    strncpy(namevar, pessoa[vaga].nome, MAX_NAME);
    return 1;
}

void imprimirLista() {
    for(int i=0; i < 10; ++i) {
        printf("Pessoa: %d\n", i);
        printf("Nome: %s\n", pessoa[i].nome);
        printf("Rg: %d\n\n", pessoa[i].rg);
    }
}
int cadastrarPessoa(const int vaga, const char *name, const int rg) {
    for(int i=0; i<10; ++i) {
        if(rg == getRg(i))
            return printf("Ja existe um cadastro com esse RG!!!");
        char namevar[MAX_NAME];
        getName(i, namevar);
        if(strcmp(name, namevar)==0) {
            return printf("Ja existe um cadastro com esse nome!!!!");
        }
    }
    pessoa[vaga].cadastrado = true;
    strncpy(pessoa[vaga].nome, name, MAX_NAME);
    pessoa[vaga].rg = rg;
    return 1;
}

int removerPessoa(const int vaga) {
    pessoa[vaga].cadastrado = false;
    strncpy(pessoa[vaga].nome, "", MAX_NAME);
    pessoa[vaga].rg = 0;
    return 1;
}

int alterarDados(const int vaga, const char *name, const int rg) {
    for(int i=0; i<10; ++i) {
        if(rg == getRg(i))
            return printf("Ja existe um cadastro com esse RG!!!");
        char namevar[MAX_NAME];
        getName(i, namevar);
        if(strcmp(name, namevar)==0) {
            return printf("Ja existe um cadastro com esse nome!!!!");
        }
    }
    strncpy(pessoa[vaga].nome, name, MAX_NAME);
    pessoa[vaga].rg = rg;
    return 1;
}


int main() {
    int opcao = 1;
    while (opcao > 0 && opcao < 5) {
        printf("1 - cadastrarPessoa\n");
        printf("2 - remover pessoa\n");
        printf("3 - Alterar dados\n");
        printf("4 - Imprimir dados\n");
        printf("Selecione uma opcao: ");
        scanf("%d", &opcao);
        int p;
        char name[MAX_NAME];
        int rg;
        switch (opcao) {
            case 1: {
                printf("Selecione a vaga desejada: ");
                scanf("%i", &p);
                if(pessoa[p].cadastrado)
                    return printf("Essa vaga esta ocupada, use a opcao 3");
                printf("Cadastre um nome: ");
                scanf("%s", &name);
                printf("Cadastre um rg: ");
                scanf("%i", &rg);
                cadastrarPessoa(p, name, rg);
                break;
            }
            case 2: {
                printf("Selecione a vaga desejada: ");
                scanf("%i", &p);
                if(!pessoa[p].cadastrado)
                    return printf("A vaga %i nao esta ocupada\n", p);
                removerPessoa(p);
                break;
            }
            case 3: {
                printf("Selecione a vaga desejada: ");
                scanf("%i", &p);
                if(!pessoa[p].cadastrado)
                    return printf("A vaga nao existe por favor use a opcao 1");
                printf("altere o nome: ");
                scanf("%s", &name);
                printf("altere o rg: ");
                scanf("%i", &rg);
                alterarDados(p, name, rg);
                break;
            }
            case 4: {
                imprimirLista();
                break;
            }
        }
    }
    system("pause");
    return 1;
}