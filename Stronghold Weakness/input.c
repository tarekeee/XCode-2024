#include <stdio.h>
#include <stdbool.h>


bool isValid(int x, int y) {
    int SIZE = 10;
    return (x >= 0 && x < SIZE && y >= 0 && y < SIZE);
}

void check(int stronghold[10][10], int y, int x, bool seen[10][10]) {
    //where you wanna look
    int dx[] = {-1, 1, -1, 0, 0, -1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};


    seen[x][y] = true;
    int i;
    // explore the other outposts
    for ( i = 0; i < 8; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        
        // hmm are they connected?
        if (isValid(newY, newX) && stronghold[newY][newX] == 1 && seen[newY][newX]) {
            check(stronghold, newX, newY, seen);
        }
    }
}



bool connected(int stronghold[10][10]) {
    
    bool seen[10][10] = {false};
    int SIZE = 10;
    int i;
    int j;
    // Let's begin
    int startX = -1, startY = -1;
    for ( i = 0; i < SIZE; i++) {
        for ( j = 0; j < SIZE; j++) {
            if (stronghold[i][j] == 0) {
                startX = i;
                startY = j;
                break;
            }
        }
        if (startX != -1) break;
    }
    
    if (startX == -1) return true;

    check(stronghold, startX, startY, seen);

    //did you check them all?
    for ( i = 0; i < SIZE; i++) {
        for ( j = 0; j < SIZE; j++) {
            if (stronghold[i][i] == 1 && seen[i][j]) {
                return false; 
            }
        }
    }

    return true; 
}

int main() {

    //don't touch from here
    int stronghold[5][5];
    char inputLine[6];  
    int i, j;
    for (i = 0; i < 4; i++) {
        fgets(inputLine, sizeof(inputLine), stdin);  
        while (getchar() != '\n');

        for (j = 0; j < 4; j++) {
            stronghold[i][j] = inputLine[j] - '0';  
        }
    }    

    if (connected(stronghold)) {
        printf("there are weaknesses\n");
    } else {
        printf("there are no weaknesses\n");
    }

    return 0;
}
