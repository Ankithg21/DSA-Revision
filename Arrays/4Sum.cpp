#include<bits/stdc++.h>
using namespace std;

// Brute Force Soltuion.
vector<vector<int>> solve(vector<int> &nums, int target){
  vector<vector<int>> ans;
  set<vector<int>> st;
  for(int i=0;i<nums.size();i=i+1){
    for(int j=i+1;j<nums.size();j=j+1){
      for(int k=j+1;k<nums.size();k=k+1){
        for(int l=k+1;l<nums.size();l=l+1){
          if(nums[i]+nums[j]+nums[k]+nums[l] == target){
            vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
            sort(temp.begin(),temp.end());
            st.insert(temp);
          }
        }
      }
    }
  }
  for(auto it:st)ans.push_back(it);
  return ans;
}

// Better Solution.
vector<vector<int>> solve2(vector<int> &nums, int target){
  vector<vector<int>> ans;
  map<int,int> mp;
  set<vector<int>> st;
  for(auto it:nums)mp[it]++;
  for(int i=0;i<nums.size();i=i+1){
    for(int j=i+1;j<nums.size();j=j+1){
      for(int k=j+1;k<nums.size();k=k+1){
        int l=target-(nums[i]+nums[j]+nums[k]);
        int res=mp[l];
        if(res!=0){
          vector<int> temp={nums[i],nums[j],nums[k],l};
          sort(temp.begin(),temp.end());
          st.insert(temp);
        }
      }
    }
  }
  for(auto it:st)ans.push_back(it);
  return ans;
}

// Optimal SOlution
vector<vector<int>> solve3(vector<int> &nums, int target){
  sort(nums.begin(),nums.end());
  vector<vector<int>> ans;
  for(int i=0;i<nums.size();i=i+1){
    if(i>0 && nums[i]==nums[i-1])continue;
    for(int j=i+1;j<nums.size();j=j+1){
      if(j!=i+1 && nums[j]==nums[j-1])continue;
      int k=j+1;
      int l=nums.size()-1;
      while(k<l){
        int sum=nums[i]+nums[j]+nums[k]+nums[l];
        if(sum < target){
          k++;
        }
        else if(sum > target){
          l--;
        }
        else{
          vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
          ans.push_back(temp);
          k++;l--;
          while(k<l && nums[k]==nums[k-1])k++;
          while(k<l && nums[l]==nums[l+1])l--;
        }
      }
    }
  }
  return ans;
}

int main(){
  vector<int> v={1,0,-1,0,1,-2,2};
  int target=0;
  vector<vector<int>> ans=solve3(v,target);
  for(int i=0;i<ans.size();i=i+1){
    for(int j=0;j<ans[i].size();j=j+1){
      cout<<ans[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}