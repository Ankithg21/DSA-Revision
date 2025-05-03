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

Node* solve(Node* head1, Node* head2){
  Node* temp1=head1;
  Node* temp2=head2;
  Node* dummyNode=new Node(-1);
  Node* curr = dummyNode;
  int carry=0;
  while(temp1!=NULL || temp2!=NULL){
    int sum=0;
    if(temp1)sum+=temp1->data;
    if(temp2)sum+=temp2->data;
    carry=carry+sum;
    Node* newNode=new Node(carry%10);
    carry=carry/10;
    curr->next = newNode;
    curr=curr->next;
    if(temp1)temp1=temp1->next;
    if(temp2)temp2=temp2->next;
  }
  if(carry){
    Node* newNode=new Node(carry);
    curr->next=newNode;
  }
  return dummyNode->next;
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
  
  vector<int> v1={3,5};
  vector<int> v2={4,5,9,9};
  Node* head1=arrayToDLL(v1);
  Node* head2=arrayToDLL(v2);
  // print(head);
  cout<<endl;
  Node* head = solve(head1,head2);
  print(head);
  return 0;
}