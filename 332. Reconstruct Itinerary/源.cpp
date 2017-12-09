/*
* Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], 
* reconstruct the itinerary in order.
* All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.
*/
#include<vector>
#include<unordered_map>
#include<set>
#include<stack>
using namespace std;

class Solution {
public:
	vector<string> findItinerary(vector<pair<string, string>> tickets) {
		unordered_map<string, multiset<string>> vertexes;
		for (auto &edge : tickets)
		{
			vertexes[edge.first].insert(edge.second);
		}
		stack<string> portStack;
		portStack.push("JFK");
		vector<string> route;
		while (!portStack.empty())
		{
			string from = portStack.top();
			if (vertexes[from].empty())
			{
				route.push_back(from);
				portStack.pop();
				continue;
			}
			portStack.push(*vertexes[from].begin());
			vertexes[from].erase(vertexes[from].begin());
		}
		reverse(route.begin(), route.end());
		return route;
	}
};

int main()
{
	vector<pair<string, string>> graph = { {"EZE","AXA"},{"TIA","ANU"},{"ANU","JFK"}
	,{"JFK","ANU"},{"ANU","EZE"},{"TIA","ANU"},{"AXA","TIA"},{"TIA","JFK"},{"ANU","TIA"},{"JFK","TIA"} };
	Solution s;
	auto r=s.findItinerary(graph);
	return 0;
}