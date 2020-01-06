#include <unordered_map>

using namespace std;





class LRUCache {


    int size;
    unordered_map<int, list<pair<int,int>>::iterator> m_map;
    list<pair<int,int>> m_list;

public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(!m_map.count(key)){
            return -1;
        }
        m_list.splice(m_list.begin(), m_list, m_map[key]);
        return m_map[key]->second;
    }
    
    void put(int key, int value) {
        if(m_map.count(key)){
            m_map[key]->second = value;
            m_list.splice(m_list.begin(), m_list, m_map[key]);
            return;
        }
        if(m_map.size()==size){
            int nKey = m_list.back().first;
            m_list.pop_back();
            m_map.erase(nKey);
        }
        m_list.emplace_front(key,value);
        m_map[key] = m_list.begin();
    }
};


/**
class LRUCache {
struct node{
    int value;
    int time;
    node(){
        value = 0;
        time = 0;
    }
};

    int size;
    unordered_map<int, node> m;

public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end()){
        for(auto& per:m){
            if(per.second.time < m[key].time){
                per.second.time++;
            }
        }
        m[key].time = 1;
        return m[key].value;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            m[key].value = value;
            for(auto& per:m){
                if(per.second.time < m[key].time){
                    per.second.time++;
                }
            }
            m[key].time = 1;
        }else{
            if(m.size()==size){
                for(auto& per:m){
                    if(per.second.time == size){
                        m.erase(per.first);
                        break;
                    }
                }
            }
            node temp;
            temp.value = value;
            temp.time = 0;
            m[key] = temp;
            for(auto& per:m){
                per.second.time++;  
            }
        }
    }
};
**/