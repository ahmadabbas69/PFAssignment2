#include <stdio.h>

// Function to calculate the Collatz sequence length
unsigned long long collatz_length(unsigned long long start) {
    unsigned long long length = 1; // Start counting with the initial number
    while (start != 1) {
        if (start % 2 == 0) {
            start /= 2;
        } else {
            start = 3 * start + 1;
        }
        length++;
    }
    return length;
}

void main() {
    unsigned long long limit, max_length = 0, max_start_number = 1;
    printf("Enter the upper limit N: ");
    scanf("%llu", &limit);

    for (unsigned long long i = 1; i <= limit; i++) {
        unsigned long long current_length = collatz_length(i);
        if (current_length > max_length) {
            max_length = current_length;
            max_start_number = i;
        }
    }

    printf("The number %llu produces the longest Collatz sequence under %llu, with a length of %llu.\n",
           max_start_number, limit, max_length);

    
}
