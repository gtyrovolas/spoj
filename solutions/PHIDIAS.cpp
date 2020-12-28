#include <iostream>
#include <stdio.h>

using namespace std;

long n, w, h, t;



int main()
{
    scanf("%ld", &t);
    for(long i = 0; i < t; i++){
      scanf("%ld%ld%ld",&w, &h, &n);
      long dp[601][601] = {};
      long tempw, temph;
      for(long i = 0; i < n; i++){
        scanf("%ld%ld",&tempw,&temph);
        dp[tempw][temph] = tempw * temph;
      }
      for(long i = 1; i <= w; i++){
        for(long j = 1; j <= h; j++){
          if(dp[i][j] != 0) continue;
          for(long k = 1; k < i; k++){
            dp[i][j] = max(dp[i][j], dp[i-k][j] + dp[k][j]);
          }
          for(long k = 1; k < j; k++){
            dp[i][j] = max(dp[i][j], dp[i][j-k] + dp[i][k]);
          }
        }
      }
      printf("%ld\n",w*h - dp[w][h]);
    }
    return 0;
}
