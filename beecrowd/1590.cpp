// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1590
#include <algorithm>
#include <cstdio>
#define MAXN 36
using namespace std;
int vetor[MAXN], n, m, TC;
bool comp(int a, int b) { return a > b; }
int brute1() {
    int resp = 0;
    for (int i = 1; i <= n; i++) {
        resp = max(resp, vetor[i]);
    }
    return resp;
}
int brute2() {
    int resp = 0;
    for (int i = 1; i <= n; i++) {
        if (vetor[i] <= resp) continue;
        for (int j = i + 1; j <= n; j++) {
            resp = max(resp, (vetor[i] & vetor[j]));
        }
    }
    return resp;
}
int brute3() {
    int resp = 0;
    for (int i = 1; i <= n; i++) {
        if (vetor[i] <= resp) continue;
        for (int j = i + 1; j <= n; j++) {
            if ((vetor[i] & vetor[j]) <= resp) continue;
            for (int k = j + 1; k <= n; k++) {
                resp = max(resp, (vetor[i] & vetor[j] & vetor[k]));
            }
        }
    }
    return resp;
}
int brute4() {
    int resp = 0;
    for (int i = 1; i <= n; i++) {
        if (vetor[i] <= resp) continue;
        for (int j = i + 1; j <= n; j++) {
            if ((vetor[i] & vetor[j]) <= resp) continue;
            for (int k = j + 1; k <= n; k++) {
                if ((vetor[i] & vetor[j] & vetor[k]) <= resp) continue;
                for (int r = k + 1; r <= n; r++) {
                    resp =
                        max(resp, (vetor[i] & vetor[j] & vetor[k] & vetor[r]));
                }
            }
        }
    }
    return resp;
}
int brute5() {
    int resp = 0;
    for (int i = 1; i <= n; i++) {
        if (vetor[i] <= resp) continue;
        for (int j = i + 1; j <= n; j++) {
            if ((vetor[i] & vetor[j]) <= resp) continue;
            for (int k = j + 1; k <= n; k++) {
                if ((vetor[i] & vetor[j] & vetor[k]) <= resp) continue;
                for (int r = k + 1; r <= n; r++) {
                    if ((vetor[i] & vetor[j] & vetor[k] & vetor[r]) <= resp)
                        continue;
                    for (int l = r + 1; l <= n; l++) {
                        resp = max(resp, (vetor[i] & vetor[j] & vetor[k] &
                                          vetor[r] & vetor[l]));
                    }
                }
            }
        }
    }
    return resp;
}
int brute6() {
    int resp = 0;
    for (int i = 1; i <= n; i++) {
        if (vetor[i] <= resp) continue;
        for (int j = i + 1; j <= n; j++) {
            if ((vetor[i] & vetor[j]) <= resp) continue;
            for (int k = j + 1; k <= n; k++) {
                if ((vetor[i] & vetor[j] & vetor[k]) <= resp) continue;
                for (int r = k + 1; r <= n; r++) {
                    if ((vetor[i] & vetor[j] & vetor[k] & vetor[r]) <= resp)
                        continue;
                    for (int l = r + 1; l <= n; l++) {
                        if ((vetor[i] & vetor[j] & vetor[k] & vetor[r] &
                             vetor[l]) <= resp)
                            continue;
                        for (int p = l + 1; p <= n; p++) {
                            resp = max(resp, (vetor[i] & vetor[j] & vetor[k] &
                                              vetor[r] & vetor[l] & vetor[p]));
                        }
                    }
                }
            }
        }
    }
    return resp;
}
int brute7() {
    int resp = 0;
    for (int i = 1; i <= n; i++) {
        if (vetor[i] <= resp) continue;
        for (int j = i + 1; j <= n; j++) {
            if ((vetor[i] & vetor[j]) <= resp) continue;
            for (int k = j + 1; k <= n; k++) {
                if ((vetor[i] & vetor[j] & vetor[k]) <= resp) continue;
                for (int r = k + 1; r <= n; r++) {
                    if ((vetor[i] & vetor[j] & vetor[k] & vetor[r]) <= resp)
                        continue;
                    for (int l = r + 1; l <= n; l++) {
                        if ((vetor[i] & vetor[j] & vetor[k] & vetor[r] &
                             vetor[l]) <= resp)
                            continue;
                        for (int p = l + 1; p <= n; p++) {
                            if ((vetor[i] & vetor[j] & vetor[k] & vetor[r] &
                                 vetor[l] & vetor[p]) <= resp)
                                continue;
                            for (int q = p + 1; q <= n; q++) {
                                resp =
                                    max(resp, (vetor[i] & vetor[j] & vetor[k] &
                                               vetor[r] & vetor[l] & vetor[p] &
                                               vetor[q]));
                            }
                        }
                    }
                }
            }
        }
    }
    return resp;
}
int main() {
    scanf("%d", &TC);
    while (TC--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &vetor[i]);
        }
        sort(vetor + 1, vetor + n + 1);
        if (m == 1)
            printf("%d\n", brute1());
        else if (m == 2)
            printf("%d\n", brute2());
        else if (m == 3)
            printf("%d\n", brute3());
        else if (m == 4)
            printf("%d\n", brute4());
        else if (m == 5)
            printf("%d\n", brute5());
        else if (m == 6)
            printf("%d\n", brute6());
        else
            printf("%d\n", brute7());
    }
    return 0;
}
