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
    StaticMap x({{1, 27}, {14, 414}, {33, 66}});
    std::cout << x.FindKey(99) << std::endl;
    std::cout << x.FindKey(1) << std::endl;
    std::cout << x.Get(1, 2020) << std::endl;
    std::cout << x.Get(18, 2021) << std::endl;
    return 0;
}
