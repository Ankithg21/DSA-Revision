#include<bits/stdc++.h>
using namespace std;
vector<int> solve(vector<vector<int>> &nums){
  int n=nums.size(), m=nums[0].size();
  int startRow=0, endRow=n-1;
  int startCol=0, endCol=m-1;
  vector<int> ans;
  while(startRow<endRow && startCol<endCol){
    for(int i=startCol;i<=endCol;i=i+1){
      ans.push_back(nums[startRow][i]);
    }
    startRow++;
    for(int i=startRow;i<=endRow;i=i+1){
      ans.push_back(nums[i][endCol]);
    }
    endCol--;
    for(int i=endRow;i>=startCol;i--){
      ans.push_back(nums[endRow][i]);
    }
    endRow--;
    for(int i=endRow;i>=startRow;i--){
      ans.push_back(nums[i][startCol]);
    }
    startCol++;
  }
  return ans;
}
int main(){
  vector<vector<int>> v={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
  for(int i=0;i<v.size();i=i+1){
    for(int j=0;j<v[i].size();j=j+1){
      cout<<v[i][j]<<" ";
    }
    cout<<endl;
  }
  vector<int> ans=solve(v);
  for(int i=0;i<ans.size();i=i+1){
    cout<<ans[i]<<" ";
  }
  return 0;
}