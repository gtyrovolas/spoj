#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long k;
    scanf("%ld", &k);
    for(long y = 0; y < k; y++){
    long n, m, temp, maxnum = 0;
    bool found = false;
    scanf("%ld %ld", &n, &m);
    for(long i = 0; i < n; i++){
        scanf("%ld", &temp);
        maxnum = max(maxnum, temp);
    }for(long j = 0; j < m; j++){
        scanf("%ld", &temp);
        if(temp > maxnum)
            found = true;
    }
    if(found)
        printf("MechaGodzilla\n");
    else
        printf("Godzilla\n");
    }
    return 0;
}
