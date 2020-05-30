#include<iostream>
using namespace std;
int functioncall=0;
string res=" ";
int mazepath(int sr,int sc,int er,int ec,string ans)
{
  functioncall++;
  if(sr==er && sc==ec)
  {
  //  cout<<ans;
    if(res.size()<ans.size())
    {
        res=ans;
    }
    return 0;
  }
  int count=0;
  if(sr+1<=er)
 {
  count+= mazepath(sr+1,sc,er,ec,ans+"V")+1;
 }
 if(sc+1<=ec)
 {
   count+= mazepath(sr,sc+1,er,ec,ans+"H")+1;
 }
 if(sr+1<=er &&sc+1<=ec)
 {
    count+= mazepath(sr+1,sc+1,er,ec,ans+"D");
 }
 cout<<" ";
 return count;
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