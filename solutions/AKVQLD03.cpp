#include <iostream>
#include <stdio.h>

using namespace std;

typedef long long ll;

ll n, q, BIT[1000100] = {};

void add(ll pos, ll val){
    while(pos <= n){
      BIT[pos] += val;
      pos += pos & -pos;
    }
}

ll sum(ll st, ll en){
    ll sol = 0;
    if(st != 1){
      return sum(1, en) - sum(1, st - 1);
    }
    while(en > 0){
      sol += BIT[en];
      en -= (en & -en);
    }
    return sol;
}

int main()
{
    scanf("%lld %lld", &n, &q);
    for(ll i = 0; i < q; i++){
      char T [100];
      ll a, b;
      scanf("%s", T);
  //    cout << T << endl;
      scanf("%lld %lld", &a, &b);
      if(T[0] == 'a') add(a, b);
      else printf("%lld\n", sum(a,b));
    }
    return 0;
}
