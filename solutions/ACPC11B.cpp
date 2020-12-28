#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

ll t;

int main()
{
    scanf("%lld",&t);
    for(ll k = 0; k < t; k++){
      ll n1, n2;
      ll A[2][1010];
      scanf("%lld", &n1);
      for(ll i = 0; i < n1; i++){
        scanf("%lld", &A[0][i]);
      }
      scanf("%lld", &n2);
      for(ll i = 0; i < n2; i++){
        scanf("%lld", &A[1][i]);
      }
      sort(A[0], A[0] + n1);
      sort(A[1], A[1] + n2);
      ll sol = (1ll << 30);
      ll j = 0;
      for(ll i = 0; i < n1; i++){
    //    cout << abs(A[1][j] - A[0][i])  << " " << abs(A[1][j + 1] - A[0][i]) << endl;
        while(j < n2 - 1 && (abs(A[1][j] - A[0][i]) >= abs(A[1][j + 1] - A[0][i]))){
          j++;
        }
        sol = min(sol, abs(A[0][i] - A[1][j]));
      }
      printf("%lld\n",sol);
    }
    return 0;
}
