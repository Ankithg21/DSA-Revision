#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
    int data;
    Node* next;
    Node(int data){
      this->data=data;
      next=NULL;
    }
};

// convert Array to LinkedList
// [1,2,3] -> 1->2->3
Node* convertArrayToLL(vector<int> &nums){
  Node* head= new Node(nums[0]);
  Node* temp=head;
  for(int i=1;i<nums.size();i=i+1){
    Node* newNode=new Node(nums[i]);
    temp->next = newNode;
    temp=newNode;
  }
  return head;
}

int main(){
  
  vector<int> v={1,2,3};
  Node* head = convertArrayToLL(v);
  while(head!=NULL){
    cout<<head->data<<"->";
    head=head->next;
  }
  
  return 0;
}