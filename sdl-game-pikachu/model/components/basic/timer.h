//
//  timer.h
//  sdl-game-pikachu
//
//  Created by Ondřej März on 05.11.2023.
//

#ifndef timer_h
#define timer_h

#include <chrono>

/**
 * Class timer.
 *
 * Provides ability to measure time.
 *
 * \since This function is available since 1.0.
 *
 */
class timer {
    
public:
    
    /**
     * Timer constructor.
     *
     * Constructs timer class. Turns on clocks. Sets measured time to zero.
     *
     * \since This function is available since 1.0.
     *
     */
    timer( void ): start(std::chrono::steady_clock::now()), limit(0) { }
    
    /**
     * Timer constructor.
     *
     * Constructs timer class. Turns on clocks. Sets measured time.
     *
     * \param sec seconds we want to know wheter elapsed or not.
     *
     * \since This function is available since 1.0.
     *
     */
    timer( double sec ): start(std::chrono::steady_clock::now()), limit(sec) { }
    
    /**
     * Compars times.
     *
     * Tests if given number of seconds have passed since construction or reseting.
     *
     * \param sec seconds that are asked if they have passed.
     *
     * \return true if given seconds have passed, false otherwise.
     *
     * \since This function is available since 1.0.
     *
     */
    bool elapsed( double sec ) const { return sec < (double) ((std::chrono::duration<double>)(std::chrono::steady_clock::now()-start)).count(); }
    
    /**
     * Compars times.
     *
     * Tests if given number of seconds have passed since construction or reseting.
     *
     * \return true if given seconds have passed, false otherwise.
     *
     * \since This function is available since 1.0.
     *
     */
    bool elapsed( void ) const { return limit < (double) ((std::chrono::duration<double>)(std::chrono::steady_clock::now()-start)).count(); }
    
    /**
     * Resets timer.
     *
     * Deleted old time stamp and saves current time.
     *
     * \since This function is available since 1.0.
     *
     */
    void reset( void ) { start = std::chrono::steady_clock::now(); }
    
    /**
     * Sets timer limit.
     *
     * Limit is used when asked if elapsed.
     *
     * \param sec seconds that will be asked if they have elapsed.
     *
     * \since This function is available since 1.0.
     *
     */
    void set( double sec ) { limit = sec; }
    
private:
    
    /**
     * Time stamp.
     *
     * Stores last time timer was reseted or contructed.
     *
     * \since This function is available since 1.0.
     *
     */
    std::chrono::time_point<std::chrono::steady_clock> start;
    
    /**
     * Measured time.
     *
     * Stores time limit we want to know wheter elapsed or not.
     *
     * \since This function is available since 1.0.
     *
     */
    double limit;
};

#endif /* timer_h */
