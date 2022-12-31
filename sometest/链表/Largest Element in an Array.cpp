#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

class Solution{
	public:
		int findKthLargest(vector<int>& nums, int k){
			priority_queue< int, vector<int>, greater<int> > Q;
			for(int i = 0; i < nums.size(); i++){
				if(	Q.size()  < k){
					Q.push(nums[i]);
				} else if(Q.top() < nums[i]){
					Q.pop();
				    Q.push(nums[i]);
				} 
			}
			return Q.top();
		}
};

int main(){
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(5);
	nums.push_back(6);
	nums.push_back(4);
	Solution solve;
	printf("%d\n", solve.findKthLargest(nums, 2));	
	return 0;
}

