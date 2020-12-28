#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    long n,m;
    while(cin >> n >> m && n !=0 && m != 0){
        long A [501][501];
        long B [501][501];
        long Y [501][501];
        for(long i = 1; i <= n; i++){
            for(long j = 1; j <= m; j++){
                cin >> Y[i][j];
                Y[i][j] += Y[i][j-1];
            }
        }
        for(long i = 1; i <= n; i++){
            for(long j = 1; j <= m; j++){
                cin >> B[i][j];
                B[i][j] += B[i-1][j];
            }
        }
        for(long i = 1; i <= n; i++){
            for(long j = 1; j <= m; j++){
                A[i][j] = max(A[i][j-1] + B[i][j], A[i-1][j] + Y[i][j]);
            }
        }
        cout << A[n][m] << endl;
    }
    return 0;
}
