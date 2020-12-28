#include <iostream>
#include <stdio.h>

using namespace std;

typedef long long ll;

ll t;
ll n, M;
ll A[1000100] = {};

void read(){
    scanf("%lld %lld", &n, &M);
    for(ll i = 0; i < n; i++){
      scanf("%lld", &A[i]);
    }
}
/*
100
4 2
2 100 1 100
*/

void solve(){
    ll sum = 0;
    ll sol = 0, num = 0;
    ll en = 0;ll st = 0;
    for(; st < n; st++){
      sum -= (st == 0 ? 0 : A[st - 1]);
      for(; en <= n; en++)
      {
   //     cout << "ST " << st << " EN " << en << " SUM " << sum << endl;

        if(en - st - 1 >  sol)
        {
          sol = en - st - 1;
          num = sum - A[en - 1];
        }

        else if(sol == en - st- 1)
        {
          num = min(sum - A[en - 1], num);
        }
        if(sum > M)
          break;
        sum += A[en];
      }
      if(en - st - 1 >  sol)
        {
          sol = en - st - 1;
          num = sum - A[en - 1];
        }

        else if(sol == en - st- 1)
        {
          num = min(sum - A[en - 1], num);
        }
    }
    printf("%lld %lld\n", num, sol);
}

int main()
{
    scanf("%lld", &t);
    for(ll i = 0; i < t; i++){
      read();
      solve();
    }
    return 0;
}
