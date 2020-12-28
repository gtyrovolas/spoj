#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

typedef long long ll;

ll t;
ll A[10100];

int main()
{
    scanf("%lld",&t);
    for(ll k = 0; k < t; k++){
      ll n, sum = 0, sol = 0;
      scanf("%lld", &n);
      for(ll i = 1; i <= n; i++){
        scanf("%lld", &A[i]);
        sum += A[i];
      }
      for(ll i = 1 ; i <= n; i++){
        sum -= (n - i + 1) * (A[i] - A[i - 1]);
        sol += sum;
    //    cout << sum << " " << sol << endl;
      }
      printf("%lld\n",sol);
    }
    return 0;
}
