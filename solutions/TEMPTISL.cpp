#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k) && n != -1){
        int a,b;
        scanf("%d%d",&a,&b);
        long long A[51][51] {};
        A[0][a-1] = 1;
        for(long i = 1; i <= k; i++){
            for(long j = 0; j < n;j++){
   //             for(long y = 0; y <= k; y++){
    //                for(long l = 0; l < n; l++)
     //                   cout << A[y][l] << " ";
     //               cout << endl;
   //             }
     //           cout << endl << endl;
                long cola,colb;
                cola = (j-1)%n;
                if(cola == -1)
                    cola += n;
                colb = (j+1) % n;
                A[i][j] = A[i-1][cola] + A[i-1][colb];
            }
        }
        printf("%lld\n",A[k][b-1]);
    }
    return 0;
}
