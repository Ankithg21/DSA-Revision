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

Node* solve(Node* head1, Node* head2){
  Node* temp1=head1;
  Node* temp2=head2;
  Node* dummyNode=new Node(-1);
  Node* curr=dummyNode;
  while(temp1!=NULL && temp2!=NULL){
    if(temp1->data > temp2->data){
      curr->next=temp2;
      curr=temp2;
      temp2=temp2->next;
      curr->next=NULL;
    }
    else{
      curr->next=temp1;
      curr=temp1;
      temp1=temp1->next;
      curr->next=NULL;
    }
  }
  if(temp1 != NULL){
    curr->next=temp1;
  }
  if(temp2!=NULL){
    curr->next=temp2;
  }
  return dummyNode->next;
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
  vector<int> v={1,2,3,4,5};
  vector<int> v2={3,4,8,9,10,15};
  Node* head = arrayToLL(v);
  Node* head2=arrayToLL(v2);
  head=solve(head,head2);
  print(head);
  return 0;
}