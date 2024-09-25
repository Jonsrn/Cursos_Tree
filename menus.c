#include <stdio.h>
#include <stdlib.h>
#include "universidade.h"

void menu_principal(){
 
    printf("Menu Principal\n"); 
    printf("1- Menu Cadastrar\n"); 
    printf("2- Menu Exibir\n"); 
    printf("3- Menu Remover\n"); 
    printf("4- Menu Testes\n"); 
    printf("0- Sair\n"); 
}

void menu_cadastrar(){

    printf("Menu Cadastrar\n"); 
    printf("1- Cadastrar Alunos\n"); 
    printf("2- Cadastrar Cursos\n"); 
    printf("3- Cadastrar Disciplinas\n"); 
    printf("4- Cadastrar Matricula\n"); 
    printf("5 - Cadastrar Notas\n"); 
    printf("0 - Sair\n"); 

}

void menu_exibir(){
   
   printf("Menu Exibir\n"); 
   printf("1 - Exibir Todos Alunos de Um Curso\n"); 
   printf("2 - Exibir Todos os cursus do Campus\n"); 
   printf("3 - Exibir Todas as Disciplinas de um Curso\n"); 
   printf("4 - Exibir Todas as Disciplinas de um Curso em um Periodo Especifico\n"); 
   printf("5 - Exibir Todas as Disciplinas que um determinado Aluno está Matriculado\n"); 
   printf("6 - Exibir todas as notas de disciplinas de um determinado período de um determinado aluno.\n"); 
   printf("7 - Exibir nota de uma disciplina de um determinado aluno, mostrando o período e a carga horária da disciplina.\n"); 
   printf("0 - Sair\n"); 
}

void menu_excluir(){
    printf("Menu Remover\n"); 
    printf("1 - Remover uma Disciplina de um Determinado Curso\n");
    printf("2 - Remover uma disciplina da árvore de matrícula de um determinado aluno."); 
    printf("3 - Mostrar o histórico de um determinado aluno, contendo o nome do curso, as disciplinas e sua respectiva nota organizadas pelo período que a disciplina está cadastrada no curso.\n"); 
    printf("0 - Sair\n");  
}

void mensagens_tela_cadastro(int opcao, int resposta){
   if(opcao == 2){
       if(resposta == 1){
        printf("Curso inserido com sucesso"); 
       }else{
        printf("Falha na Inserção, o curso com esse código já existe"); 
       }
   }




}



void preencher_cursos(Arv_cursos **R){
    int operacao = 1; 
    char nome_curso[100]; 
    int codigo_curso; 
    int qtdade_periodos; 
    Arv_cursos *no;
    no = NULL; 
    
     
    printf("Digite o código do curso: "); 
    scanf("%d", &codigo_curso); 
    while (getchar() != '\n');
    printf("Digite o nome do curso: "); 
    fgets(nome_curso, 100, stdin); 
    printf("Digite a quantidade de periodos desse curso: "); 
    scanf("%d", &qtdade_periodos); 
    
    operacao = criarNo(codigo_curso, nome_curso, qtdade_periodos, &no); 

    if(operacao == 1){
        operacao =  inserirArvBB_Cursos(R, no); 
    }
      
    mensagens_tela_cadastro(2, operacao); 
}