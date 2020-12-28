#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

struct ele{
	ll a, b, w;
	bool operator<(const ele &A)const{
		return a < A.a;
	}
};

int main(){
	ll t;
	scanf("%lld",&t);
	for(ll k = 0; k < t; k++){
		ll n;
		ll dp[10100][2] = {};
		ele A[10100] = {};
		scanf("%lld", &n);
		for(ll i = 0; i < n; i++){
			scanf("%lld %lld %lld", &A[i].a, &A[i].b, &A[i].w);
			A[i].b += A[i].a;
		}
		sort(A, A + n);
		for(ll i = n - 1; i >= 0; i--){
			dp[i][0] = max(dp[i + 1][1], dp[i + 1][0]);
			ele temp = {A[i].b,0,0};
			ele *f = lower_bound(A, A + n, temp);
			dp[i][1] = A[i].w + max(dp[f - A][0], dp[f - A][1]);
	//		cout << dp[i][0] << " " << dp[i][1] << endl;
		}
		printf("%lld\n",max(dp[0][0], dp[0][1]));
	}
}
