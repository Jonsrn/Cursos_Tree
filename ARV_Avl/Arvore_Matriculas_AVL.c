#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include "universidade.h"


//uma função de criar o No da arvore de Matriculas

//Uma função de inserir na arvore de matriculas



//Essa função se refere ao item IV (Inserir Matriculas)
//A função "criarNo_Mat" é chamada pra criar o Nó que será inserida na árvore de Matriculas
int criarNo_Mat(int codigo_disciplina, Arv_Mat_Disc **novo){
   *novo = (Arv_Mat_Disc*)malloc(sizeof(Arv_Mat_Disc)); 
   int operacao = 1; 

   if(*novo != NULL){
      (*novo)->codigo_disciplina = codigo_disciplina; 
      (*novo)->esq = NULL; 
      (*novo)->dir = NULL; 
      (*novo)->altura = 0; 
   }else{
     operacao = 0; 
   }
   return operacao; 
}







int altura_Matricula(Arv_Mat_Disc *R) {
    int valor; 
    if (R == NULL) {
        valor = -1; //caso o nó seja nulo, o valor será -1
    }else{
        valor = R->altura; //caso não, o valor será atualizado de acordo com o valor armazenadado
    }

    return valor;  // o valor retorna
}



//Uma função pra atualizar a altura 

void atualizarAltura_Matricula(Arv_Mat_Disc *R) {
    int valor, esq, dir; 
    if (R != NULL) {
        esq = altura_Matricula(R->esq); 
        dir = altura_Matricula(R->dir); 
        if(esq > dir){
            valor = 1 + esq; 
        }else{
            valor = 1 + dir; 
        }

        R->altura = valor;
    }
}



//Função Rotação Direita

void rotacaoDir_Matricula(Arv_Mat_Disc **R) {
    // O filho esquerdo de R vai subir e se tornar a nova raiz
    Arv_Mat_Disc *novo_R = (*R)->esq;

    // O filho direito de novo_R se torna o filho esquerdo de R
    (*R)->esq = novo_R->dir;

    // novo_R se torna a nova raiz e R desce para a direita de novo_R
    novo_R->dir = *R;

    // Atualizar a altura de R e novo_R
    atualizarAltura_Matricula(*R);
    atualizarAltura_Matricula(novo_R);

    // Atualizar o ponteiro original R para apontar para o novo nó raiz
    *R = novo_R;
}


//Função Rotação Esquerda

void rotacaoEsq_Matricula(Arv_Mat_Disc **R) {
    // O filho direito de R vai subir e se tornar a nova raiz
    Arv_Mat_Disc *novo_R = (*R)->dir;

    // O filho esquerdo de novo_R se torna o filho direito de R
    (*R)->dir = novo_R->esq;

    // novo_R se torna a nova raiz e R desce para a esquerda de novo_R
    novo_R->esq = *R;

    // Atualizar a altura de R e novo_R
    atualizarAltura_Matricula(*R);
    atualizarAltura_Matricula(novo_R);

    // Atualizar o ponteiro original R para apontar para o novo nó raiz
    *R = novo_R;
}



//fator_balanceamento

int fatorBalanceamento_Matricula(Arv_Mat_Disc *R) {
    int valor, esq, dir; 
    if (R == NULL) {
        valor = 0;
    }else{
        esq = altura_Matricula(R->esq); 
        dir = altura_Matricula(R->dir); 
        valor = esq - dir; 
    }
    
    return valor;
}


//Função de balanceamento
void balanceamento_ArvAVL_Matricula(Arv_Mat_Disc **R){
    int fb; 
    fb = fatorBalanceamento_Matricula(*R);
    if(fb == -2){
        if(fatorBalanceamento_Matricula((*R)->dir) > 0){
            rotacaoDir_Matricula(&((*R)->dir)); 
        }
        rotacaoEsq_Matricula(R); 
    }else if(fb == 2){
        if(fatorBalanceamento_Matricula((*R)->esq) < 0){
            rotacaoEsq_Matricula(&((*R)->esq));
        }
        rotacaoDir_Matricula(R); 
    }
}



// Essa função se refere ao item IV (Inserir Matriculas) (tbm pode ser utilizada no Item V)
//A função "inserirArvBB_Mat" é chamada para inserir o nó na árvore de Matriculas
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

    atualizarAltura_Matricula(*matriculas); //Função que serve


    balanceamento_ArvAVL_Matricula(matriculas);

    return operacao; // Retorna 1 se inserido com sucesso, 0 se já existir
}

//Mostrar todas as disciplinas que um determinado aluno está matriculado (tbm pode ser utilizada no Item V)

void exibir_disciplinas_matriculadas(Arv_Mat_Disc *raiz, Arv_disc *disciplinas) {
    if (raiz != NULL) {
        // Ir para a subárvore esquerda
        exibir_disciplinas_matriculadas(raiz->esq, disciplinas);

        // Buscar a disciplina correspondente ao código encontrado na árvore de matrículas
        Arv_disc *disciplina_encontrada = NULL;
        buscar_disciplina(disciplinas, raiz->codigo_disciplina, &disciplina_encontrada);

        if (disciplina_encontrada != NULL) {
            printf("\nCódigo da Disciplina: %d\nNome da Disciplina: %s\nPeriodo: %d\nCarga Horária: %d horas\n",
                   disciplina_encontrada->info.codigo_disciplina,
                   disciplina_encontrada->info.nome_da_disciplina,
                   disciplina_encontrada->info.periodo,
                   disciplina_encontrada->info.carga_horaria);
        }

        // Ir para a subárvore direita
        exibir_disciplinas_matriculadas(raiz->dir, disciplinas);
    }
}




//Funções de remover matricula 
//Função auxiliar que cuida de encontrar menor Filho, pra efetuar a posterior remoção
//Essa função é utilizada em multiplos Itens (V, )

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


//Remove o nó da arvore de matriculas de um aluno
//Essa função é utilizda em multiplos itens (V, )

int removeArvBB_Matriculas(Arv_Mat_Disc **R, int codigo_disciplina) {
    Arv_Mat_Disc *aux, *endFilho, *endMenorFilho;
    int operacao = 1;  
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
    // Se o nó foi removido ou alterado, atualizar a altura e balancear a árvore
    if (*R != NULL) {
        atualizarAltura_Matricula(*R);  // Atualiza a altura do nó
        balanceamento_ArvAVL_Matricula(R);  // Balanceia a árvore após a remoção
    }

    return operacao;  // Retorna 1 se a remoção foi bem-sucedida, 0 caso contrário
}

int verificar_matricula_ARVMatricula(int codigo_disciplina, Arv_Mat_Disc *R){
   int operacao = 0; 

    if(R != NULL){    

        if(R->codigo_disciplina == codigo_disciplina){
            operacao = 1; 
        } 
        else if(codigo_disciplina < R->codigo_disciplina){
            operacao = verificar_matricula_ARVMatricula(codigo_disciplina, R->esq); 
        }
        else if(codigo_disciplina > R->codigo_disciplina){
                operacao = verificar_matricula_ARVMatricula(codigo_disciplina, R->dir);  
        }
    } 

    return operacao; 

}