#include <stdio.h>
#include <vector>
using namespace std;

struct treeNode{
	int iVal;
	treeNode *left;
	treeNode *right;
	treeNode(int  x):iVal(x),left(NULL),right(NULL){} 
};

class Solution {
	public:
		vector < vector<int> > pathSum(treeNode *root, int iSum){
			vector<vector<int> > result;
			vector<int> path;
			int path_value  = 0;
			preorder(root, path_value, iSum, path, result);
			return result;
		}
	private:
		void preorder(treeNode *node, int &path_value, int iSum, vector<int> &path, vector< vector<int> > &result){
			if(!node){
				return;
			}		
			path_value += node->iVal;
			path.push_back(node->iVal);
			if(!node->left && !node->right && path_value == iSum){
				result.push_back(path);
			}	
			preorder(node->left, path_value, iSum, path, result);
			
			preorder(node->right, path_value, iSum, path, result);
			path_value -= node->iVal;
			path.pop_back(); 
		}
};

int main(){
	treeNode a(5);
	treeNode b(4);
	treeNode c(8);
	treeNode d(11);
	treeNode e(13);
	treeNode f(4);
	treeNode g(7);
	treeNode h(2);
	treeNode x(5);
	treeNode y(1);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	c.left = &e;
	c.right = &f;
	d.left = &g;
	d.right = &h;
	f.left = &x;
	f.right = &y;
	Solution solve;
	vector<vector<int> > result = solve.pathSum(&a, 22);
	for (int i = 0; i < result.size(); i++){
		for (int j = 0; j < result[i].size(); j++){
			printf("[%d]", result[i][j]);
		}
		printf("\n");
	}
	return 0;
}

