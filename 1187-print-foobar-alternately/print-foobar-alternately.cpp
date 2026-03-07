#include<bits/stdc++.h>
class FooBar {
private:
    int n;
    mutex m;
    bool flag=false;
    condition_variable cv;
public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(m);
            cv.wait(lock,[&](){
                return !flag;
            });
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            cv.notify_all();
            flag=true;
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {

            unique_lock<mutex> lock(m);
            cv.wait(lock,[&](){
                return flag;
            });

            
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            flag=false;

            cv.notify_all();
        }
    }
};