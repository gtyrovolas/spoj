#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;
ll n, c, t;
ll A[100100] = {};

bool place(ll dist){
	ll prev = -(1ll << 40);
	ll tot = 0;
	for(ll i = 0; i < n; i++){
	//	cout << A[i] << " " << prev << " " << dist << endl;
		if(A[i] - prev >= dist){
			tot++;
			prev = A[i];
		}
	}
	if(c <= tot) return 1;
	else return 0;
}

int main(){
	scanf("%lld",&t);
	for(ll k = 0; k < t; k++){
		scanf("%lld %lld",&n, &c);
		for(ll i = 0; i < n; i++){
			scanf("%lld",&A[i]);
		}
		sort(A, A + n);
		ll st = 0, en = 1000000000;
		while(st < en){
			ll mid = (st + en + 1) / 2;
	//		cout << mid << " " << place(mid) << "\n\n\n";
			if(place(mid)) st = mid;
			else en = mid - 1;
		} 
		printf("%lld\n", st);
	}	
}
