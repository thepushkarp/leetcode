class StockSpanner {
public:
    stack<pair<int, int>> stocks;
    int dayCount;
    StockSpanner() {
        dayCount = 0;
    }

    int next(int price) {
        int n = stocks.size();
        while (!stocks.empty() && stocks.top().second <= price)
            stocks.pop();
        dayCount++;
        int span = (stocks.empty()) ? (dayCount) : (dayCount - stocks.top().first);
        stocks.push(make_pair(dayCount, price));
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
