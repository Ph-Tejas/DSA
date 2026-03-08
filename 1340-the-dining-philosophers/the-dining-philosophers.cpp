class DiningPhilosophers {
public:
    mutex m;
    condition_variable cv[5];
    bool f[5] = {false,false,false,false,false};

    DiningPhilosophers() {}

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {

        unique_lock<mutex> lock(m);

        int left = philosopher;
        int right = (philosopher + 4) % 5;

        cv[left].wait(lock,[&](){
            return f[left] == false;
        });
        f[left] = true;
        pickLeftFork();

        cv[right].wait(lock,[&](){
            return f[right] == false;
        });
        f[right] = true;
        pickRightFork();

        eat();

        f[left] = false;
        putLeftFork();
        cv[left].notify_one();

        f[right] = false;
        putRightFork();
        cv[right].notify_one();
    }
};