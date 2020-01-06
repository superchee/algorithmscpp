
#include <list>
#include <limits>
#include <algorithm>
#include <vector>

using namespace std;


class MinStack {
    vector<int> s;
    vector<int> mins;
    int size;

public:
    /** initialize your data structure here. */
    MinStack() {
        s.clear();
        mins.clear();
        size = 0;
    }
    
    void push(int x) {
        if(size==0){
            s.push_back(x);
            mins.push_back(x);
            size++;
            return;
        }
        int minV = mins[size-1];
        if(x<minV){
            minV = x;
        }
        s.push_back(x);
        mins.push_back(minV);
        size++;
        return;
    }
    
    void pop() {
        if(size!=0){
            s.pop_back();
            mins.pop_back();
            size--;
            return;
        }
        return;
    }
    
    int top() {
        if(size!=0){
            return s[size-1];
        }
        return -1;
    }
    
    int getMin() {
        if(size==0) return -1;
        return mins[size-1];
    }
};


// class MinStack {
//     list<int> m_list;
//     int size;
// public:
//     /** initialize your data structure here. */
//     MinStack() {
//         size = 0;
//     }
    
//     void push(int x) {
//         m_list.emplace_back(x);
//     }
    
//     void pop() {
//         m_list.pop_back();
//     }
    
//     int top() {
//         return m_list.front();
//     }
    
//     int getMin() {
//         int nMin(INT_MAX);
//         for(auto& per:m_list){
//             nMin = min(nMin, per);
//         }
//         return nMin;
//     }
// };