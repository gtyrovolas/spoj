#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll seg[3][400100] ={};
bool lazy[3][400100];

void update(ll st, ll en, ll cur, ll B, ll E, ll seg[400100], bool lazy[400100]){
	if(en < st) return;
	if(lazy[cur] != 0){
		seg[cur] = en - st + 1 -seg[cur];
		if(st != en){
			lazy[cur * 2] = !lazy[cur * 2];
			lazy[cur * 2 + 1] = !lazy[cur * 2 + 1];
		}
		lazy[cur] = 0;
	}	
	if(B > en || E < st) return;
	//cout << "ENTER Cur " << st << " " << en << " " << seg[cur] << endl;
	if(B <= st && en <= E){
		seg[cur] = en - st + 1 - seg[cur];
		if(st != en){
			lazy[cur*2] = !lazy[cur*2];
			lazy[cur*2 + 1] = !lazy[cur*2 + 1];
		}
		//cout << " LEAVE Cur " << st << " " << en << " " << seg[cur] << endl;
		return;
	}
	if(st != en){
		ll mid = (st + en)/2;
		update(mid+1, en , 2*cur + 1, B, E, seg, lazy);
		update(st, mid, 2*cur, B, E, seg, lazy);
		seg[cur] = seg[cur * 2] + seg[cur * 2 + 1];
	}
	//cout << "LEAVE Cur " << st << " " << en << " " << seg[cur] << endl;
}
ll query(ll st, ll en, ll cur, ll B, ll E, ll seg[400100], bool lazy[400100]){
	if(st > en || en < B || E < st) return 0;
	if(lazy[cur] != 0){
		seg[cur] = en - st + 1 - seg[cur];
		if(st != en){
			lazy[2 * cur] = !lazy[cur*2];
			lazy[2 * cur + 1] = !lazy[cur*2 + 1];
		}
		lazy[cur] = 0;
	}
	//cout << "ENTER Cur " << st << " " << en << " " << seg[cur] << endl;
	if(B <= st && en <= E){
		//cout << "LEAVE Cur " << st << " " << en << " " << seg[cur] << endl;
		return seg[cur];
	}
	ll mid = (st + en)/2;
	ll temp = query(st, mid, 2 * cur, B, E, seg, lazy) +
		   query(mid + 1, en, 2 * cur + 1, B, E, seg, lazy);
	//cout << "LEAVE Cur " << st << " " << en << " " << temp << endl;
	return temp;
}

ll n[3], q;

int main(){
	#ifdef CONTEST
	freopen("starwars.in","r",stdin);  
	freopen("starwars.out","w",stdout);  
	#endif
	ll s;
	scanf("%lld",&s);
	for(ll k = 0; k < s; k++){
		scanf("%lld %lld %lld %lld", &n[0], &n[1], &n[2], &q);
		for(ll i = 0; i < 3; i++){
			fill(seg[i], seg[i] + 4 * n[i] + 10, 0);
			fill(lazy[i], lazy[i] + 4 * n[i] + 10, 0);
		}
		for(ll i = 0; i < q; i++){
			ll t, a, b;
			scanf("%lld",&t);
			if(t != 3){
				ll a, b;
				scanf("%lld %lld",&a, &b);
				update(0, n[t]-1, 1, a, b, seg[t], lazy[t]);
			}else{
				ll x1, x2, y1, y2, z1, z2;
				scanf("%lld %lld %lld %lld %lld %lld",&x1, &y1, &z1, &x2, &y2, &z2);  
				ll x = query(0, n[0]-1, 1, x1, x2, seg[0], lazy[0]), XS = x2 - x1 + 1, xx = XS - x;
				ll y = query(0, n[1]-1, 1, y1, y2, seg[1], lazy[1]), YS = y2 - y1 + 1, yy = YS - y;
				ll z = query(0, n[2]-1, 1, z1, z2, seg[2], lazy[2]), ZS = z2 - z1 + 1, zz = ZS - z;
			//	cout << x << " " << y << " " << z << endl;
				ll sol = x*yy*zz + xx*y*zz + xx*yy*z + x*y*z;
				printf("%lld\n",sol);
			}
		}
	}
}
