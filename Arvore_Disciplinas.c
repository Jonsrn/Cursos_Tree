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



void imprimirArvBB_Disciplinas_do_aluno(Arv_disc *R, int codigo_disciplina){
    if (R != NULL) {
        // Visitar o subárvore esquerda
        imprimirArvBB_Disciplinas_periodo_especifico(R->esq, codigo_disciplina);

        // Imprimir o nó atual
        if(R->info.periodo == codigo_disciplina){ 
          printf("\nCódigo da Disciplina: %d\n Nome da Disciplina: %s\n Periodo na Grade: %d\nCarga Horaria: %d horas\n", R->info.codigo_disciplina, R->info.nome_da_disciplina, R->info.periodo, R->info.carga_horaria);
        }
        // Visitar o subárvore direita
        imprimirArvBB_Disciplinas_periodo_especifico(R->dir, codigo_disciplina);
    }

}

// Função auxiliar para buscar uma disciplina na árvore de disciplinas
void buscar_disciplina(Arv_disc *raiz, int codigo_disciplina, Arv_disc **disciplina_encontrada) {
    if (raiz != NULL) {
        if (codigo_disciplina == raiz->info.codigo_disciplina) {
            *disciplina_encontrada = raiz; // Disciplina encontrada
        } else if (codigo_disciplina < raiz->info.codigo_disciplina) {
            buscar_disciplina(raiz->esq, codigo_disciplina, disciplina_encontrada); // Buscar na subárvore esquerda
        } else {
            buscar_disciplina(raiz->dir, codigo_disciplina, disciplina_encontrada); // Buscar na subárvore direita
        }
    }
}

//Funções de remoção

int menorFilho_Disc(Arv_disc *R, Arv_disc **menor) {
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



int ArvBB_Disc_Remover(Arv_disc **R, int codigo_disciplina){
    Arv_disc *aux, *endfilho, *endMenorFilho; 
    int operacao = 1; //1 significa sucesso 

    if(*R == NULL){
        operacao = 0; //Se a arvore de disciplinas estiver vazia, não há nada a ser feito
    }else{
        // se for menor, buscar na subarvore a esquerda
        if(codigo_disciplina < (*R)->info.codigo_disciplina){
            operacao = ArvBB_Disc_Remover(&((*R)->esq), codigo_disciplina); 
        }
        // se for maior, vai pra subarvore a direita
        else if(codigo_disciplina > (*R)->info.codigo_disciplina){
            operacao = ArvBB_Disc_Remover(&((*R)->dir), codigo_disciplina); 
        }
        else{
            //caso 1: O nó não tem filhos
            if((*R)->esq == NULL && (*R)->dir == NULL){
                aux = *R; 
                *R = NULL; //O nó passa a ser nulo
                free(aux); //A memória é liberada
            }
            //caso 2: O nó tem apenas um filho
            else if((*R)->esq == NULL || (*R)->dir == NULL){
                // Se o filho esquerdo é NULL, endFilho aponta para o filho direito e vice-versa 
                endfilho = (*R)->esq != NULL ? (*R)->esq : (*R)->dir; 
                aux = *R; 
                *R = endfilho; // Substitui o nó pelo seu único filho
                free(aux); // Libera a memória do nó
            }
            //caso 3: O nó tem dois filhos
            else{
                if(menorFilho_Disc((*R)->dir, &endMenorFilho)){
                    (*R)->info = endMenorFilho->info;
                    operacao = ArvBB_Disc_Remover(&((*R)->dir), endMenorFilho->info.codigo_disciplina); 
                }else{
                    //falhou em encontrar o menor filho 
                    operacao = 0; 
                }
            } 




        }
    }
    return operacao;  
}

 
