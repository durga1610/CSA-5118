#include <stdio.h>
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int modinv(int a, int m) {
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1) return x;
    return -1;
}
int main() {
    int p = 7, q = 11, n = p * q, phi = (p - 1) * (q - 1);
    int d = 3;
    int e = modinv(d, phi);
    int msg = 5;
    int sign = 1;
    for (int i = 0; i < d; i++) sign = (sign * msg) % n;
    printf("Signature: %d\n", sign);
    return 0;
}
