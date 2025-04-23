#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &nums){
  queue<pair<int,int>> q;
  for(int i=0;i<nums.size();i=i+1){
    for(int j=0;j<nums[i].size();j=j+1){
      if(nums[i][j]==0){
        q.push({i,j});
      }
    }
  }
  while(!q.empty()){
    pair<int,int> p=q.front();
    q.pop();
    int row=p.first;
    int col=p.second;
    for(int i=0;i<nums.size();i=i+1){
      nums[i][col]=0;
    }
    for(int j=0;j<nums[0].size();j=j+1){
      nums[row][j]=0;
    }
  }
  return;
}

void solve2(vector<vector<int>> &nums) {
    // Your logic here
    int rows = nums.size();
    int cols = nums[0].size();

    vector<bool> rowZero(rows, false);
    vector<bool> colZero(cols, false);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (nums[i][j] == 0) {
                rowZero[i] = true;
                colZero[j] = true;
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (rowZero[i] || colZero[j]) {
                nums[i][j] = 0;
            }
        }
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 8, 9}
    };

    solve2(matrix);

    for (auto row : matrix) {
        for (auto val : row)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
