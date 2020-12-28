#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

ll n;

struct ele{
	ll st, en;
	bool operator<(const ele &A)const{
		return st < A.st;
	}
};

int main(){
/*	for(ll i = 1; i <= 30; i++){
		cout << i << " " << i << endl;
	}*/
	scanf("%lld",&n);
	for(;n != -1;){
		ele A[100100] = {};
		ll dp[100100][2] = {};
		for(ll i = 0; i < n; i++){
			scanf("%lld %lld",&A[i].st, & A[i].en);
		}
		sort(A, A + n);
		for(ll i = n - 1; i >= 0; i--){
			dp[i][0] = dp[i + 1][1] + dp[i + 1][0];
			ele temp = {A[i].en, 0};
			ele * f = lower_bound(A, A + n, temp);
			dp[i][1] = dp[f - A][1] + dp[f - A][0] + 1;
			dp[i][0] %= 100000000;
			dp[i][1] %= 100000000;
		}
		printf("%08lld\n", (dp[0][0] + dp[0][1]) % 100000000);
		scanf("%lld",&n);
	}
}
