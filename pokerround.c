#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int* cards){
  srand(time(0));
  int repeat = 0;
  for (int i = 0; i < 52; i++){
    cards[i] = rand() % 52;
    while(1){
      repeat = 0;
      for(int a = 0; a < i; a++){
        if(cards[i] == cards[a]){
          repeat = 1;
        }
      }
      if(repeat == 1){
        cards[i] = rand() % 52;
      }else{
        break;
      }
    }
  }

  for(int i = 0; i < 52; i++){
  printf("%d\n", cards[i]);
  }
}

void draw(int* top, int* deck, int* draw){
  for (int i = 0; i<52; i++){
    if (draw[i] == -1){
      draw[i] = deck[*top];
      break;
    }
  }
  *top -= 1;
}

void main(int b, char *input[]){
  FILE *fp;
  int deck[52];
  int player[52];
  int dealer[52];
  int value;
  int num = 0;
  int a = 0;
  int top;

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
      deck[a] = num;
      a++;
      num = 0;
      }
      if (value == ']') break;
    }
    a = 0;
    while(1){
      value = fgetc (fp);
      if (isdigit(value)) {
        value -= 48;
        num = num * 10;
        num += (int)value;
      }
      if (value == ',') {
      player[a] = num;
      a++;
      num = 0;
      }
      if (value == ']' && a == 0){
        for (int i = 0; i<52; i++){
          player[i] = -1;
        }
      }
      if (value == ']') break;
    }
    a = 0;
    while(1){
      value = fgetc (fp);
      if (isdigit(value)) {
        value -= 48;
        num = num * 10;
        num += (int)value;
      }
      if (value == ',') {
      dealer[a] = num;
      a++;
      num = 0;
      }
      if (value == ']' && a == 0){
        for (int i = 0; i<52; i++){
          dealer[i] = -1;
        }
      }
      if (value == ']') break;
    }
    fclose (fp);
  }

  if (!(isdigit(player[1]))){
    shuffle(deck);
    top = 51;
  }

 /* switch (*input[1]){
    case 'r':
      draw(&top, deck, player);
      draw(&top, deck, player);
      draw(&top, deck, dealer);
      draw(&top, deck, dealer);
      break;
    case 'd':
      draw(&top, deck, player);
      check score
      if (score greater thn 21)
      Player loses
      printf "wow trash"
      break;
    case 's':
      if (dealer score below 16);
      draw(&top, deck, dealer);
      if dealer score above 21
      player wins
      else compare scores
      if (playerScore higher or equal to dealerScore);
      Player wins
      printf("good job")
      else (Dealer score higher)
      Player loses
      printf("you suck")
      break;
    default:
      break;
 */ }
}
