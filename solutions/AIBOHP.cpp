#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

ll dp[6200][6200] = {};

int main(){
	ll t;
	scanf("%lld",&t);
	for(ll i = 0; i < t; i++){
		char A[6200], R[6200];
		scanf("%s",A + 1);
		ll n = strlen(A + 1);
		for(ll i = 1; i <= n; i++){
			R[i] = A[n - i + 1];
		}
		for(ll i = 1; i <= n; i++){
			for(ll j = 1; j <= n; j++){
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				if(A[i] == R[j]){
					dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
				}
			}
		}
		printf("%lld\n", n - dp[n][n]);
	}
}
