class ZeroEvenOdd {
private:
    int n;
    int st=0;
    mutex m;
    condition_variable cv;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {

        unique_lock<mutex>lock(m);
        for(int i=0;i<n;i++){
            cv.wait(lock,[&](){
                return (!(st&1));
            });
            printNumber(0);
            st++;
            cv.notify_all();
        }
        

        
    }

    void even(function<void(int)> printNumber) {
        unique_lock<mutex>lock(m);
        for(int i=2;i<=n;i+=2){
            cv.wait(lock,[&](){
                return ((((st+1)/2))==i);
            });
            printNumber(i);
            st++;
            cv.notify_all();
        }
        
    }

    void odd(function<void(int)> printNumber) {
        unique_lock<mutex>lock(m);
        for(int i=1;i<=n;i+=2){
            cv.wait(lock,[&](){
                return ((((st+1)/2))==i);
            });
            printNumber(i);
            st++;
            cv.notify_all();
        }
    }
};