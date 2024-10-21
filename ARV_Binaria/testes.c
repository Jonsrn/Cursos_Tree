#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include "universidade.h"

#define NUM_TESTES 10  // Número de testes (números específicos)

// Inicializa os cursos excluídos e seus nomes
void inicializar_excluidos(int *excluidos, const char **nomes) {
    int excl[NUM_TESTES] = {15, 135, 297, 1937, 2428, 5789, 9106, 14324, 21662, 24999};
    const char *nom[NUM_TESTES] = {"Curso15", "Curso135", "Curso297", "Curso1937", "Curso2428", 
                                   "Curso5789", "Curso9106", "Curso14324", "Curso21662", "Curso24999"};

    for (int i = 0; i < NUM_TESTES; i++) {
        excluidos[i] = excl[i];
        nomes[i] = nom[i];
    }
}

// Função para inserir cursos a partir de um arquivo, exceto números específicos
void teste_insercao_cursos(const char *arquivo, Arv_cursos **R, int qtdCursos, int *excluidos, int qtdExcluidos) {
    FILE *file = fopen(arquivo, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s\n", arquivo);
        return;
    }

    int codigo_curso, qtdade_periodos;
    char nome_curso[100];
    Arv_cursos *no = NULL;
    int inserir;

    // Ler e inserir os cursos no arquivo, exceto pelos excluídos
    for (int i = 0; i < qtdCursos; i++) {
        fscanf(file, "%d %s %d", &codigo_curso, nome_curso, &qtdade_periodos);
        inserir = 1;
        // Verificar se o curso está na lista de excluídos
        for (int j = 0; j < qtdExcluidos; j++) {
            if (codigo_curso == excluidos[j]) {
                inserir = 0;
                break;
            }
        }
        if (inserir) {
            criarNo_Cursos(codigo_curso, nome_curso, qtdade_periodos, &no);
            inserirArvBB_Cursos(R, no);
        }
    }

    fclose(file);
}

// Função para medir o tempo de inserção de cursos específicos e salvar no arquivo
void medir_tempo_insercao_cursos(Arv_cursos **R, int *codigos, const char **nomes, int qtdade_periodos, const char *arquivo_saida) {
    FILE *file = fopen(arquivo_saida, "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s\n", arquivo_saida);
        return;
    }

    LARGE_INTEGER frequency, start, end;
    QueryPerformanceFrequency(&frequency);

    double tempos[NUM_TESTES];
    double total_tempo = 0;

    // Inserindo os 10 números específicos e medindo o tempo de cada inserção
    for (int i = 0; i < NUM_TESTES; i++) {
        Arv_cursos *no = NULL;
        criarNo_Cursos(codigos[i], nomes[i], qtdade_periodos, &no);

        QueryPerformanceCounter(&start);
        inserirArvBB_Cursos(R, no);
        QueryPerformanceCounter(&end);

        // Calculando o tempo em nanosegundos
        double total_nanoseconds = (double)(end.QuadPart - start.QuadPart) * 1000000000.0 / frequency.QuadPart;
        tempos[i] = total_nanoseconds;
        total_tempo += total_nanoseconds;

        // Salvando o tempo no arquivo
        fprintf(file, "Tempo de inserção do curso %d: %.6f nanosegundos\n", codigos[i], total_nanoseconds);
    }

    // Calculando e salvando a média dos tempos
    double media_tempo = total_tempo / NUM_TESTES;
    fprintf(file, "Média de tempo de inserção: %.6f nanosegundos\n", media_tempo);

    fclose(file);
}


void executar_testes_insercao(Arv_cursos **arvore, int opcao) {
    int excluidos[NUM_TESTES];
    const char *nomes[NUM_TESTES];

    // Inicializando os números excluídos e seus respectivos nomes
    inicializar_excluidos(excluidos, nomes);

    if(opcao == 1){

        // Teste 1: Inserção de cursos crescente(exceto os excluídos)
        teste_insercao_cursos("cursos_ordenados.txt", arvore, 25000, excluidos, NUM_TESTES);
    }else if(opcao == 2){
        //Teste 2: Inserção de cursos decrescente(exceto os excluídos)
        teste_insercao_cursos("cursos_decrescentes.txt", arvore, 25000, excluidos, NUM_TESTES);
    }else if(opcao == 3){
        //Teste 3: Inserção de cursos crescente(exceto os excluídos)
        teste_insercao_cursos("cursos_aleatorios.txt", arvore, 25000, excluidos, NUM_TESTES);

    }


    // Teste 2: Medição de tempo de inserção dos cursos excluídos
    medir_tempo_insercao_cursos(arvore, excluidos, nomes, 8, "resultado_tempo_insercao.txt");
}

//Funções relacionadas ao Teste 2
// Função para preencher a árvore de cursos com múltiplos cursos
void preencher_cursos_automatico(Arv_cursos **R, int quantidade_cursos) {
    // Loop para inserir múltiplos cursos
    for (int i = 1; i <= quantidade_cursos; i++) {
        int codigo_curso = i; // Código do curso
        char nome_curso[50];
        sprintf(nome_curso, "Curso_%d", i); // Nome do curso com base no código
        int qtdade_periodos = 8; // Número de períodos para cada curso (pode variar se desejar)

        Arv_cursos *novo_curso = NULL;
        criarNo_Cursos(codigo_curso, nome_curso, qtdade_periodos, &novo_curso);
        inserirArvBB_Cursos(R, novo_curso);
    }
}


// Função para preencher as disciplinas
void preencher_arv_disciplinas_curso(Arv_cursos *R) {
    if (R == NULL) {
        printf("Curso não encontrado!\n");
        return;
    }

    Arv_cursos *curso_encontrado = NULL;
    verificar_arv_Cursos(9999, R, &curso_encontrado); // Usando código 9999, já que é curso mais distante

    if (curso_encontrado == NULL) {
        printf("Curso não encontrado!\n");
        return;
    }

    // Adicionar 2500 disciplinas ao curso
    for (int i = 1; i <= 2500; i++) {
        char nome_disciplina[50];
        sprintf(nome_disciplina, "Disciplina_%d", i);
        
        Inf_Disc nova_disciplina = {
            .codigo_disciplina = i,
            .periodo = (i % 10) + 1, // Para distribuir em 10 períodos
            .carga_horaria = 60 // Valor arbitrário para carga horária
        };
        snprintf(nova_disciplina.nome_da_disciplina, sizeof(nova_disciplina.nome_da_disciplina), "%s", nome_disciplina);

        Arv_disc *novo_no_disciplina = NULL;
        criarNo_Disc(&nova_disciplina, &novo_no_disciplina);
        inserirArvBB_Disc(&(curso_encontrado->info.disciplinas), novo_no_disciplina);
    }
}

// Função para inserir 1 aluno na lista encadeada
void preencher_aluno_automatico(No_Aluno **lista_alunos) {
    char nome_base[50] = "Aluno_";
    int matricula_base = 10000; // Iniciar a partir de um número arbitrário de matrícula

    
    info_Aluno novo_aluno;
    novo_aluno.matricula = matricula_base + 1; // Matricula 10001
    snprintf(novo_aluno.nome_do_aluno, sizeof(novo_aluno.nome_do_aluno), "%s%d", nome_base, 1); // Nomeando Aluno_1.
    novo_aluno.codigo_curso = 9999; // aluno cadastrado no curso 9999
    novo_aluno.notas = NULL;
    novo_aluno.matriculas = NULL;

    No_Aluno *novo_no_aluno = NULL;
    criarNo_Aluno(&novo_aluno, &novo_no_aluno);
    inserir_lista_alunos(lista_alunos, &novo_no_aluno); // Lista organizada em ordem alfabética
    
}



void matricular_e_registrar_notas(No_Aluno *lista_alunos, Arv_cursos *cursos) {
    int matricula = 10001; 
    No_Aluno *aluno_encontrado = NULL;
    Arv_cursos *curso_encontrado = NULL;
    verificar_arv_Cursos(9999, cursos, &curso_encontrado); // Curso 9999

    if (curso_encontrado == NULL) {
        printf("Curso não encontrado para registrar notas!\n");
        return;
    }


    if (buscarAlunoPorMatricula(lista_alunos, matricula, &aluno_encontrado)) {
        int disciplinas[2500];
        // Preencher a lista de disciplinas
        for (int j = 0; j < 2500; j++) {
            disciplinas[j] = j + 1;
        }


        // Matricular o aluno e registrar as notas nas disciplinas de maneira aleatória
        for (int j = 0; j < 2500; j++) {
            int codigo_disciplina = disciplinas[j];

            // Verificar se a disciplina existe
            if (verificar_disciplina(curso_encontrado->info.disciplinas, codigo_disciplina)) {
                // Criar a matrícula
                Arv_Mat_Disc *nova_matricula = NULL;
                criarNo_Mat(codigo_disciplina, &nova_matricula);
                inserirArvBB_Mat(&(aluno_encontrado->aluno.matriculas), nova_matricula);

                // Criar a nota após a matrícula (aleatória de 1 a 10)
                Info_Notas nova_nota = {.codigo_disciplina = codigo_disciplina, .nota_final = (float)(rand() % 10 + 1), .semestre_cursado = 20232};
                Arv_Not *novo_no_nota = NULL;
                criarNo_Notas(nova_nota, &novo_no_nota);
                inserirArvBB_Notas(&(aluno_encontrado->aluno.notas), novo_no_nota);
                removeArvBB_Matriculas(&(aluno_encontrado->aluno.matriculas), codigo_disciplina);

            }
        }
    }
}


// Função para medir o tempo da busca da nota do aluno em uma disciplina específica
void medir_tempo_busca_nota_nanosegundos(No_Aluno *lista_alunos, Arv_cursos **Cursos, int matricula, int codigo_disciplina, const char *arquivo_tempos) {
    No_Aluno *aluno_encontrado = NULL;
    Arv_cursos *Curso_Encontrado; 
    Curso_Encontrado = NULL;
    Arv_disc *Disciplina_Encontrada; 
    Disciplina_Encontrada = NULL;

    // Arquivo de saída
    FILE *file_tempos = fopen(arquivo_tempos, "w");
    if (file_tempos == NULL) {
        printf("Erro ao abrir o arquivo %s\n", arquivo_tempos);
        return;
    }

    // Inicializando as variáveis para medição de tempo
    LARGE_INTEGER frequency, start, end;
    QueryPerformanceFrequency(&frequency);

    double tempos[30];
    double total_tempo = 0;

    // Executar o teste 30 vezes para registrar os tempos de busca
    for (int i = 0; i < 30; i++) {



        
        // Capturando o tempo antes da busca
        QueryPerformanceCounter(&start);

        // Buscar o aluno e a nota da disciplina
        if (buscarAlunoPorMatricula(lista_alunos, matricula, &aluno_encontrado)) {
           
            verificar_arv_Cursos(aluno_encontrado->aluno.codigo_curso, *Cursos, &Curso_Encontrado);

            buscar_disciplina(Curso_Encontrado->info.disciplinas, codigo_disciplina, &Disciplina_Encontrada); 


            imprimir_nota_aluno_materia_especifica(aluno_encontrado->aluno.notas, codigo_disciplina, Disciplina_Encontrada,  2); // Modo 2 apenas retorna
        }

        // Capturando o tempo após a busca
        QueryPerformanceCounter(&end);

        // Calculando o tempo em nanosegundos
        double total_nanoseconds = (double)(end.QuadPart - start.QuadPart) * 1000000000.0 / frequency.QuadPart;
        tempos[i] = total_nanoseconds;
        total_tempo += total_nanoseconds;

        // Escrevendo o tempo de cada execução no arquivo
        fprintf(file_tempos, "Tempo de busca %d: %.6f nanosegundos\n", i + 1, total_nanoseconds);
    }

    // Calculando a média dos tempos
    double media_tempo = total_tempo / 30;

    // Escrevendo a média no arquivo
    fprintf(file_tempos, "Média de tempo de busca: %.6f nanosegundos\n", media_tempo);

    // Fechando o arquivo
    fclose(file_tempos);
}

// Função para executar os testes de busca e gravação dos tempos
void executar_testes_busca_nanosegundos(No_Aluno *lista_alunos, Arv_cursos **cursos, int matricula, int codigo_disciplina) {
     medir_tempo_busca_nota_nanosegundos(lista_alunos, cursos, matricula, codigo_disciplina, "resultados_tempo_busca.txt");
}


void teste_de_busca(Arv_cursos **Raiz, No_Aluno **Lista){
    preencher_cursos_automatico(Raiz, 10000); //Vai inserir 10000 cursos

    preencher_arv_disciplinas_curso(*Raiz); 

    preencher_aluno_automatico(Lista); 

    matricular_e_registrar_notas(*Lista, *Raiz); 

    executar_testes_busca_nanosegundos(*Lista, Raiz, 10001, 1125);

}
