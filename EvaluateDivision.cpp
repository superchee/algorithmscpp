#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> dict;

        string from, to;

        vector<double> results;

        for(int i = 0; i < equations.size(); i++){
            from = equations[i][0];
            to = equations[i][1];
            dict[from][to] = values[i];
            dict[to][from] = 1/values[i];
            dict[from][from] = dict[to][to] = 1.0;
        }

        for(auto& k:dict){
            for(auto& i:dict[k.first]){
                for(auto& j:dict[k.first]){
                    dict[i.first][j.first] = dict[i.first][k.first]*dict[k.first][j.first];
                }
            }
        }


        for(auto& query:queries){
            from = query[0];
            to = query[1];
            if(dict.find(from) != dict.end() && dict[from].find(to)!=dict[from].end()){
                results.push_back(dict[from][to]);
            }
            else{
                results.push_back(-1.0);
            }
        }

        return results;

    }
};