#include<bits/stdc++.h>
using namespace std;
int lowerBound(vector<int> &nums, int target){
  int i=0, j=nums.size()-1;
  int ans=-1;
  while(i<=j){
    int mid=(i+j)/2;
    if(nums[mid] == target){
      ans=mid;
      return ans;
    }
    else if(target > nums[mid]){
      i=mid+1;
    }
    else{
      ans=mid;
      j=mid-1;
    }
  }
  return ans;
}
int main(){
  vector<int> v={3,5,8,15,19};
  int target = 3;
  int ans = lowerBound(v, target);
  cout<<ans<<endl;
  return 0;
}