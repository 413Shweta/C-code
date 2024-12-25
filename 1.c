#include <stdio.h>
#include <string.h>

// Structure to store player details
struct Player {
    char name[50];
    int runs;
    int balls;
    int fours;
    int sixes;
    float strikeRate;
};

// Function to calculate strike rate
void calculateStrikeRate(struct Player *p) {
    if (p->balls != 0) {
        p->strikeRate = (p->runs / (float)p->balls) * 100;
    } else {
        p->strikeRate = 0.0; // Avoid division by zero
    }
}

// Function to display the scorecard
void displayScorecard(struct Player players[], int n) {
    printf("\n=================================\n");
    printf("            Scorecard            \n");
    printf("=================================\n");
    printf("Name\t\tRuns\tBalls\t4s\t6s\tStrike Rate\n");
    printf("---------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-15s %d\t%d\t%d\t%d\t%.2f\n", 
               players[i].name, 
               players[i].runs, 
               players[i].balls, 
               players[i].fours, 
               players[i].sixes, 
               players[i].strikeRate);
    }
    printf("=================================\n");
}

int main() {
    int n;

    // Prompt the user to enter the number of players
    printf("Enter the number of players: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Number of players must be a positive integer.\n");
        return 1;
    }

    struct Player players[n];

    // Input player details
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for player %d:\n", i + 1);

        printf("Name: ");
        scanf(" %49[^\n]", players[i].name); // Read input including spaces, max 49 chars

        printf("Runs scored: ");
        if (scanf("%d", &players[i].runs) != 1 || players[i].runs < 0) {
            printf("Invalid input. Runs must be a non-negative integer.\n");
            return 1;
        }

        printf("Balls faced: ");
        if (scanf("%d", &players[i].balls) != 1 || players[i].balls < 0) {
            printf("Invalid input. Balls must be a non-negative integer.\n");
            return 1;
        }

        printf("Number of 4s: ");
        if (scanf("%d", &players[i].fours) != 1 || players[i].fours < 0) {
            printf("Invalid input. Number of 4s must be a non-negative integer.\n");
            return 1;
        }

        printf("Number of 6s: ");
        if (scanf("%d", &players[i].sixes) != 1 || players[i].sixes < 0) {
            printf("Invalid input. Number of 6s must be a non-negative integer.\n");
            return 1;
        }

        calculateStrikeRate(&players[i]); // Calculate strike rate
    }

    // Display the scorecard
    displayScorecard(players, n);

    return 0;
}
