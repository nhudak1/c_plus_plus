/* Nina Hudak
 * Header file for class Watch (watch.h)
 * April 10, 2019
 */

#undef WATCH_H
#ifndef WATCH_H
#define WATCH_H
#include <time.h>

class Watch
{
    public:
        Watch();
        void start();
        void stop();
        void delay(int duration);
        float seconds();
        float minutes();
        float hours();
    private:
        clock_t ticks_passed;
};

#endif
