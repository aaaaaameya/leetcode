#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstdlib>

class RandomizedSet {
public:
    std::vector<int> set_values;
    std::unordered_map<int, int> set_indices;

    RandomizedSet() {
    }
    
    bool insert(int val) {
        if (set_indices.contains(val)) return false;

        set_indices.insert({val, set_values.size()});
        set_values.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        auto search = set_indices.find(val);
        if (search == set_indices.end()) {
            return false;
        } else {
            int index = search->second;
            std::swap(set_values[index], set_values[set_values.size() - 1]);

            if (set_values.size() > 1) {
                set_indices.erase(set_values[index]);
                set_indices.insert({set_values[index], index});
            }

            set_indices.erase(val);
            set_values.pop_back();
            return true;
        }
    }
    
    int getRandom() {
        int num_values = set_values.size();

        return set_values[rand() % num_values];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */