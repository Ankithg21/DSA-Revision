#include<bits/stdc++.h>
using namespace std;

// Optimal solution
vector<int> solve(vector<int> &nums){
  sort(nums.begin(),nums.end());
  int count=0;
  int i=0,j=i+1;
  vector<int> ans;
  while(j<nums.size()){
    if(nums[i]==nums[j]){
      count++;
      j++;
    }
    else{
      count++;
      if(count > nums.size()/3){
        ans.push_back(nums[i]);
      }
      i=j;
      j++;
    }
  }
  return ans;
}

// Better Solution.
vector<int> solve2(vector<int> &nums){
  map<int,int> mp;
  vector<int> ans;
  int n=nums.size();
  for(auto it:nums){
    mp[it]++;
  }
  for(auto it:mp){
    if(it.second > n/3){
      ans.push_back(it.first);
    }
  }
  return ans;
}

int main(){
  vector<int> v={1,1,3,3,1,2,2,2};
  vector<int> ans=solve2(v);
  for(int i=0;i<ans.size();i=i+1){
    cout<<ans[i]<<" ";
  }
  return 0;
}