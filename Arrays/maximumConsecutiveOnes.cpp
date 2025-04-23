#include<bits/stdc++.h>
using namespace std;
// Optimal Solution.
int solve(vector<int> &nums){
  int i=0,j=0;
  int n=nums.size();
  int count=0;
  int ans=0;
  while(i<n && j<n){
    if(nums[j]==1){
      count++;
      j++;
      ans=max(ans,count);
    }
    else{
      i=j;
      i++;j++;
      count=0;
    }
  }
  return ans;
}

int main(){
  vector<int> v={1,1,0,1,1,1,0,1,0,1,1,1,1,1,0,1,1};
  int ans = solve(v);
  cout<<ans<<endl;
  return 0;
}

