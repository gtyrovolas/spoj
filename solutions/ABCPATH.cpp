#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;



ll dfs(ll i, ll j, char A[][55], ll matrix[][55]){
	if(matrix[i][j] != 0) return matrix[i][j];
	matrix[i][j] = 1;
	if(A[i - 1][j - 1] == A[i][j] + 1) matrix[i][j] = max(matrix[i][j], dfs(i - 1, j - 1, A,  matrix) + 1);
	if(A[i - 1][j    ] == A[i][j] + 1) matrix[i][j] = max(matrix[i][j], dfs(i - 1, j    , A,  matrix) + 1);
	if(A[i - 1][j + 1] == A[i][j] + 1) matrix[i][j] = max(matrix[i][j], dfs(i - 1, j + 1, A,  matrix) + 1);
	if(A[i    ][j - 1] == A[i][j] + 1) matrix[i][j] = max(matrix[i][j], dfs(i    , j - 1, A,  matrix) + 1);
	if(A[i    ][j + 1] == A[i][j] + 1) matrix[i][j] = max(matrix[i][j], dfs(i    , j + 1, A,  matrix) + 1);
	if(A[i + 1][j - 1] == A[i][j] + 1) matrix[i][j] = max(matrix[i][j], dfs(i + 1, j - 1, A,  matrix) + 1);
	if(A[i + 1][j    ] == A[i][j] + 1) matrix[i][j] = max(matrix[i][j], dfs(i + 1, j    , A,  matrix) + 1);
	if(A[i + 1][j + 1] == A[i][j] + 1) matrix[i][j] = max(matrix[i][j], dfs(i + 1, j + 1, A,  matrix) + 1);
//	cout << i << " " << j << " " << matrix[i][j] << endl;
	return matrix[i][j];
}

int main(){
	ll cur = 0;
	while(true){
		const ll INF = ( 1ll << 40);
		char A[55][55] = {};
		ll n, m;
		ll mx = 0;
		ll matrix[55][55] = {};
		cur++;
		scanf("%lld %lld",&n, &m);
		if(n == 0 && m == 0) return 0;
		fill(A[0], A[0] + m + 2, '$');
		fill(A[n + 1], A[n + 1] + m + 2, '$');
		for(ll i = 1; i <= n; i++){
			scanf("%s",A[i] + 1);
			A[i][0] = '$';
			A[i][m+1] = '$';
		}
		for(ll i = 1; i <= n; i++){
			for(ll j = 1; j <= m; j++){
        if(A[i][j] == 'A')
          mx = max(dfs(i,j, A, matrix	),mx);
			}
		}
/*		for(ll i = 0; i <= n + 1; i++){
      cout << A[i] << endl;
		}*/
		printf("Case %lld: %lld\n",cur,mx);
	}
}
/*
4 7
ABKLMXY
CIJNOVZ
FDHPQUZ
EGZRSTA
 *
 */
