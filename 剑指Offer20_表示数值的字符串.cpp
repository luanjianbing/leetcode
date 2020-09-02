#include <iostream>
#include <unordered_map>

using namespace std;

//请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
//例如，字符串"+100"、"5e2"、"-123"、"3.1416"、"-1E-16"、"0123"都表示数值，
//但"12e"、"1a3.14"、"1.2.3"、"+-5"及"12e+5.4"都不是。

class Solution {
public:
	enum State {
		STATE_INITIAL,		// 起始空格
		STATE_INT_SIGN,		// 符号位
		STATE_INTEGER,		// 整数部分
		STATE_POINT,		// 小数点（左有整数）
		STATE_POINT_WITHOUT_INT,	// 小数点（左无整数）
		STATE_FRACTION,		// 小数部分
		STATE_EXP,			// 字符e
		STATE_EXP_SIGN,		// 指数符号
		STATE_EXP_NUMBER,	// 指数数字
		STATE_END,			// 末尾空格
	};

	enum CharType {
		CHAR_NUMBER,		// 数字
		CHAR_EXP,			// 字符e
		CHAR_POINT,			// 小数点
		CHAR_SIGN,			// 符号
		CHAR_SPACE,			// 空格
		CHAR_ILLEGAL,		// 非法
	};

	CharType toCharType(char ch) {
		if (ch >= '0' && ch <= '9') {
			return CHAR_NUMBER;
		}
		else if (ch == 'e' || ch == 'E') {
			return CHAR_EXP;
		}
		else if (ch == '.') {
			return CHAR_POINT;
		}
		else if (ch == '+' || ch == '-') {
			return CHAR_SIGN;
		}
		else if (ch == ' ') {
			return CHAR_SPACE;
		}
		else {
			return CHAR_ILLEGAL;
		}
	}

	bool isNumber(string s) {
		unordered_map<State, unordered_map<CharType, State>> transfer{
			{
				STATE_INITIAL,{		// 起始状态
					{ CHAR_SPACE, STATE_INITIAL },	// 空格->起始状态
					{ CHAR_NUMBER, STATE_INTEGER },	// 数字->整数状态
					{ CHAR_POINT, STATE_POINT_WITHOUT_INT },	// 小数点->小数点（无整数）状态
					{ CHAR_SIGN, STATE_INT_SIGN },	// 符号->符号状态
				}
			},{
				STATE_INT_SIGN,{		// 符号
					{ CHAR_NUMBER, STATE_INTEGER },		// 数字->整数
					{ CHAR_POINT, STATE_POINT_WITHOUT_INT },	// 小数点->小数点（无整数）状态
				}
			},{
				STATE_INTEGER,{		// 整数状态
					{ CHAR_NUMBER, STATE_INTEGER },		// 数字->整数
					{ CHAR_EXP, STATE_EXP },		// 指数e->e
					{ CHAR_POINT, STATE_POINT },	// 小数点->小数点（有整数）
					{ CHAR_SPACE, STATE_END },		// 空格->结束
				}
			},{
				STATE_POINT,{
					{ CHAR_NUMBER, STATE_FRACTION },
					{ CHAR_EXP, STATE_EXP },
					{ CHAR_SPACE, STATE_END },
				}
			},{
				STATE_POINT_WITHOUT_INT,{
					{ CHAR_NUMBER, STATE_FRACTION },
				}
			},{
				STATE_FRACTION,
				{
					{ CHAR_NUMBER, STATE_FRACTION },
					{ CHAR_EXP, STATE_EXP },
					{ CHAR_SPACE, STATE_END },
				}
			},{
				STATE_EXP,
				{
					{ CHAR_NUMBER, STATE_EXP_NUMBER },
					{ CHAR_SIGN, STATE_EXP_SIGN },
				}
			},{
				STATE_EXP_SIGN,{
					{ CHAR_NUMBER, STATE_EXP_NUMBER },
				}
			},{
				STATE_EXP_NUMBER,{
					{ CHAR_NUMBER, STATE_EXP_NUMBER },
					{ CHAR_SPACE, STATE_END },
				}
			},{
				STATE_END,{
					{ CHAR_SPACE, STATE_END },
				}
			}
		};

		int len = s.length();
		State st = STATE_INITIAL;

		for (int i = 0; i < len; i++) {
			CharType typ = toCharType(s[i]);
			if (transfer[st].find(typ) == transfer[st].end()) {
				return false;
			}
			else {
				st = transfer[st][typ];
			}
		}
		return st == STATE_INTEGER || st == STATE_POINT || st == STATE_FRACTION || st == STATE_EXP_NUMBER || st == STATE_END;
	}
};

int main() {

	return 0;
}
