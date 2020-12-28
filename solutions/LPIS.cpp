#include <iostream>
#include <stdio.h>

using namespace std;

typedef int ll;

ll n;
ll A[1000010] = {};
ll mx;

int main()
{
    scanf("%d", &n);
    while(n--){
      ll t;
      scanf("%d", &t);
      A[t] = A[t - 1] + 1;
      mx = mx > A[t] ? mx : A[t];
    }
    printf("%d", mx);
    return 0;
}
