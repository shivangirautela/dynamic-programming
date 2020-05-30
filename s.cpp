#include<iostream>
#include<vector>
using namespace std;




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
   // cout<<"fdfd";
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
         //cout << "a";
       if(issafetoplacenumber(boxe,r,c,val))
       {
           //cout << "b";
        boxe[r][c]=val;
        count += sudoku_01(boxe,vidx+1);
        boxe[r][c]=0;
       }
     }
    }
    else
    {
        //cout << "c";
    count+= sudoku_01(boxe,vidx+1);
    }
    return count;
}

int main(){

         vector<vector<int>> boxe ={{3,0,6,5,0,8,4,0,0},
                             {5,2,0,0,0,0,0,0,0},
                             {0,8,7,0,0,0,0,3,1},
                             {0,0,3,0,1,0,0,8,0},
                             {9,0,0,8,6,3,0,0,5},
                             {0,5,0,0,9,0,6,0,0},
                             {1,3,0,0,0,0,2,5,0},
                             {0,0,0,0,0,0,0,7,4},
                             {0,0,5,2,0,6,3,0,0}};
       // vector<vector<int>> boxe (9,vector<int> (9,0));
  cout<<sudoku_01(boxe,0);
}