// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2368
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
typedef long long ll;
struct range {
    ll ini, fim;
    ll A, B;
    range(ll _A, ll _B, ll add = 0) {
        A = _A;
        B = _B;
        ini = add + 1;
        fim = ini + abs(A - B);
    }
};
vector<range> left, mid, right, S;
ll N, M;
void inverte(ll a, ll b) {
    for (ll i = 0; i < S.size(); i++) {
        if (S[i].fim < a) {
            left.push_back(S[i]);
        } else if (S[i].ini > b) {
            right.push_back(S[i]);
        } else {
            if (S[i].A <= S[i].B) {
                ll avanca = max(a - S[i].ini, 0LL);
                ll recua = max(S[i].fim - b, 0LL);
                range temp1(S[i].A, S[i].A + avanca - 1);
                range temp2(S[i].A + avanca, S[i].B - recua);
                range temp3(S[i].B - recua + 1, S[i].B);
                if (S[i].A <= S[i].A + avanca - 1) left.push_back(temp1);
                if (S[i].A + avanca <= S[i].B - recua) mid.push_back(temp2);
                if (S[i].B - recua + 1 <= S[i].B) right.push_back(temp3);
            } else {
                ll avanca = max(a - S[i].ini, 0LL);
                ll recua = max(S[i].fim - b, 0LL);
                range temp1(S[i].A, S[i].A - avanca + 1);
                range temp2(S[i].A - avanca, S[i].B + recua);
                range temp3(S[i].B + recua - 1, S[i].B);
                if (S[i].A >= S[i].A - avanca + 1) left.push_back(temp1);
                if (S[i].A - avanca >= S[i].B + recua) mid.push_back(temp2);
                if (S[i].B + recua - 1 >= S[i].B) right.push_back(temp3);
            }
        }
    }
    for (ll i = 0; i < mid.size(); i++) {
        swap(mid[i].A, mid[i].B);
    }
    reverse(mid.begin(), mid.end());
    S.clear();
    for (ll i = 0; i < left.size(); i++) {
        S.push_back(left[i]);
    }
    for (ll i = 0; i < mid.size(); i++) {
        S.push_back(mid[i]);
    }
    for (ll i = 0; i < right.size(); i++) {
        S.push_back(right[i]);
    }
    S[0].ini = 1;
    S[0].fim = S[0].ini + abs(S[0].B - S[0].A);
    for (ll i = 1; i < S.size(); i++) {
        S[i].ini = S[i - 1].fim + 1;
        S[i].fim = S[i].ini + abs(S[i].B - S[i].A);
    }
    left.clear();
    mid.clear();
    right.clear();
}
ll soma(ll a, ll b) {
    ll resp = 0;
    for (ll i = 0; i < S.size(); i++) {
        if (S[i].fim < a) {
            continue;
        } else if (S[i].ini > b) {
            continue;
        } else {
            if (S[i].A <= S[i].B) {
                ll avanca = max(a - S[i].ini, 0LL);
                ll recua = max(S[i].fim - b, 0LL);
                ll Ax = S[i].A + avanca;
                ll Ay = S[i].B - recua;
                resp += ((Ax + Ay) * (Ay - Ax + 1)) / 2LL;
            } else {
                ll avanca = max(a - S[i].ini, 0LL);
                ll recua = max(S[i].fim - b, 0LL);
                ll Ax = S[i].A - avanca;
                ll Ay = S[i].B + recua;
                resp += ((Ax + Ay) * (Ax - Ay + 1)) / 2LL;
            }
        }
    }
    return resp;
}
int main() {
    scanf("%lld %lld", &N, &M);
    range temp(1LL, N);
    temp.ini = 1LL;
    temp.fim = N;
    S.push_back(temp);
    while (M--) {
        char op;
        scanf(" %c", &op);
        if (op == 'I') {
            ll a, b;
            scanf("%lld %lld", &a, &b);
            inverte(a, b);
            // for(ll i=0;i<S.size();i++){
            //	printf("INI %lld FIM %lld A %lld B
            //%lld\n",S[i].ini,S[i].fim,S[i].A,S[i].B);
            // }
        } else if (op == 'S') {
            ll a, b;
            scanf("%lld %lld", &a, &b);
            printf("%lld\n", soma(a, b));
        }
    }
    return 0;
}
