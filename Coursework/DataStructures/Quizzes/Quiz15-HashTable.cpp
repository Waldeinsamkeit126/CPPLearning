#include <iostream>
#include <vector>
#include <list>
#include <utility>      // for std::pair
#include <functional>   // for std::hash
using namespace std;

template<typename Key, typename Value>
class HashTable {
private:
    struct Entry {
        Key key;
        Value value;
        Entry(const Key& k, const Value& v) : key(k), value(v) {}
    };

    vector<list<Entry>> buckets;
    size_t num_buckets;
    size_t count;

    // 哈希函数：使用标准库的 std::hash
    size_t hash(const Key& key) const {
        return std::hash<Key>{}(key) % num_buckets;  // ✅ 显式使用 std::hash
    }

public:
    explicit HashTable(size_t initial_size = 16)
        : num_buckets(initial_size), count(0) {
        buckets.resize(num_buckets);
    }

    void insert(const Key& key, const Value& value) {
        size_t idx = hash(key);
        auto& bucket = buckets[idx];

        for (auto& entry : bucket) {
            if (entry.key == key) {
                entry.value = value;
                return;
            }
        }

        bucket.emplace_back(key, value);
        ++count;

        if (static_cast<double>(count) / num_buckets > 0.75) {
            rehash();
        }
    }

    bool find(const Key& key, Value& out_value) const {
      // 根据关键字key查找与之对应的value，保存在out_value中返回。
      size_t idx = hash(key);
      const auto& bucket = buckets[idx];
      for (const auto& entry : bucket){
        if (entry.key == key){
            out_value = entry.value;
            return true;
        }
      }
      return false;
    }

    bool remove(const Key& key) {
        size_t idx = hash(key);
        auto& bucket = buckets[idx];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->key == key) {
                bucket.erase(it);
                --count;
                return true;
            }
        }
        return false;
    }

    size_t size() const {
        return count;
    }

private:
    void rehash() {
        size_t old_size = num_buckets;
        num_buckets *= 2;
        vector<list<Entry>> new_buckets(num_buckets);

        for (size_t i = 0; i < old_size; ++i) {
            for (auto& entry : buckets[i]) {
                size_t new_idx = std::hash<Key>{}(entry.key) % num_buckets;  // ✅ 修正这里
                new_buckets[new_idx].push_back(entry);
            }
        }

        buckets.swap(new_buckets);
    }
};

int main() {
    HashTable<string, int> ht;

    ht.insert("apple", 10);
    ht.insert("banana", 20);
    ht.insert("cherry", 30);

    int val;
    if (ht.find("banana", val)) {
        cout << "Found banana: " << val << "\n";
    }

    ht.remove("apple");

    if (!ht.find("apple", val)) {
        cout << "apple not found\n";
    }

    cout << "Total entries: " << ht.size() << "\n";

    return 0;
}
