#include <cstdlib>
#include <ctime>

/*
 *  Generates unique random numbers between 1000 and 2000
 */
class UniqueRandomNumberGenerator {
    private:
        static const int MINIMUM = 1000;
        static const int MAXIMUM = 2000;
        static const int RANGE = MAXIMUM - MINIMUM;
        bool used[RANGE];
    public:
        UniqueRandomNumberGenerator() {
            srand(time(NULL));
            for(int i=0; i < RANGE; ++i) {
                used[i] = false;
            }
        }
        int generate() {
            int next_id;
            do {
                next_id = (rand() % RANGE) + MINIMUM;
            } while (used[next_id]);
            return next_id;
        }
};