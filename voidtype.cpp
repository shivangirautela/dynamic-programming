#include<iostream>
#include<vector>
using namespace std;
//sunsequence=======================================================================================
int subsequence(string str,string ans)
{
  if(str.size()==0)
  {
      cout<<ans<<" ";
      return 1;
  }
  char ch=str[0];
  string roq=str.substr(1);
  int count =0;
  count+= subsequence(roq,ans+ch);
  count+= subsequence(roq,ans);

  return count;
  cout<<endl;
}
// mazepath============================================================================================================
int functioncall=0;
int mazepath(int sr,int sc,int er,int ec,string ans)
{
  functioncall++;
  if(sr==er && sc==ec)
  {
    cout<<ans;
    return 1;
  }
  int count=0;
  if(sr+1<=er)
 {
  count+= mazepath(sr+1,sc,er,ec,ans+"V");
 }
 if(sc+1<=ec)
 {
   count+= mazepath(sr,sc+1,er,ec,ans+"H");
 }
 if(sr+1<=er &&sc+1<=ec)
 {
    count+= mazepath(sr+1,sc+1,er,ec,ans+"D");
 }
 cout<<" ";
 return count;
}
int mazepath_multimoves(int sr, int sc,int er,int ec,string ans)
{
if(sr==er && sc==ec)
{
  cout<<ans;
  return 1;
}
int count=0;
for(int jump=1;jump+sr<=er;jump++)
{
  count+= mazepath_multimoves(sr+jump,sc,er,ec,ans+"V"+to_string(jump));
}
for(int jump=1;sc+jump<=ec;jump++)
{
  count+= mazepath_multimoves(sr,sc+jump,er,ec,ans+"H"+to_string(jump));
}
for(int jump=1;sc+jump<=ec&& sr+jump<=er;jump++)
{
  count+= mazepath_multimoves(sr+jump,sc+jump,er,ec,ans+"D"+to_string(jump));
}
cout<<" ";
return count;
}
int boardpath(int si,int ei,string ans)
{
  if(si==ei)
  {
    cout<<ans;
    return 1;
  }
  int count=0;
  for(int dice=1;dice<=6 && si+dice<=ei;dice++)
  {
    count+=boardpath(si+dice,ei,ans+to_string(dice));
  }
  return count;
}
// nokia phone ============================================================================================
int keypad(string ques,string ans)
{
  string codes[] ={"+","abc","def","ghi","jkl","mno","pqrs","tuv","wx","yz","#","*"};
if(ques.size()==0)
{
    cout<<ans<<" ";
    return 1;
}
int count=0;
char ch=ques[0];
string roq=ques.substr(1);
string code=codes[ch-'0'];
for(int i=0;i<code.size();i++)
{
count += keypad(roq,ans+code[i]);
}
return count;
}
// flood fill questions ========================================================================================
bool isvalidlocation(vector<vector<bool>> &isdone,int x,int y)
{
    if(x<0 || y<0 || x>=isdone.size() || y>= isdone[0].size() || isdone[x][y])
    {
        return false;
    }
    return true;
}
int floodf(vector<vector<bool>> &isdone,int sr,int sc,int er,int ec,string ans)
{
    if(sr==er && sc==ec)
    {
        cout<<ans<<endl;
        return 1;
    }
   int count=0;
   isdone[sr][sc]=true;
    if(isvalidlocation(isdone,sr+1,sc))
    {
        count += floodf(isdone,sr+1,sc,er,ec,ans+"D");
    }
    if(isvalidlocation(isdone,sr,sc+1))
    {
        count += floodf(isdone,sr,sc+1,er,ec,ans+"R");
    }
    if(isvalidlocation(isdone,sr-1,sc))
    {
        count += floodf(isdone,sr-1,sc,er,ec,ans+"U");
    }
    if(isvalidlocation(isdone,sr,sc-1))
    {
        count += floodf(isdone,sr,sc-1,er,ec,ans+"L");
    }
    isdone[sr][sc]=false;
    return count;

}
void floodfillquestions()
{
  vector<vector<bool>> isdone={
      {0,1,0,0,0},
      {0,0,1,0,1},
      {0,0,0,0,0},
      {0,1,0,0,0}
  };
  cout<<floodf(isdone,0,0,2,3," ")<<endl;
}

// set questions ============================================================================================
int targetsum(vector<int> &arr,int idx,int target,string ans)
{
  if(idx== arr.size()|| target==0)
  {
    if(target==0)
    {
      cout<<ans<<endl;
      return 1;
    }
    return 0;
  }
 
 int count=0;
 count += targetsum(arr,idx+1,target-arr[idx],ans+to_string(arr[idx])+" "); // once accepts the option
 count += targetsum(arr,idx+1,target,ans);  // does not accept the option 
 return count;
}
int equiset(vector<int> &arr,int idx,int set1,int set2,string ans1,string ans2)
{
  if(idx==arr.size())
  {
    if(set1 == set2)
    {
      cout<<ans1 <<" = "<<ans2 <<endl;
      return 1;
    }
    return 0;
  }
    int count =0;
    count += equiset(arr,idx+1,set1 +arr[idx],set2,ans1+to_string(arr[idx])+ " ",ans2);
    count += equiset(arr,idx+1,set1,set2+ arr[idx],ans1,ans2+to_string(arr[idx])+" ");
    return count;
  
}

void setquestions()
{
  vector<int> arr={10,20,30,40,50,60,70};
   cout<<targetsum(arr,0,60," ")<<endl;
   cout<<equiset(arr,1,10,0,"10 "," ")<<endl;
}

//coinchange==========================================================================================
int coinchangecr(vector<int> arr,int idx,int target,string ans)
{
  if(idx==arr.size() || target==0)
  {
    if(target==0)
    {
      cout<<ans<<endl;
      return 1;
    }
    return 0;
  }
  int count=0;
  for(int i=idx;i<=arr.size();i++)
  {
    if(target-arr[i]>=0)
    {
      count += coinchangecr(arr,i,target-arr[i],ans+to_string(arr[i]));
    }
  }
  return count;
}
int coinchangecwr(vector<int> arr,vector<bool> isdone, int idx,int target,string ans)
{
  if(idx==arr.size() || target==0)
  {
    if(target==0)
    {
      cout<<ans<<endl;
      return 1;
    }
    return 0;
  }
  int count=0;
  for(int i=idx;i<arr.size();i++)
  {
    if(target-arr[i]>=0 && !isdone[i])
    {
      isdone[i]=true;
      count += coinchangecwr(arr,isdone,i,target-arr[i],ans+to_string(arr[i]));
      isdone[i]=false;
    }
  }
  return count;
}
 int coinchangepr(vector<int> arr,int idx,int target,string ans)
{
  if(idx==arr.size()|| target==0)
  {
    if(target==0)
    {
      cout<<ans<<endl;
      return 1;
    }
    return 0;
  }

  int count=0;
  for(int i=0;i<arr.size();i++)
  {
   if(target-arr[i]>=0)
   {
    count += coinchangepr(arr,i+1,target-arr[i],ans+to_string(arr[i]));
   }
  }
  return count;
}  

int coinchangepwr (vector<int> &arr,vector<bool> &isdone,int marked,int target,string ans)
{
 if(marked ==arr.size() || target==0 )
 {
     if(target==0)
     {
       cout<<ans<<endl;
       return 1;
     }
     return 0;
 }
 int count=0;
 for(int i=0;i<arr.size();i++)
 {
   if(target-arr[i]>=0 && !isdone[i])
   {
     isdone[i]=true;
     count += coinchangepwr(arr,isdone,marked+1,target-arr[i],ans+to_string(arr[i]));
     isdone[i]=false;
   }
 }
 return count;
}

void coinchangequestion()
{
   vector<int> arr= {2,3,5,7};
   vector<bool> isdone(4,false);
   int marked=0;
 //coinchangecr(arr,0,10," ");
 cout<<endl;
  coinchangecwr(arr,isdone,0,10,"");
 cout<<endl;
 // coinchangepr(arr,0,10,"");
  cout<<endl;
 // coinchangepwr(arr,isdone,marked,10,"");
 cout<<endl;
}
// encoding ==============================================================================================
int encoding(string ques,string ans)
{
  if(ques.size()==0)
  {
  cout<<ans<<endl;
  return 1;
  }
 
 char ch=ques[0];
 int count=0;
 if(ch=='a')
 {
   count += encoding(ques.substr(1),ans);
 }
 else
 {
   count += encoding(ques.substr(1),ans+(char)(ch-'a'+'1'));
   if( ch<'3' && ques.size()>1)
   {
     char ch1=ques[1];
     int num=(ch-'a')*10+(ch1-'a');
     if(num<=26)
     {
       count += encoding(ques.substr(2),ans+(char)(ch-'a'+'1'));
     }

   }
 }
 return count;
 }
 
void encodingquestion()
{
  cout<<encoding("abcde"," ");
}
//queen p and c =====================================================================================
int queen_perm(int boxes,int isset,int tnq,int q, string ans)
{
  if(q==tnq+1)
  {
    cout<<ans<<endl;
    return 1;
  }
  int count=0;
  for(int i=0;i<boxes;i++)
  {
    int mask=(1<<i);
    if((isset&mask)==0)
    {
      isset|=mask;
      count += queen_perm(boxes,isset,tnq,q+1,ans+"b"+to_string(i)+"q"+to_string(q));
      isset &= (~mask);
    }
  }
  return count;
}
int queencombi(int boxes,int box,int tnq,int q,string ans)
{
  if(q==tnq+1)
  {
    cout<<ans<<endl;
    return 1;
  }
  int count =0;
  for (int  i = box; i <boxes; i++)
  {
    count += queencombi(boxes,i+1,tnq,q+1,ans+"b"+to_string(i)+"q"+to_string(q));
  }
  return count;
}
int queenperm_2d(vector<vector<int>> &boxes,int tnq,int q,string ans)
{
  if(q==tnq+1)
  {
    cout<<ans<<endl;
    return 1;
  }
  int count =0;
  for(int i=0;i<boxes.size()*boxes[0].size();i++)
  {
    int r=i/boxes[0].size();
    int c=i%boxes[0].size();
     if(!boxes[r][c])
     {
     boxes[r][c]=true;
     count += queenperm_2d(boxes,tnq,q+1,ans+"b"+to_string(i)+"q"+to_string(q) +" ");
     boxes[r][c]=false;
     }
  }
  return count;
} /*
bool isvalidspot(int r,int c,int n,int m)
{
  if(r<0 ||c<0 || r>=n|| c>=m)
  return false;
  return true;
}
bool isqueensafe(vector<vector<bool>> &boxes,int x,int y)
{
  int n=boxes.size();
  int m=boxes[0].size();
  int arr[4][2]={{0,-1},{-1,-1},{-1,0},{-1,1}};
  for(int i=0;i<4;i++)
  {
    for(int rad=1;rad<max(n,m);rad++)
    {
      int r=x+rad*arr[i][0];
      int c=y+rad*arr[i][1];
      if(isvalidspot(r,c,n,m) && boxes[r][c])
      return false;
    }
  }
  return true;
}
int queencomb_2d_sub(vector<vector<int>> &boxes,int idx,int tnq,int q,string ans)
{
  if(q==tnq+1)
  {
    cout<<ans<<endl;
    return 1;
  }
   bool flag=false;  // for 1 answere onlty
    int n= boxes.size();
    int m= boxes[0].size();
      int r= idx/m;
      int c=idx%m;
    if(isqueensafe(boxes,r,c))
    {
    boxes[r][c]=true;
    flag = flag ||queencomb_2d_sub(boxes, idx+1, tnq, q+1,ans + "(" + to_string(r) + "," + to_string(c)+") q"+ to_string(q+1) + " ");
    boxes[r][c]=false;
    }
    return flag;
} 
bool isvalidlocation(vector<vector<bool>> &isdone,int x,int y)
{
    if(x<0 || y<0 || x>=isdone.size() || y>= isdone[0].size() || isdone[x][y])
    {
        return false;
    }
    return true;
} */
int queenCom_2D(vector<vector<bool>> &boxes, int idx, int tnq, int qpsf, string ans)
{
    if (qpsf == tnq + 1 || idx == boxes.size() * boxes[0].size())
    {
        if (qpsf == tnq + 1)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    int n= boxes.size();
    int m= boxes[0].size();
    for(int i=idx;i<n*m;i++)
    {
    count += queenCom_2D(boxes, i+1, tnq, qpsf+1,ans + "b" + to_string(i+1) + "q" + to_string(qpsf+1) + " ");
    }
    return count;
}
bool isvalidspot(int r,int c,int n,int m)
{
  if(r<0 ||c<0 || r>=n|| c>=m)
  return false;
  return true;
}
bool isqueensafe(vector<vector<bool>> &boxes,int x,int y)
{
  int n=boxes.size();
  int m=boxes[0].size();
  int arr[4][2]={{0,-1},{-1,-1},{-1,0},{-1,1}};
  for(int i=0;i<4;i++)
  {
    for(int rad=1;rad<max(n,m);rad++)
    {
      int r=x+rad*arr[i][0];
      int c=y+rad*arr[i][1];
      if(isvalidspot(r,c,n,m) && boxes[r][c])
      return false;
    }
  }
  return true;
}
bool safequeenplaces(vector<vector<bool>> &boxes, int idx, int tnq, int qpsf, string ans)
{
  if(qpsf ==tnq)
  {
    cout<<ans<<endl;
    return true;
  }
    //int count = 0;    // for 2 answere all.
    bool flag=false;  // for 1 answere onlty
    int n= boxes.size();
    int m= boxes[0].size();
    for(int i=idx;i<n*m;i++)
    {
      int r= i/m;
      int c=i %m;
    if(isqueensafe(boxes,r,c))
    {
    boxes[r][c]=true;
    flag = flag ||safequeenplaces(boxes, i+1, tnq, qpsf+1,ans + "(" + to_string(r) + "," + to_string(c)+") q"+ to_string(qpsf+1) + " ");
    boxes[r][c]=false;
    }
    }
    return flag;
}
void queenpandc()
{
    // cout << queencombi(5, 0, 3, 1, "") << endl; 
    // cout << queen_perm(5, 0, 3, 1, "") << endl;
   // vector<vector<bool>> boxes(4, vector<bool>(4, 0));
    // cout << queencomb_2D_sub(boxes, 0, 3, 1, "") << endl; ?
    // cout << queenCom_2D(boxes, 0, 4, 1, "") << endl;
    // cout<< safequeenplaces(5,0,4,0,"")<<endl;

}
//sudoku===============================================================================================
void display(vector<vector<int>> &a)
{
  for(int i=0;i<a.size();i++)
  {
    for(int j=0;j<a[0].size();j++)
    {
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }
  cout << endl;
}
bool issafetoplacenumber(vector<vector<int>> &boxe,int r,int c,int val)
{
  for(int i=0;i<9;i++)
  {
    if(boxe[i][c]==val)
      return false;
  } 
  for(int j=0;j<9;j++){

    if(boxe[r][j]==val)
      return false;

  }
  
  int nr=(r/3)*3;
  int nc=(c/3)*3;

  for(int i=0;i<3 ;i++){
    for(int j=0;j<3;j++){
      if(boxe[nr+i][nc+j]==val)
              return false;
    }
  }

  return true;
}
int sudoku_01(vector<vector<int>> &boxe,int vidx)
{
  if(vidx==81)
  {
    cout<<"fdfd";
    display(boxe);
    return 1;
  }
  int count=0;
    int r=vidx/9;
    int c=vidx%9;
    if(boxe[r][c]==0)
    {
     for(int val=1;val<=9;val++)
     {
       if(issafetoplacenumber(boxe,r,c,val))
       {
        boxe[r][c]=val;
        count += sudoku_01(boxe,vidx+1);
        boxe[r][c]=0;
       }
     }
    }
    else
    {
    count+= sudoku_01(boxe,vidx+1);
    }
    return count;
}
#define vii vector<vector<int>>
#define vi vector<int>
int sudoku_02(vii boxe,int vidx,vector<int> &row,vector<int> &col,vector<vector<int>> &mat)
{
  if(vidx==81)
  {
    display(boxe);
    return 1;
  }
  int count =0;
  int r=vidx/9;
  int c= vidx%9;
  if(boxe[r][c]==0)
  {
    for(int val=1;val<=9;val++)
    {
      int mask=1<<val;
      if(((row[r] & mask)==0) && ((col[c]& mask)==0) && ((mat[r/3][c/3] & mask)==0))
      {
       boxe[r][c]=val;
       row[r] |= mask;
       col[c] |= mask;
       mat[r/3][c/3] |= mask;

       count+= sudoku_02(boxe,vidx+1,row,col,mat);
       boxe[r][c]=0;
       row[r] ^= mask;
       col[c]^= mask;
       mat[r/3][c/3] ^=mask;
      }
    }
  }
  else
  {
    count += sudoku_02(boxe,vidx+1,row,col,mat);
  }
  return count;
}
void sudoku_populate(vector<vector<int>> &boxe,vi &row,vi &col,vii &mat)
{
     for(int i=0;i<9;i++)
     {
      for(int j=0;j<9;j++)
      {
         if(boxe[i][j]==0)
         continue;
         int mask = (1<<boxe[i][j]);
         row[i] |= mask;
         col[j] |= mask;
         mat[i/3][j/3] |=mask;
      }
     }
}
void sudokuquestions()
{
  vector<vector<int>> boxe ={   {3, 0, 6, 5, 0, 8, 4, 0, 0},
                                {5, 2, 0, 0, 0, 0, 0, 0, 0},
                                {0, 8, 7, 0, 0, 0, 0, 3, 1},
                                {0, 0, 3, 0, 1, 0, 0, 8, 0},
                                {9, 0, 0, 8, 6, 3, 0, 0, 5},
                                {0, 5, 0, 0, 9, 0, 6, 0, 0},
                                {1, 3, 0, 0, 0, 0, 2, 5, 0},
                                {0, 0, 0, 0, 0, 0, 0, 7, 4},
                                {0, 0, 5, 2, 0, 6, 3, 0, 0}};
  vi row(9,0);
  vi col(9,0);
  vii mat(3,vi(3,0));
 //cout<<sudoku_01(boxe,0);
//  vii boxe (9,vi (9,0));
 sudoku_populate(boxe,row,col,mat);
  cout<<sudoku_02(boxe,0,row,col,mat);

}
//wordcompare=======================================================================================
bool iswordpresent(vector<string> &dict,string word)
{
  for(string str :dict)
  {
    if(word.compare(str)==0)
    {
      return true;
    }                                                                                                                                                                                                                                                                                                      
  }
   return false;
}
int wordbreak(vector<string> &dict,string statement,string ans)
{
  if(statement.length()== 0)
  {
    cout<<ans<<endl;
    return 1;
  }
  int count=0;
  for(int i=1;i<=statement.length();i++)
  {
    string str= statement.substr(0,i);
    if(iswordpresent(dict,str))
    {
      count += wordbreak(dict,statement.substr(i),ans+str+" ");
    }
  }
  return count;
}
vector<int> freqmap(string str)
{
  vector <int> freq(26,0);
  for(int i=0;i<str.length();i++)
  {
    freq[str[i]-'a']++;
  }
  return freq;
}
string str1="send";
  string str2="more";
  string str3="money";
int getnumber(string str,vi &numberagainstchar)
  {
    int ans=0;
    for(int i=0;i<str.length();i++)
    {
      char ch=str[i];
      int num=numberagainstchar[ch-'a'];
      ans=ans*10+num;
    }
 return ans;
  }
int cryptoarithmetic_01(string ques,int vidx,vi &numberagainstchar,int istaken)
{
  if(vidx==ques.length())
  {
    int num1=getnumber(str1,numberagainstchar);
    int num2=getnumber(str2,numberagainstchar);
    int num3=getnumber(str3,numberagainstchar);
    if(num1+num2== num3 )
    {
      if(str3.length() >str2.length() && numberagainstchar[str3[0]-'a']==0)
      {
      return 0;
      }
      cout<<endl;
      cout<<num1<< "\n"<<num2 <<"\n+"<<"-----\n"<<num3<<endl;
      return 1;
    }
    return 0;
  }
  int count=0;
  for(int i=0;i<10;i++)
  {
    int mask=1 << i;
    if((istaken &mask )==0)
    {//not taken
     istaken|=mask;
     numberagainstchar[ques[vidx]-'a']=i;
     count += cryptoarithmetic_01(ques,vidx+1,numberagainstchar,istaken);
     numberagainstchar[ques[vidx]-'a']=0;
     istaken ^= mask;
    }
  }
  return count;
}
void cryptoarithmetic()
{
  vi freq=freqmap(str1+str2+str3);
  string ques="";
  for(int i=0;i<freq.size();i++)
  {
    if(freq[i]>0)
    {
      ques+=(char)(i+'a');
    }
  }
 // for(int i=0;i<26;i++)
 // {
 //   cout<<i<<" "<<freq[i]<<" " <<(char)(i+'a')<<endl;
 // }
  cout<<ques;
  vi numberagainstchar(26,0);
  int istaken=0;
  cryptoarithmetic_01(ques,0,numberagainstchar,istaken);
}
void wordbreak_crypto()
{
  vector<string> dict={"samsung","sam","sung","i","like","ilike","sun","go","o"};
  string str="ilikelikesamsungo";
 cout<< wordbreak(dict,str,"")<<endl;
// cryptoarithmetic();
}
void solve()
{
  //floodfillquestions();
  // setquestions();
   //coinchangequestion();
    encodingquestion();
  // queenpandc();
  //sudokuquestions();
  //wordbreak_crypto();
}

int main(int args,char** argv)
{
  string ans=" ";
 /* cout<<subsequence("abc"," ");
cout<<endl;
cout<<mazepath(0,0,2,2,ans);
cout<<endl;
cout<<" no of function calss in mazepath problem:"<<functioncall<<endl;
cout<<mazepath_multimoves(0,0,2,2,ans);
cout<<endl;
cout<<"height of each end node in the trace of recursion tree diagram of mazepath_multimoves problem:"<<endl;
cout<<" and maximum height from it :"<<endl;
cout<<" "<<boardpath(0,6,ans)<<endl;
cout<<keypad("235",ans)<<endl;
cout<<endl;*/
solve();
return 0;
}