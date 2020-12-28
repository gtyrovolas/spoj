#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>
#include <algorithm>
#define F first
#define S second
#define mk make_pair
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

vector< vector < ll > > G;
vector< pll > P;
vector< pll > visit;

bool bfs(vector< vector < ll > > & G, ll st, ll pow, vector< pll > & visit, ll idx){
    queue<pll> Q;
    Q.push({st, pow});
  //  cout << "BFS " << st << " " << pow << endl;
    while(!Q.empty()){
      pll top = Q.front();
      Q.pop();

      if((visit[top.F].F == 0 || (visit[top.F].F == idx && top.S > visit[top.F].S )
          )&& top.S > 0){
        for(auto it = G[top.F].begin(); it != G[top.F].end(); it++){
          Q.push({*it, top.S - 1});
        }
      }
  //    cout << "Position " << top.F << " visited with power " <<  top.S << endl;
      if(visit[top.F].F != 0 && visit[top.F].F != idx) return 1;
      else{
    //    cout << top.F << " " << idx << endl;
        visit[top.F].F = idx;
        visit[top.F].S = max(top.S, visit[top.F].S);
      }
    }
    return 0;
}

bool solve(vector< vector < ll > > G, vector< pll > & P,ll n){
    ll idx = 1;
    visit.clear();
    visit.resize(n + 1);
    fill(visit.begin(), visit.begin() + n + 1, mk(0,0));
    for(auto it = P.begin() ; it != P.end(); it++, idx++){
      if(bfs(G, it->F, it->S, visit, idx)) return 1;
    }
    for(ll i = 1; i <= n; i++){
  //    cout << visit[i].F << " ";
      if(visit[i].F == 0){
    //    cout << endl;
         return 1;
      }
    }
    return 0;
}

void read(){
    ll n, m , r;
    scanf("%lld %lld %lld",&n, &m, &r);
    G.clear();
    G.resize(n + 1);
    P.clear();
    for(ll i = 0; i < m; i++){
      ll a, b;
      scanf("%lld %lld", &a, &b);
      G[a].push_back(b);
      G[b].push_back(a);
    }
    for(ll i = 0; i < r; i++){
      ll pos, val;
      scanf("%lld %lld", &pos, &val);
      P.push_back({pos, val});
    }
    printf("%s", (solve(G, P, n) == 1 ? "No\n" : "Yes\n"));
}

ll t;
/*
1
4 5 2
1 4
1 2
1 3
4 2
3 4
2 1
3 0
*/
int main()
{
    scanf("%lld",&t);
    for(ll i = 0; i < t; i++){
      read();
    }
    return 0;
}
