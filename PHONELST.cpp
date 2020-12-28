#include <iostream>
#include <cstring>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

void create(){
    freopen("test.in","w",stdout);
    cout << 40 << endl;
    for(long i = 0; i < 40; i++){
      cout << 10000 << endl;
      for(long j = 0; j < 10000; j++){
        cout << 1000 + j << endl;
      }
    }
}

struct trie{
    long next[13];
    bool isWord;
};

long n,t, top = 1;
vector<trie> tries;

bool ins(char* q, long size){
    bool ne = 0;
    long cur = 0;
    for(long i = 0; i < size; i++){
   //   cout << q[i] << " ";
      if(tries[cur].next[q[i] - '0'] == 0){
        ne = 1;
        tries[cur].next[q[i] - '0'] = top;
        cur = top;
        top++;
        trie temp = {};
        tries.push_back(temp);
      }
      else{
        cur = tries[cur].next[q[i] - '0'];
      }
      if(tries[cur].isWord) return 0;
    }
    tries[cur].isWord = 1;
    if(!ne) return 0;
    return 1;
}


int main()
{
    #define TES
    #ifdef TEST
    freopen("phone.in","r",stdin);
    #endif // TEST
    scanf("%ld",&t);
    for(long i = 0; i < t; i++){
      top = 1;
      scanf("%ld",&n);
      tries.resize(0);
      trie tempT = {}; tries.push_back(tempT);
      bool found = 1;
      for(long j = 0; j < n; j++){
        char temp[15];
        scanf("%s",temp);
        if(found){
          found = ins(temp,strlen(temp));
    //       cout << endl;
        }
      }

      if(found) printf("YES\n");
      else printf("NO\n");
    }
    return 0;
}
