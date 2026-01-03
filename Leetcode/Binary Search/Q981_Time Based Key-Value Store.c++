class TimeMap {
public:
    using pii = pair<int, string>;
    unordered_map<string, vector<pii>> map;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        auto& pairs = map[key];
        pii p = {timestamp, string({127})};
        auto it = upper_bound(pairs.begin(), pairs.end(), p);
        return it == pairs.begin() ? "" : (it - 1)->second;
    }
};
