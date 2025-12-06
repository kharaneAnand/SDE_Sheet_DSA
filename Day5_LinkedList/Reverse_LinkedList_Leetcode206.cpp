
/*
          206. Reverse the Linked list 
Given the head of a singly linked list, reverse the list, and return the reversed list

Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int val, ListNode* next = nullptr) {
        this->val = val;
        this->next = next;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nxt = NULL;

        while (curr != NULL) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
};

int main(){
    int n ;
    cin>>n ;

    vector<int>list(n) ;
    for(int i=0 ; i<n ; i++){
        cin>>list[i] ;
    }

    ListNode* head = NULL ;
    ListNode* tail = NULL ;

    for(int i=0 ; i<n ; i++){
        ListNode* node = new ListNode(list[i] , NULL) ;
        if(head==NULL && tail==NULL){
            head = node ;
            tail = node ;
        }
        else {
            tail->next = node ;
            tail = tail->next ;
        }
    }

    Solution sol ;
    head = sol.reverseList(head);


    ListNode* temp = head ;
    while(temp!=NULL){
        cout<<temp->val<<"->" ;
        temp = temp->next ;
    }
    cout<<endl ;
    return 0;
}
