// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2111
#include <cstdio>
char matriz[10][10];
void seta0(int pos) {
    matriz[0][pos] = '1';
    matriz[1][pos] = '0';
    matriz[2][pos] = '-';
    matriz[3][pos] = '0';
    matriz[4][pos] = '1';
    matriz[5][pos] = '1';
    matriz[6][pos] = '1';
    matriz[7][pos] = '1';
}
void seta1(int pos) {
    matriz[0][pos] = '1';
    matriz[1][pos] = '0';
    matriz[2][pos] = '-';
    matriz[3][pos] = '1';
    matriz[4][pos] = '0';
    matriz[5][pos] = '1';
    matriz[6][pos] = '1';
    matriz[7][pos] = '1';
}
void seta2(int pos) {
    matriz[0][pos] = '1';
    matriz[1][pos] = '0';
    matriz[2][pos] = '-';
    matriz[3][pos] = '1';
    matriz[4][pos] = '1';
    matriz[5][pos] = '0';
    matriz[6][pos] = '1';
    matriz[7][pos] = '1';
}
void seta3(int pos) {
    matriz[0][pos] = '1';
    matriz[1][pos] = '0';
    matriz[2][pos] = '-';
    matriz[3][pos] = '1';
    matriz[4][pos] = '1';
    matriz[5][pos] = '1';
    matriz[6][pos] = '0';
    matriz[7][pos] = '1';
}
void seta4(int pos) {
    matriz[0][pos] = '1';
    matriz[1][pos] = '0';
    matriz[2][pos] = '-';
    matriz[3][pos] = '1';
    matriz[4][pos] = '1';
    matriz[5][pos] = '1';
    matriz[6][pos] = '1';
    matriz[7][pos] = '0';
}
void seta5(int pos) {
    matriz[0][pos] = '0';
    matriz[1][pos] = '1';
    matriz[2][pos] = '-';
    matriz[3][pos] = '0';
    matriz[4][pos] = '1';
    matriz[5][pos] = '1';
    matriz[6][pos] = '1';
    matriz[7][pos] = '1';
}
void seta6(int pos) {
    matriz[0][pos] = '0';
    matriz[1][pos] = '1';
    matriz[2][pos] = '-';
    matriz[3][pos] = '1';
    matriz[4][pos] = '0';
    matriz[5][pos] = '1';
    matriz[6][pos] = '1';
    matriz[7][pos] = '1';
}
void seta7(int pos) {
    matriz[0][pos] = '0';
    matriz[1][pos] = '1';
    matriz[2][pos] = '-';
    matriz[3][pos] = '1';
    matriz[4][pos] = '1';
    matriz[5][pos] = '0';
    matriz[6][pos] = '1';
    matriz[7][pos] = '1';
}
void seta8(int pos) {
    matriz[0][pos] = '0';
    matriz[1][pos] = '1';
    matriz[2][pos] = '-';
    matriz[3][pos] = '1';
    matriz[4][pos] = '1';
    matriz[5][pos] = '1';
    matriz[6][pos] = '0';
    matriz[7][pos] = '1';
}
void seta9(int pos) {
    matriz[0][pos] = '0';
    matriz[1][pos] = '1';
    matriz[2][pos] = '-';
    matriz[3][pos] = '1';
    matriz[4][pos] = '1';
    matriz[5][pos] = '1';
    matriz[6][pos] = '1';
    matriz[7][pos] = '0';
}
int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int pos = 0; pos < 9; pos++) {
            int resto = n % 10;
            n /= 10;
            if (resto == 0) seta0(pos);
            if (resto == 1) seta1(pos);
            if (resto == 2) seta2(pos);
            if (resto == 3) seta3(pos);
            if (resto == 4) seta4(pos);
            if (resto == 5) seta5(pos);
            if (resto == 6) seta6(pos);
            if (resto == 7) seta7(pos);
            if (resto == 8) seta8(pos);
            if (resto == 9) seta9(pos);
        }
        for (int linha = 0; linha < 8; linha++) {
            for (int pos = 8; pos >= 0; pos--) {
                printf("%c", matriz[linha][pos]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
