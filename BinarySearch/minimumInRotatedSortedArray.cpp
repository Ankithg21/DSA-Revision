#include<bits/stdc++.h>
using namespace std;

int minimum(vector<int> &nums){
  int i=0, j=nums.size()-1;
  int ans = INT_MAX;
  while(i<=j){
    int mid = (i+j)/2;
    if(nums[i] < nums[mid]){
      ans=min(ans,nums[i]);
      i=mid+1;
    }
    else{
      ans=min(ans,nums[mid]);
      j=mid-1;
    }
  }
  return ans;
}

int main(){
  vector<int> v={4,5,6,7,8,-1,0,1,2};
  int ans = minimum(v);
  cout<<ans<<endl;
  return 0;
}