#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int addClass(int turmas[10][100], int classNumber, int flagTurma) {
  turmas[flagTurma][0] = classNumber;
}

void summaryClass(int turmas[10][100]) {
  printf("\n\nTURMAS CADASTRADAS\n\n");
  for (int z= 0; z < 10; z++){
      printf("%d\n", turmas[z][0]);
    }
}

int classExists(int turmas[10][100], int classCode) {
  for(int i = 0; i < 10; i++) {
    if(turmas[i][0] == classCode) {
      return 1;
    }
  }

  return 0;
}

int studentExists(int turmas[10][100], int studentCode) {
  for(int i = 0; i < 10; i++){
    for(int z = 1; z < 100; z++) {
      if(turmas[i][z] == studentCode) {
        return 1;
      }
    }
  }

  return 0;
}

int indexOfClass(int turmas[10][100], int classCode) {
  for(int i = 0; i < 10; i++) {
    if(turmas[i][0] == classCode) {
      return i;
    }
  }
}

int studentInsert(int turmas[10][100], int studentCode, int indexClass) {
  for(int i = 0; i < 100; i++){
    if(turmas[indexClass][i] == 0){
      turmas[indexClass][i] = studentCode;
      break;
    }
  }
}

int classReport(int turmas[10][100]) {
  int count = 0;
  for(int i = 0; i < 10; i++) {
    if(turmas[i][0] != 0) {
      codeClass(turmas, i);
      count++;
    }
  }

  if(count == 0) {
    printf("\n\nAinda não existem turmas cadastradas\n\n");
  }
}

int codeClass(int turmas[10][100], int indexClass) {
  int count = 0;
  printf("Turma %d\n", turmas[indexClass][0]);
  for(int i = 1; i < 100; i++) {
    if(turmas[indexClass][i] != 0) {
      printf("- %d\n", turmas[indexClass][i]);
      count++;
    }
  }

  printf("Total de alunos = %d\n\n", count);
}

int removeStudent(int turmas[10][100], int classCode, int studentPosition) {
  for(int i = studentPosition; turmas[classCode][i] != 0; i++) {
    turmas[classCode][i] = turmas[classCode][i + 1];
  }
}

int indexOfClassStudent(int turmas[10][100], int studentRegister) {
  for(int i = 1; i < 10; i++) {
    for(int z = 1; z < 100; z++){
      if(turmas[i][z] == studentRegister) {
        return i;
      }
    }
  }
}

int indexOfStudent(int turmas[10][100], int studentRegister) {
  for(int i = 0; i < 10; i++) {
    for(int z = 1; z < 100; z++){
      if(turmas[i][z] == studentRegister) {
        printf("%d", z);
        return z;
      }
    }
  }
}

int main(){
  UINT UTF8 = 65001;
  SetConsoleOutputCP(UTF8);

  int programControl = 1;
  int menuControl;
  int turmas[10][100] = {{0}};

  int flagTurma = 0;
  int countStudent = 0;

  do
  {
    printf("\n\n\n_____Escola____"
  "\n1 - Cadastrar Turma"
  "\n2 - Cadastrar Aluno"
  "\n3 - Relatório de Turmas"
  "\n4 - Remover Aluno"
  "\n0 - Sair\n\n\n");

  scanf("%d", &menuControl);


  if (menuControl == 1)
  {
    int classCode;
    int isClass;
    printf("Digite o código da turma\n");
    scanf("%d", &classCode);

    isClass = classExists(turmas, classCode);

    if(isClass == 1) {
      printf("ERRO: já existe uma turma com esse código");
    } else if(isClass == 0) {
      if(flagTurma > 9) {
        printf("ERRO: Número máximo de turmas atingido");
      } else {
      addClass(turmas, classCode, flagTurma);
      flagTurma++;
      }
    }

    summaryClass(turmas);

    }

  else if (menuControl == 2)
  {
    int classCode, studentCode, flagClass, flagStudent, indexClass;

    if(countStudent > 99) {
      printf("Número máximo de alunos excedido\n\n");
    }

    printf("Digite o código da turma para cadastrar o aluno:\n");
    scanf("%d", &classCode);
    flagClass = classExists(turmas, classCode);

    if(flagClass == 0) {
      printf("A turma não existe\n\n");
    }

    else if (flagClass == 1) {
    printf("Digite a matrícula do aluno:\n");
    scanf("%d", &studentCode);
    flagStudent = studentExists(turmas, studentCode);

      if(flagStudent == 1) {
        printf("O aluno já está cadastrado\n");
      }

      else if (flagStudent == 0) {
      indexClass = indexOfClass(turmas, classCode);
      studentInsert(turmas, studentCode, indexClass);
      countStudent++;
      }
    }
  }
  
  else if(menuControl == 3) {
    classReport(turmas);
  }

  else if(menuControl == 4) {
    int studentRegister, isStudent, classCode, studentPosition;
    printf("Digite o número da matrícula do aluno a ser removido:\n");
    scanf("%d", &studentRegister);

    isStudent = studentExists(turmas, studentRegister);

    if(isStudent == 1) {
      classCode = indexOfClassStudent(turmas, studentRegister);
      studentPosition = indexOfStudent(turmas, studentRegister);
      removeStudent(turmas, classCode, studentPosition);
    }

    else {
      printf("ERRO: o aluno informado não está cadastrado\n\n");
    }
  }

  else if(menuControl == 0) {
    programControl = menuControl;
  }

  else {
    printf("Opção inexistente! Por favor tente novamente.\n\n");
  }
  
  } while (programControl!= 0);

  return 0;
}