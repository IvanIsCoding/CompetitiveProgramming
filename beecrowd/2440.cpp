// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2440
// Link do problema :
// http://olimpiada.ic.unicamp.br/pratique/programacao/nivel2/2013f2p2_troia No
// CodCad na seção grafos há uma explicação do problema Também pode ser útil :
// http://noic.com.br/informatica/curso-noic-de-informatica/aula-9-grafos-parte-ii-flood-fill/
#include <iostream>        // Entrada e saída
#include <queue>           //Literalmente uma fila
#include <vector>          // Armazenar o grafo em um vetor
using namespace std;       // C++
vector<int> grafo[50001];  // Armazena o grafo, 5*10^4 porque é o tamanho da
                           // entrada (nota : tem que ter 1 de sobra)
int ok[50001];       // Checa se o vértice já foi processado (está 'OK')
int N, M, resposta;  // Vértices e arestas respectivamente
int main() {
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {  // Loop para iterar as arestas
        int u, v;                   // Vertices U e V
        cin >> u >> v;
        grafo[u].push_back(v);  // Adiciono V aos vizinhos de U
        grafo[v].push_back(u);  // Adiciono U aos vizinhos de V
                                // O comando para adicionar é push_back
                                // O u entre [] indica que são os vizinhos de U.
                                // O v entre () indica que v é adicinado
    }
    for (int vertice = 1; vertice <= N; vertice++) {
        // Para cada vértice, vejo se ele já está  OK
        //  Nota : ! é negação
        //  Se não estiver, processo e conto a família dele
        if (!ok[vertice]) {
            resposta++;       // Uma família a mais
            queue<int> fila;  // Fila para percorrer o grafo
            // A fila possui três operações :
            // push (não push_back, cuidado)  : adiciona um vértice no final da
            // fila pop : tira um vértice do início da fila front : vê quem está
            // na frente da fila Uma condição adicional é checar se ela está
            // vazia , empty() A negação de empty indica que a fila não está
            // vazia
            fila.push(vertice);      // Adiciono inicialmente o vértice a fila
            while (!fila.empty()) {  // Enquanto a fila não estiver vazia
                int u = fila.front();  // Pegamos o vértice U da fila
                fila.pop();            // Tiramos ele da fila
                if (!ok[u]) {          // Se ele não estiver ok
                    ok[u] = 1;         // Ele fica ok
                    for (int i = 0; i < grafo[u].size();
                         i++) {  // Para todo i menor que o tamanho da
                                 // vizinhança de U
                        // Pego o elemento que está no índice i do vetor
                        // size é o tamnho do grafo[u]
                        int v = grafo[u][i];  // Vizinho v que está no indíce I
                                              // do vizinho de U
                        fila.push(v);  // Adiciono V a fila
                    }
                }
            }
        }
    }
    cout << resposta << endl;
    return 0;
}
