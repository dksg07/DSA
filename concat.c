#include <stdio.h>

void concatenate(char *str1, char *str2, char *result) {
    int i = 0, j = 0;

    // Copy first string to result
    while (str1[i] != '\0') {
        result[i] = str1[i];
        i++;
    }

    // Append second string to result
    while (str2[j] != '\0') {
        result[i] = str2[j];
        i++;
        j++;
    }

    // Null-terminate the result
    result[i] = '\0';
}

int main() {
    char str1[100], str2[100], result[200];

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    concatenate(str1, str2, result);

    printf("Concatenated string: %s\n", result);

    return 0;
}