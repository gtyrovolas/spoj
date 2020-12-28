#include <iostream>
#include <stdio.h>
#define MAXN 5100

using namespace std;

bool check(long pos, long long* A){
//    cout << pos << " " << A[pos] << endl;
    if(A[pos-1] == 1)
        return true;
    else if(A[pos-1] == 2){
        if(A[pos] <= 6){
            return true;
        }
    }
    return false;
}

int main()
{
    long long n, i = 1;
    char temp;
    while(true){
    i = 1;
    bool end = false;
    long long A[MAXN] = {}, dp[MAXN][2] = {};
    A[1] = 1;
    while(scanf("%c", &temp) && A[1] != 0 && temp != '\n'){
        A[i] = temp -'0';
        i++;
    }
    n = --i;
    if(A[1] == 0)
        break;
    dp[0][0] = 1; dp[0][1] = 0;
    dp[1][0] = 1; dp[1][1] = 0;
    for(long i = 2; i <= n; i++){
        dp[i][0] = 0;
        if(A[i] != 0)
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = 0;
        if(check(i,A)){
            dp[i][1] = dp[i-2][0] + dp[i-2][1];
        }
    }
 //   for(long i = 1; i <= n;i++)
 //       cout << dp[i][0] <<" ";
 //       cout << endl;
 //   for(long i = 1; i <= n;i++)
 //       cout << dp[i][1] <<" ";
 //       cout << endl << endl;
    long long lysh = dp[n][0] + dp[n][1];
    printf("%lld\n",lysh);
    if(end)
        break;
    }
    return 0;
}
