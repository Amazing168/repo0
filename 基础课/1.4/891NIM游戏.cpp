/*
最裸的博弈论，
简单nim问题
所有堆的石子数异或起来，为1则先手必胜，为0则先手必败

*/


#include<bits/stdc++.h>
using namespace std;
int main(){

    int n,res=0;
    scanf("%d",&n);
    while(n--){
        int x;
        scanf("%d",&x);
        res^=x;
    } 
    if(res)puts("Yes");
    else puts("No");
    return 0;
}