#include <stdio.h>
#include <stdlib.h>

/* Exemplo criado para este laboratório. */
int secret(int x) {
    return x * 7 + 3;
}

int main(int argc, char **argv) {
    int x = 5;
    if (argc > 1) {
        x = atoi(argv[1]);
    }
    printf("secret(%d) = %d\n", x, secret(x));
    return 0;
}
