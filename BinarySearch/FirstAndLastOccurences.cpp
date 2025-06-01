#include<bits/stdc++.h>
using namespace std;

vector<int> firstAndLastOccurences(vector<int> &nums, int target){
  int i=0,p=0, j=nums.size()-1, q=nums.size()-1;
  int ans1=-1, ans2=-1;
  while(i<j && p<q){
    int mid1=(i+j)/2;
    int mid2=(p+q)/2;
    if(nums[mid1]==target){
      j=mid1-1;
      ans1=mid1;
    }
    if(nums[mid2] == target){
      p=mid2+1;
      ans2=mid2;
    }
    if(nums[mid1] > target ){
      j=mid1-1;
    }
    if(nums[mid1] < target){
      i=mid1+1;
    }
    if(nums[mid2] > target){
      q=mid2-1;
    }
    else{
      p=mid2+1;
    }
  }
  return {ans1, ans2};
}

int main(){
  vector<int> v={2,4,6,8,8,8,11,13};
  int target = 8;
  vector<int> ans=firstAndLastOccurences(v, target);
  cout<<ans[0]<<" "<<ans[1]<<endl;
  return 0;
}