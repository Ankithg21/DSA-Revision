#include<bits/stdc++.h>
using namespace std;
// Brute-Force solution.
vector<int> solve(vector<int> &nums, int target){
  int n=nums.size();
  for(int i=0;i<n;i=i+1){
    for(int j=i+1;j<n;j=j+1){
      if(nums[i]+nums[j]==target){
        return {i,j};
      }
    }
  }
  return {-1,-1};
}

// Better solution.
vector<int> solve2(vector<int> &nums, int target){
  map<int,int> mp;
  for(int i=0;i<nums.size();i=i+1){
    int ele=nums[i];
    int remaining=target-ele;
    if(mp.find(remaining)!=mp.end()){
      return {mp[remaining],i};
    }
    mp[ele]=i;
  }
  return {-1,-1};
}

// Optimal Solution.
vector<int> solve3(vector<int> &nums, int target){
  sort(nums.begin(),nums.end());
  int i=0,j=nums.size()-1;
  while(i<=j){
    if(nums[i]+nums[j]==target){
      return {i,j};
    }
    else if(nums[i]+nums[j] > target){
      j--;
    }
    else{
      i++;
    }
  }
  return {-1,-1};
}
int main(){
  vector<int> v={2,6,5,8,11};
  int target=14;
  vector<int> ans=solve3(v,target);
  for(int i=0;i<ans.size();i=i+1){
    cout<<ans[i]<<" ";
  }
  return 0;
}