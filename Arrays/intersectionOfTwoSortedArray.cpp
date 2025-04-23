#include<bits/stdc++.h>
using namespace std;
// Brute-Force solution.
vector<int> solve2(vector<int> &a,vector<int> &b){
  vector<int> vis(b.size(),0);
  vector<int> ans;
  for(int i=0;i<a.size();i=i+1){
    for(int j=0;j<b.size();j=j+1){
      if(a[i]==b[j] && !vis[j]){
        ans.push_back(a[i]);
        vis[j]=1;
        break;
      }
    }
  }
  return ans;
}
// Optimal Solution.
vector<int> solve(vector<int> &a, vector<int> &b){
  int i=0,j=0;
  int n1=a.size(),n2=b.size();
  vector<int> ans;
  while(i<n1 && j<n2){
    if(a[i]==b[j]){
      ans.push_back(a[i]);
      i++;
      j++;
    }
    else if(a[i]>b[j]){
      j++;
    }
    else{
      i++;
    }
  }
  return ans;
}
int main(){
  vector<int> a={1,2,2,3,3,4,5,6,11};
  vector<int> b={2,3,3,5,6,6,7,11};
  vector<int> ans=solve2(a,b);
  for(int i=0;i<ans.size();i=i+1){
    cout<<ans[i]<<" ";
  }
  cout<<endl;
  return 0;
}