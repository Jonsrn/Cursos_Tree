#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "universidade.h"


//Função de mensagem do Item II (Inserção de Cursos)
void mensagens_tela_cadastro(int situacao){
   if(situacao == 0){
        printf("\nCurso inserido com sucesso\n"); 
   }
   if(situacao == 1){
     printf("\nA operação falhou porque houve uma falha na criação do Nó\n"); 
   }  
   if(situacao == 2){
     printf("\nA operação falhou porque já existe um curso com esse código de curso\n"); 
   }
}


//Função de mensagem do Item I (Inserção de Aluno)
void mensagens_cadastro_aluno(int situacao){
   //situação 0 significa que a operação funcionou conforme esperado
   if(situacao == 0){
     
      printf("\nOperação realizada com sucesso.\n"); 
    
   }
   if(situacao == 1){
      printf("\nA operação falhou, pois não há cadastros de cursos no sistema.\n"); 
   }
    
   if(situacao == 2){ 
      printf("\nA operação falhou porque o curso digitado não foi encontrado.\n");
      
   }
   
   if(situacao == 3){
      printf("\nA operação falhou porque houve uma falha na criação do nó.\n"); 
   }
   if(situacao == 4){
      printf("\nA operação falhou porque o número de matricula já existe\n"); 
   }
}

//Função de mensagem referente ao Item III (Inserir Disciplinas)
void mensagens_cadastro_disciplina(int situacao){
    if(situacao == 0){
       printf("\nDisciplina Cadastrada com Sucesso!\n"); 
    }
    if(situacao == 1){
        printf("\nA operação falhou porque não há cursos cadastrados no sistema\n"); 
    }
    if(situacao == 2){
        printf("\nA operação falhou porque nenhum curso com esse codigo foi encontrado.\n"); 
    }
    if(situacao == 3){
        printf("\nA operacao falhou porque o Nó não foi alocado corretamente.\n"); 
    }
    if(situacao == 4){
        printf("\nA operação falhou porque um curso de mesmo codigo foi inserido anteriormente.\n");
    }
}

//Função de mensagem referente ao Item IV (Inserir Matriculas)
void mensagens_cadastro_matricula(int situacao){
    if(situacao == 0){
        printf("\nDisciplina matriculada com sucesso\n"); 
    }
    if(situacao == 1){
        printf("\nA operação falhou, porque não há cursos cadastrados no sistema\n"); 
    }
    if(situacao == 2){
        printf("\nA operação falhou, porque não há alunos cadastrados no sistema\n"); 
    }
    if(situacao == 3){
        printf("A operação falhou porque o aluno não está na lista\n"); 
    }
    if(situacao == 4){
        printf("\nA operação falhou porque não há disciplinas cadastradas nesse curso\n"); 
    }
    if(situacao == 5){
        printf("A operação falhou porque a disciplina solicitada não está disponivel no curso\n"); 
    }
    if(situacao == 6){
        printf("A operação falhou porque o Nó não foi alocado corretamente\n"); 
    }
    if(situacao == 7){
        printf("A operação falhou poruque não foi possivel a inserção na árvore de matriculas\n"); 
    }
}

//Função de mensagem, referente ao item V (Inserir Notas)
void mensagens_cadastro_notas(int situacao){
    if(situacao == 0){
        printf("\nCadastro de Notas Efetuado com Sucesso\n"); 
    }
    if(situacao == 1){
        printf("\nA operação falhou porque não há alunos cadastrados no sistema\n"); 
    }
    if(situacao == 2){
        printf("\nA operação falhou porque o aluno buscado não foi encontrado\n");
    }
    if(situacao == 3){
        printf("\nA operação falhou porque não há disciplinas matriculadas nesse aluno\n");
    }
    if(situacao == 4){
        printf("\nA operação falhou porque a disciplina não foi encontrada ou a remoção falhou.\n"); 
    }
    if(situacao == 5){
        printf("\nA operação falhou porque o nó de Notas não foi criado corretamente\n"); 
    }
    if(situacao == 6){
        printf("\nA operação falhou porque a inserção não foi feita corretamente, o valor retirado da arvore de matriculas foi revertido\n"); 
    }
} 

void mensagens_exibicao_cursos(int situacao){
    if(situacao == 0){
        printf("\nOperação realizada com sucesso\n"); 
    }
    if(situacao == 1){
        printf("\nA operação falhou porque não há cursos cadastrados no sistema\n"); 
    }
}
//Função de mensagem, referente ao Item VIII (Exibir todas as disciplinas daquele curso)
void mensagens_exibicao_disc(int situacao){
    if(situacao == 0){
        printf("\nOperação realizada com sucesso.\n"); 
    }    
    if(situacao == 1){
        printf("\nA operação falhou porque não há nenhum curso cadastrado no sistema\n"); 
    }
    if(situacao == 2){
        printf("\nA operação falhou porque nenhum curso com o valor pesquisado foi encontrado.\n"); 
    }
    if(situacao == 3){
        printf("\nA operação falhou porque o curso solicitado não possui disciplinas cadastradas\n"); 
    }
}

void mensagens_exibicao_alunos(int situacao){
    if(situacao == 0){
         printf("\nOperação realizada com sucesso.\n");
    }
    if(situacao == 1){
        printf("\nNão há nenhum curso cadastrado no Sistema\n"); 
    }
    if(situacao == 2){
        printf("\nNão há nenhum aluno cadastrado no Sistema\n"); 
    }
    if(situacao == 3){
        printf("\nCurso não encontrado\n"); 
    }
}

void mensagens_exibir_todas_disc_aluno(int situacao){
    if(situacao == 0){
        printf("\nA operação foi realizada com sucesso\n"); 
    }
    if(situacao == 1){
        printf("\nA operação falhou porque não há cursos cadastrados no sistema\n"); 
    }
    if(situacao == 2){
        printf("\nA operação falhou porque não há alunos cadastrados no sistema\n"); 
    }
    if(situacao == 3){
        printf("\nA operação falhou porque não há nenhum aluno com a matricula pesquisada\n"); 
    }
    if(situacao == 4){
        printf("\nA operação falhou porque não foi possivel recuperar o endereço da memória do Nó da Árvore de Cursos\n"); 
    }
    if(situacao == 5){
       printf("\nA operação falhou porque a arvore de matriculas do aluno está vazia\n"); 
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
    if (situacao == 4){
        printf("\nA nota buscada não foi encontrada\n"); 
    }
}

void mensagens_historico_aluno(int situacao){
    if(situacao == 0){
        printf("\nOperação realizada com sucesso\n"); 
    }
    if(situacao == 1){
        printf("\nA operação falhou, pois nenhum curso foi encontrado no sistema\n"); 
    }
    if(situacao == 2){
        printf("\nA operação falhou, pois não há alunos cadastrados no sistema"); 
    }
    if(situacao == 3){
        printf("\nA operação falhou, pois o aluno buscado não foi encontrado\n"); 
    }
    if(situacao == 4){
        printf("\nA operação falhou, pois não há notas cadastradas pra esse aluno\n"); 
    }
    if(situacao == 5){
        printf("\nA operação falhou, pois não há disciplinas cadastradas no momento, é necessário disciplinas cadastradas no curso\n"); 
    }
    if(situacao == 6){
        printf("\nA operação falhou em recuperar os dados da árvore de disciplinas\n"); 
    }
    if(situacao == 7){
        printf("\nA operação falhou em recuperar os dados da árvore de notas\n"); 
    }
}
