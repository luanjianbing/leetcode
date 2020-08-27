#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

//一个网站域名，如"discuss.leetcode.com"，包含了多个子域名。
//作为顶级域名，常用的有"com"，下一级则有"leetcode.com"，
//最低的一级为"discuss.leetcode.com"。
//当我们访问域名"discuss.leetcode.com"时，
//也同时访问了其父域名"leetcode.com"以及顶级域名 "com"。
//
//给定一个带访问次数和域名的组合，要求分别计算每个域名被访问的次数。
//其格式为访问次数 + 空格 + 地址，例如："9001 discuss.leetcode.com"。
//
//接下来会给出一组访问次数和域名组合的列表cpdomains 。
//要求解析出所有域名的访问次数，输出格式和输入格式相同，不限定先后顺序。

class Solution {
public:
	vector<string> subdomainVisits(vector<string>& cpdomains) {
		vector<string> ans;
		unordered_map<string, int> pairs;
		for (int i = 0; i < cpdomains.size(); ++i) {
			int spaceIdx = cpdomains[i].find(" ");
			int num = atoi(cpdomains[i].substr(0, spaceIdx).c_str());
			string webAddr = cpdomains[i].substr(spaceIdx + 1, cpdomains[i].size());
			while (webAddr.find(".") != -1) {
				int pointIdx = webAddr.find(".");
				if (pairs.find(webAddr) == pairs.end())
					pairs.insert(make_pair(webAddr, num));
				else
					pairs[webAddr] += num;
				webAddr = webAddr.substr(pointIdx + 1, webAddr.length());
			}
			if (pairs.find(webAddr) == pairs.end())
				pairs.insert(make_pair(webAddr, num));
			else
				pairs[webAddr] += num;
			
			}
		for (unordered_map<string, int>::const_iterator iter = pairs.begin();
			iter != pairs.end(); iter++) {
			string anstr = to_string(iter->second);
			anstr.append(" ").append(iter->first);
			ans.push_back(anstr);
		}
		return ans;
	}
};

int main() {
	vector<string> cpdomains = { "900 google.mail.com", "50 yahoo.com", 
		"1 intel.mail.com", "5 wiki.org" };

	Solution s;
	vector<string> res = s.subdomainVisits(cpdomains);
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << endl;
	}

	return 0;
}
