#include <stdio.h>
#include <vector>
#include <stack>
#include <iostream>
#include <set>

using namespace std;

typedef long long ll;

vector< vector< ll > > G, R, comp;
vector< set <ll > > adComp;

ll n, m;
bool visited[1000100];
stack<ll> stac;
ll sol[1000100];
ll num[1000100] = {};

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
	if(visited[st]){
		adComp[id].insert(num[st]);
		return;
	}
	visited[st] = 1;
	num[st] = id;
	comp[id].push_back(st);
	vector<ll>::iterator it = G[st].begin();
	for(; it != G[st].end(); it++){
		dfs2(*it, id);
	}
}

ll dfs3(ll st){
	if(visited[st]) return 0;
	visited[st] = 1;
	ll sol = comp[st].size();
	//cout << "Component " << st << " ";
	//for(ll i = 0; i < comp[st].size(); i++) cout << comp[st][i] << " ";
	//cout << endl;
	set<ll>::iterator it = adComp[st].begin();
	for(; it != adComp[st].end(); it++){
		if(*it != st)
		sol += dfs3(*it);
	}
	//cout << "solution for compononent " << st << " : " << sol << endl;
	return sol;
}
ll t;

int main(){
	scanf("%lld",&t);
		for(ll k = 0; k < t; k++){
		scanf("%lld", &n);
		G.clear();
		R.clear();
		comp.clear();
		adComp.clear();
		G.resize(n + 1);
		R.resize(n + 1);
		fill(visited, visited + n + 10, 0);
		fill(num, num + n + 10, 0);
		for(ll i = 1; i <= n; i++){
		//	cout << i << endl;
			ll a, b;
			scanf("%lld",&m);
			for(ll j = 0; j < m; j++){
				scanf("%lld", &a);
				R[i].push_back(a);
				G[a].push_back(i);
			}
		}
		for(ll i = 1; i <= n; i++){
			dfs1(i);
		}
		fill(visited, visited + n + 10, 0);
		while(!stac.empty()){
			ll i = stac.top();
			stac.pop();
			if(!visited[i]){
				comp.resize(comp.size() + 1);
				adComp.resize(adComp.size() + 1);
				dfs2(i, comp.size() - 1);
			}
		}
	//	cout << 2 << endl;
/*		for(ll i = 0; i < comp.size(); i++){
			ll mn = (1ll << 50);
			for(ll j = 0; j < comp[i].size(); j++){
				mn = min(comp[i][j], mn);
			}
			for(ll j = 0; j < comp[i].size(); j++){
				sol[comp[i][j]] = mn;
			}
		}*/
		fill(visited, visited + n + 10, 0);
		ll sol = dfs3(comp.size() - 1);
		if(sol == n) printf("%lld\n", (long long)comp[comp.size() - 1].size());
		else printf("0\n");
	}
}
