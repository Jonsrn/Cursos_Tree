#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "universidade.h"


// criar uma função de criar No de Disciplina

//Criar uma função na Árvore de Disciplinas



int criarNo_Disc(Inf_Disc *temp, Arv_disc **novo){ 
    *novo = (Arv_disc*)malloc(sizeof(Arv_disc)); //Vai alocar a memória para o novo nó
    int operacao = 1; 

    if(*novo != NULL){
        (*novo)->info.carga_horaria = temp->carga_horaria; 
        snprintf((*novo)->info.nome_da_disciplina, sizeof((*novo)->info.nome_da_disciplina), "%s", temp->nome_da_disciplina);
        (*novo)->info.codigo_disciplina = temp->codigo_disciplina; 
        (*novo)->info.periodo = temp->periodo;  
        (*novo)->esq = NULL; 
        (*novo)->dir = NULL; 
    }else{
        operacao = 0; 
    }  

    return operacao; 

}



int inserirArvBB_Disc(Arv_disc **disciplinas, Arv_disc *novo) {
    int operacao = 1; // Assume que a operação será bem-sucedida

    // Se a subárvore estiver vazia, insira o novo nó
    if (*disciplinas == NULL) {
        *disciplinas = novo; // Insere a disciplina
    } else {
        // Compare o código da nova disciplina com o nó atual
        if (novo->info.codigo_disciplina < (*disciplinas)->info.codigo_disciplina) {
            // Inserir na subárvore esquerda
            operacao = inserirArvBB_Disc(&(*disciplinas)->esq, novo);
        } else if (novo->info.codigo_disciplina > (*disciplinas)->info.codigo_disciplina) {
            // Inserir na subárvore direita
            operacao = inserirArvBB_Disc(&(*disciplinas)->dir, novo);
        } else {
            // O código da disciplina já existe na árvore
            operacao = 0; 
        }
    }

    return operacao; // Retorna 0 ou 1 conforme a operação
}


int verificar_disciplina(Arv_disc *disciplinas, int codigo_disciplina) {
    int operacao = 0; // Inicializa a operação como "não encontrada"

    if (disciplinas != NULL) {
        // Verifica se o código da disciplina é igual ao do nó atual
        if (disciplinas->info.codigo_disciplina == codigo_disciplina) {
            operacao = 1; // Disciplina encontrada
        } else if (codigo_disciplina < disciplinas->info.codigo_disciplina) {
            // Recursivamente busca na subárvore esquerda
            operacao = verificar_disciplina(disciplinas->esq, codigo_disciplina);
        } else {
            // Recursivamente busca na subárvore direita
            operacao = verificar_disciplina(disciplinas->dir, codigo_disciplina);
        }
    }

    return operacao; // Retorna 0 se não encontrou, ou 1 se encontrou
}


void imprimirArvBB_Disciplinas(Arv_disc *R) {
    if (R != NULL) {
        // Visitar o subárvore esquerda
        imprimirArvBB_Disciplinas(R->esq);

        // Imprimir o nó atual
        printf("\nCódigo da Disciplina: %d\n Nome da Disciplina: %s\n Periodo na Grade: %d\nCarga Horaria: %d horas\n", R->info.codigo_disciplina, R->info.nome_da_disciplina, R->info.periodo, R->info.carga_horaria);

        // Visitar o subárvore direita
        imprimirArvBB_Disciplinas(R->dir);
    }
}


void imprimirArvBB_Disciplinas_periodo_especifico(Arv_disc *R, int periodo) {
    if (R != NULL) {
        // Visitar o subárvore esquerda
        imprimirArvBB_Disciplinas_periodo_especifico(R->esq, periodo);

        // Imprimir o nó atual
        if(R->info.periodo == periodo){ 
          printf("\nCódigo da Disciplina: %d\n Nome da Disciplina: %s\n Periodo na Grade: %d\nCarga Horaria: %d horas\n", R->info.codigo_disciplina, R->info.nome_da_disciplina, R->info.periodo, R->info.carga_horaria);
        }
        // Visitar o subárvore direita
        imprimirArvBB_Disciplinas_periodo_especifico(R->dir, periodo);
    }
}







 

