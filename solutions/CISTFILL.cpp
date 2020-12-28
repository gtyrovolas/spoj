#include <iostream>
#include <stdio.h>

using namespace std;

typedef long long ll;
ll n, l;

struct tank{
    ll b, h, w, l;
}t[50100] = {};

double f( double h){
    double lysh = 0;
    for(ll i = 0; i < n; i++){
        if(t[i].b + t[i].h < h) lysh += t[i].h * t[i].w * t[i].l;
        else if(t[i].b < h) lysh += t[i].w * t[i].l *(h - t[i].b);
    }
    return lysh;
}

int main()
{
    scanf("%lld", &l);
    for(ll k = 0; k < l; k++){
        scanf("%lld", &n);
        for(ll i = 0; i < n; i++){
            scanf("%lld %lld %lld %lld", &t[i].b, &t[i].h, &t[i].w, &t[i].l);
        }
        ll tar;
        scanf("%lld", &tar);
        double st = 0, en = 2000000001;
        while(st < en- 0.001){
            double mid = (st + en)/2;
         //   cout << mid << endl;
            if(f(mid) >= tar) en = mid;
            else st = mid;
        }
        if(en == 2000000001) printf("OVERFLOW\n");
        else printf("%.2f\n", st);
    }
    return 0;
}
