#include <iostream>
#include <memory>

class A {
public:
    A(int n) : n_(n) {}

    int Get() {
        return n_;
    }

    void Set(int n) {
        n_ = n;
    }

private:
    int n_;
};

struct C;

struct B {
    std::shared_ptr<C> x;
};

struct C {
    std::weak_ptr<B> x;
};

int main() {
    std::unique_ptr ptr = std::make_unique<A>(17);
    std::unique_ptr<A> ptr2;
    // std::cout << ptr2->Get() << std::endl;  -- runtime error
    ptr2 = std::move(ptr);
    std::cout << ptr2->Get() << std::endl;

    // shared ptr is all about "shallow copy"
    std::shared_ptr<A> sptr = std::make_shared<A>(18), sptr2;
    sptr2 = sptr;
    sptr->Set(10);
    std::cout << sptr->Get() << ' ' << sptr2->Get() << std::endl;

    std::shared_ptr<B> b = std::make_shared<B>();
    std::shared_ptr<C> c = std::make_shared<C>();
    b->x = c;
    c->x = b;

    return 0;
}
