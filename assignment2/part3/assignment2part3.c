#include <stdio.h>
#include <openssl/evp.h>
#include <time.h>
#include "assignment2part3.h"

// http://stackoverflow.com/questions/15767691/whats-the-c-library-function-to-generate-random-string
void rand_str(char *dest, size_t length) {
    char charset[] = "0123456789"
                     "abcdefghijklmnopqrstuvwxyz"
                     "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    while (length-- > 0) {
        size_t index = (double) rand() / RAND_MAX * (sizeof charset - 1);
        *dest++ = charset[index];
    }
    *dest = '\0';
}

void weakCollisionResistance(int argc, char *argv[]) {
    EVP_MD_CTX *mdctx;
    const EVP_MD *md;
    unsigned char md_value[EVP_MAX_MD_SIZE];
    unsigned char first_md_value[EVP_MAX_MD_SIZE];
    int md_len, i;

    // Initialize random number generator
    time_t t;
    srand((unsigned) time(&t));

    // Boilerplate EVP setup
    OpenSSL_add_all_algorithms();
    if (!argv[1]) {
        printf("Usage: mdtest digestname\n");
        exit(1);
    }

    md = EVP_get_digestbyname(argv[1]);

    if (!md) {
        printf("Unknown message digest %s\n", argv[1]);
        exit(1);
    }

    printf("WEAK COLLISION RESISTANCE\n");

    // Generate random string
    unsigned char randomString[25];
    rand_str(randomString, 25);

    // Create first md value (known)
    mdctx = EVP_MD_CTX_create();
    EVP_DigestInit_ex(mdctx, md, NULL);
    EVP_DigestUpdate(mdctx, randomString, strlen(randomString));
    EVP_DigestFinal_ex(mdctx, first_md_value, &md_len);
    EVP_MD_CTX_destroy(mdctx);

    // Iterate until collision is found
    int counter = 0;
    while (1) {
        // Iteratively generate random strings and digests
        rand_str(randomString, 25);
        mdctx = EVP_MD_CTX_create();
        EVP_DigestInit_ex(mdctx, md, NULL);
        EVP_DigestUpdate(mdctx, randomString, strlen(randomString));
        EVP_DigestFinal_ex(mdctx, md_value, &md_len);
        EVP_MD_CTX_destroy(mdctx);

        // Compare the first 3 bytes (24 bits)
        if (memcmp(md_value, first_md_value, 3) == 0) {
            printf("Collision found! Number of attempts: %i\n", counter);
            break;
        } else {
            counter++;
        }
    }
}

void strongCollisionResistance(int argc, char *argv[]) {
    EVP_MD_CTX *mdctx;
    const EVP_MD *md;
    unsigned char md_value[EVP_MAX_MD_SIZE];
    unsigned char first_md_value[EVP_MAX_MD_SIZE];
    int md_len, i;

    // Initialize random number generator
    time_t t;
    srand((unsigned) time(&t));

    // Boilerplate EVP setup
    OpenSSL_add_all_algorithms();
    if (!argv[1]) {
        printf("Usage: mdtest digestname\n");
        exit(1);
    }

    md = EVP_get_digestbyname(argv[1]);

    if (!md) {
        printf("Unknown message digest %s\n", argv[1]);
        exit(1);
    }

    printf("STRONG COLLISION RESISTANCE\n");

    // Generate random string
    unsigned char randomString[25];

    // Iterate until collision is found
    int counter = 0;
    while (1) {
        // Iteratively generate random strings and digests
        rand_str(randomString, 25);
        mdctx = EVP_MD_CTX_create();
        EVP_DigestInit_ex(mdctx, md, NULL);
        EVP_DigestUpdate(mdctx, randomString, strlen(randomString));
        EVP_DigestFinal_ex(mdctx, first_md_value, &md_len);
        EVP_MD_CTX_destroy(mdctx);

        rand_str(randomString, 25);
        mdctx = EVP_MD_CTX_create();
        EVP_DigestInit_ex(mdctx, md, NULL);
        EVP_DigestUpdate(mdctx, randomString, strlen(randomString));
        EVP_DigestFinal_ex(mdctx, md_value, &md_len);
        EVP_MD_CTX_destroy(mdctx);

        // Compare the first 3 bytes (24 bits)
        if (memcmp(md_value, first_md_value, 3) == 0) {
            printf("Collision found! Number of attempts: %i\n", counter);
            break;
        } else {
            counter++;
        }
    }
}

int main(int argc, char *argv[]) {
    int i;
    for (i = 0; i < 100; i++) {
        weakCollisionResistance(argc, argv);
        strongCollisionResistance(argc, argv);
    }

    exit(0);
}
