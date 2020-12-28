#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

typedef long long ll;
ll n, m, sol;
vector< vector < ll > > G;

ll d[100100], low[100100], num[100100]; // initialize D, low
bool visited[100100] = {};
const ll INF = (1ll << 60);

/*
5 6
1 2
2 3
1 3
1 4
4 5
1 5
*/
ll dfs(ll cur, ll p){
    num[cur] = max(1ll, num[cur]);
    low[cur] = min(low[cur], d[cur]);
 //   cout << "Intro cur : " << cur << " num " << num[cur] <<
 //   " low " << low[cur] << " d " << d[cur] <<  endl;
    if(!visited[cur]){
      visited[cur] = 1;
      for(auto it = G[cur].begin(); it != G[cur].end(); it++){
        if(p != *it){
          if(d[*it] == INF) d[*it] = d[cur] + 1;
          dfs(*it, cur);
          low[cur] = min(low[cur], low[*it]);
        }
      }
      if(low[cur] >= d[cur]){
        sol += num[cur] * (num[cur]-1) / 2;
      }
      else if (low[cur] < d[cur]){
        num[p] += num[cur];
      }
 //   cout << "Outro cur : " << cur << " num " << num[cur] <<
 //   " low " << low[cur] << " d " << d[cur] <<  endl;
    }
}

int main()
{
    scanf("%lld %lld", &n, &m);
    G.resize(n + 1);
    for(ll i = 1; i <= n ; i++) d[i] = INF;
    for(ll i = 1; i <= n ; i++) low[i] = INF;
    d[1] = 1;
    for(ll i = 0; i < m; i++){
      ll a, b;
      scanf("%lld %lld", &a, &b);
      G[a].push_back(b);
      G[b].push_back(a);
    }
    dfs(1,0);
    sol += num[0] * (num[0]-1) / 2;
 /*   cout <<"Sol " << sol << endl;
    cout << "Depth\n";
    for(ll i = 1; i <= n; i++) cout << i << " "; cout << endl;
    for(ll i = 1; i <= n; i++) cout << d[i] << " ";
    cout << "\nLow\n";
    for(ll i = 1; i <= n; i++) cout << i << " "; cout << endl;
    for(ll i = 1; i <= n; i++) cout << low[i] << " ";
    cout << "\nNum\n";
    for(ll i = 1; i <= n; i++) cout << i << " "; cout << endl;
    for(ll i = 1; i <= n; i++) cout << num[i] << " ";
    cout << endl;*/
    if(n != 1){
      printf("%.5f\n",  1 - ((double)sol)/( (double)n*(n-1)/2.0));
    }else{
      printf("%.5f\n", 0);
    }
    return 0;
}
