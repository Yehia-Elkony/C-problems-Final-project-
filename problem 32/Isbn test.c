#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isValidISBN(char isbn[]) {
    int i, len = strlen(isbn);
    int running_total = 0;
    int partial_sum = 0;
    for (i = 0; i < len; i++) {
        if (isbn[i] >= '0' && isbn[i] <= '9') {
            partial_sum += (isbn[i] - '0');
            running_total += partial_sum;
        } else if (isbn[i] == 'X' || isbn[i] == 'x') {
            if (i == len - 1) {
                partial_sum += 10;
                running_total += partial_sum;
            } else {
                return false; // 'X' can only appear as the last character
            }
        } else if (isbn[i] == '-') {
            // do nothing, ignore the hyphen
        } else {
            return false; // invalid character
        }
    }
    return running_total % 11 == 0;
}

int main() {
    char isbn[20];
    while (scanf("%s", isbn) != EOF) {
        if (isValidISBN(isbn)) {
            printf("%s is correct.\n", isbn);
        } else {
            printf("%s is incorrect.\n",isbn);
        }
    }
    return 0;
}