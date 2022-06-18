// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2476
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <map>
#include <set>
#include <string>
#include <vector>
#define MAXN 100010
#define gc getchar_unlocked
void getint(int &x) {
    register int c = gc();
    x = 0;
    for (; (c < 48 || c > 57); c = gc())
        ;
    for (; c > 47 && c < 58; c = gc()) {
        x = (x << 1) + (x << 3) + c - 48;
    }
}
using namespace std;
typedef struct mo_que {
    int left, right, idx, u, v, ancestor;
} que;
int mo_left, mo_right, resp, freq[MAXN], n, sqn, q, dfsNum, pai[MAXN],
    superpai[MAXN], nivel[MAXN], resposta[MAXN], vetor[2 * MAXN], cor[MAXN],
    cont, processado[MAXN], ini[MAXN], fim[MAXN], segmento, aparicoes[MAXN];
que Q[MAXN];
map<string, int> compressao;
char entrada[30];
vector<int> grafo[MAXN];
void dfs_pai(int x) {
    processado[x] = 1;
    ini[x] = ++dfsNum;
    for (int i = 0; i < grafo[x].size(); i++) {
        int v = grafo[x][i];
        if (!processado[v]) {
            pai[v] = x;
            nivel[v] = nivel[x] + 1;
            dfs_pai(v);
        }
    }
    fim[x] = ++dfsNum;
    vetor[ini[x]] = vetor[fim[x]] = x;
}
void dfs_superpai(int x, int p) {
    processado[x] = 1;
    superpai[x] = p;
    if (nivel[x] % segmento == 0) p = x;
    for (int i = 0; i < grafo[x].size(); i++) {
        int v = grafo[x][i];
        if (!processado[v]) {
            dfs_superpai(v, p);
        }
    }
}
int LCA(int u, int v) {
    while (superpai[u] != superpai[v]) {
        if (nivel[u] > nivel[v])
            u = superpai[u];
        else
            v = superpai[v];
    }
    while (u != v) {
        if (nivel[u] > nivel[v])
            u = pai[u];
        else
            v = pai[v];
    }
    return u;
}
inline void insere(int i) {
    if (freq[i] == 0) {
        resp++;
        freq[i]++;
    } else {
        freq[i]++;
    }
}
inline void tira(int i) {
    if (freq[i] == 1) {
        resp--;
        freq[i]--;
    } else {
        freq[i]--;
    }
}
inline void add(int i) {
    if (aparicoes[i] == 0)
        insere(cor[i]);
    else
        tira(cor[i]);
    aparicoes[i]++;
}
inline void remove(int i) {
    if (aparicoes[i] == 2)
        insere(cor[i]);
    else
        tira(cor[i]);
    aparicoes[i]--;
}
inline void query(int i) {
    for (int j = mo_right + 1; j <= Q[i].right; j++) add(vetor[j]);
    for (int j = mo_left - 1; j >= Q[i].left; j--) add(vetor[j]);
    for (int j = mo_right; j > Q[i].right; j--) remove(vetor[j]);
    for (int j = mo_left; j < Q[i].left; j++) remove(vetor[j]);
    mo_left = Q[i].left;
    mo_right = Q[i].right;
    resposta[Q[i].idx] = resp;
    if (Q[i].u != Q[i].ancestor && Q[i].v != Q[i].ancestor &&
        freq[cor[Q[i].ancestor]] == 0)
        resposta[Q[i].idx]++;
}
bool comp(que A, que B) {
    if (A.left / sqn < B.left / sqn) return 1;
    if (A.left / sqn > B.left / sqn) return 0;
    return A.right < B.right;
}
int main() {
    getint(n);
    getint(q);
    for (int i = 1; i <= n; i++) {
        scanf("%s", entrada);
        string s = entrada;
        if (!compressao.count(s)) {
            compressao[s] = ++cont;
        }
        cor[i] = compressao[s];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        getint(u);
        getint(v);
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!processado[i]) {
            nivel[i] = 0;
            pai[i] = i;
            dfs_pai(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        processado[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        segmento = max(nivel[i], segmento);
    }
    segmento = sqrt(segmento);
    for (int i = 1; i <= n; i++) {
        if (!processado[i]) {
            dfs_superpai(i, i);
        }
    }
    sqn = sqrt(dfsNum);
    for (int i = 1; i <= q; i++) {
        getint(Q[i].u);
        getint(Q[i].v);
        if (ini[Q[i].u] > ini[Q[i].v]) swap(Q[i].u, Q[i].v);
        Q[i].idx = i;
        Q[i].ancestor = LCA(Q[i].u, Q[i].v);
        if (Q[i].ancestor == Q[i].u || Q[i].ancestor == Q[i].v) {
            Q[i].left = ini[Q[i].u];
            Q[i].right = ini[Q[i].v];
        } else {
            Q[i].left = fim[Q[i].u];
            Q[i].right = ini[Q[i].v];
        }
    }
    // printf("Cores\n");
    // for(int i=1;i<=n;i++){
    //	printf("%d ",cor[i]);
    // }
    // printf("\n");
    // printf("Array\n");
    // for(int i=1;i<=dfsNum;i++){
    //	printf("%d ",vetor[i]);
    // }
    // printf("\n");
    sort(Q + 1, Q + q + 1, comp);
    // printf("Queries\n");
    // for(int i=1;i<=q;i++){
    //	printf("ID: %d U : %d V: %d P: %d L : %d R :
    //%d\n",Q[i].idx,Q[i].u,Q[i].v,Q[i].ancestor,Q[i].left,Q[i].right);
    // }
    mo_left = Q[1].left;
    mo_right = Q[1].right;
    for (int i = mo_left; i <= mo_right; i++) add(vetor[i]);
    resposta[Q[1].idx] = resp;
    if (Q[1].u != Q[1].ancestor && Q[1].v != Q[1].ancestor &&
        freq[cor[Q[1].ancestor]] == 0)
        resposta[Q[1].idx]++;
    for (int i = 2; i <= q; i++) query(i);
    for (int i = 1; i <= q; i++) printf("%d\n", resposta[i]);
    return 0;
}
