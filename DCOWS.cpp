#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

ll n, m;
ll dp[5010][5010] = {};
const ll INF = (1ll << 40);
ll A[5010], B[5010];

int main(){
	scanf("%lld %lld",&n,&m);
	for(ll i = 1; i <= n; i++){
		scanf("%lld",&A[i]);
	}
	for(ll i = 1; i <= m; i++){
		scanf("%lld",&B[i]);
	}
	sort(A + 1, A + n + 1);
	sort(B + 1, B + m + 1);
	for(ll i = 1; i <= n; i++){
		dp[i][i-1] = INF;
		for(ll j = i; j <= m; j++){
			dp[i][j] = min(dp[i][j-1], dp[i-1][j-1] + abs(A[i] - B[j]));
	//		cout << dp[i][j] << " ";
		}
//		cout << endl;
	}
	printf("%lld\n",dp[n][m]);
}
