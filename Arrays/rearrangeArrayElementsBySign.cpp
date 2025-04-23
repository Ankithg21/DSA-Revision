#include<bits/stdc++.h>
using namespace std;
// Optimal solution.
vector<int> solve(vector<int> &nums){
  int n=nums.size();
  vector<int> ans(n,0);
  int posIndex=0, negIndex=1;
  for(int i=0;i<n;i=i+1){
    if(nums[i]<0){
      ans[negIndex]=nums[i];
      negIndex+=2;
    }
    else{
      ans[posIndex]=nums[i];
      posIndex+=2;
    }
  }
  return ans;
}

int main(){
  vector<int> v={3,1,-2,-5,2,-4};
  vector<int> ans=solve(v);
  for(int i=0;i<ans.size();i=i+1){
    cout<<ans[i]<<" ";
  }
  return 0;
}