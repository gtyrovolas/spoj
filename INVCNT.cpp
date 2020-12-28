#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

long long splitDC(long long* L, long long* R, long long nL, long long nR){
    long long i = 0, j = 0,lysh=0;
    while (i < nL && j < nR){
        if(L[i] <= R[j])
            i++;
        else if(L[i] > R[j]){
            j++;
            lysh+=nL-i;
        }
    }
    return lysh;
}

long long DC(long long* A, long long n){
    if(n==1)
        return 0;
    if(n == 2){
        if(A[0] > A[1]){
            swap(A[1], A[0]);
            return 1;
        }
        return 0;
    }
    long long l,r,split;
    long long* L = new long long [n/2];
    long long* R = new long long [n - n/2];
    long long i = 0;
    for(; i < n/2; i++)
        L[i] = A[i];
    for(; i < n; i++)
        R[i-n/2] = A[i];
    l = DC(L, n/2);
    r = DC(R, n - n/2);
    long long j = 0, k = 0;
    i = 0;
    while(i < n/2 && j < n - n/2){
        if(L[i] < R[j]){
            A[k] = L[i];
            i++;
        }else{
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n/2){
        A[k] = L[i];
        i++;
        k++;
    }
    while(j < n - n/2){
        A[k] = R[j];
        j++;
        k++;
    }
    split = splitDC(L,R, n/2 , n-n/2);
    return l+r+split;
}

int main()
{
    long long t,n;
    long long* A;
    scanf("%lld", &t);
    for(long long j = 0; j < t;j++){
    scanf("%lld", &n);
    long long* A = new long long [n];
    for(long i = 0; i < n; i++)
        scanf("%lld ", &A[i]);
    printf("%lld\n", DC(A,n));
    }
    return 0;
}
