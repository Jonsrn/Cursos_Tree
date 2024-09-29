#include <stdio.h>
#include <stdlib.h>
#include "universidade.h"

int main(){
    int op1, op2, op3, op4;
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
                      preencher_notas(&lista_alunos);
                      break;      
                   default: 
                      break; 



                }





            }while(op2 != 0); 
            



            break;

        case 2:
            do{
                menu_exibir();
                scanf("%d", &op3); 
                // Você pode adicionar lógica adicional aqui
                switch(op3){
                    case 2: 
                        imprimirArvBB_Cursos(cursos); 
                        break;
                    case 3: 
                    exibir_disc_do_curso(&cursos); 
                    //exibir todas as disciplinas daquele curso
                    break; 
                    case 4: 
                    exibir_disc_periodo_especifico(&cursos); 
                    //vai exibir todas as disciplinas de um curso especifico em um periodo especifico
                    break;   
                }
            }while(op3 != 0); 
            break;
        case 3:
            do{ 
                menu_excluir(); 
                scanf("%d", &op4); 
                switch(op4){

                case 2: 
                   remover_Matricula(&lista_alunos);
                   break;
                }   
            }while(op4 != 0); 

            break;        
        
        default:
            if (op1 != 0)
                printf("Opção inválida!\n");
            break;
        }
    } while(op1 != 0); // Sai do loop quando op1 for 0

    return 0;
}
