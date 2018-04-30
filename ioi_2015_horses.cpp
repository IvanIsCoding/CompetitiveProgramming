// Ivan Carvalho
// IOI Horses - 2015
// O(n*(log(n)))
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll MAXN = 5*1e5 + 10;

// Start of Segment Tree Node 
struct node{
	
	double maximum,total;
	ll max_product,tot_product;
	
	// Join operator
	node operator*(const node& other)const{
		node novo;
		novo.total = total + other.total;
		novo.tot_product = (tot_product * other.tot_product) % MOD;
		if(other.maximum + total >= maximum){
			novo.maximum = total + other.maximum;
			novo.max_product = (tot_product * other.max_product) % MOD;
		}
		else{
			novo.maximum = maximum;
			novo.max_product = max_product;
		}
		return novo;
	}

};
// End of Segment Tree Node

node seg[4*MAXN];
ll X[MAXN],Y[MAXN],N,M;

// Start of Segment Tree
// Segment Tree Build Function - Given an 1-indexed array of nodes, builds it SegTree in linear time
void build(int pos,int left,int right){
	if(left == right){
		seg[pos].max_product = (Y[left] * X[left]) % MOD;
		seg[pos].tot_product = X[left];
		seg[pos].maximum = log(Y[left]) + log(X[left]);
		seg[pos].total = log(X[left]);
		return;
	}
	int mid = (left+right)/2;
	build(2*pos,left,mid);
	build(2*pos+1,mid+1,right);
	seg[pos] = seg[2*pos]*seg[2*pos+1];
}

// Segment Tree Update - Updates a position x in logarithmic time
void update(int pos,int left,int right,int x){
	if(left == right){
		seg[pos].max_product = (Y[left] * X[left]) % MOD;
		seg[pos].tot_product = X[left];
		seg[pos].maximum = log(Y[left]) + log(X[left]);
		seg[pos].total = log(X[left]);
		return;
	}
	int mid = (left+right)/2;
	if(x <= mid) update(2*pos,left,mid,x);
	else update(2*pos+1,mid+1,right,x);
	seg[pos] = seg[2*pos]*seg[2*pos+1];
}

// End of Segment Tree

int init(int n,int x[], int y[]){
	N = n;
	for(int i = 0;i<n;i++){
		X[i] = x[i];
		Y[i] = y[i];
	}
	build(1,0,N-1);
	return (int)seg[1].max_product;
}
int updateX(int pos,int val){
	X[pos] = (ll)val;
	update(1,0,N-1,pos);
	return (int)seg[1].max_product;
}
int updateY(int pos,int val){
	Y[pos] = (ll)val;
	update(1,0,N-1,pos);
	return (int)seg[1].max_product;
}
int main(){
	return 0;
}
