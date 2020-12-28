#include <cstdio>
#include <iostream>
#define MAX 1000000007

using namespace std;

int main()
{
  char x [1000200];
  long long t;
  long dp[1000200] = {};
  scanf("%lld", &t);
  scanf("%*c");
  for(long long j = 0; j < t; j++){
    long long count[46] = {};
    long long i = 1;
    while(scanf("%c",&x[i]) &&  x[i] != '\n'){
      i++;
    }
    long long n = i;
    dp[0] = 1;
    for(long long i = 1; i < n; i++){
      long long a = dp[i-1]*2 - count[x[i] - 'A'];
      while(a < 0)
        a += MAX;
      dp[i] = a % MAX;
      long long cnt = dp[i-1];
      count[x[i] - 'A'] = (dp[i-1] +  MAX) % MAX;
    }
    printf("%ld\n",dp[n-1]);
  }

  return 0;
}
