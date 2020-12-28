#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

char A[1100], B[1100];

int main()
{
    while(scanf("%s",A)){
      if(A[0] == '#') return 0;
      long dp[1010][1010] = {}, n, m;
      scanf("%s",B);
      n = strlen(A);
      m = strlen(B);
      for(long i = 0; i <= n; i++) dp[i][0] = i;
      for(long i = 0; i <= m; i++) dp[0][i] = 2*i;
      for(long i = 1; i <= n; i++){
        for(long j = 1; j <= m; j++){
          if(A[i-1] == B[j-1]){
            dp[i][j] = dp[i-1][j-1];
          }
          else{
            dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+2);
          }
        }
      }
    /*  for(long i = 0; i <= n; i++){
        for(long j = 0; j <= m; j++){
          cout << dp[i][j] << " ";
        }
        cout << endl;
      }*/
      printf("%ld\n",dp[n][m]*15);
    }
    return 0;
}
