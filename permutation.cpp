#include<iostream>
using namespace std;

int permutation(string str,string ans)
{
  if(str.size()==0)
  {
      cout<<ans<<" ";
      return 1;
  }
  int count =0;
  bool arr[26]={0};
  for(int i=0;i<str.size();i++)
  {
      char ch=str[i];
     if(arr[ch-'a']==false) { 
      string one=str.substr(0,i);
      string two=str.substr(i+1);
      count+= permutation(one+two,ans+ch);
      arr[ch-'a']=true;
      }
  }
  return count;
}

  int main(int args,char** argv)
{
cout<<permutation("abc"," ");
}
