#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <netinet/in.h>

uint32_t read_uint32(FILE *fp) {
    uint32_t num;
    if (fread(&num, sizeof(uint32_t), 1, fp) != 1) {
        fprintf(stderr, "Error: Failed to read 4 bytes from file.\n");
        exit(EXIT_FAILURE);
    }
    return ntohl(num);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file1> <file2>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fp1 = fopen(argv[1], "rb");
    if (fp1 == NULL) {
        fprintf(stderr, "Error: Cannot open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    FILE *fp2 = fopen(argv[2], "rb");
    if (fp2 == NULL) {
        fprintf(stderr, "Error: Cannot open file %s\n", argv[2]);
        fclose(fp1);
        return EXIT_FAILURE;
    }

    uint32_t num1 = read_uint32(fp1);
    uint32_t num2 = read_uint32(fp2);

    uint32_t sum = num1 + num2;

    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", num1, num1, num2, num2, sum, sum);

    fclose(fp1);
    fclose(fp2);

    return EXIT_SUCCESS;
}

