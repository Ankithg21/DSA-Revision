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

//Remove at specific location.
Node* removeKthElementInLL(Node* head, int pos){
  pos=pos-1;
  pos--;
  Node* temp=head;
  while(pos--){
    temp=temp->next;
  }
  Node* deleteEmelemt = temp->next;
  temp->next = deleteEmelemt->next;
  deleteEmelemt->next=NULL;
  delete(deleteEmelemt);
  return head;
}

// Delete Element by value - search for the target value and then delete it.
Node* deleteByValue(Node* head, int target){
  Node* temp=head;
  Node* prev=NULL;
  while(temp!=NULL){
    if(temp->data == target){
      prev->next = temp->next;
      temp->next=NULL;
      delete(temp);
      return head;
    }
    prev=temp;
    temp=temp->next;
  }
  return head;
}

//Remove Tail.
Node* removeTail(Node* head){
  Node* temp=head;
  while(temp->next->next!=NULL){
    temp=temp->next;
  }
  Node* tail=temp->next;
  temp->next=NULL;
  delete(tail);
  return head;
}

//Remove Head
Node* removeHead(Node* head){
  if(head==NULL)return NULL;
  Node* temp=head;
  head=head->next;
  delete(temp);
  return head;
}

int main(){
  vector<int> v={1,2,3,4,5,6,7,8,9,10};
  Node* head = arrayToLL(v);
  // Node* head2=removeHead(head);
  // head=removeKthElementInLL(head,9);
  head=deleteByValue(head, 6);
  print(head);
  return 0;
}