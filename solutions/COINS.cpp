#include <iostream>
#include <stdio.h>
#define MAXN 10000000

using namespace std;

long long n,A[MAXN] = {};

long long coins(long long q){
    if(q >= MAXN){
        return coins(q/2)+coins(q/3)+coins(q/4);
    }else if(A[q] == 0 && q != 0)
        A[q] = coins(q/2) + coins(q/3) + coins(q/4);
    return A[q];
}

int main()
{
    for(long i = 0; i < 12; i++)
        A[i] = i;
    while(cin >> n){
        printf("%lld\n",coins(n));
    }
    return 0;
}
