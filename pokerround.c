#include <stdio.h>
//hdjshajdhsadas
void main(int a, char *input[]){
  FILE *fp;
  int deck[52];
  int value;
  int num = 0;
  int i = 0;

  fp = fopen ("./cards.txt", "rb");
  if (fp) {
    while(1){
      value = fgetc (fp);
      if (isdigit(value)) {
        printf("%d", value);
        num = num * 10;
        num += value;
      }
      if (value == ',') {
      deck[i] = num;
      i++;
      }
      if (value == ']') break;
    }
    while(1){
      value = fgetc (fp);
      if (value == ']') break;
    }
    while(1){
      value = fgetc (fp);
      if (value == ']') break;
    }
    fclose (fp);

  }


}
