#include <stdio.h>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

long gcd(long m, long n){
    while (n != 0)
	{
	  long t = m % n;
	  m = n;
	  n = t;
	}
    return m;
}

int main()
{
    long t;
    double temp;
    scanf("%d",&t);
    for(long i = 0; i < t; i++){
        scanf("%lf",&temp);
        temp -= trunc(temp);
        temp *= 10000;
        long int cur = round(temp);
        long ans = gcd(cur, 10000);
        printf("%ld\n", 10000/ans);
    }
    return 0;
}
