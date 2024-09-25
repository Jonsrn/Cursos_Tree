#ifndef _UNIVERSIDADE_H
#define _UNIVERSIDADE_H

//funções de menu, mensagens e preenchimento
void menu_principal(); 
void menu_cadastrar();
void menu_exibir();

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
typedef struct Aluno {
    int matricula;
    char nome_do_aluno[100];
    int codigo_curso; 
    Arv_Not *notas;           // Ponteiro para a árvore de notas do aluno
    Arv_Mat_Disc *matriculas;  // Ponteiro para a árvore de matrículas do aluno
} Aluno;

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
int criarNo(int codigo, const char *nome, int periodos, Arv_cursos **novo);  
int inserirArvBB_Cursos(Arv_cursos **R, Arv_cursos *No); 
void preencher_cursos(Arv_cursos **R);  
void imprimirArvBB_Cursos(Arv_cursos *R); 










#endif