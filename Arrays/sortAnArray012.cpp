#include<bits/stdc++.h>
using namespace std;
// Brute-Force solution.
void solve(vector<int> &nums){
  // use any sorting algorithms like quick sort or merge sort.
  sort(nums.begin(),nums.end());
  return;
}

// Better solution.
void solve2(vector<int> &nums){
  int count0=0,count1=0,count2=0;
  for(int i=0;i<nums.size();i=i+1){
    if(nums[i]==0)count0++;
    else if(nums[i]==1)count1++;
    else count2++;
  }
  for(int i=0;i<count0;i=i+1)nums[i]=0;
  for(int i=count0;i<count0+count1;i=i+1)nums[i]=1;
  for(int i=count0+count1;i<nums.size();i=i+1)nums[i]=2;
  return;
}

// Optimal solution.
void solve3(vector<int> &nums){
  int low=0,mid=0,high=nums.size()-1;
  while(mid<=high){
    if(nums[mid]==0){
      swap(nums[low],nums[mid]);
      low++;
      mid++;
    }
    else if(nums[mid]==1){
      mid++;
    }
    else{
      swap(nums[mid],nums[high]);
      high--;
    }
  }
  return;
}
int main(){
  vector<int> v={0,1,1,0,1,2,1,2,0,0,0};
  solve3(v);
  for(int i=0;i<v.size();i=i+1){
    cout<<v[i]<<" ";
  }
  return 0;
}