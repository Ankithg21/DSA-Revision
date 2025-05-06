
#include<bits/stdc++.h>
using namespace std;

class Node{
  public: 
    int data;
    Node* next;
    Node(int data){
      this->data = data;
      next=NULL;
    }
};

// Brute
bool solve(Node* head){
  stack<int> st;
  Node* temp=head;
  while(temp!=NULL){
    st.push(temp->data);
    temp=temp->next;
  }
  temp=head;
  while(temp!=NULL){
    if(temp->data!=st.top())return false;
    st.pop();
    temp=temp->next;
  }
  return true;
}

Node* reverse(Node* head){
  Node* prev=NULL;
  Node* temp=head;
  while(temp!=NULL){
    Node* front=temp->next;
    temp->next=prev;
    prev=temp;
    temp=temp->next;
  }
  return prev;
}

//Optimal
bool optimal(Node* head){
  Node* fast=head;
  Node* slow=head;
  while(fast->next!=NULL && fast->next->next!=NULL){
    slow=slow->next;
    fast=fast->next->next;
  }
  Node* newHead=reverse(slow);
  Node* first=head;
  Node* second=newHead;
  while(second!=NULL){
    if(first->data != second->data)return false;
    first=first->next;
    second=second->next;
  }
  return true;
}

// array to LL
Node* arrayToLL(vector<int> &nums){
  Node* head=new Node(nums[0]);
  Node* temp=head;
  for(int i=1;i<nums.size();i=i+1){
    Node* newNode=new Node(nums[i]);
    temp->next=newNode;
    temp=newNode;
  }
  return head;
}

//print LL.
void print(Node* head){
  if(head==NULL)return;
  Node* temp=head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  return;
}

int main(){
  vector<int> v={1,2,3,4,3,2,1};
  Node* head = arrayToLL(v);
  bool ans = optimal(head);
  cout<<(ans?"PALINDROME":"NOT A PALINDROME")<<endl;
  print(head);
  return 0;
}
