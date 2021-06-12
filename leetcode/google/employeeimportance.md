## 15mins

``` c++
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    
    int getImportance(vector<Employee*> employees, int id) {

        Employee *emp;
        for (int i=0; i<employees.size(); i++) {
            if (id == employees[i]->id) {
                emp = employees[i];
            }
        }
        
        int sum = emp->importance;
        for(int i =0; i<emp->subordinates.size(); i++) {
            sum += getImportance(employees, emp->subordinates[i]);
        }
        
        return sum;
    }
};

// finding the root employee id
// sum of all numbers in that root
```