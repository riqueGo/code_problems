package time_based_key_value_store;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class TimeMapValue {
    public String value;
    public int timestamp;

    TimeMapValue(String value, int timestamp) {
        this.value = value;
        this.timestamp = timestamp;
    }
}

class TimeMap {
    private Map<String, List<TimeMapValue>> tm;

    public TimeMap() {
        tm = new HashMap<>();
    }
    
    public void set(String key, String value, int timestamp) {
        TimeMapValue tmValue = new TimeMapValue(value, timestamp);
        if(tm.containsKey(key)) {
            tm.get(key).add(tmValue);
        } else {
            ArrayList<TimeMapValue> tmValues = new ArrayList<>();
            tmValues.add(tmValue);
            tm.put(key, tmValues);
        }
    }
    
    public String get(String key, int timestamp) {
        if(!tm.containsKey(key) || tm.get(key).get(0).timestamp > timestamp) return "";
        
        String ans = "";
        int l = 0, r = tm.get(key).size() - 1, m;
        while(l <= r) {
            m = l+(r-l)/2;
            TimeMapValue tmValue = tm.get(key).get(m);
            if(tmValue.timestamp <= timestamp) {
                ans = tmValue.value;
                l = m+1;
            } else {
                r = m-1;
            }
        }
        return ans;
    }
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap obj = new TimeMap();
 * obj.set(key,value,timestamp);
 * String param_2 = obj.get(key,timestamp);
 */
