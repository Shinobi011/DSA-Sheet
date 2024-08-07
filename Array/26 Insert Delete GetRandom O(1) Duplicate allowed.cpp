// Time Complexity -> O(1)
// Space Somplexity -> O(n)
class RandomizedCollection {
public:
    vector<int> vec;
    unordered_map<int, unordered_set<int>> mp;

    RandomizedCollection() {
    }
    
    bool insert(int val) {
        bool contains = mp.find(val) != mp.end();
        vec.push_back(val);
        mp[val].insert(vec.size() - 1);
        return !contains;
    }
    
    bool remove(int val) {
        if (mp.find(val) == mp.end() || mp[val].empty())
            return false;

        int idx = *mp[val].begin();
        int lastVal = vec.back();

        // Move the last element to the place of the element to delete
        vec[idx] = lastVal;
        mp[val].erase(idx);

        if (idx != vec.size() - 1) {
            mp[lastVal].erase(vec.size() - 1);
            mp[lastVal].insert(idx);
        }

        vec.pop_back();
        if (mp[val].empty())
            mp.erase(val);

        return true;
    }

    // Get a random element from the collection. 
    int getRandom() {
        if (vec.empty()) {
            throw runtime_error("Cannot get a random element from an empty collection");
        }
        int idx = rand() % vec.size();
        return vec[idx];
    }
};
