#include <stdio.h>
#include <stdbool.h>

// Function to check if two grid coordinates are within bounds
bool isValid(int x, int y) {
    return (x >= 0 && x < 5 && y >= 0 && y < 5);
}

// Depth-first search function to mark connected cells as visited
void DFS(int grid[5][5], int x, int y, bool visited[5][5]) {
    // Define the 8 possible moves: up, down, left, right, and diagonals
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    // Mark the current cell as visited
    visited[x][y] = true;
    int i;
    // Explore the adjacent cells
    for ( i = 0; i < 8; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        
        // Check if the adjacent cell is valid and contains a '1' and has not been visited
        if (isValid(newX, newY) && grid[newX][newY] == 1 && !visited[newX][newY]) {
            // Recursively call DFS for the adjacent cell
            DFS(grid, newX, newY, visited);
        }
    }
}


// Function to check if all '1's are connected in the grid
bool isConnected(int grid[5][5]) {
    
    bool visited[5][5] = {false};

    int i;
    int j;
    // Find the first '1' in the grid
    int startX = -1, startY = -1;
    for ( i = 0; i < 5; i++) {
        for ( j = 0; j < 5; j++) {
            if (grid[i][j] == 1) {
                startX = i;
                startY = j;
                break;
            }
        }
        if (startX != -1) break;
    }
    
    // If no '1' is found, return true (empty grid)
    if (startX == -1) return true;

    // Perform DFS starting from the first '1'
    DFS(grid, startX, startY, visited);

    // Check if all '1's are visited
    for ( i = 0; i < 5; i++) {
        for ( j = 0; j < 5; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                return false; // There's a '1' not connected to others
            }
        }
    }

    return true; // All '1's are connected
}

int main() {
    int grid[5][5];
    char inputLine[6];  // +1 for null terminator
    int i, j;
    for (i = 0; i < 5; i++) {
        //printf("Enter row %d (consisting of 0s and 1s): ", i + 1);
        fgets(inputLine, sizeof(inputLine), stdin);  // Read a line from the terminal
        
        // Clear the input buffer
        while (getchar() != '\n');

        // Convert characters to integers
        for (j = 0; j < 5; j++) {
            grid[i][j] = inputLine[j] - '0';  // Convert character to integer
        }
    }
    
    if (isConnected(grid)) {
        printf("there are no weaknesses\n");
    } else {
        printf("there are weaknesses\n");
    }

    return 0;
}

