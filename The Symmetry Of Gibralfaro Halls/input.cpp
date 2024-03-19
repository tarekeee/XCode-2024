#include <stdio.h>
#include <string.h>

int distance(const char *str1, const char *str2) {
    // Base case: if either string is empty, return the length of the other string
    if (str1[0] == '\0') {
        return strlen(str2);
    }
    if (str2[0] == '\0') {
        return strlen(str1);
    }

    // If the last characters are the same, no edit is needed for this position
    if (str1[0] == str2[0]) {
        return distance(str1 + 1, str2 + 1);
    }

    // Otherwise, consider three possible operations: insertion, deletion, and substitution
    int insertion = distance(str1, str2 + 1);
    int deletion = distance(str1 + 1, str2);
    int substitution = distance(str1 + 1, str2 + 1);

    // Return the minimum of the three operations plus 1
    return 1 + ((insertion < deletion) ? (insertion < substitution ? insertion : substitution)
                                       : (deletion < substitution ? deletion : substitution));
}

int main() {
    char string1[100], string2[100];

    scanf("%s", string1);

    scanf("%s", string2);

    int result = distance(string1, string2);
    printf("distance between '%s' and '%s': %d\n", string1, string2, result);

    return 0;
}