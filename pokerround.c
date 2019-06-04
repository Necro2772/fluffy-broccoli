#include <stdio.h>
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
  int value;
  int i = 0;

  fp = fopen ("./cards.txt", "rb");
  if (fp) {
    while(1){
      value = fgetc (fp);
//      if (isdigit(value)) {
//        printf("%d", value);
//        deck[i] = value;
//      }
      i++;
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




    if (&deck[1] == NULL){
      shuffle(deck);
    }
}
