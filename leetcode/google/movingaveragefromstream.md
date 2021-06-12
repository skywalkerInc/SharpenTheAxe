## 22mins
```
#include <deque>
class MovingAverage {
public:
    /** Initialize your data structure here. */
    int windowSize;
    double movingAvg;
    int count;
    deque<int> window;
    
    MovingAverage(int size) {
        windowSize = size;
        movingAvg = 0;
        count = 0;
    }
    
    double next(int val) {
        
        window.push_back(val);
        
        double add = (double)val;
        double sub = 0;
        if (count == windowSize) {
           sub = (double)window.front(); window.pop_front();
           movingAvg = movingAvg + (add - sub) / (double)windowSize;
        }
        else
        {
            count++;
            if (count == 1) {
                movingAvg = (double)add;
            }
            else
            {
                movingAvg = (movingAvg * (count - 1))/ (double)count + add / (double)count;
            }
        }
    
        return movingAvg;
        
    }
};
```