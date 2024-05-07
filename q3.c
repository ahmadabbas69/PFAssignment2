#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void generate_hand(int hand[5][2]); // Using a 2D array to store both value and suit
int highest_card(int hand[5][2], int *highest_suit);
int compare_hands(int hand1[5][2], int hand2[5][2]);

// Main function
void main() {
    srand(time(NULL)); // Seed for random number generation
    
    int player1_hand[5][2], player2_hand[5][2];
    int player1_wins = 0, player2_wins = 0, games;

    printf("Enter number of games: ");
    scanf("%d", &games);

    for (int i = 0; i < games; i++) {
        generate_hand(player1_hand);
        generate_hand(player2_hand);

        printf("Player 1 hand:");
        for (int j = 0; j < 5; j++) {
            printf(" %d%c", player1_hand[j][0], player1_hand[j][1]);
        }
        printf("\nPlayer 2 hand:");
        for (int j = 0; j < 5; j++) {
            printf(" %d%c", player2_hand[j][0], player2_hand[j][1]);
        }

        int result = compare_hands(player1_hand, player2_hand);
        if (result > 0) {
            printf("\nPlayer 1 wins this round.\n\n");
            player1_wins++;
        } else if (result < 0) {
            printf("\nPlayer 2 wins this round.\n\n");
            player2_wins++;
        } else {
            printf("\nIt's a tie this round.\n\n");
        }
    }

    printf("Final Results: Player 1 wins %d, Player 2 wins %d\n", player1_wins, player2_wins);
    
}

// Function to generate a hand of 5 random cards, now including suits
void generate_hand(int hand[5][2]) {
    char suits[4] = {'C', 'D', 'H', 'S'}; // Suits
    for (int i = 0; i < 5; i++) {
        hand[i][0] = rand() % 13 + 2; // Card values between 2 and 14
        hand[i][1] = suits[rand() % 4]; // Random suit
    }
}

// Function to determine the highest card in a hand, returns highest card and suit via pointer
int highest_card(int hand[5][2], int *highest_suit) {
    int max = hand[0][0];
    *highest_suit = hand[0][1];
    for (int i = 1; i < 5; i++) {
        if (hand[i][0] > max || (hand[i][0] == max && hand[i][1] > *highest_suit)) {
            max = hand[i][0];
            *highest_suit = hand[i][1];
        }
    }
    return max;
}

// Function to compare two hands
int compare_hands(int hand1[5][2], int hand2[5][2]) {
    int highest_suit1, highest_suit2;
    int max1 = highest_card(hand1, &highest_suit1);
    int max2 = highest_card(hand2, &highest_suit2);
    if (max1 > max2 || (max1 == max2 && highest_suit1 > highest_suit2)) return 1;
    if (max1 < max2 || (max1 == max2 && highest_suit1 < highest_suit2)) return -1;
    return 0;
}
