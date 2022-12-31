#include <stdio.h>
#include <stack>

using namespace  std;

class MinStack{
	public:
		void push(int x){
			data.push(x);
			if(minS.empty()){
				minS.push(x);
			} else{
					if(x > minS.top()){
				        x = minS.top();
			        } else{
			         	minS.push(x);
		    	    }
			}	
		}
	
	    void pop(){
	    	data.top();
	    	minS.pop();
		}
		
		int top(){
			return data.top();
		}
	
	    int getMin(){
			return minS.top();
		}
	
	private:
		stack<int> data; 
	    stack<int> minS;
};


int main(){
	MinStack minStack;
	minStack.push(-2);
	printf("top = [%d]\n", minStack.top());
	printf("min = [%d]\n\n", minStack.getMin());	
	minStack.push(0);
	printf("top = [%d]\n", minStack.top());
	printf("min = [%d]\n\n", minStack.getMin());
	minStack.push(-5);
	printf("top = [%d]\n", minStack.top());
	printf("min = [%d]\n\n", minStack.getMin());
	minStack.pop();
	printf("top = [%d]\n", minStack.top());
	printf("min = [%d]\n\n", minStack.getMin());	
	return 0;
}
