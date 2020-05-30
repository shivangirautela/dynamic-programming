#include <iostream> 
#include<vector>    
using namespace std;
void display (vector <int> &arr, int idx)
{
     if(idx==arr.size())
     return ;
     cout<<arr[idx];
     display(arr,idx+1);     
}
bool find(vector <int> &arr,int idx,int data)
{
     if(idx==arr.size())
     return false;
     if(arr[idx]==data)
     return true;

     return find(arr,idx+1,data);
}
int main(int args,char** argv)
{
     int n;
     cin>>n;
    vector<int> a(n);
    for(int i=0;i<=a.size();i++)
    {
         cin>>a[i];
    }
    for(int i=0;i<=a.size();i++)
    display(a,i);

    if(find(a,0,5)==0)
    cout<<"element not found";
    else
    {
         cout<<"element found at index";
    }

    return 0;
}
    
