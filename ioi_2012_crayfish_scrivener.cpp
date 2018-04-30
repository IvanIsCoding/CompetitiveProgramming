// Ivan Carvalho
// IOI Crayfish Scrivener - 2012
// O(n*(log(n)))
#include <bits/stdc++.h>
#define MAXN 1000010
#define MAXL 22
int ancestral[MAXN][MAXL],nivel[MAXN],ultima[MAXN],ptr,n,atualizacao;
char corresponde[MAXN];

// Gets the h-th letter of the state x by binary-lifting
char get_letter(int x,int h){
	for(int i = MAXL-1;i>=0;i--){
		int v = ancestral[x][i];
		if(nivel[v] >= h){
			x = v;
		} 
	}
	return corresponde[x];
}

// Starts the root information
void Init(){
    nivel[0] = -1;
	ultima[0] = 0;
}

// Creates a new state with an additional character L
void TypeLetter(char L){
    char davez;
	davez = L;
	ultima[++atualizacao] = ++ptr;
	nivel[ptr] = nivel[ultima[atualizacao-1]]+1;
	corresponde[ptr] = davez;
	ancestral[ptr][0] = ultima[atualizacao-1];
	for(int i=1;i<MAXL;i++){
		ancestral[ptr][i] = ancestral[ancestral[ptr][i-1]][i-1];
	}
}

// Creates a new state based on U
void UndoCommands(int U){
    int davez;
    davez = U;
	ultima[atualizacao+1] = ultima[atualizacao - davez];
	atualizacao++; 
}

// Retrieves the P-th letter
char GetLetter(int P){
    int davez;
    davez = P;
    return get_letter(ultima[atualizacao],davez);
}

int main(){
	return 0;
}
