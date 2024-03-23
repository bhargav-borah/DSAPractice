#include<vector>

int getSingleElement(vector<int> &arr){
	int ans = 0;
	for (auto it: arr) ans = ans ^ it;
	return ans;
}