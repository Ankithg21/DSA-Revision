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

Node* solve(Node* head){
  int count0=0,count1=0,count2=0;
  Node* temp=head;
  while(temp!=NULL){
    if(temp->data == 0)count0++;
    if(temp->data == 1)count1++;
    else count2++;
    temp=temp->next;
  }
  temp=head;
  while(temp!=NULL){
    if(count0){
      temp->data=0;
      count0--;
    }
    else if(count1){
      temp->data=1;
      count1--;
    }
    else{
      temp->data=2;
      count2--;
    }
    temp=temp->next;
  }
  return head;
}

//OPTIMAL
Node* optimal(Node* head){
  Node* zeroHead=new Node(-1);
  Node* oneHead=new Node(-1);
  Node* twoHead=new Node(-1);
  Node* temp=head;
  Node* originalOne=oneHead;
  Node* originalTwo=twoHead;
  Node* originalZero=zeroHead;
  while(temp!=NULL){
    if(temp->data == 0){
      zeroHead->next=temp;
      zeroHead=temp;
      temp=temp->next;
      zeroHead->next=NULL;
    }
    else if(temp->data==1){
      oneHead->next=temp;
      oneHead=temp;
      temp=temp->next;
      oneHead->next=NULL;
    } 
    else{
      twoHead->next=temp;
      twoHead=temp;
      temp=temp->next;
      twoHead->next=NULL;
    }
  }
  zeroHead->next=originalOne->next;
  oneHead->next=originalTwo->next;
  return originalZero->next;
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
  
  vector<int> v={1,0,1,2,0,2,1};
  Node* head = arrayToLL(v);
  head=optimal(head);
  print(head);
  
  return 0;
}