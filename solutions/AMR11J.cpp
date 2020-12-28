#include <iostream>
#include <stdio.h>
#include <queue>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

struct obj{
    ll F, S;
    char t;
    ll ti;
};


ll t, r, c;

char A[510][510] = {};
ll visit[510][510] = {};
queue<obj> Q;
map<pll, obj> S;

void read(){
    scanf("%lld %lld", &r, &c);
    for(ll i = 0; i <= c + 1; i++){
      A[0][i] = '#';
      A[r + 1][i] = '#';
    }
    for(ll i = 1; i <= r; i++){
      A[i][0] = '#';
      A[i][c + 1] = '#';
      scanf("%s", A[i] + 1);
    }
}

void push(obj temp){
    Q.push({temp.F + 1, temp.S, temp.t, temp.ti + 1});
    Q.push({temp.F - 1, temp.S, temp.t, temp.ti + 1});
    Q.push({temp.F, temp.S + 1, temp.t, temp.ti + 1});
    Q.push({temp.F, temp.S - 1, temp.t, temp.ti + 1});
}

void solve(){
    for(ll i = 1; i <= r; i++){
      for(ll j = 1; j <= c; j++){
        if(A[i][j] != '.' && A[i][j] != '#'){
          obj temp = {i, j, A[i][j], 0};
          push(temp);
        }
      }
    }
    ll gen = 0;
    while(!S.empty() || gen == 0){
      for(auto it = S.begin(); it != S.end(); it++){
        push(it->second);
      }
      S.clear();
      while(!Q.empty()){
        obj temp = Q.front();
        Q.pop();
        ll r = temp.F, c = temp.S;
        gen = max(gen, temp.ti);
        if(A[r][c] == '#'){}
        else if(A[r][c] == '.'){
          A[r][c] = temp.t;
          visit[r][c] = temp.ti;
          S[{temp.F, temp.S}] = temp;
        }else if(visit[r][c] == temp.ti && A[r][c] != temp.t){
          A[r][c] = '*';
          auto it = S.find({temp.F, temp.S});
          if(it != S.end()) S.erase(it);
        }
      }
    }
}

/*
1
3 5
.....
.#.#.
a...b

*/

void print(){
    for(ll i = 1; i <= r; i++){
      for(ll j = 1; j <= c; j++){
        printf("%c",A[i][j]);
      }
      printf("\n");
    }
}

int main()
{
    scanf("%lld", &t);
    for(ll i = 0; i < t; i++){
      read();
      solve();
      print();
      printf("\n");
    }
    return 0;
}
