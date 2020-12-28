#include <stdio.h>

using namespace std;

long A[30000], B[30000];

int main()
{
  long nA, nB;
  while(scanf("%ld",&nA) && nA != 0){
    for(long i = 0; i < nA; i++){
      scanf("%ld",&A[i]);
    }
    scanf("%ld",&nB);
    for(long i = 0; i < nB; i++){
      scanf("%ld",&B[i]);
    }
    long curA = 0, curB = 0, sumA = 0, sumB = 0, lysh = 0;
    while(curA < nA && curB < nB){
      if(A[curA] < B[curB]){
        sumA += A[curA];curA++;
      }
      else if(A[curA] > B[curB]){
        sumB += B[curB];curB++;
      }
      else{
        lysh += A[curA];curA++;curB++;
        lysh += sumA > sumB ? sumA : sumB;
        sumA = 0; sumB = 0;
      }
    }
    while(curA < nA){
      sumA += A[curA++];
    }
    while(curB < nB){
      sumB += B[curB++];
    }
    lysh += sumA > sumB ? sumA : sumB;
    printf("%ld\n",lysh);
  }

  return 0;
}
