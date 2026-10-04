class Foo {
public:
    atomic<int> flag{0};
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        while(flag!=0){
            
        }
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        flag++;
    }

    void second(function<void()> printSecond) {
        while(flag!=1){
            
        }
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        flag++;
    }

    void third(function<void()> printThird) {
        while(flag!=2){
            
        }
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        flag=0;
    }
};