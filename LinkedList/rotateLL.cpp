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

Node* findNthNode(Node* temp, int k){
  int count=1;
  while(temp!=NULL){
    if(count==k)return temp;
    count++;
    temp=temp->next;
  }
  return temp;
}

Node* solve(Node* head, int k){
  if(head==NULL || k==0)return head;
  Node* tail=head;
  int len=1;
  while(tail->next != NULL){
    len++;
    tail=tail->next;
  }
  if(k%len == 0)return head;
  k=k%len;
  tail->next=head;
  Node* newLastNode = findNthNode(head, len-k);
  head=newLastNode->next;
  newLastNode->next=NULL;
  return head;
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
  Node* head = arrayToLL(v);
  head=solve(head,2);
  print(head);
  return 0;
}