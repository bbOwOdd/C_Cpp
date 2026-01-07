class MedianFinder {
public:
    priority_queue<int> minQ;
    priority_queue<int, vector<int>, greater<int>> maxQ;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxQ.push(num);
        minQ.push(maxQ.top());
        maxQ.pop();
        if(minQ.size() > maxQ.size() + 1){
            maxQ.push(minQ.top());
            minQ.pop();
        }
    }
    
    double findMedian() {
        return minQ.size() == maxQ.size() ? (minQ.top() + maxQ.top()) / 2.0 : minQ.top();
    }
};
