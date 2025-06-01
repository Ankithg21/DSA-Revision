#include<bits/stdc++.h>
using namespace std;

int UpperBound(vector<int> &nums, int target){
  int i=0, j=nums.size()-1;
  int ans=-1;
  while(i<=j){
    int mid=(i+j)/2;
    if(nums[mid] > target){
      ans=mid;
      j=mid-1;
    }
    else{
      i=mid+1;
    }
  }
  return ans;
}

int main(){
  vector<int> v={2,3,6,7,8,8,11,11,11,12};
  int target = 6;
  int ans = UpperBound(v, target);
  cout<<ans<<endl;
  return 0;
}