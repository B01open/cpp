#include <stdio.h>
# include <string>
#include <map>

using namespace std;

/*
int main1(){
	int char_map[128] = {0};
	string str = "abcdedgaaxxy";
	
	for(int i = 0; i < str.length(); i++){
		char_map[str[i]]++;
	}
	
	for(int i = 0; i < 128; i++){
		if(char_map[i] > 0){
			printf("[%c] [%d]   %d\n", i, i, char_map[i]);
		}
	}
		
}

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

int hash_fun(int key, int table_len){
	return key%table_len;
}

void insert(ListNode *hash_table[], ListNode *node, int table_len){
	int hash_key = hash_fun(node->val, table_len);
	node->next = hash_table[hash_key];
	hash_table[hash_key] = node;
}

bool search(ListNode *hash_table[], int value, int table_len){
	int hash_key = hash_fun(value, table_len);
	ListNode *head = hash_table[hash_key];
	while(head){
		if(head->val == value){
			return true;
		}
		head = head->next;
	}
	return false;
}

*/

/*
struct ListNode{
	string str;
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){} 
};

int main(){
	map<string, int> hash_map;
	string str1 = "abc";
	string str2 = "aaa";
	string str3 = "xxxxx";
	hash_map[str1] = 1;
	hash_map[str2] = 2;
	hash_map[str3] = 100;
	
	if(hash_map.find(str1) != hash_map.end()){
		printf("%s is in hash_map, value id %d \n", str1.c_str(), hash_map[str1]);
	}
	
	map<string, int> ::iterator it;
	for(it = hash_map.begin(); it != hash_map.end(); it++){
		printf("hash_map[%s]  =  %d \n",it->first.c_str(),it->second);
	}
	return 0;	
}
*/

#include <stdio.h>
#include <string>

class Solution {
public:
	int longestPalindrome(string s){
		int  char_map[128] = {0};
		int max_length = 0;
		int flag = 0;
		for(int i = 0; i < s.length(); i++){
			char_map[s[i]]++;
		}
		
		for(int i = 0; i < 128; i++){
			if(char_map[i]%2 == 0){
				max_length += char_map[i];
			}else{
				max_length += (char_map[i] - 1);
				flag = 1;
			}
		}
		return max_length + flag;
	}
};

int main(){
	std::string s = "abccccddaa";
	Solution solve;
	printf("%d\n", solve.longestPalindrome(s));
	return 0;
}





























