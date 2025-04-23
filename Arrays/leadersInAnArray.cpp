#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums){
  for(int i=0;i<nums.size();i=i+1){
    int ele=nums[i];
    bool flag=true;
    for(int j=i+1;j<nums.size();j=j+1){
      if(nums[j] > ele){
        flag=false;
        break;
      }
    }
    if(flag)return ele;
  }
  return -1;
}

//optimal solution.
vector<int> solve2(vector<int> &nums){
  vector<int> ans;
  int maxi=INT_MIN;
  for(int i=nums.size()-1;i>=0;i--){
    if(nums[i] > maxi){
      ans.push_back(nums[i]);
    }
    maxi=max(maxi,nums[i]);
  }
  sort(ans.begin(),ans.end());
  return ans;
}
int main(){
  vector<int> v={10,22,12,3,0,6};
  // int ans=solve(v);
  vector<int> res=solve2(v);
  for(int i=0;i<res.size();i=i+1){
    cout<<res[i]<<" ";
  }
  // cout<<ans<<endl;
  return 0;
}