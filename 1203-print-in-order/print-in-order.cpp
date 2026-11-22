class Foo {
private:
    mutex mtx1;
    mutex mtx2;
public:
    Foo() {
        mtx1.lock(); 
        mtx2.lock(); 
    }

    void first(function<void()> printFirst) {
        printFirst();
        mtx1.unlock(); 
    }

    void second(function<void()> printSecond) {
        mtx1.lock(); 
        printSecond();
        mtx2.unlock(); 
    }

    void third(function<void()> printThird) {
        mtx2.lock();
        printThird();
    }
};