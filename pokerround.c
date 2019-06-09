#include <stdio.h>
#include "pokerfunctions.h"
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

int main(int b, char *input[]){
  FILE *fp;
  int deck[52];
  int player[52];
  int dealer[52];
  int value;
  int num = 0;
  int a = 0;
  int top;

  fp = fopen ("./cards", "rb");
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
      if (value == '-'){
        num = -1;
      }
      if (isdigit(value) && num != -1) {
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
      if (value == '-'){
        num = -1;
      }
      if (isdigit(value) && num != -1) {
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
    while(1){
      value = fgetc (fp);
      if (isdigit(value)) {
        value -= 48;
        num = num * 10;
        num += (int)value;
      }
      if (value == ']') {
        top = num;
        break;
      }
    }
    fclose (fp);
  }
  switch (*input[2]){
    case 'r':
      shuffle(deck, player, dealer);
      top = 51;
      draw(&top, deck, player);
      draw(&top, deck, player);
      draw(&top, deck, dealer);
      draw(&top, deck, dealer);
      break;
    case 'd':
      draw(&top, deck, player);
      printf("Player: %d\n", score(player));
      if (score(player) > 21){
        printf("Your hand is over 21, you lose!\n");
        return 3;
      }
      break;
    case 's':
      while (score(dealer) < 16){
        draw(&top, deck, dealer);
      }
      printf("Player: %d, Dealer: %d\n", score(player), score(dealer));
      if (score(dealer) > 21){
        printf("Dealer busts, player wins!\n");
        return 2;
      }
      else if (score(player) >= score(dealer)){
        printf("Player wins!\n");
        return 2
      }
      else{
        printf("Dealer wins!\n");
        return 3
      }
      break;
    default:
      break;
  }

  fp = fopen ("cards", "wb");
  if(fp){
    fprintf(fp, "deck[");
    for(int i = 0; i < 52; i++){
      fprintf(fp, "%d,", deck[i]);
    }
    fprintf(fp, "]\n");
    fprintf(fp, "player[");
    for(int i = 0; i < 52; i++){
      fprintf(fp, "%d,", player[i]);
    }
    fprintf(fp, "]\n");
    fprintf(fp, "dealer[");
    for(int i = 0; i < 52; i++){
      fprintf(fp, "%d,", dealer[i]);
    }
    fprintf(fp, "]\n");
    fprintf(fp, "top[");
    fprintf(fp, "%d]", top);
  }
  fclose(fp);
}
