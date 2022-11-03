#include <cstdlib>

//
// Created by Lanture on 2022/11/3.
//
class MyQueue {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(): val(0), next(nullptr){}
        ListNode(int x): val(x), next(nullptr){}
    };

    ListNode* dummy, *root, *back;

    MyQueue() {
        dummy = new ListNode(0);
        dummy->next = root;
        back = root;
    }

    void push(int x) {
        back->next = new ListNode(x);
        back = back->next;
    }

    int pop() {
        int res = dummy->next->val;
        root = dummy->next;
        dummy->next = root->next;
        root->next = nullptr;
        delete(root);
        root = dummy->next;
        if(root== nullptr){
            back = nullptr;
        }
        return res;
    }

    int peek() {
        if(dummy->next== nullptr){
            return -1;
        }
        return dummy->next->val;
    }

    bool empty() {
        if(dummy->next== nullptr){
            return true;
        } else{
            return false;
        }
    }
};