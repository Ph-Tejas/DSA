class DiningPhilosophers {
public:
    mutex m;
    condition_variable cv0;
    condition_variable cv1;
    condition_variable cv2;
    condition_variable cv3;
    condition_variable cv4;
    bool f0=false,f1=false,f2=false,f3=false,f4=false;
    DiningPhilosophers() {
        
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {

                        unique_lock<mutex>lock(m);
                        
                        if(philosopher==0){
                            cv0.wait(lock,[&](){
                                return f0==false;
                            });
                            f0=true;
                            pickLeftFork();
                            cv4.wait(lock,[&](){
                                return f4==false;
                            });
                            f4=true;
                            pickRightFork();
                            eat();
                            f0=false;
                            putLeftFork();

                            cv0.notify_all();
                            f4=false;
                            putRightFork();
                            cv4.notify_all();
                        }
                        if(philosopher==1){
                            cv1.wait(lock,[&](){
                                return f1==false;
                            });
                            f1=true;
                            pickLeftFork();
                            cv0.wait(lock,[&](){
                                return f0==false;
                            });
                            f0=true;
                            pickRightFork();
                            eat();
                            f1=false;
                            putLeftFork();

                            cv1.notify_all();
                            f0=false;
                            putRightFork();
                            cv0.notify_all();
                        }
                        if(philosopher==2){
                            cv2.wait(lock,[&](){
                                return f2==false;
                            });
                            f2=true;
                            pickLeftFork();
                            cv1.wait(lock,[&](){
                                return f1==false;
                            });
                            f1=true;
                            pickRightFork();
                            eat();
                            f2=false;
                            putLeftFork();

                            cv2.notify_all();
                            f1=false;
                            putRightFork();
                            cv1.notify_all();
                        }
                        if(philosopher==3){
                            cv3.wait(lock,[&](){
                                return f3==false;
                            });
                            f3=true;
                            pickLeftFork();
                            cv2.wait(lock,[&](){
                                return f2==false;
                            });
                            f2=true;
                            pickRightFork();
                            eat();
                            f3=false;
                            putLeftFork();

                            cv3.notify_all();
                            f2=false;
                            putRightFork();
                            cv2.notify_all();

                        }
                        if(philosopher==4){
                            cv4.wait(lock,[&](){
                                return f4==false;
                            });
                            f4=true;
                            pickLeftFork();
                            cv3.wait(lock,[&](){
                                return f3==false;
                            });
                            f3=true;
                            pickRightFork();
                            eat();
                            f4=false;
                            putLeftFork();

                            cv4.notify_all();
                            f3=false;
                            putRightFork();
                            cv3.notify_all();
                        }
                        
		
    }
};