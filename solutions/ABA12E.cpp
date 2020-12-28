#include <iostream>
#include <stdio.h>

using namespace std;

typedef long long ll;

ll n, k, A[50100], P[50100];

ll sum(ll st, ll en){
    return P[en] - (st == 0 ? 0 : P[st - 1]);
}

ll query(ll num){
    ll curSol = 0, en = 0;
    for(ll st = 0; st < n; st++){
      for(en = max(en, st); en < n; en++){
      //  cout << sum(st, en) << endl;
        if(sum(st, en) >= num){
          curSol += n - en;
          break;
        }
      }
    }
 //   cout << curSol << endl;
    return (curSol < k);
}

ll solve(){
    ll st = 0, en = P[n - 1];
    while(st < en){
   //   cout << st << " " << en << endl;
      ll mid = (st + en + 1) / 2;
      if(query(mid)) en = mid - 1;
      else st = mid;
    }
    return st;
}

void read(){
    scanf("%lld %lld", &n, &k);
    for(ll i = 0; i < n; i++){
      scanf("%lld",&A[i]);
      P[i] = (i == 0 ? 0 : P[i - 1]) + A[i];
    }
}

int main()
{
    read();
    k = n * (n + 1) / 2 - k + 1;
 //   cout << "K " << k << endl;
 /*   for(ll i = 0; i <= 15; i++){
      cout << query(i) << " ";
    }
    cout << endl;*/

    printf("%lld\n", solve());
    return 0;
}
