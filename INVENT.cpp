#include <iostream>
#include <algorithm>
#define MAXN 16000
using namespace std;

long long n,m;

long long A[MAXN], num[MAXN];

struct edge{
    long long a,b,w;
    bool operator <(const edge &A)const{
        return w < A.w;
    }
};

long long find(long long a){
    if(A[a] != a)
        A[a] = find( A[a] );
    return A[a];
}


void unionf(long long v, long long u){
    long long vpos = find(v);
    long long upos = find(u);
    if(vpos != upos){
   //     cout << "Uniting " << vpos << " " << upos << endl;
   //     cout << "Num " << num[vpos] << " " << num[upos] << endl;
        A[vpos] = upos;
        num[upos] += num[vpos];
    }
}

long long specialKruskal(edge* edges){
    long long cost = 0;
    for(long long i = 0; i < n-1; i++){
        edge temp = edges[i];
        long long apos = find(temp.a);
        long long bpos = find(temp.b);
   //         cout << temp.a << " " << temp.b << endl;
   //         cout << temp.w << endl;
            cost += temp.w;
            cost += ((num[apos] * num[bpos]) - 1)*(temp.w+1);
    //1        cout << cost << endl;
            unionf(temp.a,temp.b);
    }
    return cost;
}

int main()
{
    long long t;
    cin >> t;
    for(long long j = 0; j < t; j++){
    long long a,b,w;
    cin >> n;
    edge edges[15100];
    for(long long i = 0; i < n-1; i++){
        cin >> a >> b >> w;
        edge temp = {a, b, w};
        edges[i] = temp;
    }
    for(long long i = 1; i <= n+1; i++){
        A[i] = i;
        num[i] = 1;
    }
    sort(edges, edges+n-1);
    cout << specialKruskal(edges) << endl;
    }
    return 0;
}
