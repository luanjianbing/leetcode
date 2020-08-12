#include <iostream>
#include <vector>

using namespace std;

//柠檬水摊上，每一杯柠檬水的售价为 5 美元。
//
//顾客排队购买你的产品，（按账单 bills 支付的顺序）一次购买一杯。
//
//每位顾客只买一杯柠檬水，然后向你付 5 美元、10 美元或 20 美元。
//你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付 5 美元。
//
//注意，一开始你手头没有任何零钱。
//
//如果你能给每位顾客正确找零，返回 true ，否则返回 false 。

class Solution {
public:
	bool lemonadeChange(vector<int>& bills) {
		// 5 美元 ： 不需要找钱
		// 10 美元 ： 找5美元
		// 20 美元 ： 找15美元（5+5+5或者10+5）
		// 仅需要考虑当前5美元与10美元的数目是否满足要求
		vector<int> dollers(2, 0);	// dollers[0]计数5美元，dollers[1]计数10美元
		for (int i = 0; i < bills.size(); ++i) {
			if (bills[i] == 5) {
				dollers[0]++;
			}
			else if (bills[i] == 10) {
				if (dollers[0] == 0)
					return false;
				dollers[0]--;
				dollers[1]++;
			}
			else {
				if (dollers[1] > 0) {	// 10 + 5
					if (dollers[0] > 0) {
						dollers[1]--;
						dollers[0]--;
					}
					else
						return false;
				}
				else {	// 5 + 5 + 5
					if (dollers[0] > 2)
						dollers[0] -= 3;
					else
						return false;
				}
			}
		}
		return true;
	}
};

int main() {
	vector<int> bills = { 5, 5, 5, 10, 20 };
	Solution s;
	cout << s.lemonadeChange(bills) << endl;

	return 0;
}

