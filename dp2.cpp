#include <iostream>
#include <vector>
#include<list>
#define vi vector<int>
#define vii vector<vi>
#define vb vector<bool>
#define vbb vector<vb>
using namespace std;
void display(vi &dp)
{
    for (int ele : dp)
        cout << ele << " ";
    cout << endl;
}
void display2D(vii &dp)
{
    for (vi &ar : dp)
    {
        for (int &ele : ar)
            cout << ele << " ";
        cout << endl;
    }
    cout << endl;
}
//set01.============================================================
int fibo_01(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        dp[n] = n;
        return n;
    }
    if (dp[n] != 0)
        return dp[n];
    int ans = fibo_01(n - 1, dp) + fibo_01(n - 2, dp);
    dp[n] = ans; // dp will on and off.
    return ans;
}
int fibo_02(int n, vector<int> &dp)
{
    for (int i = 0; i <= n; i++)
    {
        if (i <= 1)
        {
            dp[i] = i;
            continue;
        }
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
int mazePathHV_01(int sr, int sc, int er, int ec, vii &dp)
{
    if (sr == er && sc == ec)
    {
        dp[sr][sc] = 1;
        return 1;
    }
    int count = 0;
    if (dp[sr][sc] != 0)
        return dp[sr][sc];
    if (er == ec && dp[sc][sr] != 0)
        return dp[sc][sr];
    if (sr + 1 <= er)
        count += mazePathHV_01(sr + 1, sc, er, ec, dp);
    if (sc + 1 <= ec)
        count += mazePathHV_01(sr, sc + 1, er, ec, dp);
    if (sc + 1 <= ec && sr + 1 <= er)
        count += mazePathHV_01(sr + 1, sc + 1, er, ec, dp);
    dp[sr][sc] = count;
    if (er == ec)
        dp[sc][sr] = count;
    return count;
}
int mazePathHV_02(int er, int ec, vii &dp)
{
    for (int sr = er; sr >= 0; sr--)
    {
        for (int sc = ec; sc >= 0; sc--)
        {
            if (sr == er && sc == ec)
            {
                dp[sr][sc] = 1;
                continue;
            }
            int count = 0;
            if (sr + 1 <= er)
                count += dp[sr + 1][sc];
            if (sc + 1 <= ec)
                count += dp[sr][sc + 1];
            if (sc + 1 <= ec && sr + 1 <= er)
                count += dp[sr + 1][sc + 1];
            dp[sr][sc] = count;
        }
    }
    return dp[0][0];
}
int mazePathMulti_01(int sr, int sc, int er, int ec, vii &dp)
{
    if (sr == er && sc == ec)
    {
        dp[sr][sc] = 1;
        return 1;
    }
    if (dp[sr][sc] != 0)
        return dp[sr][sc];
    int count = 0;
    for (int jump = 1; sr + jump <= er; jump++)
        count += mazePathMulti_01(sr + jump, sc, er, ec, dp);
    for (int jump = 1; sc + jump <= ec; jump++)
        count += mazePathMulti_01(sr, sc + jump, er, ec, dp);
    for (int jump = 1; sr + jump <= er && sc + jump <= ec; jump++)
        count += mazePathMulti_01(sr + jump, sc + jump, er, ec, dp);
    dp[sr][sc] = count;
    return count;
}
int mazePathMulti_02(int er, int ec, vii &dp)
{
    for (int sr = er; sr >= 0; sr--)
    {
        for (int sc = ec; sc >= 0; sc--)
        {
            if (sr == er && sc == ec)
            {
                dp[sr][sc] = 1;
                continue;
            }
            int count = 0;
            for (int jump = 1; sr + jump <= er; jump++)
                count += dp[sr + jump][sc];
            for (int jump = 1; sc + jump <= ec; jump++)
                count += dp[sr][sc + jump];
            for (int jump = 1; sr + jump <= er && sc + jump <= ec; jump++)
                count += dp[sr + jump][sc + jump];
            dp[sr][sc] = count;
        }
    }
    return dp[0][0];
}
int boardPath_01(int st, int end, vector<int> &dp)
{
    if (st == end)
    {
        dp[st] = 1;
        return 1;
    }
    if (dp[st] != 0)
        return dp[st];
    int count = 0;
    for (int dice = 1; dice <= 6 && st + dice <= end; dice++)
    {
        count += boardPath_01(st + dice, end, dp);
    }
    dp[st] = count;
    return count;
}
int boardPath_02(int st, int end, vector<int> &dp)
{   for (int i = end; i >= st; i--)
    {
        if (i == end)
        {
            dp[i] = 1;
            continue;
        }
        int count = 0;
        for (int dice = 1; dice <= 6 && i + dice <= end; dice++)
        {
            count += dp[i + dice];
        }
        dp[i] = count;
    }
    return dp[0];
}
int boardPath_01_giveOutcomes(int st, int end, vector<int> &outcomes, vector<int> &dp)
{
    if (st == end)
    {
        dp[st] = 1;
        return 1;
    }
    if (dp[st] != 0)
        return dp[st];
    int count = 0;
    for (int i = 0; i < outcomes.size(); i++)
    {
        if (st + outcomes[i] <= end)
            count += boardPath_01_giveOutcomes(st + outcomes[i], end, outcomes, dp);
    }
    dp[st] = count;
    return count;
}
int boardPath_02_giveOutcomes(int stP, int end, vector<int> &outcomes, vector<int> &dp)
{
    for (int st = end; st >= stP; st--)
    {
        if (st == end)
        {
            dp[st] = 1;
            continue;
        }
        int count = 0;
        for (int i = 0; i < outcomes.size(); i++)
        {
            if (st + outcomes[i] <= end)
                count += dp[st + outcomes[i]];
        }
        dp[st] = count;
    }
    return dp[0];
}
//set02.=========================================================
//leetode 70
int climbStairs(int n)
{
    if (n <= 1)
        return 1;
    int a = 1, b = 1, ans = 0;
    for (int i = 2; i <= n; i++)
    {
        ans = a + b;
        a = b;
        b = ans;
    }
    return ans;
}
// leetcode 746
int minCostClimbingStairs_01(int n, vector<int> &cost, vector<int> &dp)
{
    if (n <= 1)
        return cost[n];
    if (dp[n] != 0)
        return dp[n];
    int c1 = minCostClimbingStairs_01(n - 1, cost, dp);
    int c2 = minCostClimbingStairs_01(n - 2, cost, dp);
    return dp[n] = min(c1, c2) + cost[n];
}
int minCostClimbingStairs(vector<int> &cost)
{
    cost.push_back(0);
    int n = cost.size();
    vector<int> dp(n, 0);
    return minCostClimbingStairs_01(n - 1, cost, dp);
}

int minCostClimbingStairs_02(int n, vector<int> &cost, vector<int> &dp)
{
    for (int i = 0; i <= n; i++)
    {
        if (i <= 1)
        {
            dp[i] = cost[i];
            continue;
        }
        int c1 = dp[i - 1];
        int c2 = dp[i - 2];
        dp[i] = min(c1, c2) + cost[i];
    }
    return dp[n];
}
int minCostClimbingStairs_03(vector<int> &cost)
{
    if (cost.size() == 1)
        return cost[0];
    if (cost.size() == 2)
        return min(cost[0], cost[1]);
    int a = cost[0];
    int b = cost[1];
    for (int i = 2; i < cost.size(); i++)
    {
        int ans = cost[i] + min(a, b);
        a = b;
        b = ans;
    }
    return min(a, b);
}
int minPathSum(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (i == n - 1 && j == m - 1)
            {
                continue;
            }
            int c1 = j + 1 < m ? arr[i][j + 1] : 1e6;
            int c2 = i + 1 < n ? arr[i + 1][j] : 1e6;
            int minCost = min(c1, c2);
            arr[i][j] += minCost;
        }
    }
    return arr[0][0];
}
//set2==============================================================
int friendsproblem(int n)
{
    if(n<=2)
    return n;
   int c=0;      //simple recursion 
   c+=friendsproblem(n-1);
   c+=(n-1) * friendsproblem(n-2);
   return c;
}
int friendsproblem_01(int n,vi &dp)
{
    if(n<=1)
    {  // simple memoizarion
    dp[n]=1;
    return 1;
    }
    if(dp[n]!=0)
    return dp[n];
   
   int singleways=friendsproblem_01(n-1,dp);
   int pairways=  friendsproblem_01(n-2,dp) *(n-1);
   
   dp[n]=singleways+pairways;
   return dp[n];
}
int friendsproblem_02(int n,vi &dp)
{
  for(int i=0;i<=n;i++)  //tabulation
  {
    if(i<=1)
    {
    dp[i]=1;
    continue;
    }

   int singleways=dp[i-1];
   int pairways= dp[i-2] *(i-1);
   
   dp[i]=singleways+pairways;
  }
  return dp[n];
}
int friendsproblem_03(int n)
{
    //making solution easy to code using less space
    if(n<=1)
    {
    return 1;
    }
    int a=1;
    int b=1;
    int ans=0;
    
    for(int i=2;i<=n;i++)
    {
        ans=b+ a*(i-1);
        a=b;
        b=ans;
    }
    return ans;
}
int minjumps_01(int idx,vi & nums,vi& dp)
{
    if(idx == nums.size()-1)  
      return 0;

    // if(nums[idx]==0)
    // return (int)1e7;
    
    if(dp[idx]!=0)
       return dp[idx];
    
    int minans=(int)1e7;
    for(int jump=1;jump<= nums[idx] && idx+jump< nums.size();jump++)
    {
        int minjumps=minjumps_01(idx+jump,nums,dp);
        if(minjumps!=(int)1e6 && minjumps+1<minans)
        {
            minans=minjumps+1;
        }
    }
    dp[idx]=minans;
    return dp[idx];
}
int minjumps_02(vi & nums)  //tabulation
{
    vi dp(nums.size(),0);
 for(int idx=0;idx<nums.size();idx++)
 {
    if(idx == nums.size()-1)  
      {
          dp[idx]=0;
          continue;
      }

    // if(nums[idx]==0)
    // return (int)1e7;
    int minans=(int)1e7;
    for(int jump=1;jump<= nums[idx] && idx+jump< nums.size();jump++)
    {
        int minjumps=dp[idx+jump];
        if(minjumps!=(int)1e6 && minjumps+1<minans)
        {
            minans=minjumps+1;
        }
    }
    dp[idx]=minans;
 }
    return dp[nums.size()-1];
}
int jump(vi& nums)
{
    vi dp(nums.size(),0);
  //  cout<<minjumps_01(0,nums,dp)<<endl;
  cout<<minjumps_02(nums)<<endl;
    display(dp);
}
int tilesproblem(int n,int m,vi &dp)
{
    if(n<=m)
    {
        return dp[n]= (n==m) ? 2: 1;
    }

    if(dp[n]!=0)
    return dp[n];

    int horzontal=tilesproblem(n-1,m,dp);
    int vertival=tilesproblem(n-m,m,dp);

    dp[n]=horzontal+vertival;

    return dp[n];
}
int tilesproblem_01(int n,int m,vi &dp)
{
  for(int i=0;i<=n;i++)
  {  
    if(i<=m)
    {
        dp[i] = ((i==m) ?2:1);
        continue;
    }

    int horzontal=dp[i-1];
    int vertival=dp[i-m];

    dp[i]=horzontal+vertival;
  }
    return dp[n];  
}
int tilesproblem_02(int n,int m)
{
   if(n<=m)
      return ((n==m) ? 2: 1);
    list<int> ll;
    for(int i=1;i<=m;i++)
    {
        ll.push_back(1);
    }
    for(int i=m;i<=n;i++)
    {
        int horizontal=ll.back();
        int vertical=ll.front();

        ll.push_back(horizontal+vertical);
        ll.pop_back();
    }
    return ll.back();
}
int maxsqans=0;
int maxsqrof1s(vii &m,int r,int c,vii& dp)
{
    if(r==m.size() || c==m[0].size())
      return 0;
    
    if(dp[r][c]!=-1)
    return dp[r][c];

    int down=maxsqrof1s(m,r+1,c,dp);
    int diag=maxsqrof1s(m,r+1,c+1,dp);
    int right=maxsqrof1s(m,r,c+1,dp);

    int minpossiblesqr=0;
    if(m[r][c]==1)
      minpossiblesqr= min(down,min(diag,right))+1;

    dp[r][c]=minpossiblesqr;
    maxsqans=max(dp[r][c],maxsqans);

    return dp[r][c];
}
int maxsubmatrix(vii &m,vii &dp)
{
  ///  vii dp(m.size(),vi (m[0].size(),-1));
    int maxsq=0;
    for(int r=m.size()-1;r>=0;r--)
    {
        for(int c=m[0].size()-1;c>=0;c--)
        {
               if(m[r][c]==1)
               dp[r][c]= min(dp[r+1][c],min(dp[r+1][c+1],dp[r][c+1]))+1;
               else
               dp[r][c]=0;
               maxsq=max(dp[r][c],maxsq);             
        }
    }
    return maxsq;
}
int coin_change_permutation_dp(vector<int> &arr,int tar,vi& dp)
{
        if(tar==0)
        {   
            dp[tar]=1;
            return 1;
        }
        if(dp[tar]!=0)
        return dp[tar];
    int c=0;
    for(int i=0;i<arr.size();i++){
        if(tar-arr[i]>=0)
        c+=coin_change_permutation_dp(arr,tar-arr[i],dp);
    }
    dp[tar]=c;
    return c;
}
int coin_change_permutation_tabulation(vector<int> &arr,int target,vi& dp)
{
    dp[0]=1;
    int c=0;
    for(int tar=1;tar<=target;tar++)
    {
          for(int i=0;i<arr.size();i++)
          {
             if(tar-arr[i]>=0)
             dp[tar] += dp[tar-arr[i]];
          }
    }
    return dp[target];
}
/*
int coin_change_combination_dp(vector<int> &arr,int target,vi& dp)
{
   
   if(arr.size()==0)
   return 1;

    int c=0;
            for(int tar=1;tar<=target;tar++)
             {
                if(tar-arr[i]>=0)
                c +=coin_change_combination_dp(arr,tar-arr[i],dp);
             }
        }
    return dp[target];
}*/
int coin_change_combination_tabulation(vector<int> &arr,int target,vi& dp)
{
    dp[0]=1;
    int c=0;
        for(int i=0;i<arr.size();i++)
        {
            for(int tar=1;tar<=target;tar++)
             {
                if(tar-arr[i]>=0)
                dp[tar] += dp[tar-arr[i]];
             }
        }
    return dp[target];
}
vii dirarr={{0,1},{-1,1},{1,1}};
int goldmine_01(int x,int y,vii &arr,vii& dp)
{
    if(y==arr[0].size())
    {
        dp[x][y]=arr[x][y];  
        return arr[x][y];
    }
    if(dp[x][y]!=0)
    return dp[x][y];

    int maxans=-1e6;

    for(int d=0;d<3;d++)
    {
        int r=x+dirarr[d][0];
        int c=y+dirarr[d][1];

        if(r>=0 &&c>=0 && r<arr.size() && c<arr[0].size())
           maxans=max(maxans,goldmine_01(r,c,arr,dp));
    }
    dp[x][y]=maxans+arr[x][y];
    return dp[x][y];
}
int goldMine_02(vii &arr, vii &dp)
{
    for (int y = arr[0].size() - 1; y >= 0; y--)
    {
        for (int x = arr.size() - 1; x >= 0; x--)
        {
            if (y == arr[0].size() - 1)
            {
                dp[x][y] = arr[x][y];
                continue;
            }
            int maxAns = -1e6;
            for (int d = 0; d < 3; d++)
            {
                int r = x + dirarr[d][0];
                int c = y + dirarr[d][1];
                if (r >= 0 && c >= 0 && r < arr.size() && c < arr[0].size())
                    maxAns = max(maxAns, dp[r][c]);
            }
            dp[x][y] = maxAns + arr[x][y];
        }
    }
    int maxAns = -1e6;
    for (int row = 0; row < arr.size(); row++)
    {
        maxAns = max(maxAns, dp[row][0]);
    }
    return maxAns;
}
int goldmine()
{
     vii arr = {{1, 3, 3},
               {2, 1, 4},
               {0, 6, 4}};
    vii dp(arr.size(), vi(arr[0].size(), 0));
    // int maxAns = -1e6;
    // for (int row = 0; row < arr.size(); row++)
    // {
    //     maxAns = max(maxAns, goldMine_01(row, 0, arr, dp));
    // }
    // cout << maxAns << endl;
    cout << goldMine_02(arr, dp) << endl;
    display2D(dp);
}
int divideInKGroups(int n, int k, vii &dp)
{
    if (n < k)
        return 0;
    if (n == k || k == 1)
    {
        dp[n][k] = 1;
        return 1;
    }
    if (dp[n][k] != 0)
        return dp[n][k];
    int startingOfNewSet = divideInKGroups(n - 1, k - 1, dp);
    int totalGroups = divideInKGroups(n - 1, k, dp); // n-1, number will divide in k sets and generate some x group.
    int totalSets = totalGroups * k; //total set avilable for me.
    dp[n][k] = startingOfNewSet + totalSets;
    return dp[n][k];
}
int divideInKGroups_02(int n, int k, vii &dp)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i < j)
            {
                dp[i][j] = 0;
                continue;
            }
            if (i == j || j == 1)
            {
                dp[i][j] = 1;
                continue;
            }
            int startingOfNewSet = dp[i - 1][j - 1];
            int totalGroups = dp[i - 1][j]; // n-1, number will divide in k sets and generate some x group.
            int totalSets = totalGroups * j; //total set avilable for me.
            dp[i][j] = startingOfNewSet + totalSets;
        }
    }
    return dp[n][k];
}
//leetcode 377
int combinationSum4(vector<int> &nums, int target) //same as permuation
{
    vector<unsigned int> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= target; i++)
    {
        for (int coin : nums)
        {
            if (i - coin >= 0)
                dp[i] += dp[i - coin];
        }
    }
    return dp[target];
}
//leetcode 322
int minCoinsHeight(vector<int> &arr, int tar, vector<int> &dp)
{
    if (tar == 0)
        return 0;
    if (dp[tar] != 0)
        return dp[tar];
    int height = 1e8;
    for (int i = 0; i < arr.size(); i++)
    {
        if (tar - arr[i] >= 0)
        {
            int recAns = minCoinsHeight(arr, tar - arr[i], dp);
            if (recAns < height)
                height = recAns + 1;
        }
    }
    dp[tar] = height;
    return height;
}
int minCoinsHeight_dp(vector<int> &arr, int tar, vector<int> &dp)
{
    // for (int i = 0;i < dp.size(); i++)
    //     dp[i] = 1e8;
    dp[0] = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int t = 1; t <= tar; t++)
        {
            if (t - arr[i] >= 0)
            {
                dp[t] = min(dp[t], dp[t - arr[i]] + 1);
            }
        }
    }
    return dp[tar];
}

int mincosttarget(vector<int> &arr, int tar)
{
    if (arr.size() == 0 || tar <= 0)
        return 0;
    vector<int> dp(tar + 1, 1e8); // Arrays.fill(dp,(int)1e8);
    // int ans = minCoinsHeight(arr, tar, dp);
    int ans = minCoinsHeight_dp(arr, tar, dp);
    return ans != 1e8 ? ans : -1;
}
int targetsum(vi &arr,int tar,vii &dp,int idx)
{
     if (tar == 0 || idx < 0)
    {
        return tar == 0 ? 1 : 0;
    }

    if(dp[idx][tar]!= 0)
     return dp[idx][tar];

    int count=0;
         if(tar-arr[idx]>=0)
             count+=  targetsum(arr,tar-arr[idx],dp,idx-1);
             count+=  targetsum(arr,tar,dp,idx-1);

     dp[idx][tar]=count;
    return count;
}
int targetsum_02(vi &arr,int tar,vii &dp)
{
   dp[0][0]=1;  //if append 0 at 0th index of coins array   
         for(int idx=1;idx<arr.size();idx++)
         {
              for(int t=0;t<=tar;t++)
              { 
                  if(t==0)
                  {
                    dp[idx][t]=1;
                    continue;
                   }
             if(t-arr[idx]>=0)
             dp[idx][t] += dp[idx-1][t-arr[idx]];

              dp[idx][t] += dp[idx-1][t];
 
        }
     }
    
    return dp[arr.size()-1][tar];
}
int knapsack(vi& weight,int cap,vi& cost,vii&dp,int idx)
{
    if(cap==0 || idx==weight.size())
    return 0;

    if(dp[idx][cap]!=0)
      return dp[idx][cap];

    int picked=0,unpicked=0;
    if(cap-weight[idx]>=0)
       picked+=knapsack(weight,cap-weight[idx],cost,dp,idx+1)+cost[idx];

    unpicked+=knapsack(weight,cap,cost,dp,idx+1);

    return dp[idx][cap]=max(picked,unpicked);
}
int knapsack_02(vi& weight,int cap,vi& cost)
{
     vii dp(weight.size()+1,vector<int> (cap+1,0));
  for(int idx=1;idx<dp.size();idx++)
  {   
      int weightidx=idx-1;
      for(int c=0;c<=cap;c++)
      {
            int picked=0,unpicked=0;
           if(c-weight[weightidx]>=0)
           picked = dp[idx-1][c-weight[weightidx]]+cost[weightidx];

           unpicked =dp[idx-1][c];
           dp[idx][c]=max(picked,unpicked);
      }
  }
  display2D(dp);
    return dp[dp.size()-1][dp[0].size()-1];
}
int unbounded_knapsack(vi& weight,int cap,vi& cost)
{
     vector<int> dp(cap+1,0);
     dp[0]=0;
  for(int idx=0;idx<weight.size();idx++)
  {   
      for(int c=1;c<=cap;c++)
      {
            int picked=0,unpicked=0;
           if(c-weight[idx]>=0)
           picked = dp[c-weight[idx]]+cost[idx];

           unpicked =dp[c];
           dp[c]=max(picked,unpicked);
      }
  }
    display(dp);
    return dp[cap];
}
//strings================================================
vbb ispalindromicsubstring(string str)
{
    int n=str.length();
    vbb dp(n,vb(n,false));
    for(int gap=0;gap<str.length();gap++)
    {
        for(int i=0,j=gap;j< str.length();i++,j++)
        {
            if(gap==0)
             dp[i][j]=true;
            else if(str[i]==str[j])
            {
                if(gap==1)
                dp[i][j]=true;
                else if(dp[i+1][j-1])
                {
                    dp[i][j]=true;
                }   
            }
        }
    }
    return dp;
}
int longestpalindromicsubstring(string str,vii &dp)
{
   vbb ispali=ispalindromicsubstring(str);
    int n=str.length();
    for(int gap=0;gap<str.length();gap++)
    {
        for(int i=0,j=gap;j< str.length();i++,j++)
        {
            if(gap==0)
             dp[i][j]=1;
            else if(str[i]==str[j])
            {
                if(gap==1)
                dp[i][j]=2;
                else if(ispali[i+1][j-1])
                {
                    dp[i][j] = dp[i+1][j-1]+2;
                }   
            }
            else
            {
                dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
            
        }
    }
    return dp[0][dp.size()-1];
}
int longetpalindromicsubsequence(string str,vii &dp)
{
 //  vbb ispali=ispalindromicsubstring(str);
    int n=str.length();
    for(int gap=0;gap<str.length();gap++)
    {
        for(int i=0,j=gap;j< str.length();i++,j++)
        {
            if(gap==0)
             dp[i][j]=1;
            else if(str[i]==str[j])
            {
              dp[i][j] = dp[i+1][j-1]+2;    
            }
            else
            {
                dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
        }
    }
    return dp[0][dp.size()-1];
}
int countofpalindromicsubsequence(string str,vii &dp)
{
 //  vbb ispali=ispalindromicsubstring(str);
    int n=str.length();
    for(int gap=0;gap<str.length();gap++)
    {
        for(int i=0,j=gap;j< str.length();i++,j++)
        {
            if(gap==0)
             dp[i][j]=1;
            else if(str[i]==str[j])
            {
              dp[i][j] += dp[i+1][j-1]+1; //when include both first and last characters cnsidered    
              dp[i][j] += dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];  //when we include only 1 charater from bith first and last chracter at a time.
              
            }
            else
            {
                 dp[i][j] =dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
            }
        }
    }
    return dp[0][dp.size()-1];
}
void stringquestions()
{
    string s="efabcbadd";
    int n=s.length();
    vbb jkp=ispalindromicsubstring(s);
    vii dp(n,vi(n,0));
    //cout<<longestpalindromicsubstring(s,dp)<<endl;
    //cout<<longetpalindromicsubsequence(s,dp)<<endl;
    cout<<countofpalindromicsubsequence(s,dp)<<endl;
    display2D(dp);
}
void targetsumtype()
{
    vi arr={0,2,3,5,7};
    int tar=10;
    //vii dp(arr.size(),vector<int> (tar+1,0));
    //cout<<targetsum(arr,tar,dp,arr.size()-1)<<endl;
    //cout<<targetsum_02(arr,tar,dp)<<endl;
    vi weight={2,5,1,3,4};
    vi cost={15,14,10,45,30};
    int cap=7;
    vii dp(weight.size()+1,vector<int> (cap+1,0));
    //cout<<knapsack(weight,cap,cost,dp,0)<<endl;
    //cout<<knapsack_02(weight,cap,cost)<<endl;
    cout<<unbounded_knapsack(weight,cap,cost)<<endl;
    
    //display2D(dp);
}
void coinchange()
{
    vector<int> arr={2,3,5,7};
    int tar=10;
    vector<int> dp(tar+1,0);
   // cout<<coin_change_permutation_dp(arr,tar,dp)<<endl;
   // cout<<coin_change_permutation_tabulation(arr,tar,dp)<<endl;
   cout<<coin_change_combination_tabulation(arr,tar,dp)<<endl;
   mincosttarget(arr,tar);
    display(dp);
}
void matrix()
{
    vii m={{1,1,1,1,0},
           {1,1,1,1,0},
           {1,1,1,1,0},
           {0,1,1,1,1},
           {0,1,1,1,1}};
    vii dp(m.size(),vi (m[0].size(),-1));
  cout<< maxsubmatrix(m,dp);
   display2D(dp);
  // maxsqrof1s(m,0,0,dp);
 //  cout<<maxsqans<<endl;
  // display2D(dp);
}
void set2()
{
    int n=7;
    int m=4;
    vi dp(n+1,0);
   // cout<<friendsproblem_01(n,dp)<<endl;
    //cout<<friendsproblem_02(n,dp)<<endl;
   // cout<<friendsproblem_03(n)<<endl;
   //vi nums={2,3,1,1,4};
   //jump(nums);
   // cout << divideInKGroups(n, m, dp) << endl;
    // cout << divideInKGroups_02(n, m, dp) << endl;
    // goldMine();
  // cout<<tilesproblem(n,m,dp)<<endl;
  // cout<<tilesproblem_01(n,m,dp)<<endl;
   cout<<tilesproblem_02(n,m)<<endl;
   display(dp);
}
void set1()
{
    int n = 10;
    // int m=3;
    vector<int> dp(n + 1, 0);
    // vii dp(n, vi(m, 0));
    // cout << fibo_01(n, dp) << endl;
    // cout << mazePathHV_01(0, 0, n - 1, n - 1, dp) << endl;
    // cout << mazePathHV_02(n - 1, n - 1, dp) << endl;
    // cout << mazePathMulti_01(0, 0, n - 1, n - 1, dp) << endl;
    // cout << mazePathMulti_02( n - 1, n - 1, dp) << endl;
    // cout << boardPath_01(0, n, dp) << endl;
    // cout << boardPath_02(0, n, dp) << endl;
    vi outcomes = {2, 3, 7, 5};
    // cout << boardPath_01_giveOutcomes(0, n, outcomes, dp) << endl;
    //cout << boardPath_02_giveOutcomes(0, n, outcomes, dp) << endl;
   // display(dp);
    // display2D(dp);
    //cout<<friendsproblem(5);
}

void solve()
{
    //matrix();
    //set1();
     // set2();
     //coinchange();
     //targetsumtype();
     stringquestions();
}
int main()
{
    solve();
    return 0;
}


   