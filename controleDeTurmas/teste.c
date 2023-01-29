#include <stdio.h>;
#include <stdlib.h>;
#include <windows.h>;

int main(){
  UINT UTF8 = 65001;
  SetConsoleOutputCP(UTF8);

  int a;
  scanf("%d", &a);

  printf("%d", a);

}