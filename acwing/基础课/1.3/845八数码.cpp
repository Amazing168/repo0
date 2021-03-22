#include<bits/stdc++.h>
using namespace std;
int bfs(string start ){
    queue <string> q;
    unordered_map<string ,int> d;//哈希表存搜的距离
    q.push (start);
    d[start] =0;
    int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
    string end="12345678x";
    while(q.size()){
        auto t=q.front();
        q.pop();
        if(t==end) return d[t];
        int dist =d[t];
        int k=t.find('x');
        int x=k/3,y=k%3;//确定位置
        for(int i=0;i<4;i++){//枚举四个方向
            int a=x+dx[i],b=y+dy[i];
            if(a>=0&&a<3&&b>=0&&b<3){
                swap(t[k],t[a*3+b]);
            if(!d.count(t)){//表示d目前中无人t
                d[t]=dist+1;
                q.push(t);
            }
            swap(t[k],t[a*3+b]);
            
            }
        }
    }
    return -1;
}
int main(){
    char s[2];
    string start;
    for(int i=0;i<9;i++) {
        cin>>s;
        start +=s;
    }
    cout<<bfs(start)<<endl;

    return 0;
}