#include <stdio.h>
#include <list>
#include <iostream>

using namespace std;

void create(){
  freopen("fi.in", "w", stdout);
  printf("1\n-1\n0\n");
}

int main()
{
 //   create();
    while(true){
    list<long> l;
    long size = 0;
    list<long>::iterator med = --l.begin();
      while(true){
        long temp;
        if(scanf("%ld",&temp) == EOF) return 0;
        if(temp == 0) break;
        if(temp != -1){
          l.push_back(temp);
          size++;
          if(size % 2 == 1)
            med++;
        }else{
            list<long>::iterator tempit = med--;
            size--;
            printf("%ld\n", *tempit);
            l.erase(tempit);
            if(size % 2 == 1)
              med++;
          }
      }
      printf("\n");
      char c;
    }
    return 0;
}
