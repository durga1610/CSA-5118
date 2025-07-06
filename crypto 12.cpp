#include <stdio.h>
#include <string.h>
#include <math.h>
#include <openssl/md5.h>

// ----------- RSA UTILITIES -------------

int gcd(int a, int b) {
    if(b==0) return a;
    return gcd(b, a%b);
}

int modInverse(int e, int phi) {
    for (int d = 1; d < phi; d++)
        if ((e * d) % phi == 1)
            return d;
    return -1;
}

long long modExp(long long base, int exp, int mod) {
    long long result = 1;
    for(int i = 0; i < exp; i++)
        result = (result * base) % mod;
    return result;
}

// ------------ MAIN FUNCTION ------------

int main() {
    // ----------- MD5 HASHING ------------
    char input[] = "hello";  // original plaintext
    unsigned char md5_digest[MD5_DIGEST_LENGTH];

    MD5((unsigned char*)input, strlen(input), md5_digest);

    printf("Original Message: %s\n", input);
    printf("MD5 Hash: ");
    for(int i = 0; i < MD5_DIGEST_LENGTH; i++)
        printf("%02x", md5_digest[i]);
    printf("\n");

    // ----------- RSA ENCRYPTION ----------
    int p = 3, q = 11;
    int n = p * q;           // n = 33
    int phi = (p - 1) * (q - 1); // phi = 20
    int e = 7;               // public exponent
    int d = modInverse(e, phi); // private exponent

    int plaintext = input[0]; // Taking first character only (for simplicity)
    long long encrypted = modExp(plaintext, e, n);
    long long decrypted = modExp(encrypted, d, n);

    printf("\n--- RSA Process ---\n");
    printf("Public Key: (%d, %d)\n", e, n);
    printf("Private Key: (%d, %d)\n", d, n);
    printf("Plaintext Character: '%c' -> %d\n", plaintext, plaintext);
    printf("Encrypted: %lld\n", encrypted);
    printf("Decrypted: %lld -> '%c'\n", decrypted, (char)decrypted);

    return 0;
}
