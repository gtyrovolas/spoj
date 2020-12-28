#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
    long long n;
    while(cin >> n && n != 0){
    long long A[n+10], maxarea = 0;
    A[0] = 0;
    stack<long long> k;
    for(long long i = 1; i <= n; i++){
        cin >> A[i];
    }
    k.push(0);
    for(long long i = 1; i <= n;){
        if(A[i] > A[k.top()]){
            k.push(i);
            i++;
        }else if (A[i] < A[k.top()]){
            long long temp = k.top();
            k.pop();
            maxarea = max(maxarea, (i -1 -k.top()) * A[temp]);
        }else{
            k.pop();
            k.push(i);
            i++;
        }
    }
    while(A[k.top()] != 0){
        long long temp = k.top();
        k.pop();
        maxarea = max(maxarea, (n - k.top()) * A[temp]);
    }
    cout << maxarea << endl;
    }
    return 0;
}
