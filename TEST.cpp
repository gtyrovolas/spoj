#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    short cur;
    while(cin >> cur && cur != 42){
        printf("%d\n", cur);
    }
    return 0;
}
