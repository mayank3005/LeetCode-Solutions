class SummaryRanges {
public:
    set<int> stream;
    SummaryRanges() {
        stream = {};
    }
    
    void addNum(int value) {
        stream.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        vector<int> tp(2);
        int prev = -2;
        auto itr = stream.begin();
        if(stream.size()) {
            tp[0] = *itr, tp[1] = *itr;
            prev = *itr;
            ++itr;
        }
        for(; itr != stream.end(); itr++) {
            if(prev+1 == *itr) {
                tp[1] = *itr;
            }
            else {
                ans.push_back(tp);
                tp[0] = *itr, tp[1] = *itr;
            }
            prev = *itr;
        }
        ans.push_back(tp);
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */