#include <stdio.h>

using namespace std;

typedef long long ll;

ll n;

int main(){
	ll sol = 0;
	scanf("%lld",&n);
	for(ll i = 1;  (n/i) - i + 1 > 0; i++){
		sol += (n/i) - i + 1;
	}
	printf("%lld\n",sol);
}
