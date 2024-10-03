#ifndef _UNIVERSIDADE_H
#define _UNIVERSIDADE_H

//funções de menu, mensagens e preenchimento
void menu_principal(); 
void menu_cadastrar();
void menu_exibir();
void menu_excluir(); 
void mensagens_tela_cadastro(int opcao, int resposta); 






//estruturas 

/*
código da disciplina, semestre cursado, nota final obtida pelo aluno. A árvore deve ser 
organizada pelo código da disciplina. 
*/
// Definição dos aliases
typedef struct Arvore_Notas Arv_Not;
typedef struct Arv_Matricula_na_Disciplina Arv_Mat_Disc;
typedef struct Arv_disciplinas Arv_disc;
typedef struct Arvore_Cursos Arv_cursos;

// Estrutura que guarda os dados das notas dos alunos
typedef struct Info_Notas {
    int codigo_disciplina; 
    int semestre_cursado; 
    float nota_final;
} Info_Notas; 

// Árvore das notas dos alunos
struct Arvore_Notas { 
    Info_Notas info; 
    Arv_Not *esq, *dir;     
};

// Árvore que guarda as matrículas dos alunos nas disciplinas (até que se cadastre a nota)
struct Arv_Matricula_na_Disciplina {
    int codigo_disciplina; 
    Arv_Mat_Disc *esq, *dir; 
};

// O dado do aluno (que irá servir de info para uma lista encadeada, em ordem alfabética)
typedef struct Info_Aluno {
    int matricula;
    char nome_do_aluno[100];
    int codigo_curso; 
    Arv_Not *notas;           // Ponteiro para a árvore de notas do aluno
    Arv_Mat_Disc *matriculas;  // Ponteiro para a árvore de matrículas do aluno
} info_Aluno; 

//lista do aluno
typedef struct No_Aluno {
    info_Aluno aluno;         // Informações do aluno
    struct No_Aluno *prox;    // Ponteiro para o próximo nó da lista
} No_Aluno;


// Info da árvore de disciplinas (contém os dados da disciplina)
typedef struct Info_Disciplinas {
   int codigo_disciplina; 
   char nome_da_disciplina[100]; 
   int periodo; 
   int carga_horaria;  
} Inf_Disc;  

// Árvore de disciplinas
struct Arv_disciplinas { 
    Inf_Disc info; 
    Arv_disc *esq, *dir; 
};

// Informação da árvore de cursos
typedef struct Info_cursos {
    int codigo_do_curso; 
    char nome_do_curso[100]; 
    int qtdade_de_periodos; 
    Arv_disc *disciplinas;  // Ponteiro para a árvore de disciplinas do curso
} Inf_Cursos; 

// Árvore de cursos propriamente dita
struct Arvore_Cursos { 
    Inf_Cursos info;
    Arv_cursos *esq, *dir; 
};




/*
Lista de Alunos: Matricula do aluno, Nome do aluno, Código do Curso, árvore de Notas, árvore de 
Matrícula, a lista deve ser organizada pela ordem de alfabética por nome do aluno.


*/


//Funções relacionadas ao Curso
int criarNo_Cursos(int codigo, const char *nome, int periodos, Arv_cursos **novo);  
int inserirArvBB_Cursos(Arv_cursos **R, Arv_cursos *No); 
void preencher_cursos(Arv_cursos **R);  
void imprimirArvBB_Cursos(Arv_cursos *R); 
int verificar_arv_Cursos(int codigo_curso, Arv_cursos *S, Arv_cursos **resultado);


//Funções relacionada a lista dos alunos 
void preencher_alunos(No_Aluno **R, Arv_cursos **S); 
int criarNo_Aluno(info_Aluno *temp, No_Aluno **novo);
int inserir_lista_alunos(No_Aluno **R, No_Aluno **novo); 
int buscarAlunoPorMatricula(No_Aluno *lista, int matricula_aluno, No_Aluno **aluno_encontrado); 
void imprimir_alunos_do_curso(No_Aluno *lista, int codigo_curso); 
void exibir_todos_alunos_curso(No_Aluno *raiz); 
int verificar_aluno_com_disciplina(No_Aluno *lista, int codigo_curso, int codigo_disciplina); 



//Funções relacionadas a árvore de Disciplinas

void mensagens_cadastro_disciplina(int situacao); 
int criarNo_Disc(Inf_Disc *temp, Arv_disc **novo);   
int inserirArvBB_Disc(Arv_disc **disciplinas, Arv_disc *novo);
void preencherDisciplinas(Arv_cursos **S); 
int verificar_disciplina(Arv_disc *disciplinas, int codigo_disciplina); 
void imprimirArvBB_Disciplinas(Arv_disc *R); 
void imprimirArvBB_Disciplinas_periodo_especifico(Arv_disc *R, int periodo); 
void mensagens_exibicao_disc(int situacao); 
void exibir_disc_do_curso(Arv_cursos **S); 
void exibir_disc_periodo_especifico(Arv_cursos **S);
void buscar_disciplina(Arv_disc *raiz, int codigo_disciplina, Arv_disc **disciplina_encontrada); 
int menorFilho_Disc(Arv_disc *R, Arv_disc **menor); 
int ArvBB_Disc_Remover(Arv_disc **R, int codigo_disciplina); 
void remover_disc_curso(No_Aluno **raiz, Arv_cursos **R); 
void mensagens_exclusao_disciplina(int situacao); 
int armazenar_Nos_Arv_Disc(Arv_disc *R, Arv_disc ***vetor, int *tamanho); 



//Funções relacionadas a árvore de Matriculas 

int criarNo_Mat(int codigo_disciplina, Arv_Mat_Disc **novo); 
int inserirArvBB_Mat(Arv_Mat_Disc **matriculas, Arv_Mat_Disc *nova_matricula);
void preencher_matriculas(No_Aluno **raiz, Arv_cursos *S);  
int menorFilho(Arv_Mat_Disc *R, Arv_Mat_Disc **menor); 
int removeArvBB_Matriculas(Arv_Mat_Disc **R, int codigo_disciplina); 
void mensagens_exclusao_matriculas(int situacao);
void remover_Matricula(No_Aluno **raiz);  
void exibir_disciplinas_matriculadas(Arv_Mat_Disc *raiz, Arv_disc *disciplinas); 
void mostrar_todas_disc_aluno(No_Aluno **raiz, Arv_cursos **R); 
int verificar_matricula_ARVMatricula(int codigo_disciplina, Arv_Mat_Disc *R); 


//Funções relacionadas a árvore de Notas

void mensagens_cadastro_notas(int situacao); 
int criarNo_Notas(Info_Notas temp, Arv_Not **novo); 
int inserirArvBB_Notas(Arv_Not **notas, Arv_Not *novo); 
void preencher_notas(No_Aluno **raiz); 
void imprimir_notas_aluno_periodo(Arv_Not *notas, int periodo);
void mensagens_busca_notas_periodo(int situacao);
void exibir_notas_periodo(No_Aluno **raiz); 
void imprimir_nota_aluno_materia_especifica(Arv_Not *notas, int codigo_disciplina); 
void mensagens_nota_disciplina_especifica(int situacao);
void mostrar_nota_disciplina(No_Aluno **raiz); 
int armazenar_Nos_Arv_Notas(Arv_Not *R, Arv_Not ***vetor, int *tamanho); 
void imprimir_historico_Por_Periodo(Arv_disc **vetorDisc, int tamDisc, Arv_Not **vetorNotas, int tamNotas);   
void ordenarDisciplinasPorPeriodo(Arv_disc **vetorDisc, int tamDisc); 
void mensagens_historico_aluno(int situacao);
void mostrar_historico_aluno(Arv_cursos **raiz, No_Aluno **S); 







#endif
