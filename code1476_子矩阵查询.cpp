#include <iostream>
#include <vector>

using namespace std;

class SubrectangleQueries {
private:
	vector<vector<int>> rectangle;
public:
	SubrectangleQueries(vector<vector<int>>& rectangle) {
		this->rectangle = rectangle;
	}

	void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
		for (int i = row1; i <= row2; ++i) {
			for (int j = col1; j <= col2; ++j)
				rectangle[i][j] = newValue;
		}
	}

	int getValue(int row, int col) {
		return rectangle[row][col];
	}
};

int main() {
	vector<vector<int>> rect = {	{1, 2, 1},
									{4, 3, 4}, 
									{3, 2, 1}, 
									{1, 1, 1}	};
	SubrectangleQueries *subrectangleQueries = new SubrectangleQueries(rect);
	cout << "initial rectangle : " << endl;
	for (int i = 0; i < rect.size(); ++i) {
		for (int j = 0; j < rect[i].size(); ++j)
			cout << rect[i][j] << " ";
		cout << endl;
	}
	cout << "get value (0, 2) : " << subrectangleQueries->getValue(0, 2) << endl;
	subrectangleQueries->updateSubrectangle(0, 0, 3, 2, 5);
	cout << "first update : " << endl;
	for (int i = 0; i < rect.size(); ++i) {
		for (int j = 0; j < rect[i].size(); ++j)
			cout << rect[i][j] << " ";
		cout << endl;
	}
	cout << "get value (0, 2) : " << subrectangleQueries->getValue(0, 2) << endl;
	cout << "get value (3, 1) : " << subrectangleQueries->getValue(3, 1) << endl;
	subrectangleQueries->updateSubrectangle(3, 0, 3, 2, 10);
	cout << "second update : " << endl;
	for (int i = 0; i < rect.size(); ++i) {
		for (int j = 0; j < rect[i].size(); ++j)
			cout << rect[i][j] << " ";
		cout << endl;
	}
	cout << "get value (3, 1) : " << subrectangleQueries->getValue(3, 1) << endl;
	cout << "get value (0, 2) : " << subrectangleQueries->getValue(0, 2) << endl;

	delete subrectangleQueries;

	return 0;
}

