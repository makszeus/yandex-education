#include <algorithm>
#include <iostream>
#include <vector>

struct Interval {
    int start, end;
};

bool compare(Interval a, Interval b) {
    return a.end < b.end;
}

int main() {
    int n;
    std::cin >> n;
    
    std::vector<Interval> intervals(n);
    
    for (int i = 0; i < n; ++i) {
        std::cin >> intervals[i].start >> intervals[i].end;
    }
    
    std::sort(intervals.begin(), intervals.end(), compare);
    
    int count = 0;
    int last_end = -1;
    
    for (int i = 0; i < n; i++) {
        if (intervals[i].start > last_end) {
            count++;
            last_end = intervals[i].end;
        }
    }
    
    std::cout << count << std::endl;
    
    return 0;
}
