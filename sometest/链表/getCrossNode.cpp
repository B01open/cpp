
#include <set>
#include <stdio.h>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
/*
int listLen(ListNode* head){
	int iLen = 0;
	if(NULL == head){
		return 0;
	}
	while(head){
		iLen++;
		head = head->next;
	}
	return iLen;
}

ListNode* findStartNode(ListNode* head, int Len){
	
	while(head && Len--){
		head  = head->next; 
	}
	return head;
}

class Solution{
	public:
		ListNode* getIntersectionNode(ListNode* head1, ListNode* head2){
			int iLen1 = 0;
			int iLen2 = 0;
			int iLen = 0;
			iLen1 = listLen(head1);
			iLen2 = listLen(head2);

			if(iLen1 > iLen2){
				iLen = iLen1 -iLen2;
				head1 = findStartNode(head1, iLen);
			}else{
				iLen = iLen2 -iLen1;
				head2 = findStartNode(head2, iLen);
			}
			
			while(head1 && head2){
				if(head1 == head2){
					return head1;
				}
				head1 = head1->next;
				head2 = head2->next;
			}
		}
};
*/

using namespace std;

class Solution{
	public:
		ListNode *getIntersectionNode(ListNode *head1, ListNode *head2){
			set<ListNode*> node_set;
			while(head1){
				node_set.insert(head1);
				head1 = head1->next;
			}
			
			while(head2){
				if(node_set.find(head2) != node_set.end()){
					return head2;
				}
				head2 = head2->next;
			}
			return NULL;
		}
};


int main(){
	ListNode a1(1);
	ListNode a2(2);
	ListNode b1(3);
	ListNode b2(4);
	ListNode b3(5);
	ListNode c1(6);
	ListNode c2(7);
	ListNode c3(8);
	a1.next = &a2;
	a2.next = &c1;
	c1.next = &c2;
	c2.next = &c3;
	b1.next = &b2;
	b2.next = &b3;
	b3.next = &c1;
	
	Solution solve;
	ListNode *result = solve.getIntersectionNode(&a1, &b1);
	printf("%d\n", result->val);
	return 0;
}

