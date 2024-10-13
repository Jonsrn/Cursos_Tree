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

    printf("\nMenu Cadastrar\n"); 
    printf("1- Cadastrar Alunos\n"); 
    printf("2- Cadastrar Cursos\n"); 
    printf("3- Cadastrar Disciplinas\n"); 
    printf("4- Cadastrar Matricula\n"); 
    printf("5- Cadastrar Notas\n"); 
    printf("0- Sair\n"); 

}

void menu_exibir(){
   
   printf("\nMenu Exibir\n"); 
   printf("1- Exibir Todos Alunos de Um Curso\n"); 
   printf("2- Exibir Todos os cursus do Campus\n"); 
   printf("3- Exibir Todas as Disciplinas de um Curso\n"); 
   printf("4- Exibir Todas as Disciplinas de um Curso em um Periodo Especifico\n"); 
   printf("5- Exibir Todas as Disciplinas que um determinado Aluno está Matriculado\n"); 
   printf("6- Exibir todas as notas de disciplinas de um determinado período de um determinado aluno.\n"); 
   printf("7- Exibir nota de uma disciplina de um determinado aluno, mostrando o período e a carga horária da disciplina.\n"); 
   printf("8- Mostrar o histórico de um determinado aluno, contendo o nome do curso, as disciplinas e sua respectiva nota organizadas pelo período que a disciplina está cadastrada no curso.\n");
   printf("0- Sair\n"); 
}

void menu_excluir(){
    printf("\nMenu Remover\n"); 
    printf("1- Remover uma Disciplina de um Determinado Curso\n");
    printf("2- Remover uma disciplina da árvore de matrícula de um determinado aluno.\n"); 
    printf("0- Sair\n");  
}

void menu_testes(){
    printf("\nMenu Testes"); 
    printf("\n1-Teste de inserção na árvore de Cursos"); 
    printf("\n2-Teste de Busca de Nota de aluno");
    printf("\n0-Sair\n");  
}
void teste_cursos(){
    printf("\nExecução do Teste"); 
    printf("\n1-Inserir e Testar");
    printf("\n0-Sair\n"); 
}
void menu_insercao(){
    printf("\nInserção de Cursos e Teste"); 
    printf("\n1-Inserir Ordenado Crescente e na sequência Testar");
    printf("\n2-Inserir Ordenado Decrescente e na Sequência Testar"); 
    printf("\n3-Inserir Ordem Aleatória e na Sequencia Testar"); 
    printf("\n0-Sair\n");  
}
void menu_medicao_cursos(){
    printf("\nMedição Curso");  
    printf("\n0-Sair\n"); 
}
void menu_medicao_nota(){
   printf("\nMedição Nota");
   printf("\n1-Medir Tempo de consulta na árvore de Notas");
   printf("\n0-Sair\n");  
}





//Função cujo objetivo é cadastrar os alunos
/*
Essa função se refere ao Item I- Cadastrar alunos

Passo 1 do Item I - É chamada a função "preencher_alunos", ela vai começar coletando os dados e intercambiando as funções

Passo 2- É chamada a função "verificar_arv_Cursos", verificando se o curso informado realmente existe. (Arvore_Cursos.c)

Passo 3- É chamada a função "CriarNo_Aluno", criando o nó com as informações referentes ao aluno (lista_alunos.c)

Passo 4- É chamada a função "Inserir_lista_alunos", inserindo em ordem alfabetica na lista de alunos (lista_alunos.c)

Passo 5- É chamada a função "mensagens_cadastro_aluno", apresentando uma mensagem correspondente ao status final da operação (mensagens.c)
*/

void preencher_alunos(No_Aluno **R, Arv_cursos **S) {
    int operacao = 1;  
    int situacao = 0; // Variável para armazenar o status final da operação
    //essa struct não será utilizada aqui, no entanto, ela é parametro pra função, por conta de ser a mesma funcionalidade 
    

    //Colocar a VERIFICAÇÃO DE NULO AQUI(resolvido)
        if(*S != NULL){
            info_Aluno temp;
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
                        situacao = 4; // Define a situação como matrícula já existente
                    }
                } else {
                    // Falha ao criar o nó do aluno
                    situacao = 3; // Define a situação como erro ao criar o nó
                }
            } else {
                // Nenhum curso correspondente encontrado
                operacao = 0; 
                situacao = 2; // Define a situação como curso não encontrado
            }
        }else{
            //Não há cursos cadastrados no sistema 
            situacao = 1; 
        }    
            
            // Exibir mensagem final de acordo com a situação
            mensagens_cadastro_aluno(situacao);
}

//Função cujo objetivo é cadastrar o curso 
/*
Essa função se refere ao Item II- Cadastrar Cursos 

Passo 1 do Item II - É chamada a função "preencher_cursos", ela vai começar coletando os dados e intercambiando as funções

Passo 2- É chamada a função "criarNo_Cursos", serve pra criar um nó com as infos coletadas do Curso (Arvore_Cursos.c)

Passo 3- É chamada a função "inserirArvBB_Cursos", serve para inserir o Nó criado na árvore Cursos (Arvore_Cursos.c)

Passo 4- É chamada a função "mensagens_tela_cadastro", serve para apresentar as mensagens de diagnostico da operação (mensagens.c)

*/
void preencher_cursos(Arv_cursos **R){
    int operacao, situacao, confirmacao;
    operacao = 1; 
    situacao = 0; 
    confirmacao = 1;   
    char nome_curso[100]; 
    int codigo_curso; 
    int qtdade_periodos; 
    Arv_cursos *no;
    no = NULL; 
    

    //adicionar uma logica pra verificar se o numero do curso não é negativo  
    do{
        printf("\nDigite o código do curso: "); 
        scanf("%d", &codigo_curso);
        if(codigo_curso < 1){
            confirmacao = 0; 
            printf("\nO Código digitado é inválido, tente novamente\n"); 
        }else{
            confirmacao = 1; 
        }


    }while(confirmacao == 0); 



    while (getchar() != '\n');
    printf("\nDigite o nome do curso: "); 
    fgets(nome_curso, 100, stdin); 
    do{
    
        printf("\nDigite a quantidade de periodos desse curso: "); 
        scanf("%d", &qtdade_periodos); 
        if(qtdade_periodos < 1){
            printf("\nDigite um valor válido de periodos\n");
            confirmacao = 0; 
        }else{
            confirmacao = 1;
        }

    }while(confirmacao == 0);     
    
    operacao = criarNo_Cursos(codigo_curso, nome_curso, qtdade_periodos, &no); 

    if(operacao == 1){
        operacao =  inserirArvBB_Cursos(R, no); 
        if(operacao != 1){
            //A operação falhou porque já existe um curso com esse código. 
            situacao = 2; 
            free(no); 
        } 

    }else{
        //A operação falhou em criar um nó
        situacao = 1;

    }
      
    mensagens_tela_cadastro(situacao); 
}

 
//Função cujo objetivo é cadastrar as Disciplinas dentro dos cursos (a função em si de inserir está em Arvore_Disciplinas.c)
/*
Essa função se refere ao Item III- Cadastrar Disciplinas

Passo 1- É chamada a função "preencherDisciplinas", que lida com os intermédios e coletas de dados 

Passo 2- É chamada a função "verificar_arv_Cursos", ela percorre a árvore de cursos, caso encontrando-a recupera o endereço do nó (Arvore_Cursos.c)

Passo 3- É chamada a função "criarNo_Disc", ela cria o nó com as infos da disciplina, devolvendo o endereço do nó (Arvore_Disciplinas.c)

Passo 4- É chamada a função "inserirArvBB_Disc", que insere o nó na árvore de disciplinas (Arvore_Disciplinas.c)

Passo 5- É chamada a função "mensagens_cadastro_disciplina", que apresenta as mensagens referentes ao fim da operação (mensagens.c)



*/
void preencherDisciplinas(Arv_cursos **S){
    int codigo_curso, operacao, situacao, confirmacao;
    operacao = 1;  
    Arv_cursos *curso_encontrado; 
    curso_encontrado = NULL;
    situacao = 0; 
    Inf_Disc temp; 
    
    //Colocar verificação de NULO AQUI(resolvido)
    if(*S != NULL){

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
                situacao = 4; 
            }


            }else{
                //A operacao falhou porque o Nó não foi alocado corretamente
                situacao = 3; 
            } 


        }else{
            //A operação falhou porque nenhum curso com esse codigo foi encontrado
            situacao = 2; 
        }
    }else{
        situacao = 1; 
        //Não há cursos cadastrados no sistema
    }    
    

    mensagens_cadastro_disciplina(situacao);   
  
}

//função cujo objetivo é cadastrar matriculas, coletando as infos e coordenando as funções subsequentes

/*

Essa função se refere ao item IV- (Cadastrar Matriculas)

Passo 1- A função "preencher_matriculas" é acionada, pra coletar os dados referentes ao procedimento

Passo 2- A função "buscarAlunoPorMatricula" é chamada, pra buscar o aluno, caso o encontre, recuperando o endereço de seu nó na lista (lista_alunos.c)

Passo 3- A função "verificar_arv_Cursos" é chamada, para recuperar o endereço do nó da árvore de cursos (Arvore_Cursos.c)

Passo 4- A função "verificar_disciplina" é chamada, para verificar se a disciplina realmente existe na árvore (Arvore_Disciplinas.c)

Passo 5- A função "criarNo_Mat" é chamada pra criar o Nó que será inserida na árvore de Matriculas(Arvore_Matriculas.c)

Passo 6- A função "inserirArvBB_Mat" é chamada para inserir o nó na árvore de Matriculas(Arvore_Matriculas.c)

Passo 7- A função "mensagens_cadastro_matricula" é chamada pra exibir o status final da operação (mensagens.c)

*/

void preencher_matriculas(No_Aluno **raiz, Arv_cursos *S){
    int operacao, situacao, matricula_aluno, codigo_disciplina; 
    operacao = 1; 
    situacao = 0; 

    //colocar Verificações de NULO AQUI(resolvido)

    if(S != NULL){  
        if(*raiz != NULL){      

            printf("Digite a sua matricula: ");
            scanf("%d", &matricula_aluno); 

            No_Aluno *aluno_encontrado;
            aluno_encontrado = NULL;  

            // função pra verificar a lista de alunos (recuperando o endereço nó item lista)
            // é preciso verificar se o aluno está matriculado 
            operacao = buscarAlunoPorMatricula(*raiz, matricula_aluno, &aluno_encontrado); 

            if(operacao == 1){ 

                Arv_cursos *curso_encontrado;
                curso_encontrado = NULL;  

                // a primeira função vai procurar o curso, se tiver, vai guardar o endereço do mesmo. 
                operacao = verificar_arv_Cursos(aluno_encontrado->aluno.codigo_curso, S, &curso_encontrado); 

                if(curso_encontrado->info.disciplinas != NULL){    
                    //pegando o numero da disciplina 
                    printf("Digite o codigo da Disciplina que deseja se matricular: "); 
                    scanf("%d", &codigo_disciplina);    

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
                                situacao = 7; 
                            }
                        }else{
                            //A operação falhou porque o Nó não foi alocado corretamente
                            situacao = 6; 
                        }


                        
                    }else{
                        //A operação falhou porque a disciplina informada não existe no curso.  
                        situacao = 5; 
                    }
                }else{
                    situacao = 4; 
                    //Não há disciplinas cadastradas nesse curso
                }    



            }else{
                //A operação falhou porque o aluno não está na lista
                situacao = 3; 
            }
        }else{
            situacao = 2; 
            //Não há alunos cadastrados no sistema

        }    


    }else{
        situacao = 1; 
        //Não há cursos cadastrados no sistema; 
    }          

    mensagens_cadastro_matricula(situacao); 


}

//Função cujo objetivo é inserir as disciplinas com suas respectivas notas finais na árvore de Notas

/*
Essa função se refere ao Item V (Inserir Notas)(Pra que a inserção ocorra, o valor deve ser removido da árvore de matricula)

Passo 1- A função "preencher_notas" é acionada, coletando os dados referentes ao procedimento 

Passo 2- A função "buscarAlunoPorMatricula" é chamada, buscando o aluno na lista, recuperando o endereço de seu nó em caso de sucesso. (lista_alunos.c)

Passo 3- A função "removeArvBB_Matriculas" é chamada pra procurar a matricula especifica na árvore de Matriculas, a removendo-a caso encontrando-a. (Arvore_Matriculas.c)

Passo 4- A função "criarNo_Notas" é chamada pra criar um nó, a ser inserido na árvore de Notas(Arvore_Notas.c)

Passo 5- A função "inserirArvBB_Notas" é chamada pra inserir o nó na árvore de Notas (Arvore_Notas.c)

*Em caso de falha, a função cuida de criar um novo nó de matriculas e reinsere na árvore de matriculas

Passo 6- A função "mensagens_cadastro_notas" serve para exibir o status final da operação (mensagens.c)

*/

void preencher_notas(No_Aluno **raiz){ 
    int operacao, situacao, matricula_aluno, codigo_disciplina; 
    operacao = 1; 
    situacao = 0; 
    

    //Colocar uma VERIFICAÇÃO DE NULO AQUI(resolvido)
    if(*raiz != NULL){

        printf("Digite a sua matricula: ");
        scanf("%d", &matricula_aluno); 

        No_Aluno *aluno_encontrado;
        aluno_encontrado = NULL;  

        // função pra verificar a lista de alunos (recuperando o endereço nó item lista)
        // é preciso verificar se o aluno está matriculado 
        operacao = buscarAlunoPorMatricula(*raiz, matricula_aluno, &aluno_encontrado); 

        if(operacao == 1){

            if(aluno_encontrado->aluno.matriculas != NULL){

                
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
                            //a inserção na árvore de notas não foi feita corretamente, é necessário reverter. 
                            situacao = 6;
                        }

                    }else{
                        //O nó não foi criado corretamente, é necessário reverter 
                        //usar a função de inserir(codigo_matricula); 
                        situacao = 5; 
                    } 


                }else{
                    //A disciplina não foi encontrada ou a remoção falhou, operação abortada. 
                    situacao = 4;
                }
            }else{
                //A operação falhou porque não há disciplinas matriculadas nesse aluno
                situacao = 3; 
            }     




        }else{
            //A operação falhou porque o aluno buscado não foi encontrado
            situacao = 2; 
        }
    }else{
        situacao = 1; 
        //A operação falhou porque não há alunos cadastrados no sistema
    }    

    mensagens_cadastro_notas(situacao); 



}




// Exibição agr


//Essa função exibe todos os alunos que estão vinculados a um determinado curso
/*Essa função cuida do Item VI - (Exibir todos os alunos matriculados naquele curso)

Passo 1- A função "exibir_todos_alunos_curso" é chamada, pra coletar o valor a ser pesquisado
Passo 2- A função "imprimir_alunos_do_curso" é chamada pra imprimir os alunos que correspondam ao valor pesquisado
Passo 3- A função "mensagens_exibicao_alunos" é acionada pra exibir os status final da operação. 

*/
void exibir_todos_alunos_curso(No_Aluno *raiz, Arv_cursos *R){
    int operacao, situacao, codigo_curso; 
    situacao = 0; 

    if(R != NULL){
    
        //NULO aqui tbm 
        if(raiz != NULL){
            printf("\nDigite o codigo do curso: ");
            scanf("%d", &codigo_curso); 
            Arv_cursos *curso_encontrado; 
            curso_encontrado = NULL; 

            operacao = verificar_arv_Cursos(codigo_curso, R, &curso_encontrado); 

            if(operacao == 1){
               imprimir_alunos_do_curso(raiz, codigo_curso);  
            }else{
                //Curso não encontrado
                situacao = 3; 
            }            

        }else{
            //Não há nenhum aluno registrado no sistema
            situacao = 2; 
        }
    }else{
        //Não há cursos cadastrados no sistema
        situacao = 1; 
    }
    mensagens_exibicao_alunos(situacao);      

}



//Essa função cuida da exibição dos cursos no campus

//Essa função cuida do Item VII(Imprimir todos os cursos cadastrados)
/*
Passo 1- A função "exibir_todos_cursos" é chamada, caso árvore de cursos não seja nulo, a operação prossegue
Passo 2- A função "imprimirArvBB_Cursos" é chamada, exibindo em ordem todas os cursos na árvore (Arvore_Cursos.c)
Passo 3- A função "mensagens_exibicao_cursos" é acionada pra reportar uma mensagem, caso nenhum curso esteja na árvore. (mensagens.c)
*/
void exibir_todos_cursos(Arv_cursos *R){
   int situacao;
   situacao = 0; 

   if(R != NULL){
      imprimirArvBB_Cursos(R);       

   }else{
      situacao = 1; 
      //A operação falhou porque não há nenhum curso cadastrado
   } 

   mensagens_exibicao_cursos(situacao); 

}




//Essa função exibe as disciplinas vinculadas a determinado curso
/* Essa função se refere ao item VIII (Exibir todas as disciplinas de determinado curso)

Passo 1- A função "verificar_arv_Cursos" vai verificar se o curso existe, recuperando o endereço de seu nó caso o encontre
Passo 2- A função "imprimirArvBB_Disciplinas", percorre a arvore de disciplinas, subordinada ao nó de cursos, imprimindo suas disciplinas; 



*/
void exibir_disc_do_curso(Arv_cursos **S){
    Arv_cursos *curso_encontrado; 
    curso_encontrado = NULL;


    int codigo_curso, operacao, situacao;
    situacao = 0; 

    if(*S != NULL){
        
        printf("\nDigite o codigo do curso: ");
        scanf("%d",&codigo_curso);
        operacao = verificar_arv_Cursos(codigo_curso,*S,&curso_encontrado);
        if(operacao == 1){
            if(curso_encontrado->info.disciplinas != NULL){

                  imprimirArvBB_Disciplinas(curso_encontrado->info.disciplinas);
            }else{
                situacao = 3; 
                //Esse curso não possui disciplinas cadastradas
            }      

        }else{
            situacao = 2; 
            //Nenhum curso foi encontrado 
        }
    }else{
        situacao = 1;
        //Não há cursos cadastrados no sistema; 
    } 



    mensagens_exibicao_disc(situacao);
}


//Essa função exibe as disciplinas de um periodo especifico de um curso especifico
void exibir_disc_periodo_especifico(Arv_cursos **S){
    Arv_cursos *curso_encontrado; 
    curso_encontrado = NULL; 

    int codigo_curso, situacao, operacao;
    operacao = 1; 
    situacao = 0; 
    int periodo;
    
    //Adicionar uma VERIFICAÇÃO DE NULO AQUI(resolvido)

    if(*S != NULL){

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

                    if(periodo < 1 || periodo > curso_encontrado->info.qtdade_de_periodos){
                        printf("O periodo buscado é inválido, digite novamente.\n"); 
                    }else{
                        confirmacao = 1; 
                    }


                }while(confirmacao == 0); 

                imprimirArvBB_Disciplinas_periodo_especifico(curso_encontrado->info.disciplinas, periodo);
            }else{
                situacao = 3; 
                //Não há disciplinas nesse curso 
            }
        }
        else
        {
            situacao = 2; 
            //O curso não foi encontrado
            
        }
    }else{
        situacao = 1; 
        //Não existem cursos cadastrados
    }
    mensagens_exibicao_disc(situacao);    
}

//Mostrar todas as disciplinas que o aluno está matriculado; 
void mostrar_todas_disc_aluno(No_Aluno **raiz, Arv_cursos **R){
    //primeiro passo é verificar se o aluno existe
    int operacao, situacao, matricula_aluno; 
    operacao = 1; 
    situacao = 0;  
    No_Aluno *aluno_encontrado; 
    aluno_encontrado = NULL; 

    //Adicionar uma verificação de NULO AQUI(resolvido)

    if(*R != NULL){

        if(*raiz != NULL){

            printf("Digite a matricula do aluno: "); 
            scanf("%d", &matricula_aluno); 

            operacao = buscarAlunoPorMatricula(*raiz, matricula_aluno, &aluno_encontrado); 

            if(operacao == 1){
                Arv_cursos *curso_encontrado; 
                curso_encontrado = NULL; 
                //Proximo passo é recuperar o endereço do nó do curso
                operacao = verificar_arv_Cursos(aluno_encontrado->aluno.codigo_curso, *R, &curso_encontrado); 
                if(operacao == 1){ 
                    if(aluno_encontrado->aluno.matriculas != NULL){
                         exibir_disciplinas_matriculadas(aluno_encontrado->aluno.matriculas, curso_encontrado->info.disciplinas); 
                    }else{
                        situacao = 5; 
                        //A operação falhou porque a árvore de matriculas do aluno está vazia;
                    }     

                }else{
                    //A operação falhou porque não foi possivel recuperar o endereço da memória. 
                    situacao = 4; 
                }


            }else{
                //A operação falhou porque não há nenhum aluno com a matricula pesquisada
                situacao = 3;
            }
        }else{
            situacao = 2; 
            //A operação falhou porque não há alunos cadastrados no sistema
        }    

    }else{
        situacao = 1; 
        //A operação falhou porque não há cursos cadastrados no sistema
    }        

    mensagens_exibir_todas_disc_aluno(situacao); 
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
                operacao = imprimir_nota_aluno_materia_especifica(aluno_encontrado->aluno.notas, codigo_disciplina, 1);  
                if(operacao != 1){
                    //A nota não foi encontrada
                    situacao = 4; 
                }  


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



//Mostrar o histórico de um determinado aluno, contendo o nome do curso, as disciplinas e sua respectiva nota organizadas pelo período que a disciplina está cadastrada no curso. 

void mostrar_historico_aluno(Arv_cursos **raiz, No_Aluno **S){
    //primeiro iremos verificar se a arvore de cursos é nula
    int situacao, operacao, matricula_aluno;
    operacao = 1; 
    situacao = 0;  
    
    
    if(*raiz != NULL){
        //Como há cursos cadastrados, podemos prosseguir
        // proximo passo é verificar se há alunos cadastrados 
        if(*S != NULL){
            //Temos alunos, próximo passo é verificar se o aluno desejado está cadastrado
            No_Aluno *aluno_encontrado; 
            aluno_encontrado = NULL; 

            printf("Digite sua matricula: "); 
            scanf("%d", &matricula_aluno); 
            
            operacao = buscarAlunoPorMatricula(*S, matricula_aluno, &aluno_encontrado); 
            if(operacao == 1){ 
                //O aluno foi encontrado, agr teremos de verificar se sua árvore de notas não é nula
                if(aluno_encontrado->aluno.notas != NULL){
                    //A arvore de disciplinas não é nula, ultima verificação é olhar se a arvore de disciplinas do curso não é nula
                    Arv_cursos *curso_encontrado; 
                    curso_encontrado = NULL; 

                    operacao = verificar_arv_Cursos(aluno_encontrado->aluno.codigo_curso, *raiz, &curso_encontrado); 
                    //Como um aluno só pode se cadastrar em um curso que já existe, n é necessário verificar se o curso existe

                    //vamos verificar se a árvore de disciplinas do curso não é nula. 

                    if(curso_encontrado->info.disciplinas != NULL){
                        //Com a garantia de que arvore de disciplinas não é nula, podemos percorrer a árvore e recuperar os valores que estão lá 

                        Arv_disc **disciplinas_do_curso; 
                        disciplinas_do_curso = NULL; 
                        int tamanho_do_vetor_disc_curso; 
                        tamanho_do_vetor_disc_curso = 0; 
                        
                        operacao = armazenar_Nos_Arv_Disc(curso_encontrado->info.disciplinas, &disciplinas_do_curso, &tamanho_do_vetor_disc_curso); 
                        if(operacao == 1){
                            //Blz, consegui um vetor com todas as disciplinas daquele curso
                            //proximo passo é fazer o mesmo processo e recuperar a nota dos alunos na árvore  
                            Arv_Not **disciplinas_pagas_do_aluno; 
                            disciplinas_pagas_do_aluno = NULL; 
                            int tamanho_do_vetor_notas; 
                            tamanho_do_vetor_notas = 0; 

                            operacao = armazenar_Nos_Arv_Notas(aluno_encontrado->aluno.notas, &disciplinas_pagas_do_aluno, &tamanho_do_vetor_notas); 
                            if(operacao == 1){ 
                                //Blz, já temos os dois vetores, com os nós das arvores, agr é mandar pra uma função auxiliar, de comparação, ordenação e impressão
                                
                                
                                imprimir_historico_Por_Periodo(disciplinas_do_curso, tamanho_do_vetor_disc_curso, disciplinas_pagas_do_aluno, tamanho_do_vetor_notas); 

                                //Libera a linkagem do vetor linear das notas do aluno, não afeta a árvore original;  
                                free(disciplinas_pagas_do_aluno); 
                                


                            }else{
                                situacao = 7; 
                                //Não foi possivel recuperar os dados da árvore de notas do aluno; 
                            }
                            
                            //libera a linkagem do vetor linear das disciplinas, mas não afeta a árvore original
                            free(disciplinas_do_curso); 





                        }else{
                            situacao = 6; 
                            //A operação falhou em recuperar os dados da árvore de disciplinas
        
                        }




                    }else{
                        situacao = 5; 
                        //Não há disciplinas cadastradas nesse curso. 
                    }
                    



                }else{
                    situacao = 4; 
                    //Não há notas cadastradas pra esse aluno. 
                }

            }else{
                situacao = 3; 
                //O aluno não foi encontrado
            }


        }else{
            situacao = 2; 
            //Não há alunos cadastrados no sistema
        }

    }else{
       situacao = 1; 
       //Nenhum curso cadastrado no sistema  
    }

    mensagens_historico_aluno(situacao); 


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
