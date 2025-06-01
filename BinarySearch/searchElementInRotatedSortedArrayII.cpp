#include<bits/stdc++.h>
using namespace std;

int searchInRotatedSortedArray(vector<int> &nums, int target){
  int i=0, j=nums.size()-1;
  while(i<j){
    int mid=(i+j)/2;
    if(nums[mid]==target){
      return mid;
    }
    else if(nums[i]==nums[mid] && nums[mid] == nums[j]){
      i=mid+1;
      j=mid-1;
      continue;
    }
    else if(nums[i] < nums[mid]){
      if(nums[i]<=target && target<=nums[mid]){
        j=mid-1;
      }
      else{
        i=mid+1;
      }
    }
    else{
      if(target >= nums[mid] && target <= nums[j]){
        i=mid+1;
      }
      else{
        j=mid-1;
      }
    }
  }
  return -1;
}

int main(){
  vector<int> v={7,8,1,3,3,3,5};
  int target = 3;
  int ans = searchInRotatedSortedArray(v, target);
  cout<<ans<<endl;
  return 0;
}