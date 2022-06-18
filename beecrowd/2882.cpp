// Ivan Carvalho
// Solution to
https :  // www.beecrowd.com.br/judge/problems/view/2882
#include <bits/stdc++.h>
         using namespace std;

const int MAXN = 2010;
const int MAXM = 30010;
const int INF = 1e5;

struct edge {
    int to, rev, time;  // node, index in the other adjacency list
    int cap, original;  // residual capacity
};

vector<edge> adjList[MAXN];  // adjacency list of the edges
int Ev[MAXM], Ei[MAXM];      // BFS edge list
int N, P, R, C, bfsPtr;      // number of nodes
int dist[MAXN], ok[MAXN];
int needs[MAXN], canHost[MAXN], sumNeeds;

int h[MAXN];  // heuristic of Tidal Flow
int p[MAXM];  // promised flow of Tidal Flow
int l[MAXN];  // amount of flow in pool of Tidal FLow

int TidalFlow(int edgeListSize) {
    int source = 0, sink = N;

    for (int i = 0; i <= N; i++) h[i] = 0;  // initializing h[v], for aint
    v h[source] = INF;  // there is no bound in the flow that can reach
    the source

        for (int i = 0; i < edgeListSize; i++) {
        int w = Ev[i];                          // where it comes from
        int idx = Ei[i];                        // index in the adjList
        int v = adjList[w][idx].to;             // where it goes
        p[i] = min(adjList[w][idx].cap, h[w]);  // the promised is
        the minimum of the heuristic and the capacity h[v] +=
            p[i];  // we add the promised capacity to the
        heuristic
    }

    if (h[sink] == 0) return 0;  // if the heuristic for the sink is
    0, then we are done

       for (int i = 0; i <= N; i++) l[i] = 0;  // initializing l[v], for aint
    v l[sink] = h[sink];  // the amount of flow is the heuristic in the
    sink, initiainty

        for (int i = edgeListSize - 1; i >= 0; i--) {
        int w = Ev[i];               // where it comes from
        int idx = Ei[i];             // index in the adjList
        int v = adjList[w][idx].to;  // where it goes
        // the promised is the minimum of the promised before,
        the diference between heuristic and available of the start or
            the available of the end p[i] = min(p[i], min(h[w] - l[w], l[v]));
        l[v] -= p[i];
        l[w] += p[i];
    }

    for (int i = 0; i <= N; i++) h[i] = 0;  // h[v] = 0, for aint v
    h[source] = l[source];  // the amount of pool is the heuristic
    for (int i = 0; i < edgeListSize; i++) {
        int w = Ev[i];                      // where it comes from
        int idx = Ei[i];                    // index in the adjList
        int v = adjList[w][idx].to;         // where it goes
        int rev_idx = adjList[w][idx].rev;  // index in the other
        adjList p[i] = min(p[i], h[w]);
        h[w] -= p[i];
        h[v] += p[i];
        adjList[w][idx].cap -= p[i];               // we update the residual
        capacity adjList[v][rev_idx].cap += p[i];  // update reverse edje
        capacity
    }

    return h[sink];
}

int BFS() {
    bfsPtr = 0;
    for (int i = 0; i <= N; i++) {
        ok[i] = 0;
    }

    int source = 0, sink = N;

    queue<int> bfs;
    bfs.push(source);
    ok[source] = 1;
    dist[source] = 0;

    while (!bfs.empty()) {
        int v = bfs.front();
        bfs.pop();

        for (int i = 0; i < adjList[v].size(); i++) {
            if (adjList[v][i].cap == 0) continue;
            int u = adjList[v][i].to;
            if (ok[u]) {
                if (dist[u] == dist[v] + 1) {
                    Ev[bfsPtr] = v;
                    Ei[bfsPtr] = i;
                    bfsPtr++;
                }
                continue;
            }
            ok[u] = 1;
            dist[u] = dist[v] + 1;
            bfs.push(u);
            Ev[bfsPtr] = v;
            Ei[bfsPtr] = i;
            bfsPtr++;
        }
    }

    return bfsPtr;
}

int FordFulkerson() {
    int flow = 0;

    while (true) {
        int augmenting = TidalFlow(BFS());
        if (augmenting == 0)
            break;
        else
            flow += augmenting;
    }

    return flow;
}

void addEdge(int u, int v, int cap, int time) {
    edge newedge;
    int uPtr = (int)adjList[u].size();
    int vPtr = (int)adjList[v].size();

    newedge.to = v;
    newedge.rev = vPtr;
    newedge.cap = cap;
    newedge.original = cap;
    newedge.time = time;
    adjList[u].push_back(newedge);

    newedge.to = u;
    newedge.rev = uPtr;
    newedge.cap = 0;
    newedge.original = 0;
    newedge.time = time;
    adjList[v].push_back(newedge);
}

int bs(int X) {
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j < adjList[i].size(); j++) {
            if (adjList[i][j].time <= X) {
                adjList[i][j].cap = adjList[i][j].original;
            } else {
                adjList[i][j].cap = 0;
            }
        }
    }

    return FordFulkerson() >= sumNeeds;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> P >> R >> C;

    // Read needs , creates edges to source
    for (int i = 1; i <= P; i++) {
        int a = 0;
        int b = i;
        cin >> needs[i];
        addEdge(a, b, needs[i], 0);
        sumNeeds += needs[i];
    }

    N = P + R + 1;

    // Read canHost , creates edges to sink
    for (int i = 1; i <= R; i++) {
        int a = i + P;
        int b = N;
        cin >> canHost[i];
        addEdge(a, b, canHost[i], 0);
    }

    vector<int> ordenado;

    // Read and create normal edges
    for (int i = 1; i <= C; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        addEdge(a, b + P, INF, t);
        ordenado.push_back(t);
    }

    sort(ordenado.begin(), ordenado.end());

    ordenado.erase(unique(ordenado.begin(), ordenado.end()), ordenado.end());
    C = ordenado.size();

    int ini = 0, fim = C - 1, meio, resp = -1;
    while (ini <= fim) {
        meio = ini + (fim - ini) / 2;
        if (bs(ordenado[meio])) {
            resp = ordenado[meio];
            fim = meio - 1;
        } else {
            ini = meio + 1;
        }
    }

    cout << resp << endl;

    return 0;
}
