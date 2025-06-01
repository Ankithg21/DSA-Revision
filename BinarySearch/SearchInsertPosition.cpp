#include<bits/stdc++.h>
using namespace std;

int searchInsertPosition(vector<int> &nums, int target){
  int i=0, j=nums.size()-1;
  int ans = -1;
  while(i < j){
    int mid = (i+j)/2;
    if(nums[mid] == target){
      return mid;
    }
    else if(nums[mid] > target){
      ans=mid-1;
      j=mid-1;
    }
    else{
      ans=mid+1;
      i=mid+1;
    }
  }
  return ans;
}

int main(){
  vector<int> v={1,2,4,7};
  int target = 6;
  int ans = searchInsertPosition(v, target);
  cout<<ans<<endl;
  return 0;
}