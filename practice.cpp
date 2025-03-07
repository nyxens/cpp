#include <iostream>
#include <string>
#define TABLE_SIZE 10
using namespace std;
struct HashNode {
    string key;
    int value;
    HashNode* next;
};
HashNode* table[TABLE_SIZE];
void initializeTable() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        table[i] = nullptr;
    }
}
void deleteTable() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        HashNode* entry = table[i];
        while (entry != nullptr) {
            HashNode* prev = entry;
            entry = entry->next;
            delete prev;
        }
        table[i] = nullptr;
    }
}
int hashFunction(const string& key) {
    int hash = 0;
    for (char ch : key) {
        hash = (hash * 31 + ch) % TABLE_SIZE;
    }
    return hash;
}
void insert(const string& key, int value) {
    int hash = hashFunction(key);
    HashNode* prev = nullptr;
    HashNode* entry = table[hash];
    while (entry != nullptr && entry->key != key) {
        prev = entry;
        entry = entry->next;
    }
    if (entry == nullptr) {
        entry = new HashNode{key, value, nullptr};
        if (prev == nullptr) {
            table[hash] = entry;
        } else {
            prev->next = entry;
        }
    } else {
        entry->value = value;
    }
}
int get(const string& key) {
    int hash = hashFunction(key);
    HashNode* entry = table[hash];
    while (entry != nullptr) {
        if (entry->key == key) {
            return entry->value;
        }
        entry = entry->next;
    }

    throw runtime_error("Key not found");
}
void remove(const string& key) {
    int hash = hashFunction(key);
    HashNode* prev = nullptr;
    HashNode* entry = table[hash];
    while (entry != nullptr && entry->key != key) {
        prev = entry;
        entry = entry->next;
    }
    if (entry == nullptr) {
        throw runtime_error("Key not found");
    } else {
        if (prev == nullptr) {
            table[hash] = entry->next;
        } else {
            prev->next = entry->next;
        }
        delete entry;
    }
}
int main() {
    initializeTable();
    insert("key1", 1);
    insert("key2", 2);
    insert("key3", 3);
    cout << "Value for key1: " << get("key1") << endl;
    cout << "Value for key2: " << get("key2") << endl;
    cout << "Value for key3: " << get("key3") << endl;
    remove("key2");
    try {
        cout << "Value for key2: " << get("key2") << endl;
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
    deleteTable();
    return 0;
}
