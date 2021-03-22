# include<bits/stdc++.h>
using namespace std;

const int N=100010;
int m;
int e[N],l[N],r[N],idx;
void insert(int a,int x){ //在节点a的右边插入一个数x
    e[idx]=x;
    l[idx]=a,r[idx]=r[a];
    l[r[a]]=idx,r[a]=idx++;
}

void remove(int a){
    l[r[a]]=l[a];
    r[l[a]]=r[a];
}

int main(){
    cin>>m;
    r[0]=1;
    l[1]=0;
    idx=2;
    while(m--){
        string op;
        cin>>op;
        int k,x;
        if(op[0]=='L') {
            cin>>x;
            insert(0,x);
        }
        else if(op[0]=='R'){
            cin>>x;
            insert(l[1],x);
        }
        else if(op[0]=='D'){
            cin>>x;
            remove(x+1);
        }
        else if(op[0]=='I'){
            if(op[1]=='L'){
                cin>>k>>x;
                insert(l[k+1],x);
            }
            else {
                cin>>k>>x;
                insert(k+1,x);
            }
        }
    }

for(int i=r[0];i!=1;i=r[i]) cout<<e[i]<<' ';
cout<<endl;

    return 0;
}