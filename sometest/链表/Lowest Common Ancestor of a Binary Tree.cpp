#include <stdio.h>
#include <vector>
#include <set>

using namespace std; 

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL) {}
};

/*
@node:根节点
@search:待搜索的结点
@path:搜索路径
@result:搜索结果路径 
@finish:1:搜索成功；0：搜索失败 
*/
void preorder(TreeNode* node, TreeNode* search, vector<TreeNode*>&path,vector<TreeNode*>&result, int &finish){
	
	if(!node || finish == 1){
		return;
	} 

	path.push_back(node);
	if(node == search){
		finish = 1;
		result = path;
	}	
	
	preorder(node->left, search, path, result, finish);
	preorder(node->right, search, path, result, finish);
	
	path.pop_back();
}

/*
@root:根节点
@p:待搜索结点
@q:带搜索节点 
*/
class Solution {
	public:
		TreeNode *lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
			vector<TreeNode*> path;
			vector<TreeNode*> node_p_path;
			vector<TreeNode*> node_q_path;
			int finish = 0;
			preorder(root, p, path, node_p_path, finish);
			path.clear();
			finish = 0;
			preorder(root, q, path, node_q_path, finish);
			int path_len = 0;
			if(node_p_path.size() > node_q_path.size()){
				path_len = node_q_path.size();
			}else{
				path_len = node_p_path.size();
			}
			
			TreeNode *result = 0;
			
			for(int i = 0; i < path_len; i++){
				if(node_p_path[i] == node_q_path[i]){
					result = node_q_path[i];
				}
			}
		    return result;
		}
};

int main(){
	TreeNode a(3);
	TreeNode b(5);
	TreeNode c(1);
	TreeNode d(6);
	TreeNode e(2);
	TreeNode f(0);
	TreeNode x(8);
	TreeNode y(7);
	TreeNode z(4);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.left = &f;
	c.right = &x;
	e.left = &y;
	e.right = &z;
	
	Solution solve;
	TreeNode *result = solve.lowestCommonAncestor(&a, &b, &f);
	printf("lowestCommonAncestor = %d\n", result->val);
	result = solve.lowestCommonAncestor(&a, &d, &z);
	printf("lowestCommonAncestor = %d\n", result->val);
	result = solve.lowestCommonAncestor(&a, &b, &y);
	printf("lowestCommonAncestor = %d\n", result->val);
	
	return 0;
}



