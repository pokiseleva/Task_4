#include <sstream>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <set>
#include <map>
#include <memory>
#include <iterator>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

vector<string> Task4(istream& is = cin)
{
	string s;
	getline(is, s);
	vector <string> strings;
	string word;
	stringstream d(s);
	while (d >> word) strings.push_back(word);

	if (begin(strings) == end(strings))
		return strings;
	auto last = end(strings) - 1;
	if (*last == ".")
	{
		strings.erase(last);
		if (begin(strings) == end(strings))
			return strings;
		last = end(strings) - 1;
	}

	const  string lw = *(last);

	while (true)
	{
		auto t = find(begin(strings), end(strings), lw);
		if (t == end(strings))
			break;
		else strings.erase(t);
	}
	int e;
	for (auto& a : strings)
	{
		auto k = a.begin();
		for(auto it = a.begin()+1; it != a.end(); it++)
			if (*it == *k)
			{
				e = distance(a.begin(), it);
				a.erase(e, 1);
				it -= 1;
			}
	};
	return strings;

}


int main()
{
	vector<string> s = Task4();
	for (auto it = s.begin(); it != s.end(); it++)
		cout << *it << " ";
	
}