#include <stdio.h>
#include <string.h>

// Function to calculate Levenshtein distance using dynamic programming
int levenshtein_distance(const char *str1, const char *str2) {
    int len_str1 = strlen(str1) + 1;
    int len_str2 = strlen(str2) + 1;

    // Create a matrix to store the distances between substrings
    int matrix[len_str1][len_str2];

    // Initialize the matrix with values corresponding to the length of substrings
    for (int i = 0; i < len_str1; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j < len_str2; j++) {
        matrix[0][j] = j;
    }

    // Populate the matrix with minimum distances
    for (int i = 1; i < len_str1; i++) {
        for (int j = 1; j < len_str2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            matrix[i][j] = fmin(matrix[i - 1][j] + 1,        // Deletion
                                fmin(matrix[i][j - 1] + 1,    // Insertion
                                     matrix[i - 1][j - 1] + cost));  // Substitution
        }
    }

    return matrix[len_str1 - 1][len_str2 - 1];
}

int main() {
    char string1[100], string2[100];

    scanf("%s", string1);

    scanf("%s", string2);

    // Calculate Levenshtein distance and display the result
    int distance = levenshtein_distance(string1, string2);
    printf("distance between '%s' and '%s': %d\n", string1, string2, distance);

    return 0;
}
