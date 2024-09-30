#include <stdio.h>
#include <stdlib.h>
#include "universidade.h"

//Criar nó da Arvore de Cursos 
//Talvez eu substitua o parametro dessa função por uma unica struct

int criarNo_Cursos(int codigo, const char *nome, int periodos, Arv_cursos **novo) {
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


/*
//Uma função genérica, pra confirmar a existencia de um curso com determinado valor. 
int verificar_arv_Cursos(int codigo_curso, Arv_cursos *S) {
    int operacao = 0; // Inicialmente, assume que o curso não foi encontrado
    
    if (S != NULL) {
        if (S->info.codigo_do_curso == codigo_curso) {
            operacao = 1; // Curso encontrado
        } else if (codigo_curso < S->info.codigo_do_curso) {
            operacao = verificar_arv_Cursos(codigo_curso, S->esq); // Busca na subárvore esquerda
        } else {
            operacao = verificar_arv_Cursos(codigo_curso, S->dir); // Busca na subárvore direita
        }
    }

    return operacao; // Único ponto de retorno
}

*/


//Essa função recupera o endereço do nó do curso pesquisado
int verificar_arv_Cursos(int codigo_curso, Arv_cursos *S, Arv_cursos **resultado) {
    int operacao = 0; // Inicializa a operação como não encontrada

    if (S != NULL) {
        // Se o curso for encontrado
        if (S->info.codigo_do_curso == codigo_curso) {
            *resultado = S; // Armazena o endereço do nó encontrado
            operacao = 1; // Atualiza a operação para encontrado
        } else if (codigo_curso < S->info.codigo_do_curso) {
            // Busca na subárvore esquerda
            operacao = verificar_arv_Cursos(codigo_curso, S->esq, resultado);
        } else {
            // Busca na subárvore direita
            operacao = verificar_arv_Cursos(codigo_curso, S->dir, resultado);
        }
    }    

    return operacao; // Retorna o resultado da operação
}








void imprimirArvBB_Cursos(Arv_cursos *R) {
    if (R != NULL) {
        // Visitar o subárvore esquerda
        imprimirArvBB_Cursos(R->esq);

        // Imprimir o nó atual
        printf("\nCódigo do Curso: %d\n Nome do Curso: %s\n Quantidade de Períodos: %d\n", 
               R->info.codigo_do_curso, 
               R->info.nome_do_curso, 
               R->info.qtdade_de_periodos);

        // Visitar o subárvore direita
        imprimirArvBB_Cursos(R->dir);
    }
}


