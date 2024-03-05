#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval
{
    int low, high;

    Interval(int l, int h) : low(l), high(h) {}
};

vector<Interval> findOverlappingIntervals(const vector<Interval> &intervals)
{
    vector<Interval> result;

    if (intervals.empty())
    {
        return result;
    }

    vector<Interval> sortedIntervals = intervals;
    sort(sortedIntervals.begin(), sortedIntervals.end(), [](const Interval &a, const Interval &b)
         { return a.low < b.low; });

    Interval currentInterval = sortedIntervals[0];

    for (const Interval &nextInterval : sortedIntervals)
    {
        if (currentInterval.high >= nextInterval.low)
        {
            currentInterval.high = max(currentInterval.high, nextInterval.high);
        }
        else
        {
            result.push_back(currentInterval);
            currentInterval = nextInterval;
        }
    }

    result.push_back(currentInterval);
    return result;
}

int main()
{
    vector<Interval> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}, {17, 20}, {5, 9}};

    vector<Interval> overlappingIntervals = findOverlappingIntervals(intervals);

    cout << "Overlapping Intervals:" << endl;
    for (const Interval &interval : overlappingIntervals)
    {
        cout << "[" << interval.low << ", " << interval.high << "] ";
    }
    cout << endl;

    return 0;
}
