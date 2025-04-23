#include<bits/stdc++.h>
using namespace std;

// Optimal Solution
int solve(vector<int> &nums){
  int mini=nums[0];
  int ans=0;
  for(int i=0;i<nums.size();i=i+1){
    if(nums[i] < mini){
      mini=nums[i];
    }
    int profit=nums[i]-mini;
    ans=max(ans,profit);
  }
  return ans;
}

int main(){
  vector<int> v={7,1,5,3,6,4};
  int ans=solve(v);
  cout<<ans<<endl;
  return 0;
}