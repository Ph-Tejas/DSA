class Foo {
public:
    int st=0;
    mutex m;
    condition_variable not_empty;
    condition_variable not_first;
    condition_variable not_second;
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        unique_lock<mutex> lock(m);
        // printFirst() outputs "first". Do not change or remove this line.
        not_empty.wait(lock,[&](){
            return (st==0);
        });
        st=1;
        printFirst();
        not_first.notify_one();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(m);
        not_first.wait(lock,[&](){
            return (st==1);
        });
        st=2;
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        not_second.notify_one();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(m);
        not_second.wait(lock,[&](){
            return (st==2);
        });
        st=0;
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        not_empty.notify_one();
    }
};