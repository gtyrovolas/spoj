#include <iostream>

using namespace std;

int main()
{
    long a, b;
    while(cin >> a >> b){
      if(a == -1) return 0;
      long lysh = (a*b-1)*38 + 52;
      lysh += a*b*13;
      if(a == 1 || b == 1){
        lysh += (max(a,b)-1) * 38;
      }else if(a % 2 == 0 || b % 2 == 0){
        lysh += 38;
      }
      else{
        lysh += 2*38;
      }
      cout << lysh << endl;
    }
    return 0;
}
