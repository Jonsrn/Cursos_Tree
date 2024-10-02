#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "universidade.h"

void menu_principal(){
 
    printf("\nMenu Principal\n"); 
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
   printf("8 - Mostrar o histórico de um determinado aluno, contendo o nome do curso, as disciplinas e sua respectiva nota organizadas pelo período que a disciplina está cadastrada no curso.\n");
   printf("0 - Sair\n"); 
}

void menu_excluir(){
    printf("Menu Remover\n"); 
    printf("1 - Remover uma Disciplina de um Determinado Curso\n");
    printf("2 - Remover uma disciplina da árvore de matrícula de um determinado aluno.\n"); 
    printf("0 - Sair\n");  
}

//isso aqui deve mudar
void mensagens_tela_cadastro(int opcao, int resposta){
   if(opcao == 2){
       if(resposta == 1){
        printf("Curso inserido com sucesso"); 
       }else{
        printf("Falha na Inserção, o curso com esse código já existe"); 
       }
   }
}

void mensagens_cadastro_aluno(int situacao){
   //situação 0 significa que a operação funcionou conforme esperado
   if(situacao == 0){
     
      printf("Operação realizada com sucesso.\n"); 
    
   }
   if(situacao == 1){
      printf("A operação falhou, pois houve falha na alocação da memória.\n"); 
   }
   //situação 1 informa que a operação parou na inserção da matricula do aluno na lista 
   if(situacao == 2){ 
      printf("A operação falhou porque já existe alguém com essa matricula.\n");
      
   }
   //Situação 2 informa que a operação parou na verificação da existencia do curso na arvore
   if(situacao == 3){
      printf("A operação falhou porque nenhum curso correspondente ao digitado foi encontrado.\n"); 
   }
}

//mensagens de feedback sobre resultado da operação de inserção de disciplina em determinado curso.
void mensagens_cadastro_disciplina(int situacao){
    if(situacao == 0){
       printf("Disciplina Cadastrada com Sucesso!\n"); 
    }
    if(situacao == 1){
        printf("A operação falhou porque nenhum curso com esse codigo foi encontrado.\n"); 
    }
    if(situacao == 2){
        printf("A operacao falhou porque o Nó não foi alocado corretamente.\n"); 
    }
    if(situacao == 3){
        printf("A operação falhou porque um curso de mesmo codigo foi inserido anteriormente.\n");
    }
}

void mensagens_cadastro_matricula(int situacao){
    if(situacao == 0){
        printf("Disciplina matriculada com sucesso\n"); 
    }
    if(situacao == 1){
        printf("A operação falhou porque o aluno não está na lista\n"); 
    }
    if(situacao == 2){
        printf("A operação falhou porque a disciplina solicitada não está disponivel no curso\n"); 
    }
    if(situacao == 3){
        printf("A operação falhou porque o Nó não foi alocado corretamente\n"); 
    }
    if(situacao == 4){
        printf("A operação falhou poruque não foi possivel a inserção na árvore de matriculas\n"); 
    }
}

void mensagens_cadastro_notas(int situacao){
    if(situacao == 0){
        printf("Cadastro de Notas Efetuado com Sucesso\n"); 
    }
    if(situacao == 1){
        printf("A operação falhou porque o aluno buscado não foi encontrado\n");
    }
    if(situacao == 2){
        printf("A operação falhou porque a disciplina não foi encontrada ou a remoção falhou.\n"); 
    }
    if(situacao == 3){
        printf("A operação falhou porque o nó de Notas não foi criado corretamente\n"); 
    }
    if(situacao == 4){
        printf("A operação falhou porque a inserção não foi feita corretamente, o valor retirado da arvore de matriculas foi revertido\n"); 
    }
} 

void mensagens_exibicao_disc(int situacao){
    if(situacao == 1){
        printf("Nenhum curso com o valor pesquisado foi encontrado.\n"); 
    }
}

void mensagens_exclusao_matriculas(int situacao){
    if(situacao == 0){
        printf("Disciplina Excluída com sucesso\n"); 
    }
    if(situacao == 1){
        printf("A operação falhou porque nenhum aluno foi encontrado"); 
    }
    if(situacao == 2){
        printf("A operação falhou porque Nenhum curso com esse codigo foi encontrado\n"); 
    }
} 

void mensagens_exclusao_disciplina(int situacao){
    if(situacao == 0){
        printf("Disciplina excluída com sucesso\n"); 
    }
    if(situacao == 1){
        printf("É nula a árvore de cursos, não há cursos cadastrados no sistema\n"); 
    }
    if(situacao == 2){
        printf("O curso buscado não foi encontrado.\n");
    }
    if(situacao == 3){
        printf("A arvore de cursos do curso buscado é nula, não há disciplinas cadastradas aqui\n"); 
    }
    if(situacao == 4){
        printf("Algum aluno possui essa disciplina matriculada, operação portanto cancelada\n"); 
    }
    if(situacao == 5){
        printf("A operação de remoção da disciplina falhou, tente novamente\n"); 
    }
} 

void mensagens_busca_notas_periodo(int situacao){
    if(situacao == 0){
        printf("\nImpressão realizada com sucesso\n"); 
    }
    if(situacao == 1){
        printf("\nA lista não possui alunos\n");
    }
    if(situacao == 2){
        printf("\nO aluno com o valor pesquisado não foi encontrado\n"); 
    }
    if(situacao == 3){
        printf("\nA arvore de notas é nula, portanto não há notas registradas pra esse aluno\n");
    }
}


void mensagens_nota_disciplina_especifica(int situacao){
    if(situacao == 0){
        printf("\nOperação realizada com sucesso\n");
    }
    if(situacao == 1){
        printf("\nNão há alunos matriculados no Campus\n"); 
    }
    if(situacao == 2){
        printf("\nO aluno não foi encontrado\n"); 
    }
    if(situacao == 3){
        printf("\nNão há notas registradas para esse aluno\n"); 
    }
}












//Função cujo objetivo é cadastrar o curso (a função em si de inserir está em Arvore_Cursos.c)
void preencher_cursos(Arv_cursos **R){
    int operacao = 1; 
    char nome_curso[100]; 
    int codigo_curso; 
    int qtdade_periodos; 
    Arv_cursos *no;
    no = NULL; 
    

    //adicionar uma logica pra verificar se o numero do curso não é negativo  
    printf("Digite o código do curso: "); 
    scanf("%d", &codigo_curso); 
    while (getchar() != '\n');
    printf("Digite o nome do curso: "); 
    fgets(nome_curso, 100, stdin); 
    printf("Digite a quantidade de periodos desse curso: "); 
    scanf("%d", &qtdade_periodos); 
    
    operacao = criarNo_Cursos(codigo_curso, nome_curso, qtdade_periodos, &no); 

    if(operacao == 1){
        operacao =  inserirArvBB_Cursos(R, no); 
    }
      
    mensagens_tela_cadastro(2, operacao); 
}


//Função cujo objetivo é cadastrar os alunos (a função em si de inserir está em lista_alunos.c)

void preencher_alunos(No_Aluno **R, Arv_cursos **S) {
    int operacao = 1; 
    info_Aluno temp; 
    int situacao = 0; // Variável para armazenar o status final da operação
    //essa struct não será utilizada aqui, no entanto, ela é parametro pra função, por conta de ser a mesma funcionalidade 
    Arv_cursos *curso_encontrado;
    curso_encontrado = NULL; 

    // Temporário: A matrícula seria gerada automaticamente em vez de pedida ao usuário
    printf("Digite sua matricula: "); 
    scanf("%d", &temp.matricula);
    while (getchar() != '\n'); // Limpa o buffer de entrada

    printf("Digite seu Nome Completo: "); 
    fgets(temp.nome_do_aluno, 100, stdin);
    temp.nome_do_aluno[strcspn(temp.nome_do_aluno, "\n")] = '\0'; // Remove o '\n' do fgets

    printf("Digite o codigo do curso: "); 
    scanf("%d", &temp.codigo_curso); 

    // Verificar se o curso existe na árvore de cursos
    operacao = verificar_arv_Cursos(temp.codigo_curso, *S, &curso_encontrado); 
    if (operacao == 1) {
        // Curso encontrado, prosseguir com a criação do nó do aluno
        No_Aluno *novo; 

        operacao = criarNo_Aluno(&temp, &novo); 
        if (novo != NULL) {
            // Inserir aluno na lista encadeada
            operacao = inserir_lista_alunos(R, &novo); 
            if (operacao == 0) {
                // A operação falhou porque a matrícula já existe
                free(novo); // Libera o nó criado
                situacao = 2; // Define a situação como matrícula já existente
            }
        } else {
            // Falha ao criar o nó do aluno
            situacao = 1; // Define a situação como erro ao criar o nó
        }
    } else {
        // Nenhum curso correspondente encontrado
        operacao = 0; 
        situacao = 3; // Define a situação como curso não encontrado
    }
    
    // Exibir mensagem final de acordo com a situação
    mensagens_cadastro_aluno(situacao);
}
 
//Função cujo objetivo é cadastrar as Disciplinas dentro dos cursos (a função em si de inserir está em Arvore_Disciplinas.c)
void preencherDisciplinas(Arv_cursos **S){
    int codigo_curso, operacao, situacao, confirmacao;
    operacao = 1;  
    Arv_cursos *curso_encontrado; 
    curso_encontrado = NULL;
    situacao = 0; 
    Inf_Disc temp; 


    printf("Digite o Codigo do Curso que deseja inserir a Disciplina: "); 
    scanf("%d", &codigo_curso); 

    //a função deve ir na arvore de cursos digitada e trazer de volta o endereço do Nó, caso o encontre.
    operacao = verificar_arv_Cursos(codigo_curso, *S, &curso_encontrado); 
    if(operacao == 1){ 
        //A operação até o momento é bem sucedida, já temos o endereço do nó, prosseguimos. 
        //proximo passo é coletar as infos pra inserir na árvore de disciplinas
        printf("Digite o codigo da Disciplina: "); 
        scanf("%d",&temp.codigo_disciplina); 
        while (getchar() != '\n'); // Limpa o buffer de entrada

        printf("Digite o Nome da Disciplina: "); 
        fgets(temp.nome_da_disciplina, 100, stdin);
        temp.nome_da_disciplina[strcspn(temp.nome_da_disciplina, "\n")] = '\0';
        confirmacao = 0; 
        do{
            printf("Digite a carga horaria da disciplina(30, 45, 60, 75, 90): ");
            scanf("%d", &temp.carga_horaria); 
            if(temp.carga_horaria == 30 || temp.carga_horaria == 45 || temp.carga_horaria == 60 || temp.carga_horaria == 75 || temp.carga_horaria == 90){
                confirmacao = 1;
            }else{
                printf("O valor de carga horaria digitado não é válido, tente novamente"); 
            }
        }while(confirmacao == 0); 
            
        confirmacao = 0; 

        do{
           printf("Digite o periodo da Disciplina no Curso: "); 
           scanf("%d", &temp.periodo); 
           if(1 <= temp.periodo && temp.periodo <= curso_encontrado->info.qtdade_de_periodos){
            confirmacao = 1; 
           }else{
            printf("O periodo digitado deve ser válido(maior do que 0 e menor/igual ao periodo máximo do curso)"); 
           }

        }while(confirmacao == 0);

        Arv_disc *novo; 

        operacao = criarNo_Disc(&temp, &novo); 

        if(operacao == 1){
           // com o nó criado corretamente 
           // o último passo é tentar inserir na árvore de disciplinas
           operacao = inserirArvBB_Disc(&curso_encontrado->info.disciplinas, novo); 

           if(operacao == 0){
              //A operação falhou porque um curso de mesmo codigo foi inserido anteriormente. 
              free(novo); 
              situacao = 3; 
           }


        }else{
            //A operacao falhou porque o Nó não foi alocado corretamente
            situacao = 2; 
        } 


    }else{
        //A operação falhou porque nenhum curso com esse codigo foi encontrado
        situacao = 1; 
    }
    

    mensagens_cadastro_disciplina(situacao);   
  
}

void preencher_matriculas(No_Aluno **raiz, Arv_cursos *S){
    int operacao, situacao, matricula_aluno, codigo_disciplina; 
    operacao = 1; 
    situacao = 0; 

    printf("Digite a sua matricula: ");
    scanf("%d", &matricula_aluno); 

    No_Aluno *aluno_encontrado;
    aluno_encontrado = NULL;  

    // função pra verificar a lista de alunos (recuperando o endereço nó item lista)
    // é preciso verificar se o aluno está matriculado 
    operacao = buscarAlunoPorMatricula(*raiz, matricula_aluno, &aluno_encontrado); 

    if(operacao == 1){
        //pegando o numero do curso 
        printf("Digite o codigo da Disciplina que deseja se matricular: "); 
        scanf("%d", &codigo_disciplina); 

        Arv_cursos *curso_encontrado;
        curso_encontrado = NULL;  

        // a primeira função vai procurar o curso, se tiver, vai guardar o endereço do mesmo. 
        operacao = verificar_arv_Cursos(aluno_encontrado->aluno.codigo_curso, S, &curso_encontrado);         

        //com o endereço do nó de cursos, agora só percorrer na subarvore de disciplinas, e confirmar que ela existe
        operacao = verificar_disciplina(curso_encontrado->info.disciplinas, codigo_disciplina); 
        if(operacao == 1){
            //criar o No das matriculas 
            Arv_Mat_Disc *nova_matricula;
            nova_matricula = NULL;  
            operacao = criarNo_Mat(codigo_disciplina, &nova_matricula);

            if(operacao == 1){
                  //Com tudo ok, basta inserir na arvore de Matriculas
                  operacao = inserirArvBB_Mat(&aluno_encontrado->aluno.matriculas, nova_matricula);
                  if(operacao == 0){
                    //A operação falhou na Inserção na árvore de matriculas
                    free(nova_matricula); 
                    situacao = 4; 
                  }
            }else{
                //A operação falhou porque o Nó não foi alocado corretamente
                situacao = 3; 
            }


            
        }else{
            //A operação falhou porque a disciplina informada não existe no curso.  
            situacao = 2; 
        }



    }else{
        //A operação falhou porque o aluno não está na lista
        situacao = 1; 
    }  

    mensagens_cadastro_matricula(situacao); 


}

void preencher_notas(No_Aluno **raiz){ 
    int operacao, situacao, matricula_aluno, codigo_disciplina; 
    operacao = 1; 
    situacao = 0; 

    printf("Digite a sua matricula: ");
    scanf("%d", &matricula_aluno); 

    No_Aluno *aluno_encontrado;
    aluno_encontrado = NULL;  

    // função pra verificar a lista de alunos (recuperando o endereço nó item lista)
    // é preciso verificar se o aluno está matriculado 
    operacao = buscarAlunoPorMatricula(*raiz, matricula_aluno, &aluno_encontrado); 

    if(operacao == 1){
        printf("Digite o codigo da Disciplina que está matriculado: ");
        scanf("%d", &codigo_disciplina); 
         
        //a função deve então remover o item da arvore de matriculas. (guarde uma cópia desse nó)
        operacao = removeArvBB_Matriculas(&(aluno_encontrado->aluno.matriculas),codigo_disciplina);  


        if(operacao == 1){
            //O nó foi removido com sucesso, prosseguindo
            //crie um nó de arvore de Notas
            int confirmacao; 
            confirmacao = 0; 
            Arv_Not *novo_no; 
            novo_no = NULL;

            Info_Notas informacoes_do_aluno_disciplina;  
            
            do{
                printf("Digite a nota final atingida na disciplina: "); 
                scanf("%f", &informacoes_do_aluno_disciplina.nota_final); 
                if(informacoes_do_aluno_disciplina.nota_final >= 0 && informacoes_do_aluno_disciplina.nota_final <= 10){
                    confirmacao = 1; 
                }else{
                    printf("Nota digitada inválida, digite um valor entre 0 e 10\n"); 
                    confirmacao = 0;
                }
            }while(confirmacao == 0); 

            printf("Digite o semestre que você pagou essa disciplina: "); 
            scanf("%d", &informacoes_do_aluno_disciplina.semestre_cursado); 

            informacoes_do_aluno_disciplina.codigo_disciplina = codigo_disciplina;  

            operacao = criarNo_Notas(informacoes_do_aluno_disciplina, &novo_no);     
 

            if(operacao == 1){
                // O nó foi criado corretamente, prosseguindo. 
                operacao = inserirArvBB_Notas(&(aluno_encontrado->aluno.notas), novo_no); 
                if(operacao != 1){
                    Arv_Mat_Disc *nova_matricula;
                    nova_matricula = NULL;
                    criarNo_Mat(codigo_disciplina, &nova_matricula);
                    inserirArvBB_Mat(&aluno_encontrado->aluno.matriculas, nova_matricula);
                    //a inserção não foi feita corretamente, é necessário reverter. 
                    situacao = 4;
                }

            }else{
                //O nó não foi criado corretamente, é necessário reverter 
                //usar a função de inserir(codigo_matricula); 
                situacao = 3; 
            } 


        }else{
            //A disciplina não foi encontrada ou a remoção falhou, operação abortada. 
            situacao = 2;
        } 




    }else{
        //A operação falhou porque o aluno buscado não foi encontrado
        situacao = 1; 
    }

    mensagens_cadastro_notas(situacao); 



}




// Exibição agr

//Essa função exibe todos os alunos que estão vinculados a um determinado curso
void exibir_todos_alunos_curso(No_Aluno *raiz){
    int operacao, codigo_curso; 
    
    
    if(raiz != NULL){
        printf("\nDigite o codigo do curso: ");
        scanf("%d", &codigo_curso); 

        imprimir_alunos_do_curso(raiz, codigo_curso);  

    }else{
        //Não há nenhum aluno registrado no sistema
        printf("\nNão há nenhum aluno registrado no sistema\n"); 
    } 

}


//Essa função exibe as disciplinas vinculadas a determinado curso
void exibir_disc_do_curso(Arv_cursos **S){
    Arv_cursos *curso_encontrado; 
    curso_encontrado = NULL;


    int codigo_curso, operacao, situacao;
    situacao = 0; 

    printf("\nDigite o codigo do curso: ");
    scanf("%d",&codigo_curso);
    operacao = verificar_arv_Cursos(codigo_curso,*S,&curso_encontrado);
    if(operacao == 1){
        imprimirArvBB_Disciplinas(curso_encontrado->info.disciplinas);

    }else{
        situacao = 1; 
        //Nenhum curso foi encontrado
        mensagens_exibicao_disc(situacao); 
    }
}


//Essa função exibe as disciplinas de um periodo especifico de um curso especifico
void exibir_disc_periodo_especifico(Arv_cursos **S){
    Arv_cursos *curso_encontrado; 
    curso_encontrado = NULL; 

    int codigo_curso, situacao, operacao;
    operacao = 1; 
    situacao = 0; 
    int periodo;

    printf("\nDigite o codigo do curso: ");
    scanf("%d",&codigo_curso);

    operacao = verificar_arv_Cursos(codigo_curso, *S, &curso_encontrado);

    if(operacao == 1){
        int confirmacao; 
        confirmacao = 0; 

        if(curso_encontrado->info.disciplinas != NULL){
            do{
                printf("\nDigite o periodo que deseja buscar: ");
                scanf("%d",&periodo);

                if(periodo <= 0 || periodo > curso_encontrado->info.qtdade_de_periodos){
                    printf("O periodo buscado é inválido, digite novamente.\n"); 
                }else{
                    confirmacao = 1; 
                }


            }while(confirmacao == 0); 

            imprimirArvBB_Disciplinas_periodo_especifico(curso_encontrado->info.disciplinas, periodo);
        }
    }
    else
    {
        situacao = 1; 
        mensagens_exibicao_disc(situacao);
    }
}

//Mostrar todas as disciplinas que o aluno está matriculado; 
void mostrar_todas_disc_aluno(No_Aluno **raiz, Arv_cursos **R){
    //primeiro passo é verificar se o aluno existe
    int operacao, situacao, matricula_aluno; 
    operacao = 1; 
    situacao = 0;  
    No_Aluno *aluno_encontrado; 
    aluno_encontrado = NULL; 

    printf("Digite a matricula do aluno: "); 
    scanf("%d", &matricula_aluno); 

    operacao = buscarAlunoPorMatricula(*raiz, matricula_aluno, &aluno_encontrado); 

    if(operacao == 1){
        Arv_cursos *curso_encontrado; 
        curso_encontrado = NULL; 
        //Proximo passo é recuperar o endereço do nó do curso
        operacao = verificar_arv_Cursos(aluno_encontrado->aluno.codigo_curso, *R, &curso_encontrado); 
        if(operacao == 1){ 
            exibir_disciplinas_matriculadas(aluno_encontrado->aluno.matriculas, curso_encontrado->info.disciplinas); 

        }else{
            //A operação falhou porque não foi possivel recuperar o endereço da memória. 
            situacao = 2; 
        }


    }else{
        //A operação falhou porque não há nenhum aluno com a matricula pesquisada
        situacao = 1;
    }

    //falta colocar a função pra imprimir os status
}

//Mostrar todas as notas de disciplinas de um determinado período de um determinado aluno. 

void exibir_notas_periodo(No_Aluno **raiz){
    int situacao, operacao, matricula, periodo; 
    situacao = 0; 
    operacao = 1; 
   
   if(*raiz != NULL){
        No_Aluno *aluno_encontrado; 
        aluno_encontrado = NULL; 

        //Com a certeza de que temos alunos cadastrados, proximo passo é pesquisar se o aluno está cadastrado

        printf("Digite sua matricula: "); 
        scanf("%d", &matricula); 

        operacao = buscarAlunoPorMatricula(*raiz, matricula, &aluno_encontrado); 
        if(operacao == 1){
            //foi encontrado o aluno 
            //Agore é verificar se arvore de notas desse aluno não é nula. 
            if(aluno_encontrado->aluno.notas != NULL){
                int cont; 
                cont = 1; 
                do{
                   printf("\nDigite o periodo que deseja buscar: "); 
                   scanf("%d", &periodo); 
                   if(periodo < 1){
                      printf("\nDigite um periodo válido\n"); 
                   }else{
                      cont = 0; 
                   }
                }while(cont == 1);   

                imprimir_notas_aluno_periodo(aluno_encontrado->aluno.notas, periodo); 
                
            }else{
                //A arvore de notas é nula, portanto não há o que pesquisar.
                situacao = 3; 
            }

        }else{
            //O aluno com o valor pesquisado não foi encontrado
            situacao = 2; 
        }
     
        

   }else{
      //A lista não possui alunos
      situacao = 1; 
   }

   mensagens_busca_notas_periodo(situacao); 



}

// Mostrar a nota de uma disciplina de um determinado aluno, mostrando o período e a carga horária da disciplina. 

void mostrar_nota_disciplina(No_Aluno **raiz){
    //primeiramente, verificar se a lista não é nula, se for nula, não tem alunos, não há o que fazer
    int situacao, operacao, matricula_aluno, codigo_disciplina; 
    situacao = 0; 
    operacao = 1; 

    if(*raiz != NULL){
        //Com a garantia de que há uma lista de alunos, é o momento de buscar a matricula do aluno
        printf("Digite sua matricula: "); 
        scanf("%d", &matricula_aluno);

        No_Aluno *aluno_encontrado; 
        aluno_encontrado = NULL; 

        operacao = buscarAlunoPorMatricula(*raiz, matricula_aluno, &aluno_encontrado); 

        if(operacao == 1){
            //O aluno foi encontrado 
            //proximo passo é verificar se a arvore de notas do mesmo não é nula. 
            if(aluno_encontrado->aluno.notas != NULL){
                //A Arvore de Notas não sendo nula, é a hora de pesquisar pelo codigo da disciplina. 
                printf("Digite o codigo da Disciplina: "); 
                scanf("%d", &codigo_disciplina); 

                //vou só imprimir por enquanto, depois colocar uma mensagem, caso não tenha nenhuma matéria 
                imprimir_nota_aluno_materia_especifica(aluno_encontrado->aluno.notas, codigo_disciplina);  


            }else{
                situacao = 3; 
                //Não há notas registradas
            }

        }else{
            situacao = 2; 
            //O aluno não foi encontrado
        } 



    }else{
        situacao = 1; 
        //Não há alunos matriculados no Campus

    }

    mensagens_nota_disciplina_especifica(situacao); 




}











//Funções relacionadas a remoção 



void remover_Matricula(No_Aluno **raiz){
    int operacao, situacao, matricula_aluno, codigo_disciplina; 
    operacao = 1; 
    situacao = 0; 

    printf("Digite a sua matricula: ");
    scanf("%d", &matricula_aluno); 

    No_Aluno *aluno_encontrado;
    aluno_encontrado = NULL;  

    // função pra verificar a lista de alunos (recuperando o endereço nó item lista)
    // é preciso verificar se o aluno está matriculado 
    operacao = buscarAlunoPorMatricula(*raiz, matricula_aluno, &aluno_encontrado); 

    if(operacao == 1){ 
        printf("Digite o codigo da Disciplina que deseja excluir: ");
        scanf("%d", &codigo_disciplina); 
         
        //a função deve então remover o item da arvore de matriculas. (guarde uma cópia desse nó)
        operacao = removeArvBB_Matriculas(&(aluno_encontrado->aluno.matriculas),codigo_disciplina);

        if(operacao != 1){
            situacao = 2; 
            //Falha na remoção, possivelmente a disciplina não existe. 
        }



    }else{
        situacao = 1; 
        //Não foi encontrado aluno com essa matricula
    }

    mensagens_exclusao_matriculas(situacao); 

}

//Remover uma disciplina de um determinado curso desde que não tenha nenhum aluno matriculado na mesma. 

void remover_disc_curso(No_Aluno **raiz, Arv_cursos **R){
    int operacao, situacao, codigo_curso, codigo_disciplina; 
    operacao = 1; 
    situacao = 0;  

    if(R != NULL){

        Arv_cursos *curso_encontrado; 
        curso_encontrado = NULL; 

        printf("Digite o codigo do curso: "); 
        scanf("%d", &codigo_curso); 

        operacao = verificar_arv_Cursos(codigo_curso, *R, &curso_encontrado); 

        if(operacao == 1){ 
            //curso encontrado, e já temos seu endereço. 
             

            if(curso_encontrado->info.disciplinas != NULL){

                //Confirmado que existe uma árvore de disciplinas 
                printf("Digite o codigo da disciplina: "); 
                scanf("%d", &codigo_disciplina); 

                if(raiz != NULL){
                    //já que a lista de alunos é diferente de nula, é necessário verificar se há alguém vinculado a esse curso
                    // e depois ver se esse aluno está com a disciplina mencionada em sua arvore 

                    operacao = verificar_aluno_com_disciplina(*raiz, codigo_curso, codigo_disciplina); //isso aqui vai verificar na lista de alunos, se há alguem daquele curso
                    // se tiver, ele olhará a arvore de matriculas em busca de algum achado; 
                }

                if(operacao != 1){
                   //significa que nenhum aluno com essa credencial foi encontrada, dá pra prosseguir 

                   //proximo passo é remover a disciplina 
                   operacao = ArvBB_Disc_Remover(&(curso_encontrado->info.disciplinas), codigo_disciplina); 
                   if(operacao != 1){
                      situacao = 5; 
                      //Não foi possivel remover essa disciplina, tente novamente (possivelmente a causa é essa disciplina n existir)
                   }

                }else{
                    situacao = 4; 
                    //algum aluno tem esse curso em sua grade, operação abortada
                }






            }else{
                //A arvore de disciplinas desse curso é nula, portanto não há nada o que possa ser feito
                situacao = 3;
            }

            
           



        }else{
            situacao = 2; 
            //curso não encontrado na arvore

        }
    

    }else{
        situacao = 1; 
        //se for nulo a arvore de cursos, portanto não há o que ser feito
    }

    mensagens_exclusao_disciplina(situacao); 
}
