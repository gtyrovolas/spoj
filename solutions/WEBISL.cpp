#include <stdio.h>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

typedef long long ll;

vector< vector< ll > > G, R, comp;
ll n, m;
bool visited[1000100];
stack<ll> stac;
ll sol[1000100];

void dfs1(ll st){
	if(visited[st]) return;
	visited[st] = 1;
	vector<ll>::iterator it = R[st].begin();
	for(; it != R[st].end(); it++){
		dfs1(*it);
	}
	stac.push(st);
}
void dfs2(ll st, ll id){
	if(visited[st]) return;
	visited[st] = 1;
	comp[id].push_back(st);
	vector<ll>::iterator it = G[st].begin();
	for(; it != G[st].end(); it++){
		dfs2(*it, id);
	}
}

int main(){
	scanf("%lld %lld", &n, &m);
	G.resize(n + 1);
	R.resize(n + 1);
	for(ll i = 0; i < m; i++){
		ll a, b;
		scanf("%lld %lld", &a, &b);
		G[a].push_back(b);
		R[b].push_back(a);
	}
	for(ll i = 1; i <= n; i++){
		dfs1(i);
	}
	fill(visited, visited + n + 1, 0);
	while(!stac.empty()){
		ll i = stac.top();
		stac.pop();
		if(!visited[i]){
			comp.resize(comp.size() + 1);
			dfs2(i, comp.size() - 1);
		}
	}
	for(ll i = 0; i < comp.size(); i++){
		ll mn = (1ll << 50);
		for(ll j = 0; j < comp[i].size(); j++){
			mn = min(comp[i][j], mn);
		}
		for(ll j = 0; j < comp[i].size(); j++){
			sol[comp[i][j]] = mn;
		}
	}
	for(ll i = 0; i < n; i++){
		printf("%lld\n", sol[i]);
	}
	
}
