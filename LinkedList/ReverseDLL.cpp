#include<bits/stdc++.h>
using namespace std;
class Node{
    public: 
      int data;
      Node* next;
      Node* prev;
      Node(int data){
        this->data = data;
        next=NULL;
        prev=NULL;
      }
};

// Reverse a DLL.
// Brute Force.
Node* reverseDLL(Node* head){
  stack<int> st;
  Node* temp=head;
  while(temp!=NULL){
    st.push(temp->data);
    temp=temp->next;
  }
  temp=head;
  while(temp!=NULL){
    temp->data=st.top();
    st.pop();
    temp=temp->next;
  }
  return head;
}

// optimal
Node* optimal(Node* head){
  if(head==NULL || head->next==NULL)return head;
  Node* prev=NULL;
  Node* current = head;
  while(current!=NULL){
    prev=current->prev;
    current->prev=current->next;
    current->next=prev;
    current=current->prev;
  }
  return prev->prev;
}

Node* arrayToDLL(vector<int> &nums){
  Node* head=new Node(nums[0]);
  Node* temp=head;
  for(int i=1;i<nums.size();i=i+1){
    Node* newNode=new Node(nums[i]);
    temp->next=newNode;
    newNode->prev=temp;
    temp=newNode;
  }
  return head;
}

void print(Node* head){
  Node* temp=head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  return;
}


int main(){
  
  vector<int> v={1,2,3,4,5,6,7,8,9,10};
  Node* head=arrayToDLL(v);
  print(head);
  cout<<endl;
  optimal(head);
  print(head);
  
  return 0;
}