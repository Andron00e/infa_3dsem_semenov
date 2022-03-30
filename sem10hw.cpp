#include <iostream>
#include <vector>

class Heap {
public:
    Heap() : length_(0), numbs_(std::vector<std::pair<int, int>>(0)), indexes_(std::vector<int>(0)){};

    void Print() {
        for (int i = 0; i < length_; i++) {
            std::cout << numbs_[i].first << " " << numbs_[i].second << std::endl;
        }
    }

    void Add(int num, int vec_num){
        while (indexes_.size() <= vec_num) {
            indexes_.push_back(0);
        }
        indexes_[vec_num]++;
        length_++;
        numbs_.emplace_back(std::make_pair(num, vec_num));
        int i = length_ - 1;
        while(numbs_[i].first < numbs_[(i-1)/2].first) {
            std::swap(numbs_[i], numbs_[(i-1)/2]);
            i = (i-1)/2;
        }
    }

    std::pair<int, int> Remove() {
        std::swap(numbs_[0], numbs_[length_ - 1]);
        std::pair<int, int> temp = numbs_[length_ - 1];
        numbs_.pop_back();
        length_--;
        int i = 0;
        while (i < length_) {
            if (2*i + 2 < length_) {
                if (numbs_[i].first < numbs_[2*i + 1].first and numbs_[i].first < numbs_[2*i + 2].first) {
                    i = length_;
                }
                else {
                    if (numbs_[2*i + 1].first < numbs_[2*i + 2].first) {
                        std::swap(numbs_[i], numbs_[2 * i + 1]);
                        i = 2 * i + 1;
                    }
                    else {
                        std::swap(numbs_[i], numbs_[2 * i + 2]);
                        i = 2 * i + 2;
                    }
                }
            }
            else {
                if (2*i + 1 < length_) {
                        if (numbs_[2*i + 1].first < numbs_[i].first) {
                            std::swap(numbs_[i], numbs_[2 * i + 1]);
                            i = 2 * i + 1;
                        }
                        else {
                            i = length_;
                        }
                    }
                else {
                    i = length_;
                }
            }
        }
        return temp;
    }

    std::pair<int, int> Top() {
        return numbs_[0];
    }

    std::vector<int>& Indexes() {
        return indexes_;
    }

private:
    int length_;
    std::vector<std::pair<int, int>> numbs_;
    std::vector<int> indexes_;
};

int main() {
    int k, n, n_temp, temp;
    std::cin >> k;
    n = 0;
    std::vector<std::vector<int>> vectors(k);
    for (int i = 0; i < k; ++i) {
        std::cin >> n_temp;
        n += n_temp;
        for (int j = 0; j < n_temp; j++) {
            std::cin >> temp;
            vectors[i].push_back(temp);
        }
    }
    Heap heap;
    for(int j = 0; j < k; j++) {
        heap.Add(vectors[j][0], j);
    }
    std::vector<int> res(0);
    while(res.size() < n) {
        res.push_back(heap.Top().first);
        temp = heap.Remove().second;
        if (heap.Indexes()[temp] < vectors[temp].size()) {
            heap.Add(vectors[temp][heap.Indexes()[temp]], temp);
        }
    }
    for (int i = 0; i < res.size(); ++i) {
        std::cout << res[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
