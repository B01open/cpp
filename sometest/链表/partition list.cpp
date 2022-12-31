
#include <stdio.h>
	
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
	public:
		ListNode *partition(ListNode *head, int x){
			ListNode moreHeadNode(0);
			ListNode lessHeadNode(0);
			ListNode *moreHeadPtr = &moreHeadNode;
			ListNode *lessHeadPtr = &lessHeadNode;
			
			while(head){
				if(head->val >= x){
					moreHeadPtr->next = head;
					moreHeadPtr = head;
				}else{
					lessHeadPtr->next = head;
					lessHeadPtr = head;
				}
				head = head->next;
			}
			
			lessHeadPtr->next = moreHeadNode.next;
			moreHeadPtr->next = NULL;
	        return lessHeadNode.next;
		}
};

int main(){
	ListNode a(1);
	ListNode b(4);
	ListNode c(3);
	ListNode d(2);
	ListNode e(5);
	ListNode f(2);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;	
	Solution solve;
	ListNode *head = solve.partition(&a, 3);	
	while(head){
		printf("%d\n", head->val);
		head = head->next;
	}
	return 0;
}

