class FizzBuzz {
private:
    int n;
    int num;
    mutex m;
    condition_variable cv;
public:
    FizzBuzz(int n) {
        this->n = n;
        num=1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(num<=n){
            
            unique_lock<mutex>lock(m);
            cv.wait(lock,[&](){
                return (num%3==0&&num%5!=0)||(num>n);
            });
            if(num>n){
                cv.notify_all();
                break;
            }

            printFizz();
            num++;
            cv.notify_all();
        
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while(num<=n){
            unique_lock<mutex>lock(m);
            cv.wait(lock,[&](){
                return (num%5==0&&num%3!=0)||(num>n);
            });
            if(num>n){
                cv.notify_all();
                break;
            }

            printBuzz();
            num++;
            cv.notify_all();
        
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while(num<=n){
            unique_lock<mutex>lock(m);
            cv.wait(lock,[&](){
                return (num%15==0)||(num>n);
            });

            if(num>n){
                cv.notify_all();
                break;
            }
            printFizzBuzz();
            num++;
            cv.notify_all();
        
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while(num<=n){
            unique_lock<mutex>lock(m);
            cv.wait(lock,[&](){
                return (num%3!=0&&num%5!=0)||(num>n);
            });
            if(num>n){
                cv.notify_all();
                break;
            }
            printNumber(num);
            num++;
            cv.notify_all();
        
        }
    }
};