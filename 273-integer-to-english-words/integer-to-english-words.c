#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* below_20[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
char* tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
char* thousands[] = {"", "Thousand", "Million", "Billion"};

void helper(int num, char* result, size_t result_size) {
    if (num == 0) {
        return;
    } else if (num < 20) {
        strncat(result, below_20[num], result_size - strlen(result) - 1);
        strncat(result, " ", result_size - strlen(result) - 1);
    } else if (num < 100) {
        strncat(result, tens[num / 10], result_size - strlen(result) - 1);
        strncat(result, " ", result_size - strlen(result) - 1);
        helper(num % 10, result, result_size);
    } else {
        strncat(result, below_20[num / 100], result_size - strlen(result) - 1);
        strncat(result, " Hundred ", result_size - strlen(result) - 1);
        helper(num % 100, result, result_size);
    }
}

char* numberToWords(int num) {
    if (num == 0) {
        char* zero = (char*)malloc(5 * sizeof(char));
        strcpy(zero, "Zero");
        return zero;
    }

    size_t result_size = 1000;
    char* result = (char*)malloc(result_size * sizeof(char));
    result[0] = '\0';

    int i = 0;
    while (num > 0) {
        if (num % 1000 != 0) {
            char part[100] = "";
            helper(num % 1000, part, sizeof(part));
            strncat(part, thousands[i], sizeof(part) - strlen(part) - 1);
            strncat(part, " ", sizeof(part) - strlen(part) - 1);

            char temp[result_size];
            strcpy(temp, part);
            strncat(temp, result, result_size - strlen(temp) - 1);
            strcpy(result, temp);
        }
        num /= 1000;
        i++;
    }

    // Remove any extra spaces at the end
    size_t len = strlen(result);
    while (len > 0 && result[len - 1] == ' ') {
        result[len - 1] = '\0';
        len--;
    }

    return result;
}
