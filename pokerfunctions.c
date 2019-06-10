#include <stdio.h>
#include "pokerfunctions.h"
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

int score(int* hand){
  int points = 0;
  for(int i = 0; i < 12; i++){
    switch(hand[i]){
      case 0: points += 1;
      break;
      case 1: points += 1;
      break;
      case 2: points += 1;
      break;
      case 3: points += 1;
      break;
      case 4: points += 2;
      break;
      case 5: points += 2;
      break;
      case 6: points += 2;
      break;
      case 7: points += 2;
      break;
      case 8: points += 3;
      break;
      case 9: points += 3;
      break;
      case 10: points += 3;
      break;
      case 11: points += 3;
      break;
      case 12: points += 4;
      break;
      case 13: points += 4;
      break;
      case 14: points += 4;
      break;
      case 15: points += 4;
      break;
      case 16: points += 5;
      break;
      case 17: points += 5;
      break;
      case 18: points += 5;
      break;
      case 19: points += 5;
      break;
      case 20: points += 6;
      break;
      case 21: points += 6;
      break;
      case 22: points += 6;
      break;
      case 23: points += 6;
      break;
      case 24: points += 7;
      break;
      case 25: points += 7;
      break;
      case 26: points += 7;
      break;
      case 27: points += 7;
      break;
      case 28: points += 8;
      break;
      case 29: points += 8;
      break;
      case 30: points += 8;
      break;
      case 31: points += 8;
      break;
      case 32: points += 9;
      break;
      case 33: points += 9;
      break;
      case 34: points += 9;
      break;
      case 35: points += 9;
      break;
      case 36: points += 10;
      break;
      case 37: points += 10;
      break;
      case 38: points += 10;
      break;
      case 39: points += 10;
      break;
      case 40: points += 10;
      break;
      case 41: points += 10;
      break;
      case 42: points += 10;
      break;
      case 43: points += 10;
      break;
      case 44: points += 10;
      break;
      case 45: points += 10;
      break;
      case 46: points += 10;
      break;
      case 47: points += 10;
      break;
      case 48: points += 10;
      break;
      case 49: points += 10;
      break;
      case 50: points += 10;
      break;
      case 51: points += 10;
      break;
      default: break;
    }
  }
  return points;
}

void shuffle(int* cards, int* player, int* dealer){
  srand(time(0));
  int repeat = 0;
  for (int i = 0; i < 52; i++){
    cards[i] = rand() % 52;
    player[i] = -1;
    dealer[i] = -1;
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
