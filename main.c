#include <stdio.h>
#include <stdlib.h>
#include "universidade.h"

int main(){
    int op1, op2;
    Arv_cursos *raiz;  
    raiz = NULL; 
   
    do{
        menu_principal(); // Corrigido
        scanf("%d", &op1); 
        switch (op1){
        case 1:
            do{
                menu_cadastrar(); // Chamar o menu de cadastro
                scanf("%d", &op2); 
                switch(op2){
                   case 1: 
                      //cadastrar aluno
                      break; 
                   case 2: 
                      //cadastrar curso
                      preencher_cursos(&raiz); 
                      break;
                   case 3: 
                     //isso deve sair daqui, é temporario
                      imprimirArvBB_Cursos(raiz); 
                      break;     
                   default: 
                      break; 



                }





            }while(op2 != 0); 
            



            break;

        case 2:
            menu_exibir(); // Chamar o menu de exibição
            // Você pode adicionar lógica adicional aqui
            break;

        case 3: 
            // Outras opções, se necessário
            break;        
        
        default:
            if (op1 != 0)
                printf("Opção inválida!\n");
            break;
        }
    } while(op1 != 0); // Sai do loop quando op1 for 0

    return 0;
}




/*

Menu Principal 

1- Menu Cadastrar 
2- Menu Exbir 
3- Menu Remover
4- Menu Testes 
0- Sair

Menu Cadastrar 

1 - Cadastrar Alunos 
2 - Cadastrar Cursos 
3 - Cadastrar Disciplinas 
4 - Cadastrar Matricula
5 - Cadastrar Notas
0 - Sair

Menu Exibir 

1 - Exibir Todos Alunos de Um Curso
2 - Exibir Todos os cursus do Campus
3 - Exibir Todas as Disciplinas de um Curso
4 - Exibir Todas as Disciplinas de um Curso em um Periodo Especifico 
5 - Exibir Todas as Disciplinas que um determinado Aluno está Matriculado
6 - Exibir todas as notas de disciplinas de um determinado período de um determinado aluno.
7 - Exibir nota de uma disciplina de um determinado aluno, mostrando o período e a carga horária da 
disciplina.
0 - Sair 

Menu Remover 

1 - Remover uma Disciplina de um Determinado Curso
2 - Remover uma disciplina da árvore de matrícula de um determinado aluno.
3 - Mostrar o histórico de um determinado aluno, contendo o nome do curso, as disciplinas e sua respectiva 
nota organizadas pelo período que a disciplina está cadastrada no curso. 
0 - Sair 




*/