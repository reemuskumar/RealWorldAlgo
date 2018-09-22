#include <iostream>

using namespace std;

int* SimpleStockSpan(int *quotes, int n)
{
    // CreateArray
    int *spans = new int[n];
    
    for (int i = 0; i < n; i++) {
        int k = 1;
        bool span_end = false;
        
        while (((i - k) >= 0) and not span_end) {
            if (quotes[i - k] <= quotes[i]) {
                k = k + 1;
            } else {
                span_end = true;
            }
        }
        spans[i] = k;
    }
    return spans;
}

int main()
{
    const int n = 7;
    int quotes[n] = {100, 80, 60, 70, 60, 75, 85};
    int *spans;
    
    spans = SimpleStockSpan(quotes, n);
    for (int i = 0; i < n; i++) {
        cout << "Index: " << i 
             << " Quotes: " << quotes[i] 
             << " StockSpan: " << spans[i] << endl;
    }
    return 0;
}
