#include <iostream>
#include <set>
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
struct pll{
  ll F, S, id;
  bool operator <(const pll A)const{
    if(F == A.F){
      return S < A.S;
    }
    else return F < A.F;
  }
};
pll A[50100] = {};
ll n, INF = (1 << 30), solA, solB;
double sol = (1<<30);

double dist(pll A, pll B){
    return sqrt((A.F - B.F)*(A.F - B.F) + (A.S - B.S)*(A.S - B.S));
}
struct num{
    bool operator()(const pll A, const pll B)const{
    if(A.S == B.S) return A.F < B.F;
    else return A.S < B.S;
  }
};
int main()
{
    scanf("%lld",&n);
    for(long i = 0; i < n; i++){
      scanf("%lld %lld", &A[i].F, &A[i].S);
      A[i].id = i;
    }
    sort(A, A + n);

    set<pll,num> S;
    queue<pll> Q;
    for(long i = 0; i < n; i++){
      pll cur = A[i];
      while(!Q.empty() &&cur.F - Q.front().F >= sol){
        S.erase(Q.front());
        Q.pop();
      }
      pll temp = {-INF, cur.S - sol,0};
      set<pll>::iterator it = S.lower_bound(temp);
      for(; it != S.end() && it->S - cur.S < sol; it++){
        if(dist(cur,*it) < sol){
          sol = dist(cur,*it);
          solA = it->id;
          solB = cur.id;
        }
      }
      Q.push(cur);
      S.insert(cur);
    }
    ll tempA = solA;
    solA = min(solB, solA);
    solB = max(tempA, solB);
    printf("%lld %lld %f\n",solA, solB,sol);
    return 0;
}
