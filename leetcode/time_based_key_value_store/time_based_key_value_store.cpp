/*
 * Time Complexity:
 *   - set: O(1) amortized
 *     - Each set operation appends to a vector.
 *   - get: O(log N)
 *     - N is the number of entries for the given key.
 *     - Binary search is used to find the value.
 *
 * Space Complexity: O(K + N)
 *   - K is the number of unique keys.
 *   - N is the total number of set operations (total stored key-value-timestamp triples).
 */

#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

using std::string;
using std::unordered_map;
using std::vector;

struct TimeMapValue {
    string value;
    int timestamp;

    TimeMapValue(string _value, int _timestamp) : value(_value), timestamp(_timestamp) {}
};

class TimeMap {
private:
    unordered_map<string, vector<TimeMapValue>> tm;
public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        if(tm.find(key) != tm.end()) {
            tm[key].push_back(TimeMapValue(value, timestamp));
        } else {
            tm[key] = {TimeMapValue(value, timestamp)};
        }
    }
    
    string get(string key, int timestamp) {
        if(tm.find(key) == tm.end() || timestamp < tm[key][0].timestamp) return "";

        int l = 0, r = tm[key].size()-1, m;
        string ans = "";

        while(l<=r) {
            m = l+(r-l+1)/2;
            if(tm[key][m].timestamp <= timestamp) {
                l = m+1;
                ans = tm[key][m].value;
            } else r = m-1;
        }

        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main() {
    // Example usage
    TimeMap* obj = new TimeMap();

    obj->set("love", "high", 10);
    obj->set("love", "low", 20);

    std::cout << obj->get("love", 5) << std::endl;
    std::cout << obj->get("love", 10) << std::endl; 
    std::cout << obj->get("love", 15) << std::endl; 
    std::cout << obj->get("love", 20) << std::endl; 
    std::cout << obj->get("love", 25) << std::endl; 

    delete obj;
    return 0;
}