#include <iostream>
#include <vector>

using namespace std;

//你有 4 张写有 1 到 9 数字的牌。
//你需要判断是否能通过 *， / ， + ， - ，(，) 的运算得到 24。
//
//示例 1:

class Solution {
public:
	static constexpr int TARGET = 24;	// 目标和值
	static constexpr double EPSILON = 1e-6;	// 实数除法存在误差，在10(-6)内认为符合
	static constexpr int ADD = 0, MULTIPLY = 1, SUBTRACT = 2, DIVIDE = 3;	// 定义4种运算操作

	bool judgePoint24(vector<int> &nums) {
		vector<double> l;
		for (const int &num : nums) {					// 因为考虑实数除法而不是整数除法
			l.emplace_back(static_cast<double>(num)); // 强制转换为double型进行处理
		}
		return solve(l);
	}

	bool solve(vector<double> &l) {
		if (l.size() == 0) {	// 无输入，无法构数
			return false;
		}
		if (l.size() == 1) {	// 只有一个输入，判断输入值与target的差值是否符合要求
			return fabs(l[0] - TARGET) < EPSILON;
		}
		int size = l.size();	// 计算输入个数size
		for (int i = 0; i < size; i++) {	// 遍历输入数(double)
			for (int j = 0; j < size; j++) {	// 遍历当前数的所有组合
				if (i != j) {	// 考虑除本身数之外的组合
					vector<double> list2 = vector<double>();
					// 这里用两个数计算出的组合取代已经组合的两位数
					for (int k = 0; k < size; k++) {
						if (k != i && k != j) {	// 压入除已组合的两个数的其他数
							list2.emplace_back(l[k]);
						}
					}
					for (int k = 0; k < 4; k++) {
						if (k < 2 && i > j) {	// 加减交换律 
							continue;
						}
						// 每两个数的组合所有计算值重新压入list
						if (k == ADD) {
							list2.emplace_back(l[i] + l[j]);
						}
						else if (k == MULTIPLY) {
							list2.emplace_back(l[i] * l[j]);
						}
						else if (k == SUBTRACT) {
							list2.emplace_back(l[i] - l[j]);
						}
						else if (k == DIVIDE) {
							if (fabs(l[j]) < EPSILON) {	// 判断除数为0的情况
								continue;
							}
							list2.emplace_back(l[i] / l[j]);
						}

						if (solve(list2)) {
							return true;
						}
						list2.pop_back();
					}
				}
			}
		}
		return false;
	}
};

int main() {
	vector<int> nums = { 4, 1, 8 ,7 };
	Solution s;
	cout << s.judgePoint24(nums) << endl;

	return 0;
}
