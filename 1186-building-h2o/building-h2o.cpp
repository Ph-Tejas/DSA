class H2O {
public:
    int o=0;
    mutex m;
    condition_variable cv; 
    H2O() {
        
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex>lock(m);
        cv.wait(lock,[&](){
            return (o>=1);
        });
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        o++;
        if(o==3){
            
            o=0;
        }
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex>lock(m);
        cv.wait(lock,[&](){
            return (o==0);
        });
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        o++;

        cv.notify_all();

    }
};