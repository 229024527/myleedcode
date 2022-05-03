//设立链表的虚拟头结点
//Remove Linked List Elements
//在链表中删除值为val的所有节点
//- 如1->2->6->3->4->5->6->NULL, 要求删除值为6的节点
//- 返回1->2->3->4->5->NULL
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
public:
	ListNode* removeElements(ListNode* head, int val){
		
		ListNode* dummyHead = new ListNode(0);
		dummyHead->next = head;

		ListNode* cur = dummyHead;
		while( cur->next != NULL ){
			if(cur->next->val == val ){
				//删除cur->next
				ListNode* delNode = cur->next;
				cur->next = delNode->next;
				delete delNode;
				//delNode->next = NULL;
			}
			else
				cur = cur->next;
		}

		ListNode* retNode = dummyHead->next;
		delete dummyHead;

		return retNode;
	}
};

int main(){

	return 0;
}
