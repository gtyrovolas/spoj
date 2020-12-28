#include <iostream>
#include <stdio.h>

using namespace std;

typedef long long ll;

struct seg{
    ll sum = 0, add = 0;
}T[500000] = {};

void pushdown(ll id, ll st, ll en){
 //   cout << "Pushdown range "<< st << " " << en << endl;
    ll mid = (st + en) /2;
    T[id*2].sum += T[id].add * (mid - st + 1);
    T[id*2].add += T[id].add;
    T[id*2+1].sum += T[id].add * (en - mid);
    T[id*2+1].add += T[id].add;
    T[id].add = 0;
}
void pushup(ll id, ll st, ll en){
    T[id].sum = T[2*id].sum + T[2*id + 1].sum+
                T[id].add *(en - st + 1);
}
ll query(ll l, ll r, ll st, ll en, ll id){
    if(l == st && r == en){
   //  cout << "FULL RANGE " << st << " " << en << endl;
      return T[id].sum;
    }
    else{
      pushdown(id, st,en);
      ll mid = (st + en)/2;
      if(r <= mid){
        return query(l, r, st, mid,2*id);
      }else if(l > mid){
        return  query(l, r, mid + 1, en, 2*id +1);
      }else{
        return query(l, mid, st, mid, 2*id) +
               query(mid + 1, r, mid + 1, en, 2*id + 1);
      }
    }
}
void add(ll val, ll l, ll r, ll st, ll en, ll id){
    if(l == st && r == en){
      T[id].add += val;
      T[id].sum += val *(en - st + 1);
    }
    else{
      ll mid = (st + en)/2;
      pushdown(id,st,en);
      if(r <= mid){
        add(val, l, r, st, mid, 2*id);
      }else if(l > mid){
        add(val, l, r, mid + 1, en, 2*id + 1);
      }else{
        add(val, l, mid, st, mid, 2*id);
        add(val, mid + 1, r, mid + 1, en, 2*id + 1);
      }
      pushup(id,st,en);
    }
}
void init(ll l, ll r, ll id){
 // cout << l << " " << r << endl;
    T[id].sum = 0;
    T[id].add = 0;
    if(l == r) return;
    init(l, (l+r)/2,2*id);
    init((l+r)/2 + 1, r,2*id+1);
}
void dfs(ll id, ll st, ll en){
    if(st <= en){
   //   cout << "Range " << st << "," << en << " " << T[id].sum << endl;
      if(st == en) return;
      dfs(2*id, st, (st+en)/2);
      dfs(2*id + 1, (st + en)/2 + 1, en);
    }
}

int main()
{
    ll n,m,c,a,b,t;
    scanf("%lld",&t);
    for(long l = 0; l < t; l++){
    scanf("%lld%lld",&n,&m);
    init(1, n, 1);
    for(long i = 0; i < m; i++){
      scanf("%lld %lld %lld",&c,&a,&b);
      if(c != 0){
          printf("%lld\n",query(a,b,1,n,1));
      }
      else{
          ll val;
          scanf("%lld",&val);
          add(val,a,b,1,n,1);
      }
    }
    }
    return 0;
}
