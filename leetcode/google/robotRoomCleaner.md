```
Comments:
Nice use of set for visited cells
```

```c++
/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */


class Solution {
    vector<pair<int, int>> dirs;
    set<pair<int, int>> visited;
public:
    
    void goBack(Robot& robot) {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }
    
    void dfs(Robot& robot, int dirIndex, pair<int, int> currCell) {
        visited.insert(currCell);
        robot.clean();
        
        for (int i=0; i<dirs.size(); i++) {
            int newDirIndex = (dirIndex+i) % dirs.size();
            pair <int, int> newCell = {currCell.first + dirs[newDirIndex].first, currCell.second + dirs[newDirIndex].second};
            
            if (!visited.count(newCell) && robot.move()) {
                dfs(robot, newDirIndex, newCell);
                goBack(robot);
            }
            
            robot.turnRight();
        }
    }
    
    void cleanRoom(Robot& robot) {
        dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        dfs(robot, 0, {0,0});
    }
};


```