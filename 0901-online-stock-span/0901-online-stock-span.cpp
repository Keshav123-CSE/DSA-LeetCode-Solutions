class StockSpanner {
public:
    vector<int> prices;

    StockSpanner() {
        
    }

    int next(int price) {
        prices.push_back(price);

        int n = prices.size();
        int span = 1;

        for (int i = n - 2; i >= 0; i--) {
            if (prices[i] <= price) {
                span++;
            }
            else {
                break;
            }
        }

        return span;
    }
};