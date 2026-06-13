class DiningPhilosophers {
    vector<bool> forks;
    mutex mx;
    condition_variable cv;
public:
    DiningPhilosophers(): forks(5, false) {}

    void wantsToEat(int id,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
		unique_lock<mutex> lock{mx};
        cv.wait(lock, [&](){
            return forks[id] == false && forks[(id+1)%5] == false;
        });
        forks[id] = forks[(id+1)%5] = true;
        pickLeftFork(); pickRightFork(); eat();  putLeftFork(); putRightFork();
        forks[id] = forks[(id+1)%5] = false;
        cv.notify_all();
    }
};