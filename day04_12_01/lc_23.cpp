//
// Created by Lanture on 2022/12/1.
//
#include<queue>
using namespace std;

/*1.问题:
 *  1.1 pq里面顺序是大到小, cmp:a>b 是大到小, a<b 是小到大
 *  1.2 不适用dummy, 进行new 的时候会多一个默认构造
 *  1.3 pq里面别放nullptr!*/
class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;

        ListNode() : val(0), next(nullptr) {}

        ListNode(int x) : val(x), next(nullptr) {}
    };

    struct cmp {
        bool operator()(ListNode *a, ListNode *b) {
            return a->val > b->val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0) return nullptr;
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        priority_queue<ListNode *, vector<ListNode *>, cmp> pq;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i])
                pq.push(lists[i]);
        }
        while (!pq.empty()) {
            ListNode *node = pq.top();
            // cout<<node->val<<" ";
            pq.pop();
            // cur->val = node->val;
            // cur->next = new ListNode();//cur 新建最后会多一个0.
            // cur = cur->next;
            if (node->next) {
                pq.push(node->next);
            }
            cur->next = node;
            cur = cur->next;
        }
        return dummy->next;
    }
};