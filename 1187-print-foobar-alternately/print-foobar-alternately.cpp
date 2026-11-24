class FooBar {
private:
    mutex m;
    condition_variable cv;
    int n;
    bool f;

public:
    FooBar(int n) {
        this->n = n;
        f=false;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {

            unique_lock<mutex>lock(m);
        	// printFoo() outputs "foo". Do not change or remove this line.
        	if(f){
                cv.wait(lock);


            }
            printFoo();
            f=true;
            cv.notify_all();


        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex>lock(m);
            if(!f){
                cv.wait(lock);
            }
            


            

        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            f=false;
            cv.notify_all();
        }
    }
};