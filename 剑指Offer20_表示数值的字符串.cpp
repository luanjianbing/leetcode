#include <iostream>
#include <unordered_map>

using namespace std;

//��ʵ��һ�����������ж��ַ����Ƿ��ʾ��ֵ������������С������
//���磬�ַ���"+100"��"5e2"��"-123"��"3.1416"��"-1E-16"��"0123"����ʾ��ֵ��
//��"12e"��"1a3.14"��"1.2.3"��"+-5"��"12e+5.4"�����ǡ�

class Solution {
public:
	enum State {
		STATE_INITIAL,		// ��ʼ�ո�
		STATE_INT_SIGN,		// ����λ
		STATE_INTEGER,		// ��������
		STATE_POINT,		// С���㣨����������
		STATE_POINT_WITHOUT_INT,	// С���㣨����������
		STATE_FRACTION,		// С������
		STATE_EXP,			// �ַ�e
		STATE_EXP_SIGN,		// ָ������
		STATE_EXP_NUMBER,	// ָ������
		STATE_END,			// ĩβ�ո�
	};

	enum CharType {
		CHAR_NUMBER,		// ����
		CHAR_EXP,			// �ַ�e
		CHAR_POINT,			// С����
		CHAR_SIGN,			// ����
		CHAR_SPACE,			// �ո�
		CHAR_ILLEGAL,		// �Ƿ�
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
				STATE_INITIAL,{		// ��ʼ״̬
					{ CHAR_SPACE, STATE_INITIAL },	// �ո�->��ʼ״̬
					{ CHAR_NUMBER, STATE_INTEGER },	// ����->����״̬
					{ CHAR_POINT, STATE_POINT_WITHOUT_INT },	// С����->С���㣨��������״̬
					{ CHAR_SIGN, STATE_INT_SIGN },	// ����->����״̬
				}
			},{
				STATE_INT_SIGN,{		// ����
					{ CHAR_NUMBER, STATE_INTEGER },		// ����->����
					{ CHAR_POINT, STATE_POINT_WITHOUT_INT },	// С����->С���㣨��������״̬
				}
			},{
				STATE_INTEGER,{		// ����״̬
					{ CHAR_NUMBER, STATE_INTEGER },		// ����->����
					{ CHAR_EXP, STATE_EXP },		// ָ��e->e
					{ CHAR_POINT, STATE_POINT },	// С����->С���㣨��������
					{ CHAR_SPACE, STATE_END },		// �ո�->����
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
