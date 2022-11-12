class MedianFinder {
    priority_queue<int> mx;
    priority_queue<int,vector<int>,greater<int>> mn;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(mx.size()<=mn.size()){
            if(mn.size()==0 or num<mn.top()) mx.push(num);
            else{
                int val=mn.top();mn.pop();
                mx.push(val);mn.push(num);
            }
        }else{
            if(num<mx.top()){
                int val=mx.top();mx.pop();
                mn.push(val);mx.push(num);
            }else
                mn.push(num);
        }        
    }
    
    double findMedian() {
        if(mx.size()==mn.size()) return (mx.top()+mn.top())/2.0;
        else if(mx.size()>mn.size()) return mx.top();
        else return mn.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */