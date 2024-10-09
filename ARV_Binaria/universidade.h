#ifndef _UNIVERSIDADE_H
#define _UNIVERSIDADE_H

//funções de menu, mensagens e preenchimento
void menu_principal(); 
void menu_cadastrar();
void menu_exibir();
void menu_excluir(); 
 






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
//Funções do Item II- Cadastrar Curso
int criarNo_Cursos(int codigo, const char *nome, int periodos, Arv_cursos **novo); //Função que cria Nó, requisito do Item II 
int inserirArvBB_Cursos(Arv_cursos **R, Arv_cursos *No); //Função que insere o curso na árvore de cursos
void preencher_cursos(Arv_cursos **R); //Função de preenchimento, do Item II
void mensagens_tela_cadastro(int situacao);//Função que exibe as mensagens sobre o status do cadastro dos cursos (Item II)
//************************************************************ */
void mensagens_exibicao_cursos(int situacao); //Função simples que cuida de informar o status final da operação de exibição dos cursos (Item VI)
void exibir_todos_cursos(Arv_cursos *R); //Função do Item VII (imprimir todos os cursos)
void imprimirArvBB_Cursos(Arv_cursos *R); //Função que percorre a árvore de cursos, imprimindo em ordem suas informações (Item VII)
int verificar_arv_Cursos(int codigo_curso, Arv_cursos *S, Arv_cursos **resultado); //Função utilizada por múltiplos itens (I, III, IV, VI, VIII)


//Funções relacionada a lista dos alunos 
//****************************************************** */
//Funções do Item I- Cadastrar aluno
void preencher_alunos(No_Aluno **R, Arv_cursos **S); //Função de preenchimento, Item I
int criarNo_Aluno(info_Aluno *temp, No_Aluno **novo); //Função que cria Nó, requisito do Item I
int inserir_lista_alunos(No_Aluno **R, No_Aluno **novo); //Função que insere o Nó de aluno na Lista encadeada, requisito do item I
void mensagens_cadastro_aluno(int situacao); //Função simples que cuida de informar o status final da operação (Se deu certo, ou se falhou, demonstrando onde a operação falhou)
//********************************************************************* */ 
int buscarAlunoPorMatricula(No_Aluno *lista, int matricula_aluno, No_Aluno **aluno_encontrado); //Função utilizada em multiplos itens (IV, V)
void imprimir_alunos_do_curso(No_Aluno *lista, int codigo_curso); //Função utilizada no Item VI (imprime todos alunos do curso)
void exibir_todos_alunos_curso(No_Aluno *raiz, Arv_cursos *R); //Função utilizada no Item VI (Lida de coletar todas as infos necessárias pra função acima)
void mensagens_exibicao_alunos(int situacao); //Função auxiliar do Item VI, que exibe o status final da operação
int verificar_aluno_com_disciplina(No_Aluno *lista, int codigo_curso, int codigo_disciplina); 




//Funções relacionadas a árvore de Disciplinas
//********************************* */
//Funções referentes ao item III- Cadastro de Disciplinas
void mensagens_cadastro_disciplina(int situacao); //Função simples que cuida de informar o status final da operação
int criarNo_Disc(Inf_Disc *temp, Arv_disc **novo); //Função que cria um nó com os dados de uma disciplina  
int inserirArvBB_Disc(Arv_disc **disciplinas, Arv_disc *novo); //Função que insere o Nó na Arvore de Disciplinas, subordinada a um curso
void preencherDisciplinas(Arv_cursos **S); //Função de preenchimento, do Item III
/************************************************************************ */
int verificar_disciplina(Arv_disc *disciplinas, int codigo_disciplina); //Função utilizada no Item IV(Inserir Matricula), pra verificar a existencia da disciplina naquele curso
void imprimirArvBB_Disciplinas(Arv_disc *R); //Função utilizada no Item VIII (Exibir todas as disciplinas de determinado curso)
void imprimirArvBB_Disciplinas_periodo_especifico(Arv_disc *R, int periodo); 
void mensagens_exibicao_disc(int situacao); //Função auxiliar de mensagens do Item VIII
void exibir_disc_do_curso(Arv_cursos **S); //Função utilizada no Item VIII pra coletar os dados necessários pra operação 
void exibir_disc_periodo_especifico(Arv_cursos **S);
void buscar_disciplina(Arv_disc *raiz, int codigo_disciplina, Arv_disc **disciplina_encontrada); 
int menorFilho_Disc(Arv_disc *R, Arv_disc **menor); 
int ArvBB_Disc_Remover(Arv_disc **R, int codigo_disciplina); 
void remover_disc_curso(No_Aluno **raiz, Arv_cursos **R); 
void mensagens_exclusao_disciplina(int situacao); 
int armazenar_Nos_Arv_Disc(Arv_disc *R, Arv_disc ***vetor, int *tamanho); 



//Funções relacionadas a árvore de Matriculas 

//********************************* */
//Funções referentes ao item IV- Cadastro de Matriculas
int criarNo_Mat(int codigo_disciplina, Arv_Mat_Disc **novo); //Função de criar Nó pra árvore de matriculas
int inserirArvBB_Mat(Arv_Mat_Disc **matriculas, Arv_Mat_Disc *nova_matricula); //Função de inserir o nó na árvore de Matricula
void preencher_matriculas(No_Aluno **raiz, Arv_cursos *S); //Função de preenchimento do Item IV
void mensagens_cadastro_matricula(int situacao);//Função simples que imprime mensagens de status após a operação
/**************************************** */
int menorFilho(Arv_Mat_Disc *R, Arv_Mat_Disc **menor); //Função auxiliar da remoção, utilizada nos itens (V, )
int removeArvBB_Matriculas(Arv_Mat_Disc **R, int codigo_disciplina); //Função de remoção do Nó da árvore de Matriculas, utilizada nos itens (V, )
void mensagens_exclusao_matriculas(int situacao);
void remover_Matricula(No_Aluno **raiz);  
void exibir_disciplinas_matriculadas(Arv_Mat_Disc *raiz, Arv_disc *disciplinas); 
void mostrar_todas_disc_aluno(No_Aluno **raiz, Arv_cursos **R); 
void mensagens_exibir_todas_disc_aluno(int situacao);
int verificar_matricula_ARVMatricula(int codigo_disciplina, Arv_Mat_Disc *R); 




//Funções relacionadas a árvore de Notas

//******************************************** */
//Funções referentes ao Item V (Inserir Notas)
void mensagens_cadastro_notas(int situacao); //Função de mensagens da operação de inserção de notas
int criarNo_Notas(Info_Notas temp, Arv_Not **novo); //Função que cria o Nó na árvore de Notas
int inserirArvBB_Notas(Arv_Not **notas, Arv_Not *novo); //Função que insere o Nó na árvore de Notas
void preencher_notas(No_Aluno **raiz); //Função de preenchimento, do item V
/**************************************************************************** */
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