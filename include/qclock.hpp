/* -*- mode: C++; tab-width: 4; -*- */

/**
 * @file qclock.hpp
 *
 * @brief This header file defines the QClock class which is used as a timing
 * mechanism in the QSpike library.
 *
 * @author      Liam Bucci
 * @date        7/21/2013
 */

// Include guard
#ifndef _QCLOCK_HPP
#define _QCLOCK_HPP


class QClock : public QObject
{
    Q_OBJECT

public:
    QClock(); //< Default constructor for QClock type

    /**
     * Get the current time.
     */
    uint64_t GetTime() { return this->_ticks; };

    /**
     * Set the current time.
     */
    uint64_t SetTime(uint64_t ticks) {return this->_ticks = ticks; };

public slots:
    /**
     * Increment clock by one tick.
     */
    void Tick() { _ticks++; };

signals:
    /**
     * Clock has ticked.
     */
    void Tock();

private:
    uint64_t _ticks; //< Number of ticks since time zero
};

// End include guard
#endif //_QCLOCK_HPP
