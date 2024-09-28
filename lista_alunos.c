#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "universidade.h"

/*
int criarNo_Aluno(info_Aluno **aluno) {
    *aluno = (No_Aluno*)malloc(sizeof(No_Aluno));
    if (*aluno != NULL) {
        novo->aluno = aluno;
        novo->prox = NULL;
    }
    return novo;
}
*/


//Essa função aqui cria os nós da lista de alunos, ela é muito importante !!
int criarNo_Aluno(info_Aluno *temp, No_Aluno **novo) {
    int operacao = 1; 

    
    // Aloca memória para o novo nó
    *novo = (No_Aluno *) malloc(sizeof(No_Aluno));
    
    // Verifica se a alocação foi bem-sucedida
    if (*novo == NULL) {
        operacao = 0; // Falha na alocação de memória
    }else{
    
        // Preenche os dados do aluno no novo nó
        (*novo)->aluno.matricula = temp->matricula;
        strcpy((*novo)->aluno.nome_do_aluno, temp->nome_do_aluno);
        (*novo)->aluno.codigo_curso = temp->codigo_curso;
        (*novo)->aluno.notas = NULL;         // Inicializa ponteiros para NULL
        (*novo)->aluno.matriculas = NULL;
        
        // Aponta para o próximo nó como NULL (final da lista)
        (*novo)->prox = NULL;
    }    
    
    return operacao; 
}





// Função para inserir em ordem alfabética
int inserir_lista_alunos(No_Aluno **R, No_Aluno **novo) {
    int operacao = 1;
    No_Aluno *anterior = NULL;
    No_Aluno *atual = *R;
    
    // Verifica se a lista está vazia
    if (*R == NULL) {
        *R = *novo; // Insere o novo nó como o primeiro da lista
    } else {
        // Percorre a lista para encontrar o ponto de inserção
        while (atual != NULL) {
            // Verifica se já existe um aluno com a mesma matrícula
            if (atual->aluno.matricula == (*novo)->aluno.matricula) {
                operacao = 0; // Matrícula já existente, operação falha
                break;
            }
            
            // Verifica se o nome do novo aluno é alfabeticamente menor
            if (strcmp((*novo)->aluno.nome_do_aluno, atual->aluno.nome_do_aluno) < 0) {
                break; // Encontrou a posição para inserir antes de "atual"
            }

            anterior = atual; // Move o ponteiro anterior
            atual = atual->prox; // Avança na lista
        }

        // Verifica se a operação continua sendo válida (não houve matrícula duplicada)
        if (operacao == 1) {
            // Caso o novo nó deva ser o primeiro da lista
            if (anterior == NULL) {
                (*novo)->prox = *R; // O próximo do novo nó será o antigo primeiro nó (mexi aqui)
                *R = *novo;       // Atualiza a lista para apontar para o novo nó
            } else {
                // Inserção no meio ou no final da lista
                anterior->prox = *novo;
                (*novo)->prox = atual;
            }
        }
    }

    return operacao; // Retorna 1 para sucesso, 0 para falha (matrícula duplicada)
}


