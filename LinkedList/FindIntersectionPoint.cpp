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

int getCount(Node* head){
  int count=0;
  Node* temp=head;
  while(temp!=NULL){
    count++;
    temp=temp->next;
  }
  return count;
}
//BRUTE
Node* solve(Node* head1, Node* head2){
  int n1=getCount(head1);
  int n2=getCount(head2);
  int diff;
  if(n1>n2){
    diff=n1-n2;
    while(diff--){
      head1=head1->next;
    }
    while(head1!=NULL && head2!=NULL){
      if(head1==head2)return head1;
      head1=head1->next;
      head2=head2->next;
    }
  }
  else{
    diff=n2-n1;
    while(diff--){
      head2=head2->next;
    }
    while(head1!=NULL && head2!=NULL){
      if(head1==head2)return head1;
      head1=head1->next;
      head2=head2->next;
    }
  }
  return new Node(-1);
}

// OPTIMAL
Node* optimal(Node* head1, Node* head2){
  if(head1==NULL || head2==NULL)return NULL;
  Node* temp1=head1;
  Node* temp2=head2;
  while(temp1!=temp2){
    temp1=temp1->next;
    temp2=temp2->next;
    if(temp1==temp2)return temp1;
    if(temp1==NULL)temp1=head2;
    if(temp2==NULL)temp2=head1;
  }
  return temp1;
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
  Node* n1 = new Node(1);
  Node* n2 = new Node(2);
  Node* n3 = new Node(3);
  Node* n4 = new Node(4);
  Node* n5 = new Node(5);
  Node* n6 = new Node(6);
  Node* n7 = new Node(7);
  Node* n8 = new Node(8);
  Node* n9 = new Node(9);
  Node* n10 = new Node(10);
  
  n1->next=n2;
  n2->next=n3;
  n3->next=n4;
  n3->next=n9;
  n4->next=n5;
  n5->next=n6;
  n6->next=n7;
  n7->next=n8;
  n8->next=n9;
  n9->next=n10;
  
  Node* head1=n1;
  Node* head2=n4;
  
  Node* res=optimal(head1,head2);
  cout<<res->data<<endl;
  
  return 0;
}