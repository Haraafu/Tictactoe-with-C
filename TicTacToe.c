#include <stdio.h>
#include <stdlib.h>

void board(char *space) {
    printf(" %c | %c | %c \n", *(space + 0), *(space + 1), *(space + 2));
    printf("-----------\n");
    printf(" %c | %c | %c \n", *(space + 3), *(space + 4), *(space + 5));
    printf("-----------\n");
    printf(" %c | %c | %c \n", *(space + 6), *(space + 7), *(space + 8));
}

void win(int *player, char *space, int *end){
    if (*player == 1){
        if ((*(space + 0) == 'X' && *(space + 1) == 'X' && *(space + 2) == 'X') ||
            (*(space + 3) == 'X' && *(space + 4) == 'X' && *(space + 5) == 'X') ||
            (*(space + 6) == 'X' && *(space + 7) == 'X' && *(space + 8) == 'X') ||
            (*(space + 0) == 'X' && *(space + 3) == 'X' && *(space + 6) == 'X') ||
            (*(space + 1) == 'X' && *(space + 4) == 'X' && *(space + 7) == 'X') ||
            (*(space + 2) == 'X' && *(space + 5) == 'X' && *(space + 8) == 'X') ||
            (*(space + 0) == 'X' && *(space + 4) == 'X' && *(space + 8) == 'X') ||
            (*(space + 2) == 'X' && *(space + 4) == 'X' && *(space + 6) == 'X')) {
            board(space);
            printf("\nPlayer 1 wins!\n");
            *end = 1;
        }
    } else {
        if ((*(space + 0) == 'O' && *(space + 1) == 'O' && *(space + 2) == 'O') ||
            (*(space + 3) == 'O' && *(space + 4) == 'O' && *(space + 5) == 'O') ||
            (*(space + 6) == 'O' && *(space + 7) == 'O' && *(space + 8) == 'O') ||
            (*(space + 0) == 'O' && *(space + 3) == 'O' && *(space + 6) == 'O') ||
            (*(space + 1) == 'O' && *(space + 4) == 'O' && *(space + 7) == 'O') ||
            (*(space + 2) == 'O' && *(space + 5) == 'O' && *(space + 8) == 'O') ||
            (*(space + 0) == 'O' && *(space + 4) == 'O' && *(space + 8) == 'O') ||
            (*(space + 2) == 'O' && *(space + 4) == 'O' && *(space + 6) == 'O')) {
            board(space);
            printf("\nPlayer 2 wins!\n");\
            *end = 1;
        }
    }
}

int main() {
    int i, input, player, restart = 1, end = 0;
    char *space;

    do{
        space = (char *)calloc(9, sizeof(char));
        if (space == NULL) {
            printf("Error allocating memory.\n");
            return 1;
        }

        system("cls");
        printf("Welcome to Tic-Tac-Toe!\n");
        for (i = 0; i < 9; i++) {
            if (i != 0){
                system("cls");
            }

            player = i % 2 + 1;
            printf("\n");
            board(space);
            printf("\nPlayer %d, enter number between 1-9: ", player);
            scanf("%d", &input);

            if (input < 1 || input > 9) {
                printf("\nInvalid input. Try again.\n\n");
                i--;
                system("pause");
                continue;
            }

            if (*(space + input - 1) == 'X' || *(space + input - 1) == 'O') {
                printf("\nInvalid input. Try again.\n\n");
                i--;
                system("pause");
                continue;
            }

            if (i % 2 == 0) {
                *(space + input - 1) = 'X';
            } else {
                *(space + input - 1) = 'O';
            }

            if (i >= 4) {
                win(&player, space, &end);
                if (end == 1) {
                    system("cls");
                    board(space);
                    break;
                }
            }
        }
        printf("\nRematch? (1 for yes, 0 for no): ");
        scanf("%d", &restart);
    } while(restart == 1);

    free(space);

    return 0;
}