#include <stdio.h>
#include <vector>

using namespace std;

class Solution{
	public:
		int wiggleMaxLength(vector<int> &nums){
			
			if(nums.size() < 2){
				return nums.size();
			}
			int iMaxLength = 1;
			static const int iBegin = 1;
			static const int iUp = 2;
			static const int iDown = 3;
			int iState = 1;
			for(int i = 1; i < nums.size(); i++){
				
				switch(iState){
					case iBegin:
						if(nums[i] > nums[i-1]){
							iState = iUp;
							iMaxLength++;
						}else{
							iState = iDown;
							iMaxLength++;
						}
						break;
					case iUp:
						if(nums[i] < nums[i-1]){
							iState = iDown;
							iMaxLength++;
						}
						break;
					case iDown:
						if(nums[i] > nums[i-1]){
							iState = iUp;
							iMaxLength++;
						}
						break;
				}
				
			}
			return iMaxLength;
		}
};


int main(){
	std::vector<int> nums;
	nums.push_back(1);
	nums.push_back(17);
	nums.push_back(5);
	nums.push_back(10);
	nums.push_back(13);
	nums.push_back(15);
	nums.push_back(10);
	nums.push_back(5);
	nums.push_back(16);
	nums.push_back(8);
	Solution solve;
	printf("%d\n", solve.wiggleMaxLength(nums));
	return 0;
}

