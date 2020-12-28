#include <iostream>
#include <queue>
#include <stdio.h>
#define pll pair<long,long>
#define F first
#define S second
#define mk make_pair

using namespace std;

long fl, st, goal, up, down;

long BFS(){
    bool* visit = new bool [fl+10] ();
    long* lysh = new long [fl+10] ();
    queue<pll> Q;
    pll temp = mk(st,0);
    Q.push(temp);

    while(!Q.empty() && !visit[goal]){
        pll top = Q.front(),temp1,temp2;
        Q.pop();
        if(!visit[top.F]){
            visit[top.F] = true;
            lysh[top.F] = top.S;
            if(top.F > down)
                if(!visit[top.F - down])
                    Q.push(mk(top.F - down, top.S+1));
            if(top.F + up <= fl)
                if(!visit[top.F + up])
                    Q.push(mk(top.F + up, top.S+1));
        }
    }
    if(lysh[goal] != 0)
        return lysh[goal];
    if(goal == st)
        return 0;
    return -1;
}

int main()
{
    scanf("%ld%ld%ld%ld%ld",&fl,&st,&goal,&up, &down);
    long lysh = BFS();
    if(lysh != -1)
        printf("%ld\n",lysh);
    else
        printf("use the stairs\n");
    return 0;
}
