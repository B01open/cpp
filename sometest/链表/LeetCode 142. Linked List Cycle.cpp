#include <stdio.h>

#include <set>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};
/*
class Solution{
	public:
		ListNode *detectCycle(ListNode *head){
			ListNode *fastNode = head;
			ListNode *slowNode = head;
			ListNode *meetNode = NULL;
			
			while(fastNode && slowNode){
				fastNode = fastNode->next;
				slowNode = slowNode->next;
				if(!fastNode){
					return NULL;
				}
				fastNode = fastNode->next;
				if(fastNode == slowNode){
					meetNode = fastNode;
					break;
				}
			}
			if(meetNode == NULL){
				return NULL;
			}
			while(head && meetNode){
				if(head == meetNode){
					return meetNode;
				}
				head = head->next;
				meetNode = meetNode->next;
			}
			
			return NULL;
		}
};
*/



class Solution{
	public:
		ListNode *detectCycle(ListNode *head){
			set <ListNode *> node_set;
			while(head){
				if(node_set.find(head) != node_set.end()){
					return head;
				}
				node_set.insert(head);
				head = head->next;
			}
			return NULL;
		}
};


int main(){
	
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode e(5);
	ListNode f(6);
	ListNode g(7);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	f.next = &g;
	g.next = &c;
	Solution solve;
	ListNode *node = solve.detectCycle(&a);
	if (node){
		printf("%d\n", node->val);
	}
	else{
		printf("NULL\n");
	}
	return 0;
}



