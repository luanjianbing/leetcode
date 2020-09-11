#include <iostream>
#include <functional>

using namespace std;

class DiningPhilosophers {
private:
	pthread_mutex_t forks[5];
public:
	DiningPhilosophers() {
		for (int i = 0; i < 5; ++i)
			pthread_mutex_init(forks + i, NULL);
	}

	void wantsToEat(int philosopher,
		function<void()> pickLeftFork,
		function<void()> pickRightFork,
		function<void()> eat,
		function<void()> putLeftFork,
		function<void()> putRightFork) {
		int left_hand = philosopher, right_hand = (philosopher + 1) % 5;	// 左右手序号
		int ret1 = 1, ret2 = 1;
		while (ret1 || ret2) {	// 尝试同时锁两个直到成功
			if (ret1 == 0) pthread_mutex_unlock(forks + left_hand);
			if (ret2 == 0) pthread_mutex_unlock(forks + right_hand);
			ret1 = pthread_mutex_trylock(forks + left_hand);
			ret2 = pthread_mutex_trylock(forks + right_Hand);
		}
		pickLeftFork();
		pickRightFork();
		eat();
		putLeftFork();
		putRightFork();
		pthread_mutex_unlock(forks + left_hand);
		pthread_mutex_unlock(forks + right_hand);
	}
};

int main() {

	return 0;
}
