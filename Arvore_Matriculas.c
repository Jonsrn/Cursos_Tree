#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include "universidade.h"


//uma função de criar o No da arvore de Matriculas

//Uma função de inserir na arvore de matriculas




int criarNo_Mat(int codigo_disciplina, Arv_Mat_Disc **novo){
   *novo = (Arv_Mat_Disc*)malloc(sizeof(Arv_Mat_Disc)); 
   int operacao = 1; 

   if(*novo != NULL){
      (*novo)->codigo_disciplina = codigo_disciplina; 
      (*novo)->esq = NULL; 
      (*novo)->dir = NULL; 
   }else{
     operacao = 0; 
   }
   return operacao; 
}

int inserirArvBB_Mat(Arv_Mat_Disc **matriculas, Arv_Mat_Disc *nova_matricula) {
    int operacao = 1;

    // Verifica se a subárvore de matrículas está vazia
    if (*matriculas == NULL) {
        *matriculas = nova_matricula; // Insere a nova matrícula
    } else if (nova_matricula->codigo_disciplina < (*matriculas)->codigo_disciplina) {
        // Insere na subárvore esquerda
        operacao = inserirArvBB_Mat(&(*matriculas)->esq, nova_matricula);
    } else if (nova_matricula->codigo_disciplina > (*matriculas)->codigo_disciplina) {
        // Insere na subárvore direita
        operacao = inserirArvBB_Mat(&(*matriculas)->dir, nova_matricula);
    } else {
        // Se já existe uma matrícula com o mesmo código da disciplina, não insere
        operacao = 0; // Matrícula duplicada
    }

    return operacao; // Retorna 1 se inserido com sucesso, 0 se já existir
}



//Funções de remover matricula

int menorFilho(Arv_Mat_Disc *R, Arv_Mat_Disc **menor) {
    // Inicialmente, assume que não encontrou
    int operacao = 0;

    // Verifica se a árvore está vazia
    if (R != NULL) {
        // Percorre até encontrar o nó mais à esquerda
        while (R->esq != NULL) {
            R = R->esq;
        }

        // Quando encontra o menor nó
        *menor = R;
        operacao = 1;
    }

    // Retorna 1 se encontrou o menor nó, 0 caso contrário
    return operacao;
}



int removeArvBB_Matriculas(Arv_Mat_Disc **R, int codigo_disciplina) {
    Arv_Mat_Disc *aux, *endFilho, *endMenorFilho;
    int operacao = 1;  // Inicialmente, assume-se que a remoção teve sucesso

    // Verifica se a árvore está vazia
    if (*R == NULL) {
        operacao = 0;  // Código da disciplina não encontrado
    } else {
        // Se o código da disciplina for menor que o nó atual, busca na subárvore esquerda
        if (codigo_disciplina < (*R)->codigo_disciplina) {
            operacao = removeArvBB_Matriculas(&((*R)->esq), codigo_disciplina);
        }
        // Se o código da disciplina for maior que o nó atual, busca na subárvore direita
        else if (codigo_disciplina > (*R)->codigo_disciplina) {
            operacao = removeArvBB_Matriculas(&((*R)->dir), codigo_disciplina);
        }
        // Se o código da disciplina for encontrado
        else {
            // Caso 1: O nó é uma folha (não tem filhos)
            if ((*R)->esq == NULL && (*R)->dir == NULL) {
                aux = *R;
                *R = NULL;  // O nó é removido
                free(aux);  // Libera a memória do nó
            }
            // Caso 2: O nó tem apenas um filho
            else if ((*R)->esq == NULL || (*R)->dir == NULL) {
                // Se o filho esquerdo é NULL, endFilho aponta para o filho direito e vice-versa
                endFilho = (*R)->esq != NULL ? (*R)->esq : (*R)->dir;
                aux = *R;
                *R = endFilho;  // Substitui o nó pelo seu único filho
                free(aux);  // Libera a memória do nó
            }
            // Caso 3: O nó tem dois filhos
            else {
                // Encontra o menor nó na subárvore direita (sucessor)
                if (menorFilho((*R)->dir, &endMenorFilho)) {
                    (*R)->codigo_disciplina = endMenorFilho->codigo_disciplina;  // Substitui o valor do nó a ser removido
                    operacao = removeArvBB_Matriculas(&((*R)->dir), endMenorFilho->codigo_disciplina);  // Remove o nó substituto
                } else {
                    operacao = 0;  // Falhou ao encontrar o menor filho
                }
            }
        }
    }

    return operacao;  // Retorna 1 se a remoção foi bem-sucedida, 0 caso contrário
}


