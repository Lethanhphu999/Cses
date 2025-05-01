#include <iostream>
#include <memory>
#include <unordered_map>
#include <typeindex>

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
int main() {
    MyDocument doc;
    doc.Add(std::make_unique<NameComponent>("My Document"));
    doc.Print(); // Output: Name: My Document

    if (doc.Has<NameComponent>()) {
        std::cout << "Document has a name component\n";
    } else {
        std::cout << "Document does not have a name component\n";
    }

    return 0;
}    
    