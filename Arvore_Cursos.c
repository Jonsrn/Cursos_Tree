#include <stdio.h>
#include <stdlib.h>
#include "universidade.h"

int criarNo(int codigo, const char *nome, int periodos, Arv_cursos **novo) {
    *novo = (Arv_cursos*)malloc(sizeof(Arv_cursos));  // Aloca memória para o novo nó
    int operacao = 1; 

    if (*novo != NULL) {
        // Inicializando os campos da nova estrutura Arvore_Cursos
        (*novo)->info.codigo_do_curso = codigo;
        snprintf((*novo)->info.nome_do_curso, sizeof((*novo)->info.nome_do_curso), "%s", nome);
        (*novo)->info.qtdade_de_periodos = periodos;
        (*novo)->esq = NULL;       // Inicializando o ponteiro esquerdo como NULL
        (*novo)->dir = NULL;       // Inicializando o ponteiro direito como NULL
        (*novo)->info.disciplinas = NULL;  // Inicializando o ponteiro de disciplinas como NULL
        ;  // Indica que a operação foi bem-sucedida
    }else{
        operacao = 0;
    }
    return operacao;  // Indica que a operação falhou
}




int inserirArvBB_Cursos(Arv_cursos **R, Arv_cursos *No) {
    int inserir = 1;

    // Se o nó raiz é NULL, insere o novo nó aqui
    if (*R == NULL) {
        *R = No;
    }
    // Comparando o campo codigo_do_curso dentro de info
    else if (No->info.codigo_do_curso < (*R)->info.codigo_do_curso) {
        inserir = inserirArvBB_Cursos(&((*R)->esq), No);
    }
    else if (No->info.codigo_do_curso > (*R)->info.codigo_do_curso) {
        inserir = inserirArvBB_Cursos(&((*R)->dir), No);
    }
    else {
        // Se os códigos são iguais, o curso já existe
        inserir = 0; 
    }

    return inserir; 
}

void imprimirArvBB_Cursos(Arv_cursos *R) {
    if (R != NULL) {
        // Visitar o subárvore esquerda
        imprimirArvBB_Cursos(R->esq);

        // Imprimir o nó atual
        printf("Código do Curso: %d, Nome do Curso: %s, Quantidade de Períodos: %d\n", 
               R->info.codigo_do_curso, 
               R->info.nome_do_curso, 
               R->info.qtdade_de_periodos);

        // Visitar o subárvore direita
        imprimirArvBB_Cursos(R->dir);
    }
}
