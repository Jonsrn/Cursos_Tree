#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
