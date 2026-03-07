class Foo {
public:
    stack<int>st;
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
            return (st.empty());
        });
        printFirst();
        st.push(1);
        not_first.notify_one();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(m);
        not_first.wait(lock,[&](){
            return ((!st.empty())&&st.top()==1);
        });
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        st.push(2);
        not_second.notify_one();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(m);
        not_second.wait(lock,[&](){
            return ((!st.empty())&&st.top()==2);
        });
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        st.pop();
        st.pop();
        not_empty.notify_one();
    }
};