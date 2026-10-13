#include <stddef.h>
#include <stdio.h>

/* Programa original deste laboratório: não processa ficheiros nem rede. */
unsigned int weighted_sum(const unsigned char *values, size_t count) {
    unsigned int total = 0;
    for (size_t i = 0; i < count; ++i) {
        total += (unsigned int)values[i] * (unsigned int)(i + 1);
    }
    return total;
}

int main(void) {
    const unsigned char values[] = {1, 2, 3, 4};
    printf("weighted_sum = %u\n", weighted_sum(values, sizeof values));
    return 0;
}
