#include <stdio.h>
#include <stdlib.h>
#include "universidade.h"

int main(){
    int op1, op2;
    Arv_cursos *cursos;  
    cursos = NULL; 
    No_Aluno *lista_alunos; 
    lista_alunos = NULL; 
   
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
                      preencher_alunos(&lista_alunos, &cursos); 
                      break; 
                   case 2: 
                      //cadastrar curso
                      preencher_cursos(&cursos); 
                      break;
                   case 3: 
                      preencherDisciplinas(&cursos); 
                      break;
                   case 4: 
                      preencher_matriculas(&lista_alunos, cursos); 
                      break; 
                   case 5: 
                     //isso deve sair daqui, é temporario
                      imprimirArvBB_Cursos(cursos); 
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

