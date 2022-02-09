class Solution {
public:
   vector<string> ans;
   map<string, multiset<string>> graph;
   vector<string> findItinerary(vector<vector<string>>& tickets) {
      for (int i = 0; i < tickets.size(); i++) {
         string u = tickets[i][0];
         string v = tickets[i][1];
         graph[u].insert(v);
      }
      visit("JFK");
      reverse(ans.begin(), ans.end());
      return ans;
   }
   void visit(string airport) {
      while(graph[airport].size()) {
         string x = *(graph[airport].begin());
         graph[airport].erase(graph[airport].begin());
         visit(x);
      }
      ans.push_back(airport);
   }
};
