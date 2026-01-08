#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int computerChoice() {
    return rand() % 3 + 1;   // 1=Rock, 2=Paper, 3=Scissors
}

void displayChoice(int choice) {
    if (choice == 1)
        printf("Rock");
    else if (choice == 2)
        printf("Paper");
    else
        printf("Scissors");
}

int main() {
    int user, comp;
    char playAgain;

    srand(time(0));

    do {
        printf("\n=== Rock Paper Scissors Game ===\n");
        printf("1. Rock\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &user);

        if (user < 1 || user > 3) {
            printf("Invalid choice! Try again.\n");
            continue;
        }

        comp = computerChoice();

        printf("\nYou chose: ");
        displayChoice(user);
        printf("\nComputer chose: ");
        displayChoice(comp);

        printf("\n\nResult: ");

        if (user == comp)
            printf("It's a Draw!");
        else if ((user == 1 && comp == 3) ||
                 (user == 2 && comp == 1) ||
                 (user == 3 && comp == 2))
            printf("You Win!");
        else
            printf("Computer Wins!");

        printf("\n\nPlay again? (y/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("\nThanks for playing!\n");
    return 0;
}
