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

