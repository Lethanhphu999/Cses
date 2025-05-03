#include<bits/stdc++.h>

using namespace std;

// Component base - không cần virtual!
struct IComponent {
    virtual ~IComponent() = default;
};

template <typename Derived, typename Owner>
struct RuntimeComponent : public IComponent {
    using RuntimeComponentBase = Owner;

    static std::type_index TypeId() {
        return std::type_index(typeid(Derived));
    }
};

class RuntimeComposerBase {
protected:
    std::unordered_map<std::type_index, std::unique_ptr<IComponent>> _components;

public:
    template <typename T>
    void Add(std::unique_ptr<T> component) {
        static_assert(std::is_base_of_v<IComponent, T>);
        _components[T::TypeId()] = std::move(component);
    }

    template <typename T>
    T* Get() {
        auto it = _components.find(T::TypeId());
        if (it != _components.end()) {
            return static_cast<T*>(it->second.get());
        }
        return nullptr;
    }

    template <typename T>
    bool Has() const {
        return _components.find(T::TypeId()) != _components.end();
    }
};

struct MyDocument; // forward declaration

struct NameComponent : public RuntimeComponent<NameComponent, MyDocument> {
    std::string name;

    NameComponent(std::string n) : name(std::move(n)) {}
};

struct MyDocument : public RuntimeComposerBase {
    void Print() {
        if (auto name = Get<NameComponent>()) {
            std::cout << "Name: " << name->name << '\n';
        } else {
            std::cout << "No name component\n";
        }
    }
};

void PrefixSum() {
    vector<int> arr = {1,2,3,4,5,6};
    
    vector<int> prefixsum(arr.size(), 0);

    int cul = 0;
    for (int i = 0; i < arr.size(); i++) {
        cul += arr[i];
        prefixsum[i] = arr[i];
    }

    cout << prefixsum[2] - prefixsum[1];

}

void SparseTable() {
    int dp[8][8]= {0};
    vector<int> arr = {1,3,4,8,6,1,4,2}; 
    for (int i = 0; i < 8; i++) {
        dp[i][i] = arr[i];
    }
    for (int j = 0x2; j <= 8; j=j<<1) {
        for (int i = 0; i < 8; i++) {
            // a = i
            // b = i + j - 1
            // w = (b - a  + 1) / 2
            // q(a, b) = min(q(a, a + w - 1), q(a + w, b));
            if (i + j - 1 < 8) {
                dp[i][i + j - 1] = std::min(dp[i][i + j/ 2 - 1],dp[i + j/2][i + j - 1]);
            }
        }
    }

}



void SlidingWindowMin() {
    deque<pair<int, int>> q;

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &e : a) {
        cin >> e;
    }
    int l = 0, r = 0;
    for (int i = 0; i + k - 1 < n; i++) {
        if (!i) {
            for (int j = 0; j < k; j++) {
                while (!q.empty() && a[j] <= q.back().first) {
                    q.pop_back();
                }
                q.emplace_back(a[j], r++);
            }
        } else { 
            if (l == q.front().second) {
                q.pop_front();
            }
            ++l;
            while (!q.empty() && a[i + k - 1] <= q.back().first) {
                q.pop_back();
            }
            q.emplace_back(a[i + k - 1], r++);
        }

        cout << q.front().first << " ";
    }

}

int main() {
    // MyDocument doc;
    // doc.Add(std::make_unique<NameComponent>("My Document"));
    // doc.Print(); // Output: Name: My Document

    // if (doc.Has<NameComponent>()) {
    //     std::cout << "Document has a name component\n";
    // } else {
    //     std::cout << "Document does not have a name component\n";
    // }
    //SparseTable();
    SlidingWindowMin();
    //std::cout << 31 - __builtin_clz(32);
    return 0;
}    
    