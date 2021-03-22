#include<iostream>
using namespace std;
int main()
{
  int n;  
  cin>>n;   //反转之前的数
  if(n<0) {
      cout<<"-";
      n=-n;
      }  
  int sum=0;    
  while(n!=0)
  {
    int k=n%10;
    sum=sum*10+k;
    n=n/10;  
}
  cout<<sum<<endl;
  return 0;
}