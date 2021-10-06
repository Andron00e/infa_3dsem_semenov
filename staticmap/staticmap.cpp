/*
#include <iostream>
#include <algorithm>
#include <vector>

class StaticMap
{

private:
    std::vector<std::pair<int, int> > vector;
    int size;
};

public:
    StaticMap(std::vector<std::pair<int, int> > a){
        sort(a.begin(), a.end());
        vector = a;
        size = a.size();
    };

int Get(int key, int default_value){
    int l = 0;
    int r = size - 1;
    int m;
    while(true)
    {
        m = (l + r)/2;
        if(r == l){
            if(vector[l].first == key) return(vector[l].second);
            break;
        }
        if(vector[m].first == key){
            return(vector[m].second);
        }
        if(vector[m].first > key){
            r = m - 1;
        }
        if(vector[m].first < key){
            l = m + 1;
        }
    }
    return(default_value);
};
bool FindKey(int key){
    int l = 0;
    int r = size - 1;
    int m;
    bool exist = false;
    while(!exist)
    {
        m = (l + r)/2;
        if(r - l <= 1){
            if(vector[l].first == key || vector[r].first == key){
                exist = true;
                continue;
            }
            return(false);
        }
        if(vector[m].first == key){
            exist = true;
            continue;
        }
        if(vector[m].first > key){
            r = m;
        }

        if(vector[m].first < key){
            l = m;
        }
    }
    return(true);
};

int main()
{
int pairs_num, queries_num;
    std::cin >> pairs_num >> queries_num;

    std::vector<std::pair<int, int>> dict;
    for (int i = 0; i < pairs_num; ++i) {
        int key, value;
        std::cin >> key >> value;
        dict.emplace_back(key, value);
    }

    StaticMap map(dict);

    for (int i = 0; i < queries_num; ++i) {
        int key;
        std::cin >> key;
        if (map.FindKey(key)) {
            std::cout << map.Get(key, 0) << std::endl;
        } else {
            std::cout << "no such key" << std::endl;
        }
    }

    return 0;

}
*/
////////////////////////////
#include <iostream>
#include <vector>
#include <algorithm>

class StaticMap {
public:
    StaticMap(const std::vector<std::pair<int, int>>& dict) : dict_(dict) {
        sort(dict_.begin(), dict_.end());
    };

    bool FindKey(int key) {
        if (dict_.empty()) {
            return false;
        }
        int index = BinarySearchLeftmost(0, dict_.size() - 1, key);
        return dict_[index].first == key;
    };

    int Get(int key, int default_value) {
        if (dict_.empty()) {
            return default_value;
        }
        int index = BinarySearchLeftmost(0, dict_.size() - 1, key);
        if (dict_[index].first == key) {
            return dict_[index].second;
        } else {
            return default_value;
        }
    };

private:
    std::vector<std::pair<int, int>> dict_;

    int BinarySearchLeftmost(int left, int right, int search_for) {
        while (left < right) {
            int mid = (left + right) / 2;
            if (!(search_for <= dict_[mid].first)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    };
};

int main() {
    int pairs_num, queries_num;
    std::cin >> pairs_num >> queries_num;

    std::vector<std::pair<int, int>> dict;
    for (int i = 0; i < pairs_num; ++i) {
        int key, value;
        std::cin >> key >> value;
        dict.emplace_back(key, value);
    }

    StaticMap map(dict);

    for (int i = 0; i < queries_num; ++i) {
        int key;
        std::cin >> key;
        if (map.FindKey(key)) {
            std::cout << map.Get(key, 0) << std::endl;
        } else {
            std::cout << "no such key" << std::endl;
        }
    }

    return 0;
}

