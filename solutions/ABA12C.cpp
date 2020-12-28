#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

const ll INF = ( 1ll << 40);

int main(){
	ll t;
	scanf("%lld",&t);
	for(ll o = 0; o < t; o++){
	ll n,k, A[110];
	ll dp[110][110]; // dp[target] [number of stuff]
	scanf("%lld %lld",&n,&k);
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= k; j++) dp[i][j] = INF;
	}
	for(ll i = 1; i <= k; i++){
		scanf("%lld",&A[i]);
		if(A[i] != -1){
			dp[1][i] = A[i];
	//		cout << dp [1][i] << endl;
		}
	}
	for(ll i = 2; i <= n; i++){
		for(ll j = 1; j <= k; j++){
			dp[i][j] = dp[i-1][j];
			for(ll l = 1; l < j; l++){
				dp[i][j] = min(dp[i][j], dp[i-1][j - l] + dp[1][l]);
			}
		}
	}
/*	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= k; j++) cout << dp[i][j] << " ";
		cout << endl;
	}*/
	if(dp[n][k] == INF) printf("-1\n");
	else printf("%lld\n",dp[n][k]);
	}
}
