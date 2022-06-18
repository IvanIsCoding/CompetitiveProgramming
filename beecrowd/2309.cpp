// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2309
#include <cstdio>
int main() {
    int val[100];
    val[4] = 1;
    val[5] = 2;
    val[6] = 3;
    val[7] = 4;
    val[12] = 5;
    val[11] = 6;
    val[13] = 7;
    val[1] = 8;
    val[2] = 9;
    val[3] = 10;
    int pt1 = 0, pt2 = 0, n;
    scanf("%d", &n);
    while (n--) {
        int spt1 = 0, spt2 = 0;
        int a1, a2, a3, b1, b2, b3;
        scanf("%d %d %d %d %d %d", &a1, &a2, &a3, &b1, &b2, &b3);
        spt1 += (val[a1] >= val[b1]);
        spt1 += (val[a2] >= val[b2]);
        spt1 += (val[a3] >= val[b3]);
        spt2 += (val[a1] < val[b1]);
        spt2 += (val[a2] < val[b2]);
        spt2 += (val[a3] < val[b3]);
        pt1 += (spt1 > spt2);
        pt2 += (spt2 > spt1);
    }
    printf("%d %d\n", pt1, pt2);
    return 0;
}
