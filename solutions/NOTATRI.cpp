#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

typedef int ll;

int main(){
	while(true){
		ll n;
		long long sol = 0;
		scanf("%d",&n);
		ll A[2100] = {};
		if(n == 0) return 0;
		for(ll i = 0; i < n; i++){
			scanf("%d",&A[i]);
		}
		sort(A, A + n);
		
		for(ll i = 0; i < n; i++){
			ll k = i; 
			for(ll j = i + 1; j < n; j++){
				while(A[k] <= A[j] + A[i] && k < n){
					k++;
				}
		//		cout << i << " " << j << " " << k << endl;
				if(n == k) break;
				sol += n - k; 
			}
		}
		printf("%lld\n", sol);
	}
}
