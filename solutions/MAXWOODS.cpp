#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long t,n,m;
    cin >> t;
    for(long i = 0; i < t; i++){
        cin >> n >> m;
        long lysh = 0;
        char A[n+2][m+2];
        long dp[n+2][m+2];

        for(long i = 0; i < m+1; i++){
            dp[0][i] = -10000;
            dp[n+1][i] = -10000;
        }
        for(long i = 0; i < n+1; i++){
            dp[i][0] = -10000;
            dp[i][m+1] = -10000;
        }
        for(long i = 0; i < n; i++){
            for(long j = 0; j < m; j++){
                cin >> A[i][j];
                if(A[i][j] == '#')
                    dp[i+1][j+1] = -10000;
            }
        }
        dp[0][1] = 0;
        dp[1][0] = 0;
        for(long i = 1; i < n+1;i++){
            if(i % 2 == 1){
                for(long j = 1; j < m+1; j++){
                    if(A[i-1][j-1] != '#'){
                        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                        if(A[i-1][j-1] == 'T')
                            dp[i][j]++;
                    }
                lysh = max(dp[i][j],lysh);
                }
            }
            else{
                for(long j = m; j > 0; j--){
                    if(A[i-1][j-1] != '#'){
                        dp[i][j] = max(dp[i-1][j],dp[i][j+1]);
                        if(A[i-1][j-1] == 'T')
                            dp[i][j]++;
                    }
                    lysh = max(dp[i][j],lysh);
                }
            }
 /*           for(long j = 0; j < n+2; j++){
                for(long k = 0; k < m+2; k++)
                    cout << dp[j][k] <<" ";
                cout << endl;
            }
            cout << endl;*/
        }
        cout << lysh << endl;
    }
    return 0;
}
