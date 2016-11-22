#include "assignment2part5.h"

// Resources
// http://stackoverflow.com/questions/4022698/openssl-encryption-and-decryption-using-evp-library
// http://forums.fedoraforum.org/showthread.php?t=252878
// http://openssl.6102.n7.nabble.com/Openssl-encryption-help-td27912.html
// http://ideone.com/fork/OtLUQP

// Reverse engineer from variables we know
int encrypt(unsigned char *key, unsigned char *iv, unsigned char *ciphertext, unsigned char *plaintext, int plaintextLength) {
    int length;
    int ciphertextLength;

    EVP_CIPHER_CTX *ctx;
    ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv);
    EVP_EncryptUpdate(ctx, ciphertext, &length, plaintext, plaintextLength);
    ciphertextLength = length;

    EVP_EncryptFinal_ex(ctx, ciphertext + length, &length);
    ciphertextLength += length;

    EVP_CIPHER_CTX_free(ctx);
    return ciphertextLength;
}

void main() {
    unsigned char ciphertext[100];
    unsigned char *cipherHex="8d20e5056a8d24d0462ce74e4904c1b513e10d1df4a2ef2ad4540fae1ca0aaf9";
    unsigned char *plaintext = "This is a top secret.";

    int i;
    int ciphertextLength;
    char buffer[50];
    char iv[17];
    memset(iv, 0, 17);

    ERR_load_crypto_strings();
    OpenSSL_add_all_algorithms();
    OPENSSL_config(NULL);

    FILE* fp = fopen("words.txt", "r");
    while (fscanf(fp, "%s\n", buffer) != EOF) {
        int bufferLength = (int)strlen(buffer);
        if (bufferLength <= 16) {
            memset(buffer + strlen(buffer), ' ', 16 - bufferLength);
            buffer[16] = '\0';
        }

        ciphertextLength = encrypt(buffer, iv, ciphertext, plaintext, strlen(plaintext));

        unsigned char cryptoHex[50];
        for (i = 0; i < ciphertextLength; i++) {
            sprintf(cryptoHex + i * 2, "%02x", ciphertext[i]);
        }

        cryptoHex[ciphertextLength * 2] = '\0';
        if (strcmp(cryptoHex, cipherHex) == 0) {
            printf("Key: %s\n", buffer);
            break;
        }
    }

    EVP_cleanup();
    ERR_free_strings();
}
