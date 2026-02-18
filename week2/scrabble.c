#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>


int get_points(string str);

int main (void){
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");
    int points1 = get_points(player1);
    int points2 = get_points(player2);
    if (points1 > points2) {
        printf("Player 1 wins!\n");
    }
    else if (points2 > points1) {
        printf("Player 2 wins!\n");
    }
    else {
        printf("Tie!\n");
    }
}

int get_points(string str){
    int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int s = 0;
    for (int i = 0, n = strlen(str); i < n; i++){
        s += points[tolower(str[i])-'a'];
    }
    return s;
}
