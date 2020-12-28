#include <iostream>
#include <stdio.h>
#include <algorithm>
#define INF (1 << 30)
#define pll pair<long, long>
#define F first
#define S second

using namespace std;

long t;

int main()
{
    scanf("%ld",&t);
    for(long q = 0; q < t; q++){
      long dp[2][11000] = {};
      long W, tempw, n;
      scanf("%ld%ld",&tempw, &W);
      W -= tempw;
      scanf("%ld",&n);
      pll w[11000];
      for(long i = 1; i <= n; i++){
        scanf("%ld%ld",&w[i].S, &w[i].F);
      }
      sort(w, w + n);
      for(long j = 0; j <= W; j++)
        dp[0][j] = INF;
      for(long i = 0; i < 2; i++)
        dp[i][0] = 0;
      for(long i = 1; i <= n; i++){
        for(long j = 1; j <= W; j++){
        /*  for(long k = 0; k <= 1; k++){
            for(long l = 0; l <= W; l++){
              cout << dp[k][l] << " ";
            }
            cout << endl;
          }
          cout << endl;*/
          dp[i%2][j] = dp[(i-1)%2][j];
          if(w[i].F <= j){
            dp[i%2][j] = min(dp[i%2][j],
            dp[i%2][j - (w[i].F)] + w[i].S);
     //       cout << dp[i][j - (w[i].F)] + w[i].S << endl;
          }
         }
      }
      if(dp[n%2][W] != INF)
        printf("The minimum amount of money in the piggy-bank is %ld.\n", dp[n%2][W]);
      else
        printf("This is impossible.\n");
    }
    return 0;
}
