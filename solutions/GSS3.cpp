#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

struct ele{
		ll val, sum, L, R;
};

ele seg[2000100] = {};
ll A[500100] = {};
ll n, q;

void build(ll st, ll en, ll pos){
		if(st == en){
		 seg[pos].val = A[st];
		 seg[pos].L = A[st];
		 seg[pos].R = A[st];
		 seg[pos].sum = A[st];
		}else{
			ll mid = (st + en)/2;
			build(st, mid, 2*pos);
			build(mid + 1, en, 2*pos + 1);
			ele L = seg[2 * pos], R = seg[2 * pos + 1];
			seg[pos].val = max(max(L.val,R.val), L.R + R.L);
			seg[pos].sum = L.sum + R.sum;
			seg[pos].L = max(L.L, L.sum + R.L);
			seg[pos].R = max(R.R, R.sum + L.R);
		}
}

ele query(ll st, ll en, ll pos, ll B, ll E){
	//	cout << st <<" " << en << endl;
		if(st == B && en == E) return seg[pos];
		ll mid = (st + en)/2;
		if(E <= mid){
			return query(st, mid, 2 * pos, B, E);
		}
		else if(B > mid){
			return query(mid + 1, en, 2 * pos + 1, B, E);
		}
		else{
			ele L = query(st, mid, 2 * pos, B, mid);
			ele R = query(mid + 1, en, 2 * pos + 1, mid + 1, E);
			ele lysh = { 
					max(max(L.val,R.val), L.R + R.L),
					L.sum + R.sum,
					max(L.L, L.sum + R.L),
					max(R.R, R.sum + L.R)
			};
			return lysh;
		}
}
void update(ll st, ll en, ll pos, ll tar, ll val){
		if(st == en && st == tar){
			seg[pos] = {val,val,val,val};
			return;
		}else{
			ll mid = (st + en)/2;
			if(tar <= mid){
				update(st, mid, 2 * pos, tar, val);
			}else{
				update(mid + 1, en, 2 * pos + 1, tar, val);
			}
			ele L = seg[2 * pos];
			ele R = seg[2 * pos + 1];
			seg[pos].val = max(max(L.val,R.val), L.R + R.L);
			seg[pos].sum = L.sum + R.sum;
			seg[pos].L = max(L.L, L.sum + R.L);
			seg[pos].R = max(R.R, R.sum + L.R);
		}
}
int main(){
		scanf("%lld",&n);
		for(ll i = 1; i <= n; i++){
			scanf("%lld", &A[i]);
		}
		build(1, n, 1);
		scanf("%lld",&q);
		for(ll i = 0; i < q; i++){
			ll t, a, b;
			scanf("%lld %lld %lld", &t, &a, &b);
			if(t == 1){
				printf("%lld\n", query(1, n, 1, a, b).val);
			}else{
				update(1, n, 1, a, b);
			}
		}
}
