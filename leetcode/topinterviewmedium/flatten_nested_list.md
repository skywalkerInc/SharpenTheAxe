

```
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

#include <stack>

class NestedIterator {
public:
    stack <vector<NestedInteger>> listSt;
    stack <int> indexSt;
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        indexSt.push(0);
        listSt.push(nestedList);
    }
    
    void make_stack_top_an_int() {
        while (!listSt.empty()) {
            if (indexSt.top() >= listSt.top().size()) {
                indexSt.pop();
                listSt.pop();
                continue;
            }
            
            if (listSt.top()[indexSt.top()].isInteger()) {
                break;
            }
            
            listSt.push(listSt.top()[indexSt.top()].getList());
            int nextIndex = indexSt.top() + 1;
            indexSt.pop();
            indexSt.push(nextIndex);
            indexSt.push(0);
        }
    }
    
    int next() {
        make_stack_top_an_int();
        int currpos = indexSt.top();
        indexSt.pop();
        indexSt.push(currpos + 1);
        return listSt.top()[currpos].getInteger();
    }
    
    
    bool hasNext() {
        make_stack_top_an_int();
        return !indexSt.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
```


```
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

#include <stack>

class NestedIterator {
public:
    stack<NestedInteger> st;
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size()-1; i >=0 ; i--) {
            // cout << i << endl;
            st.push(nestedList[i]);
        }
    }
    
    void make_stack_top_an_int() {
        while (!st.empty() && !st.top().isInteger()) {
            vector<NestedInteger> list = st.top().getList();
            st.pop();
            for (int i = list.size()-1; i>=0; i--) {
                st.push(list[i]);
            }
        }
    }
    
    int next() {
        make_stack_top_an_int();
        int ret = st.top().getInteger();
        st.pop();
        return ret;
    }
    
    
    bool hasNext() {
        make_stack_top_an_int();
        return !st.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
```