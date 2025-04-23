#include<bits/stdc++.h>
using namespace std;
// Brute-Force solution.
int solve(vector<int> &nums){
  int n=nums.size();
  for(int i=0;i<n;i=i+1){
    int count=0;
    for(int j=0;j<n;j=j+1){
      if(nums[j]==nums[i]){
        count++;
      }
    }
    if(count > n/2)return nums[i];
  }
  return -1;
}

// Better Solution.
int solve2(vector<int> &nums){
  int n=nums.size();
  map<int,int> mp;
  for(auto it:nums){
    mp[it]++;
  }
  for(auto it:mp){
    if(it.second > n/2)return it.first;
  }
  return -1;
}

//Optimal solution.-> moore's voting algo
int solve3(vector<int> &nums){
  int count=0;
  int ele;
  for(int i=0;i<nums.size();i=i+1){
    if(count==0){
      ele=nums[i];
      count=1;
    }
    else if(nums[i]==ele){
      count++;
    }
    else{
      count--;
    }
  }
  int count2=0;
  for(int i=0;i<nums.size();i=i+1){
    if(nums[i]==ele){
      count2++;
    }
  }
  if(count2 > nums.size()/2)return ele;
  return -1;
}
int main(){
  vector<int> v={2,2,3,3,1,2,2};
  int ans = solve3(v);
  cout<<ans<<endl;
  return 0;
}