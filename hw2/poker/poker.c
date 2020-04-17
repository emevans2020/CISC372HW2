#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Emily Evans Poker Problem 4 extra credit
typedef enum suit_s {DIAMONDS, CLUBS, HEARTS, SPADES} Suit;

//1 represents an Ace, an 11 represents a Jack, a 12 Queen, a 13 King.
typedef struct card_s {
  int rank;
  Suit suit;
} * Card;

typedef struct hand_s {
  Card *c;
} * Hand;

// function declarations
Card randCard();
void printCard(Card c);
void destroyCard(Card c);
int cardsEqual(Card c1, Card c2);
Hand randHand();
void printHand(Hand h);
void destroyHand(Hand h);
int isStraightFlush(Hand h);
int isStraight(Hand h);
int isFlush(Hand h);
void sortHand (Card *c);

/* take one command line input, the number of trials.  Then iterate #trials times.  
 * At each iteration, generate a random hand, determine if it is a straight 
 * flush, increment a counter if so, and destroy the hand.  At the end print out 
 * both the total number of straight flushes encountered, and the fraction 
 * (a number between 0 and 1) of the hands that were straight flushes.*/

int main (int argc, char*argv[]){
    srand(time(NULL));
    int trials = atof(argv[1]);

    float numOfStraightFlushes = 0;

    for (int i = 0; i < trials; i++){
	Hand hand = randHand();
	if (isStraightFlush(hand)){
	    numOfStraightFlushes++;
	}
	destroyHand(hand);
    }

    printf("The total number of straight flushes encountered is %.0f \n",numOfStraightFlushes);
    printf("The fraction of hands that were\
	 straight flushes is %f \n",(numOfStraightFlushes/trials));

    return 0;
}

Card randCard(){
    Card c = (Card)malloc(sizeof(Card));
    c->rank = rand() % 13 +1;

    int suitNum = rand() % 4;
    switch(suitNum){
	case 0:
	   c->suit = CLUBS;
	   break;
	case 1:
	   c->suit = DIAMONDS;
	   break;
	case 2:
	   c->suit = SPADES;
	   break;
	case 3:
	   c->suit = HEARTS;
	   break; 
	default:
	   c->suit = HEARTS;
    }
    return c;
}

void printCard(Card c){
    char *suit;
    if (c->suit == CLUBS){
	    suit = "Clubs";
    } else if (c->suit == DIAMONDS) {
	    suit = "Diamonds";
    } else if (c->suit == SPADES) {
	    suit = "Spades";
    } else {
	    suit = "Hearts";
    }
    printf(" %s - %d, ",suit, c->rank);
}

void destroyCard(Card c){
    free(c);
}

int cardsEqual(Card c1, Card c2){
    if ((c1->suit == c2->suit) && (c1->rank == c2->rank)){
	    return 1;
    } else {
	    return 0;
    }
}

Hand randHand(){
    Hand hand = (Hand)malloc(sizeof(Hand));
    
    int distinct = 0;
    while (distinct==0){
	hand->c = (Card *)malloc(5*sizeof(Card *));
        for (int i = 0; i < 5; i++){
	    hand->c[i] = randCard();
	}
	
	distinct = 1;
	
	//check to see if cards in list are the same
	for (int j=0; j < 4; j++){
	    for (int k=(j+1); k < 5; k++){
		    if (cardsEqual(hand->c[j],hand->c[k])){
			    distinct = 0;
		    }
	    }
	}
	if (distinct == 0){
	    for (int i = 0; i < 5; i++){
	        destroyCard(hand->c[i]);
	    }
	    free(hand->c);
	}
    }
    return hand;
}

void printHand(Hand h){
    printf("[");
    for (int i=0; i<5; i++){
	    printCard(h->c[i]);
    }
    printf("] \n");
}

void destroyHand(Hand h){
    for (int i=0; i < 5; i++){
	destroyCard(h->c[i]);
    }
    free(h->c);
    free(h);
}

int isStraight(Hand h){
    sortHand(h->c); //sort cards in hand in ascending order
    // This if statement checks if the straight is Ace (1), Jack, Queen, King, 10
    if((h->c[0]->rank == 1) && (h->c[1]->rank != 2)){
	for (int i=1; i<5; i++){
	    if (h->c[i]->rank != (i+9)){
		return 0;
	    }
	}
	return 1;
    }

    for (int i=0; i<4;i++){
	if ((h->c[i]->rank) != (h->c[i+1]->rank-1)){
	    return 0;
	}
    }
    return 1;
}

int isFlush(Hand h){
    int flush = 1;
    Suit s = h->c[0]->suit;
    int i = 0;

    while (i < 5){
	if (h->c[i]->suit != s){
	    flush = 0;
	}
	i++;
    }
    return flush;	
}
	      
int isStraightFlush(Hand h){
    if(isFlush(h) && isStraight(h)){
	return 1;
    } else {
	return 0;
    }
}	

// sortHand sorts cards in ascending order and is a helper function to isStraight
void sortHand (Card *c){
    for (int i=0; i<4; i++){
	for (int j=(i+1); j<5; j++){
	    if(c[i]->rank > c[j]->rank){
		Card temp = c[i];
		c[i] = c[j];
		c[j] = temp;
	    }
	}
    }
}
    
