#include<bits/stdc++.h>
using namespace std;

int recursive(vector<int> &nums, int i, int j, int target){
  //base case
  if(i>j)return -1;
  int mid=(i+j)/2;
  if(nums[mid]==target)return mid;
  else if(nums[mid] > target)return recursive(nums,i,mid-1,target);
  else return recursive(nums,mid+1,j,target);
}

int binarySearch(vector<int> &nums, int target){
  int i=0,j=nums.size()-1;
  while(i<j){
    int mid=(i+j)/2;
    if(nums[mid]==target){
      return mid;
    }
    else if(nums[mid] > target){
      j=mid-1;
    }
    else{
      i=mid+1;
    }
  }
  return -1;
}
int main(){
  vector<int> v={1,6,9,10,30,47,60};
  int target =47;
  int ans=recursive(v,0,v.size()-1,target);
  cout<<ans<<endl;
  return 0;
}