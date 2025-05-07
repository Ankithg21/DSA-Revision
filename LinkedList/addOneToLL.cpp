
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

//BRUTE
Node* solve(Node* head){
  head=reverse(head);
  Node* temp=head;
  int carry=1;
  while(temp!=NULL){
    temp->data+=carry;
    if(temp->data < 10){
      carry=0;
      break;
    }
    else{
      temp->data=0;
      carry=1;
    }
    temp=temp->next;
  }
  if(carry==1){
    Node* newNode=new Node(carry);
    head=reverse(head);
    newNode->next=head;
    return newNode;
  }
  head=reverse(head);
  return head;
}

//Optimal - Recursion
int helper(Node* temp){
  if(temp==NULL){
    return 1;
  }
  int carry=helper(temp->next);
  temp->data=temp->data+carry;
  if(temp->data<10){
    return 0;
  }
  temp->data=0;
  return 1;
}

Node* optimal(Node* head){
  int carry=helper(head);
  if(carry){
    Node* newNode=new Node(1);
    newNode->next=head;
    return newNode;
  }
  else{
    return head;
  }
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
  vector<int> v={1,5,9};
  Node* head = arrayToLL(v);
  head=optimal(head);
  print(head);
  return 0;
}
