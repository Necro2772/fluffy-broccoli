#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


void shuffle(int *cards[]){
  for (int i = 0; i < 52; i++){
    *cards[i] = rand() % 52;
    printf("%d\n", *cards[i]);
  }

}

void main(int a, char *input[]){
  FILE *fp;
  int deck[52];
  int player[52];
  int dealer[52];
  int value;
  int num = 0;
  int i = 0;

  fp = fopen ("./cards.txt", "rb");
  if(fp){
    while(1){
      value = fgetc (fp);
      if (isdigit(value)) {
        value -= 48;
        num = num * 10;
        num += (int)value;
      }
      if (value == ',') {
      deck[i] = num;
      i++;
      num = 0;
      }
      if (value == ']') break;
    }
    while(1){
      value = fgetc (fp);
      if (isdigit(value)) {
        value -= 48;
        num = num * 10;
        num += (int)value;
      }
      if (value == ',') {
      player[i] = num;
      i++;
      num = 0;
      }
      if (value == ']') break;
    }
    while(1){
      value = fgetc (fp);
      if (isdigit(value)) {
        value -= 48;
        num = num * 10;
        num += (int)value;
      }
      if (value == ',') {
      dealer[i] = num;
      i++;
      num = 0;
      }
      if (value == ']') break;
    }
    fclose (fp);

  }




  if (&deck[1] == NULL){
    shuffle(deck);
  }
}
