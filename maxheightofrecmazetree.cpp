#include<iostream>
using namespace std;
int functioncall=0;
string res=" ";
int mazepath(int sr,int sc,int er,int ec,string ans)
{
  functioncall++;
  if(sr==er && sc==ec)
  {
    if(res.size()<ans.size())
    {
        res=ans;
        cout<<ans;
    }
    return 0;
  }
  int lefth=0,righth=0,diagnolh=0;
  int count=0;
  if(sr+1<=er)
 {
  lefth += mazepath(sr+1,sc,er,ec,ans+"V");
 }
 if(sc+1<=ec)
 {
   righth += mazepath(sr,sc+1,er,ec,ans+"H");
 }
 if(sr+1<=er &&sc+1<=ec)
 {
    diagnolh += mazepath(sr+1,sc+1,er,ec,ans+"D");
 }
 cout<<" ";
 return max(max(lefth,righth),diagnolh)+1;
}

int main(int args,char** argv)
{
  string ans=" ";
  cout<<mazepath(0,0,2,2,ans);
cout<<endl;
cout<<" no of function calss in mazepath problem:"<<functioncall<<endl;
cout<<"height of each end node in the trace of recursion tree diagram of mazepath_multimoves problem:"<<endl;
cout<<" and maximum height from it :"<<endl;
}