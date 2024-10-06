#include <stdio.h>
#include <stdlib.h>

void factorize_number(unsigned long long n) {
    unsigned long long i;

    for (i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            printf("%llu=%llu*%llu\n", n, i, n / i);
            return;
        }
    }
    printf("%llu=1*%llu\n", n, n);  // Fallback for prime numbers
}

void factorize_file(const char *filename) {
    FILE *file;
    char line[1024];
    unsigned long long num;

    file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file)) {
        num = strtoull(line, NULL, 10);
        factorize_number(num);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    factorize_file(argv[1]);

    return EXIT_SUCCESS;
}
