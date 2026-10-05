class FizzBuzz {
private:
    int n;
    int st=1;
    mutex m;
    bool flag=true;
    condition_variable cv;

public:
    FizzBuzz(int n) {
        this->n = n;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        unique_lock<mutex>lock(m);
        while(flag){
            if(st%5!=0 && st%3==0){
                printFizz();
            
                st++;
                if(st==n+1)flag=false;
                cv.notify_all();
            }
            else {
                cv.wait(lock);
            }
            
            
            

            
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        unique_lock<mutex>lock(m);
        while(flag){
            if(st%5==0 && st%3!=0){
                printBuzz();
            
                st++;

                if(st==n+1)flag=false;
                cv.notify_all();
            }
            else {
                cv.wait(lock);
            }
            
            
            

            
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        unique_lock<mutex>lock(m);
        while(flag){
            if(st%5==0 && st%3==0){
                printFizzBuzz();
            
                st++;
                if(st==n+1)flag=false;
                cv.notify_all();
            }
            else {
                cv.wait(lock);
            }
            
            
            

            
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        unique_lock<mutex>lock(m);
        while(flag){
            if(st%3==0 || st%5==0){
                cv.wait(lock);
            }
            else{
                printNumber(st);
            
                st++;
                if(st==n+1)flag=false;
                cv.notify_all();
            }
            
            
            

            
        }


        
    }
};