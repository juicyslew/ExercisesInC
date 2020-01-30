#include <stdio.h>
#include <stdlib.h>

/* cards.c takes card strings from user inputs in terminal
   and outputs the value of that card directly afterward.
   
   While doing this, the program also maintains a count
   to give a sense of the chance of drawing a high or low
   card if one were to "hit" (i.e. Ask for another card)
*/


void getCard(char * card_container);
int card2Val(char * card_container, int * skip);
void updateCounter(int * count, int val);


int main()
{
    char card_name[3];
    int c; int s;
    int * count = &c;
    int * skip = &s;
    int val;
    do{
        getCard(card_name);
        
        val = card2Val(card_name, skip);

        if (*skip){
            continue;
        }
        
        updateCounter(count, val);
    } while (card_name[0] != 'X');
    return 0;
}

void getCard(char * card_container)
{
    puts("Enter the card name: ");
    scanf("%2s", card_container);
}

int card2Val(char * card_container, int * skip)
{
    int val = 0;
    switch(card_container[0]){
    case 'K':
    case 'Q':
    case 'J':
        val = 10;
        break;
    case 'A':
        val = 11;
        break;
    case 'X':
        *skip = 1;
        break;
    default:
        val = atoi(card_container);
        if ((val < 1) || (val > 10)){
            puts("I don't understand that value!");
            *skip = 1;
        }
        break;
    }
    return val;
}

void updateCounter(int * count, int val){
    if ((val > 2) && (val < 7)){
        (*count)++;
    }else if (val==10){
        (*count)--;
    }
    printf("Current count: %i\n", *count);
}