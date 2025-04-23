#include<bits/stdc++.h>
using namespace std;
// Brute-Force solution.
int solve(vector<int> &nums){
  int n=nums.size();
  int ans=0;
  for(int i=0;i<n;i=i+1){
    for(int j=i;j<n;j=j+1){
      int sum=0;
      for(int k=i;k<=j;k=k+1){
        sum+=nums[k];
      }
      ans=max(ans,sum);
    }
  }
  return ans;
}

//Better solution.
int solve2(vector<int> &nums){
  int n=nums.size();
  int ans=0;
  for(int i=0;i<n;i=i+1){
    int sum=0;
    for(int j=i;j<n;j=j+1){
      sum+=nums[j];
      ans=max(ans,sum);
    }
  }
  return ans;
}

// Optimal solution.
int solve3(vector<int> &nums){
  int sum=0,maxi=INT_MIN;
  for(int i=0;i<nums.size();i=i+1){
    sum+=nums[i];
    maxi=max(sum,maxi); 
    if(sum<0){
      sum=0;
    }
  }
  return maxi;
}
int main(){
  vector<int> v={-2,-3,4,-1,-2,1,5,-3};
  int ans = solve3(v);
  cout<<ans<<endl;
  return 0;
}