#include<iostream>
#include<string>
using namespace std;
int countdecoding(char* input,int n)
{
    int dp[n+1];
    dp[0]=1;
    dp[1]=1;
    if(input[0]=='0')
    {
        return 0;
    }
    for(int i=2;i<=n;i++)
    {
        dp[i]=0;
        if(input[i-1]>'0')
        {
            dp[i]+=dp[i-1];
        }
        if(input[i-2]=='1'||(input[i-2]=='2' && input[i-1]<'7'))
        {
            dp[i]+=dp[i-2];
        }
    }
    return dp[n];
}
int main(int args,char** argv)
{
    int n,i;
    char* a;
    cin>>a;
    for(i=0;a[i]!='\0';i++);
    n=i;
    cout<<countdecoding(a,n);
}