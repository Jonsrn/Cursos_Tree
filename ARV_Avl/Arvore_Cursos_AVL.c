#include <stdio.h>
#include <stdlib.h>
#include "universidade.h"


// Função referente ao Item II (Cadastrar Cursos)
//Essa função cria um Nó na árvore de Cursos
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
        (*novo)->altura = 0; 
        ;  // Indica que a operação foi bem-sucedida
    }else{
        operacao = 0;
    }
    return operacao;  // Indica que a operação falhou
}

//Precisa de uma função pra altura 

int altura_curso(Arv_cursos *R) {
    int valor; 
    if (R == NULL) {
        valor = -1; //caso o nó seja nulo, o valor será -1
    }else{
        valor = R->altura; //caso não, o valor será atualizado de acordo com o valor armazenadado
    }

    return valor;  // o valor retorna
}


//Uma função pra atualizar a altura 

void atualizarAltura_Cursos(Arv_cursos *R) {
    int valor, esq, dir; 
    if (R != NULL) {
        esq = altura_curso(R->esq); 
        dir = altura_curso(R->dir); 
        if(esq > dir){
            valor = 1 + esq; 
        }else{
            valor = 1 + dir; 
        }

        R->altura = valor;
    }
}



//Função Rotação Direita

void rotacaoDir_Cursos(Arv_cursos **R) {
    // O filho esquerdo de R vai subir e se tornar a nova raiz
    Arv_cursos *novo_R = (*R)->esq;

    // O filho direito de novo_R se torna o filho esquerdo de R
    (*R)->esq = novo_R->dir;

    // novo_R se torna a nova raiz e R desce para a direita de novo_R
    novo_R->dir = *R;

    // Atualizar a altura de R e novo_R
    atualizarAltura_Cursos(*R);
    atualizarAltura_Cursos(novo_R);

    // Atualizar o ponteiro original R para apontar para o novo nó raiz
    *R = novo_R;
}


//Função Rotação Esquerda

void rotacaoEsq_Cursos(Arv_cursos **R) {
    // O filho direito de R vai subir e se tornar a nova raiz
    Arv_cursos *novo_R = (*R)->dir;

    // O filho esquerdo de novo_R se torna o filho direito de R
    (*R)->dir = novo_R->esq;

    // novo_R se torna a nova raiz e R desce para a esquerda de novo_R
    novo_R->esq = *R;

    // Atualizar a altura de R e novo_R
    atualizarAltura_Cursos(*R);
    atualizarAltura_Cursos(novo_R);

    // Atualizar o ponteiro original R para apontar para o novo nó raiz
    *R = novo_R;
}



//fator_balanceamento

int fatorBalanceamento_cursos(Arv_cursos *R) {
    int valor, esq, dir; 
    if (R == NULL) {
        valor = 0;
    }else{
        esq = altura_curso(R->esq); 
        dir = altura_curso(R->dir); 
        valor = esq - dir; 
    }
    
    return valor;
}


//Função de balanceamento
void balanceamento_ArvAVL_Cursos(Arv_cursos **R){
    int fb; 
    fb = fatorBalanceamento_cursos(*R);
    if(fb == -2){
        if(fatorBalanceamento_cursos((*R)->dir) > 0){
            rotacaoDir_Cursos(&((*R)->dir)); 
        }
        rotacaoEsq_Cursos(R); 
    }else if(fb == 2){
        if(fatorBalanceamento_cursos((*R)->esq) < 0){
            rotacaoEsq_Cursos(&((*R)->esq));
        }
        rotacaoDir_Cursos(R); 
    }
}




// Função referente ao Item II (Cadastrar Cursos)
//Essa função insere o nó criado na árvore de Cursos
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
    
    atualizarAltura_Cursos(*R); //Função que serve


    balanceamento_ArvAVL_Cursos(R);

    
    

    return inserir; 
}



//Essa função recupera o endereço do nó do curso pesquisado
//Função utilizada em muitos itens (I, III, IV )
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






//Função que imprime em ordem todos os cursos presentes na árvore
//Essa função se refere ao Item VII (Imprimir todos os cursos)
void imprimirArvBB_Cursos(Arv_cursos *R) {
    if (R != NULL) {
        // Visitar o subárvore esquerda
        imprimirArvBB_Cursos(R->esq);

        // Imprimir o nó atual
        printf("\nCódigo do Curso: %d\nNome do Curso: %s\nQuantidade de Períodos: %d\n", 
               R->info.codigo_do_curso, 
               R->info.nome_do_curso, 
               R->info.qtdade_de_periodos);

        // Visitar o subárvore direita
        imprimirArvBB_Cursos(R->dir);
    }
}


