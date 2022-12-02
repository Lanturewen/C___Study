//
// Created by Lanture on 2022/11/30.
//
struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next): val(x), next(next){}
};

class solution{
public:
    ListNode* reverseList(ListNode* head){
        ListNode* pre = nullptr, *cur = head;
        while(cur){
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};
