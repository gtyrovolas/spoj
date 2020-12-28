#include <iostream>
#include <stdio.h>

using namespace std;

typedef long long ll;
ll n;
bool dp[1000100] = {};
bool proc[1000100] = {};

bool memo(ll i){
    if(proc[i]) return dp[i];
    if(__builtin_popcount(i) == 1){
        proc[i] = 1;
        return 0;
      }else{
        for(ll j = 0; j < 21 && !dp[i]; j++){
          if(i & (1 << j)){
            dp[i] = (!memo(i ^ (1 << j))) || dp[i];
          }
          if((i & (3 << j)) == (3 << j)){
            dp[i] = (!memo(i ^ (3 << j))) || dp[i];
          }
        }
      }
    proc[i] = 1;
    return dp[i];
}

int main()
{
    proc[0] = 1;
    scanf("%lld", &n);
    for(ll i = 0; i < n; i++){
      ll t;
      scanf("%lld", &t);
      printf("%s", (memo(t) ? "Alice\n" : "Bob\n"));
    }
    return 0;
}
