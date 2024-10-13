#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "universidade.h"


//Função de criar o Nó de Notas
//Essa função é referente ao item V (Inserir Notas)

int criarNo_Notas(Info_Notas temp, Arv_Not **novo){
    *novo = (Arv_Not*)malloc(sizeof(Arv_Not)); 
    int operacao = 1; 

    if(*novo != NULL){
        (*novo)->info.codigo_disciplina = temp.codigo_disciplina; 
        (*novo)->info.nota_final = temp.nota_final; 
        (*novo)->info.semestre_cursado = temp.semestre_cursado; 
        (*novo)->esq = NULL; 
        (*novo)->dir = NULL; 
        (*novo)->altura = 0; 
    }else{
        operacao = 0; 
    }  
    return operacao; 
}

//Precisa de uma função pra altura 

int altura_Notas(Arv_Not *R) {
    int valor; 
    if (R == NULL) {
        valor = -1; //caso o nó seja nulo, o valor será -1
    }else{
        valor = R->altura; //caso não, o valor será atualizado de acordo com o valor armazenadado
    }

    return valor;  // o valor retorna
}


//Uma função pra atualizar a altura 

void atualizarAltura_Notas(Arv_Not *R) {
    int valor, esq, dir; 
    if (R != NULL) {
        esq = altura_Notas(R->esq); 
        dir = altura_Notas(R->dir); 
        if(esq > dir){
            valor = 1 + esq; 
        }else{
            valor = 1 + dir; 
        }

        R->altura = valor;
    }
}



//Função Rotação Direita

void rotacaoDir_Notas(Arv_Not **R) {
    // O filho esquerdo de R vai subir e se tornar a nova raiz
    Arv_Not *novo_R = (*R)->esq;

    // O filho direito de novo_R se torna o filho esquerdo de R
    (*R)->esq = novo_R->dir;

    // novo_R se torna a nova raiz e R desce para a direita de novo_R
    novo_R->dir = *R;

    // Atualizar a altura de R e novo_R
    atualizarAltura_Notas(*R);
    atualizarAltura_Notas(novo_R);

    // Atualizar o ponteiro original R para apontar para o novo nó raiz
    *R = novo_R;
}


//Função Rotação Esquerda

void rotacaoEsq_Notas(Arv_Not **R) {
    // O filho direito de R vai subir e se tornar a nova raiz
    Arv_Not *novo_R = (*R)->dir;

    // O filho esquerdo de novo_R se torna o filho direito de R
    (*R)->dir = novo_R->esq;

    // novo_R se torna a nova raiz e R desce para a esquerda de novo_R
    novo_R->esq = *R;

    // Atualizar a altura de R e novo_R
    atualizarAltura_Notas(*R);
    atualizarAltura_Notas(novo_R);

    // Atualizar o ponteiro original R para apontar para o novo nó raiz
    *R = novo_R;
}



//fator_balanceamento

int fatorBalanceamento_Notas(Arv_Not *R) {
    int valor, esq, dir; 
    if (R == NULL) {
        valor = 0;
    }else{
        esq = altura_Notas(R->esq); 
        dir = altura_Notas(R->dir); 
        valor = esq - dir; 
    }
    
    return valor;
}


//Função de balanceamento
void balanceamento_ArvAVL_Notas(Arv_Not **R){
    int fb; 
    fb = fatorBalanceamento_Notas(*R);
    if(fb == -2){
        if(fatorBalanceamento_Notas((*R)->dir) > 0){
            rotacaoDir_Notas(&((*R)->dir)); 
        }
        rotacaoEsq_Notas(R); 
    }else if(fb == 2){
        if(fatorBalanceamento_Notas((*R)->esq) < 0){
            rotacaoEsq_Notas(&((*R)->esq));
        }
        rotacaoDir_Notas(R); 
    }
}



//Essa função insere o nó criado na árvore de Notas
//Essa função é referente ao item V (Inserir Notas)
int inserirArvBB_Notas(Arv_Not **notas, Arv_Not *novo){
    int operacao = 1; 

    if(*notas == NULL){
        *notas = novo; 
    }else{
        //inicio das comparações
        if(novo->info.codigo_disciplina < (*notas)->info.codigo_disciplina){
            operacao = inserirArvBB_Notas(&(*notas)->esq, novo); 
        } else if(novo->info.codigo_disciplina > (*notas)->info.codigo_disciplina){
            operacao = inserirArvBB_Notas(&(*notas)->dir, novo); 
        }else{
            //já existe um valor igual
            operacao = 0; 
        }
    }

    atualizarAltura_Notas(*notas); //Função que serve


    balanceamento_ArvAVL_Notas(notas);



    return operacao; 
}









//Essa função serve pra percorrer a árvore de Notas do aluno 
int armazenar_Nos_Arv_Notas(Arv_Not *R, Arv_Not ***vetor, int *tamanho){
    int operacao; 
    operacao = 1;

    if(R != NULL){
        //visita a subarvore da esquerda
         operacao = armazenar_Nos_Arv_Notas(R->esq, vetor, tamanho); 
         
         //se houver algum problema, a operação é abortada; 
         if(operacao == 1){
              //agr a realocação do vetor

              *vetor = (Arv_Not **)realloc(*vetor, (*tamanho + 1) * sizeof(Arv_Not *)); 
              if(*vetor == NULL){
                  printf("\nErro na alocação do vetor\n"); 
                  operacao = 0; 
              }else{
                  //armazena o endereço do nó no vetor
                  (*vetor)[*tamanho] = R; 
                  (*tamanho)++; //incrementa o tamanho do vetor


                  //Proximo passo é visitar a sub-arvore à direita

                  operacao = armazenar_Nos_Arv_Notas(R->dir, vetor, tamanho); 
              }

         }
    } 

    return operacao; 
}





//Função de imprimir 


void imprimir_notas_aluno_periodo(Arv_Not *notas, int periodo){
    if(notas != NULL){
        imprimir_notas_aluno_periodo(notas->esq, periodo); 

        if(notas->info.semestre_cursado == periodo){
            printf("\nCodigo da Disciplina: %d\nNota Final: %.2f\nPeriodo Cursado: %d\n", notas->info.codigo_disciplina, notas->info.nota_final, notas->info.semestre_cursado); 
        }

        imprimir_notas_aluno_periodo(notas->dir, periodo); 
    }
}

//imprimir a nota do aluno baseada no codigo da disciplina
int imprimir_nota_aluno_materia_especifica(Arv_Not *notas, int codigo_disciplina, int opcao) {
    int operacao = 0;

    if (notas != NULL) {
        // Verificar na subárvore esquerda
        operacao = imprimir_nota_aluno_materia_especifica(notas->esq, codigo_disciplina, opcao);

        // Se a nota foi encontrada na subárvore esquerda, não é necessário continuar
        if (operacao == 0 && notas->info.codigo_disciplina == codigo_disciplina) {
            if (opcao == 1) {
                printf("\nCodigo da Disciplina: %d\nNota Final: %.2f\nPeriodo Cursado: %d\n", notas->info.codigo_disciplina, notas->info.nota_final, notas->info.semestre_cursado);
            }
            operacao = 1;  // Nota encontrada
        }

        // Continuar a busca na subárvore direita, se ainda não encontrou
        if (operacao == 0) {
            operacao = imprimir_nota_aluno_materia_especifica(notas->dir, codigo_disciplina, opcao);
        }
    }

    return operacao;  // Retorna 1 se encontrou a nota, 0 caso contrário
}


//Um metodo de ordenação pra cuidar de ordenar as disciplinas por ordem de periodo, ao invés de codigo da disciplina;

void ordenarDisciplinasPorPeriodo(Arv_disc **vetorDisc, int tamDisc) {
    for (int i = 0; i < tamDisc - 1; i++) {
        for (int j = 0; j < tamDisc - i - 1; j++) {
            if (vetorDisc[j]->info.periodo > vetorDisc[j + 1]->info.periodo) {
                // Troca os elementos se estiverem fora de ordem
                Arv_disc *temp = vetorDisc[j];
                vetorDisc[j] = vetorDisc[j + 1];
                vetorDisc[j + 1] = temp;
            }
        }
    }
}


//Essa função cuidará de imprimir as matérias pagas do aluno, na ordem de periodos do curso. 

void imprimir_historico_Por_Periodo(Arv_disc **vetorDisc, int tamDisc, Arv_Not **vetorNotas, int tamNotas) {
    // Ordenar o vetor de disciplinas pelo período
    ordenarDisciplinasPorPeriodo(vetorDisc, tamDisc);

    // Percorrer o vetor de disciplinas e, para cada disciplina, procurar a nota correspondente
    for (int i = 0; i < tamDisc; i++) {
        int codigoDisciplina = vetorDisc[i]->info.codigo_disciplina;
        int periodo = vetorDisc[i]->info.periodo;
        
        // Encontrar a nota correspondente para essa disciplina
        for (int j = 0; j < tamNotas; j++) {
            if (vetorNotas[j]->info.codigo_disciplina == codigoDisciplina) {
                printf("\nDisciplina: %s, Periodo: %d, Nota: %.2f\n",
                       vetorDisc[i]->info.nome_da_disciplina,
                       periodo,
                       vetorNotas[j]->info.nota_final);
                break; // Sai do loop assim que encontrar a nota correspondente
            }
        }
    }
}
