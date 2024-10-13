#include <stdio.h>
#include <stdlib.h>
#include "universidade.h"

int main(){
    int op1, op2, op3, op4, op5, op6, op7, op8;
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
                      /*Item I - Cadastrar alunos a qualquer momento na lista, de forma que só possa cadastrar um 
                      código de curso que já tenha sido cadastrado na árvore de cursos.                       
                      */ 
                      //Essa é a primeira função, serve pra coletar os dados necessários para o cadastro dos alunos e cuida das devidas mensagens. 
                      preencher_alunos(&lista_alunos, &cursos); 
                      break; 
                   case 2: 
                      //cadastrar curso
                      /*
                      Item II- Cadastrar Cursos, insere os cursos na árvore de Cursos
                      */
                      preencher_cursos(&cursos); 
                      break;
                   case 3: 
                      /*
                        Função referente ao Item III- Cadastrar Disciplinas
                      */
                      preencherDisciplinas(&cursos); 
                      break;
                   case 4: 
                      //Função referente ao Item IV- Cadastrar Matriculas
                      preencher_matriculas(&lista_alunos, cursos); 
                      break; 
                   case 5: 
                      //Função referente ao Item V- Cadastrar Notas
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
                switch(op3){
                    case 1: 
                        //Função referente ao Item VI- (Exibir todos os alunos daquele curso)
                        exibir_todos_alunos_curso(lista_alunos, cursos); 
                        //exbir todos os alunos cadastrados naquele curso 
                        break; 
                    case 2: 
                        //Função referente ao Item VII (Exibir todos os Cursos)
                        exibir_todos_cursos(cursos);                          
                        break;
                    case 3: 
                        exibir_disc_do_curso(&cursos); 
                        //exibir todas as disciplinas daquele curso
                        break; 
                    case 4: 
                        exibir_disc_periodo_especifico(&cursos); 
                        //vai exibir todas as disciplinas de um curso especifico em um periodo especifico
                        break;   
                    case 5: 
                        mostrar_todas_disc_aluno(&lista_alunos, &cursos); 
                        //vai exibir todas as disciplinas matriculadas pelo aluno
                        break;
                    case 6: 
                        exibir_notas_periodo(&lista_alunos); 
                        //Essa função exibe as notas de um aluno especifico, em um periodo especifico
                        break;   
                    case 7: 
                        mostrar_nota_disciplina(&lista_alunos); 
                        //Essa função exibe as notas de um aluno especifico, de uma matéria especifica
                        break;     
                    case 8: 
                        mostrar_historico_aluno(&cursos, &lista_alunos); 
                        //Essa função vai exibir o historico do aluno, organizado pela ordem das disciplinas do curso; 
                        break;     
                            
                }
            }while(op3 != 0); 
            break;
        case 3:
            do{ 
                menu_excluir(); 
                scanf("%d", &op4); 
                switch(op4){
                   
                   case 1: 
                      remover_disc_curso(&lista_alunos, &cursos); 
                      break; 
                   case 2: 
                      remover_Matricula(&lista_alunos);
                      break;
                }   
            }while(op4 != 0); 

            break; 

        case 4: 
    do {
        // Aqui é o menu principal dos testes
        menu_testes(); 
        scanf("%d", &op5); 
        switch(op5) {
            case 1:
                do {
                    // Etapas do teste inserção ou medição
                    teste_cursos(); 
                    scanf("%d", &op6); 
                    switch(op6) {
                        case 1: 
                            // Inserção  
                            do {
                                menu_insercao(); 
                                scanf("%d", &op7); 

                                switch(op7) {
                                    case 1: 
                                        // Inserir Ordenado crescente
                                        //teste_insercao_cursos("cursos_ordenados.txt", &cursos, 25000);
                                        executar_testes_insercao(&cursos, 1);
                                        break; 

                                    case 2: 
                                        // Inserir Ordenado Decrescente
                                        //teste_insercao_cursos("cursos_decrescentes.txt", &cursos, 25000);
                                        executar_testes_insercao(&cursos, 2); 
                                        break; 

                                    case 3: 
                                        // Inserir aleatório
                                        //teste_insercao_cursos("cursos_aleatorios.txt", &cursos, 25000);
                                        executar_testes_insercao(&cursos, 3);
                                        break;

                                    default:
                                        if (op7 != 0)
                                            printf("Opção inválida!\n");
                                        break;
                                }
                            } while(op7 != 0); 
                            break;

                        default:
                            if (op6 != 0)
                                printf("Opção inválida!\n");
                            break;
                    }
                } while(op6 != 0); 
                break;
            case 2: 
                //Teste de busca
                do{
                   menu_medicao_nota();
                   scanf("%d", &op8); 

                   switch(op8){
                        case 1: 
                           teste_de_busca(&cursos, &lista_alunos); 
                           break; 
                        default:
                           if(op8 != 0){
                               printf("Opção Inválida\n"); 
                           }   
                           
                   }   

                }while(op8 != 0);   

            default:
                if (op5 != 0)
                    printf("Opção inválida!\n");
                break;
        }
    } while(op5 != 0);     
    break;        
        
        default:
            if (op1 != 0)
                printf("Opção inválida!\n");
            break;
        }
    } while(op1 != 0); // Sai do loop quando op1 for 0

    return 0;
}

