#include <string>
#include <vector>
#include <string>

using namespace std;
vector<pair<string, int> > arr = {{"zero", 0},{"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};

int solution(string s) {
    int answer = 0;

    for(auto i = 0 ; i < s.size() ; ++i)
    {
        if (s[i] < '0' || s[i] > '9')
		{
			for(auto &j : arr)
			{
				if (s.substr(i, j.first.size()) == j.first)
				{
					answer = answer * 10 + j.second;
					i += j.first.size();
				}
			}
		}
		else
			answer = answer * 10 + (s[i] - '0');
    }
    return answer;
}
