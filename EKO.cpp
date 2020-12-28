#include <stdio.h>
#include <climits>
#include <algorithm>
#define MAXN 1000100

using namespace std;

long A[MAXN],m,n,lysh = 0,maxh = 0;

bool check(long val){
    long long ans = 0;
    for(long i = 0; i< n; i++){
        ans += A[i] > val ? A[i] - val : 0;
    }
    return ans >= m;
}

int main()
{
    scanf("%ld%ld",&n,&m);
    for(long i = 0; i < n; i++){
        scanf("%ld",&A[i]);
        maxh = max(A[i],maxh);
    }
    long st = 0, en = maxh;
    while(st <= en){
        long mid = (st + en)/2;
        if(check(mid)){
            lysh = max(lysh, mid);
            st = mid+1;
        }else en = mid - 1;
    }
    printf("%ld\n",lysh);
    return 0;
}
