# include<bits/stdc++.h>
using namespace std;
int main(){

    string s;
    getline(cin,s);
   // cout<<"_____"<<endl;
//   cout<<s[3];
    for(int i=0;i<s.size();i++){
        if(s[i]>='A'&&s[i]<='Z') {
            s[i]-=5;
            if(s[i]<'A') s[i]+=26;
        }
        //cout<<"_____"<<endl;
    }
    for(int i=0;i<s.size();i++){cout<<s[i];}
//     int t;
//     cin>>t;
//     while(t--){
//     char a;
//     cin>>a ;
//     if(){
//         a-=5;
//         if(a<'A')a+=26;
//     }
//     cout<<(int)a<<endl;
//     printf("%c\n",a);
// }

    return 0;
}