#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "universidade.h"


//Função de criar o Nó de Notas

int criarNo_Notas(Info_Notas temp, Arv_Not **novo){
    *novo = (Arv_Not*)malloc(sizeof(Arv_Not)); 
    int operacao = 1; 

    if(*novo != NULL){
        (*novo)->info.codigo_disciplina = temp.codigo_disciplina; 
        (*novo)->info.nota_final = temp.nota_final; 
        (*novo)->info.semestre_cursado = temp.semestre_cursado; 
        (*novo)->esq = NULL; 
        (*novo)->dir = NULL; 
    }else{
        operacao = 0; 
    }  
    return operacao; 
}

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
void imprimir_nota_aluno_materia_especifica(Arv_Not *notas, int codigo_disciplina){
    if(notas != NULL){
        imprimir_nota_aluno_materia_especifica(notas->esq, codigo_disciplina); 

        if(notas->info.codigo_disciplina == codigo_disciplina){
            printf("\nCodigo da Disciplina: %d\nNota Final: %.2f\nPeriodo Cursado: %d\n", notas->info.codigo_disciplina, notas->info.nota_final, notas->info.semestre_cursado); 
        }

        imprimir_nota_aluno_materia_especifica(notas->dir, codigo_disciplina);
    }

}
