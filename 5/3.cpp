//给定一个链表，对于每两个相邻的节点，交换其位置。
//- 如：链表为1->2->3->4->NULL
//- 返回：2->1->4->3->NULL
//- 只能对节点进行操作，不能修改节点的值
//Swap Nodes in Pairs
//
#include <iostream>

using namespace std;

///Definition for singly-linked list.
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};

class Solution{
	ListNode* swapPairs(ListNode* head){
		ListNode* dummyHead = new ListNode(0);
		dummyHead->next = head;

		ListNode*p = dummyHead;
		while( p->next && p->next->next ){
			ListNode* node1 = p->next;
			ListNode* node2 = node1->next;
			ListNode* next = node2->next;

			node2->next = node1;
			node1->next = next;
			p->next = node2;

			p = node1;
		}

		ListNode* retNode = dummyHead->next;
		delete dummyHead;

		return retNode;
	}
};

int main(){

	return 0;
}
