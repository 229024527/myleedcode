//双指针技术
//Remove Nth Node From End of List
//给定一个链表，删除倒数第n个节点
//- 如：1->2->3->4->5->NULL，n=2
//- 返回：1->2->3->5
//- n从0计还是从1计
//- n不合法，负数或者大于链表长度如何处理(保证n合法)
//解法1：先遍历一遍计算链表长度；再遍历一遍删除倒数第n个节点
//
#include <iostream>
#include <cassert>

using namespace std;

///Definition for singly-linked list.
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
	ListNode* removeNthFromEnd(ListNode* head, int n){

		assert(n >= 0);
		
		ListNode* dummyHead = new ListNode(0);
		dummyHead->next = head;

		ListNode* p = dummyHead;
		ListNode* q = dummyHead;
		for(int i=0; i<n+1; i++){
			assert( q );
			q=q->next;
		}

		while( q != NULL){
			p = p->next;
			q = q->next;
		}

		ListNode* delNode = p->next;
		p->next = delNode->next;
		delete delNode;

		ListNode* retNode = dummyHead->next; 
		delete dummyHead;

		return retNode;
	}
};

int main(){

	return 0;
}
