Lista de alunos (O sistema tem uma lista única de alunos, organizada por ordem alfabética)

Sobre o cadastro de alunos: A estrutura é de uma lista encadeada simples, organizada por ordem alfabética, a lista deve englobar todos os alunos da universidade, identificados pelo código do curso (o curso deve ser válido).           
(implementado)



Sobre Cadastro de disciplinas: 


A função deve perguntar o código do curso que deseja inserir a disciplina, percorrer a árvore de cursos e encontrar o curso, uma segunda chamada de preenchimento deve ocorrer, e inserir a disciplina na arvore especifica do curso. (A ordem é código da disciplina)
  
OBS: Verificar se a disciplina, o período é menor que 1 e menor e igual ao máximo de períodos, se não for, o usuário deve digitar novamente. Na função, de preenchimento de disciplinas, verificar, se a carga horaria é múltipla de 15 (30,45,60,75,90). 

 
Sobre Arvore de Cadastro de Matricula (Pré-requisito: Deve estar inserida dentro da lista encadeada de Alunos)

O usuário deve digitar sua matricula pessoal pra realizar a matricula em disciplinas, ao inserir o código de matricula (do aluno), deve-se realizar uma busca na lista, para encontrar o correspondente cadastrado, ao encontrar, o usuário pode inserir o código da disciplina que deseja se matricular. 

A função então deve utilizar o código do curso (proveniente de uma info da lista encadeada do aluno) percorrer a arvore de cursos, e daí, percorrer a arvore de disciplinas (Caso encontre a disciplina, retorna 1, e registra a info na árvore de matriculas do aluno, caso 0, encerra a operação)


OBS: A verificação do curso não é necessária, pq no cadastro do aluno, um valor válido de código de curso já foi inserido, no entanto, o sistema deve verificar se a disciplina existe. Como já sabemos o código do curso, basta percorrer a arvore de disciplinas e validar. 


Sobre a árvore  de cadastrar Notas (A mesma deve estar inserida dentro da Lista encadeada do Aluno). 

O sistema deve perguntar e percorrer (buscando pela matricula) na lista encadeada o aluno, ao encontra-lo (como já temos a info de qual curso ele está, não devemos perguntar isso, mas sim pegar a informação de lá) deve-se perguntar qual o código da disciplina devemos matricula-lo. Com o código do curso (proveniente da info da lista) com o código da matricula, é possível buscar correspondente na arvore de disciplinas, ao confirmar, a info deve ser inserida na arvore de matriculas (na lista encadeada do aluno, dentro da arvore de matriculas)



Funções de exibir 

Mostrar todos os alunos do curso: O sistema deve pedir o código do curso, e em seguida percorrer a lista encadeada e imprimindo os correspondentes. 

Mostrar todos os cursos do Campus: Percorre a árvore de cursos e sai imprimindo os correspondentes. 

Mostrar todas as disciplinas do Curso: O sistema deve pedir o código do curso, imprimindo todas as disciplinas cadastradas do curso correspondente. 

Mostrar todas as disciplinas do Curso em determinado período: O sistema deve pedir o código do curso, imprimindo todas as disciplinas cadastradas do curso correspondente, no período solicitado. 

Mostrar todas as disciplinas que um determinado aluno está matriculado: O sistema deve pedir a matricula do aluno, percorrer a lista encadeada e imprimir todas as disciplinas matriculadas pelo aluno (ou usar essas infos pra imprimir mais detalhes sobre as disciplinas, percorrendo a arvore de disciplinas inseridas no curso)


Mostrar todas as Notas de disciplinas de um determinado período de determinado aluno: O sistema deve pedir a matricula do aluno, percorrer a lista encadeada, e imprimir todas as notas de disciplinas do período solicitado. 

Mostrar a Nota de uma disciplina de Determinado Aluno (Mostrando o período e a carga horaria da disciplina): O sistema deve pedir a matricula do aluno, em seguida deve pedir o código da disciplina, buscando-a na árvore de notas, a função então deve chamar pra percorrer a arvore de disciplinas(dentro da árvore de cursos) e imprimir o nome da disciplina e a carga horaria.  



Sobre as funções de remoção: 

Remover uma disciplina de um determinado curso (Desde que não tenha ninguém matriculado): O usuário deve digitar o código do curso, e o código da disciplina, então o sistema deve percorrer a lista encadeada, buscando correspondência de curso(caso não encontre, é a primeira condição de parada, significando que não tem ninguém matriculado), caso encontre, o sistema deve percorrer a arvore de matriculas, atrás de correspondente (info = código da matéria), caso encontre, a operação é encerrada, caso não, vai prosseguir. 

 
Estando ok na verificação de alunos matriculados, o sistema deve percorrer a árvore de cursos atrás de um correspondente, caso não encontre, a operação é abortada. Caso o curso seja encontrado, aí ele vai percorrer a arvore de disciplinas, se encontrar a disciplina, ele remove, caso não, a operação é abortada. (Retorno 1 ou 0) 



Permita remover uma disciplina da arvore de matricula de um determinado aluno: O usuário deve inserir a matricula dele, caso não encontre, a operação é abortada, caso encontre o aluno, percorrer a lista encadeada e inserir(do usuário) o código da disciplina, caso encontre na árvore, realizar a remoção, caso não, retorna 0. 










 







