/* -*- mode: C++; tab-width: 4; */

/**
 * @file qsynapse.cpp
 *
 * @brief This source file defines the functions for the QSynapse class.
 *
 * @author      Liam Bucci
 * @date        7/21/2013
 */

// Include QSynapse header
#include <QSynapse>

QSynapse::QSynapse()
{
    this->_weight = 0;
    this->_delay = 0;
}

QSynapse::QSynapse(int32_t weight, uint32_t delay)
{
    this->_weight = weight;
    this->_delay = delay;
}

void QSynapse::ReceiveSpike()
{
    //! TODO: Add delay code here
    emit SpikeReceived(this->_weight);
}

void QSynapse::DelaySpike(uint32_t delay_remaining)
{
}
