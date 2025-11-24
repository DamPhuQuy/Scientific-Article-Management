#pragma once
#include <vector>
#include <memory>
#include <stdexcept>

template <typename K, typename V>
class HashMap {
private:
    class Node {
    public:
        K key;
        V value;
        std::unique_ptr<Node> next;

        Node(const K& k, const V& v) : key(k), value(v), next(nullptr) {}
    };

    std::vector<std::unique_ptr<Node>> containers; // array of node
    unsigned int numElements;
    unsigned int capacity;

    static constexpr double MAX_LOAD_FACTOR = 0.75; // neu bang bam da day 75% -> mo rong kich thuoc

private:
    unsigned int hashKey(const K& key) const {
        return std::hash<K>{}(key) % capacity;
    }

    void rehash() {
        unsigned int newCap = capacity * 2;
        std::vector<std::unique_ptr<Node>> newContainers(newCap);

        for (auto& head : containers) {
            Node* current = head.get();
            while (current != nullptr) {
                unsigned int newI = std::hash<K>{}(current->key) % newCap;

                auto newNode = std::make_unique<Node>(current->key, current->value);
                newNode->next = std::move(newContainers[newI]);
                newContainers[newI] = std::move(newNode);

                current = current->next.get();
            }
        }

        containers.swap(newContainers);
        capacity = newCap;
    }

public:
    HashMap(unsigned int initCap = 10) : capacity(initCap), numElements(0) { containers.resize(capacity); }
    ~HashMap() = default;
    HashMap(const HashMap&) = delete;
    HashMap& operator=(const HashMap&) = delete;
    HashMap(HashMap&&) noexcept = default;
    HashMap& operator=(HashMap&&) noexcept = default;
    unsigned int size() const { return numElements; }
    bool isEmpty() const { return numElements == 0; }

    void clear() {
        for (auto& head : containers) {
            head.reset();
        }
        numElements = 0;
    }

    void put(const K& key, const V& value) {
        unsigned int index = hashKey(key); // index to key

        Node* current = containers[index].get();

        // if key contains
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next.get();
        }

        // else append
        auto newNode = std::make_unique<Node>(key, value);
        newNode->next = std::move(containers[index]);
        containers[index] = std::move(newNode);

        numElements += 1;

        // rehash when meet max_load_factor
        if ((double)numElements / capacity > MAX_LOAD_FACTOR)
            rehash();
    } // ~ [] operator d[key] = value

    void putAll(const HashMap& otherMap) {
        otherMap.forEach([this](const K& k, const V& v) {
            this->put(k, v);
        });
    } // ~ d.update(other_dict)

    V& get(const K& key) {
        unsigned int index = hashKey(key);

        Node* current = containers[index].get();

        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next.get();
        }

        throw std::out_of_range("Không tìm thấy khóa!");
    } // ~ [] operator d[key] or d.get[key]

    V getOrDefault(const K& key, const V& defaultVal) const {
        unsigned int index = hashKey(key);
        Node* curr = containers[index].get();

        while (curr) {
            if (curr->key == key)
                return curr->value;
            curr = curr->next.get();
        }

        return defaultVal;
    }

    bool containsKey(const K& key) const {
        unsigned int index = hashKey(key);

        Node* current = containers[index].get();

        while (current != nullptr) {
            if (current->key == key) return true;
            current = current->next.get();
        }
        return false;
    } // key in d

    bool containsValue(const K& key, const V& value) const {
        unsigned int index = hashKey(key);

        Node* current = containers[index].get();

        while (current != nullptr) {
            if (current->key == key) {
                return current->value == value;
            }
            current = current->next.get();
        }
    } // value in d.values()

    bool remove(const K& key) {
        unsigned int index = hashKey(key);

        std::unique_ptr<Node>& head = containers[index];

        Node* current  = head.get();
        Node* previous = nullptr;

        while (current != nullptr) {
            if (current->key == key) {
                if (previous == nullptr) {
                    head = std::move(current->next);
                } else {
                    previous->next = std::move(current->next);
                }
                numElements -= 1;
                return true;
            }
            previous = current;
            current = current->next.get();
        }

        return false;
    } // del d[key] or d.pop(key)

    std::vector<K> keySet() {
        std::vector<K> res;
        res.reserve(numElements);

        forEach([&res](const K& k) -> void {
            res.push_back(k);
        });

        return res;
    } // d.keys()

    std::vector<V> values() {
        std::vector<V> res;
        res.reserve(numElements);

        forEach([&res](const V& v) -> void {
            res.push_back(v);
        });

        return res;
    } // d.values()

    std::vector<std::pair<K, V>> entrySet() {
        std::vector<std::pair<K, V>> res;
        res.reserve(numElements);

        forEach([&res](const K& k, const V& v) -> void {
            res.emplace_back(k, v);
        });

        return res;
    } // d.items();

    template <typename Func>
    void forEach(Func f) const {
        size_t index = 0;

        for (const auto& head : containers) {
            Node* current = head.get();
            while (current != nullptr) {

                // mutable
                if constexpr (std::is_invocable_v<Func, V&>) {
                    f(current->value);
                }
                else if constexpr (std::is_invocable_v<Func, const K&, V&>) {
                    f(current->key, current->value);
                }
                else if constexpr (std::is_invocable_v<Func, const K&, V&, size_t>) {
                    f(current->key, current->value, index);
                }

                // read only
                else if constexpr (std::is_invocable_v<Func, const V&>) {
                    f(current->value);
                }
                else if constexpr (std::is_invocable_v<Func, const K&, const V&>) {
                    f(current->key, current->value);
                }
                else if constexpr (std::is_invocable_v<Func, const K&, const V&, size_t>) {
                    f(current->key, current->value, index);
                }
                else if constexpr (std::is_invocable_v<Func>) {
                    f();
                }
                else {
                    static_assert(!sizeof(Func),
                                  "Unsupported callback signature. Use f(value), f(key, value), or f(key, value, index)");
                }

                index++;
                current = current->next.get();
            }
        }
    }

    // [] operator overload
    V& operator[](const K& key) {
        unsigned int index = hashKey(key);
        Node* curr = containers[index].get();

        while (curr) {
            if (curr->key == key)
                return curr->value;
            curr = curr->next.get();
        }

        auto newNode = std::make_unique<Node>(key, V{});
        Node* newPtr = newNode.get();

        newPtr->next = std::move(containers[index]);
        containers[index] = std::move(newNode);

        numElements++;

        return newPtr->value;
    }
};
