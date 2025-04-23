#include<bits/stdc++.h>
using namespace std;
// Brute-Force solution.
vector<int> solve(vector<int> &nums){
  vector<int> first, second;
  for(int i=0;i<nums.size();i=i+1){
    if(nums[i]!=0){
      first.push_back(nums[i]);
    }
    else{
      second.push_back(nums[i]);
    }
  }
  vector<int> ans;
  for(int i=0;i<first.size();i=i+1){
    ans.push_back(first[i]);
  }
  for(int i=0;i<second.size();i=i+1){
    ans.push_back(second[i]);
  }
  return ans;
}

// Optimal Solution.
vector<int> solve2(vector<int> &nums){
  // find first zero;
  int j=-1;
  for(int i=0;i<nums.size();i=i+1){
    if(nums[i]==0){
      j=i;
      break;
    }
  }
  for(int i=j+1;i<nums.size();i=i+1){
    if(nums[i]!=0){
      swap(nums[i],nums[j]);
      j++;
    }
  }
  return nums;
}
int main(){
  vector<int> v={1,0,2,3,2,0,0,4,5,1};
  vector<int> ans=solve2(v);
  for(int i=0;i<ans.size();i=i+1){
    cout<<ans[i]<<" ";
  }
  return 0;
}