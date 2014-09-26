/* -*- mode: C++; tab-width: 4; -*- */

/**
 * @file qsynapse.hpp
 *
 * @brief This header specifies the qsynapse class and provides prototypes for
 * its functions and variables.
 *
 * @author      Liam Bucci
 * @date        7/13/2013
 */

// Include guard
#ifndef _QSYNAPSE_HPP
#define _QSYNAPSE_HPP

// Standard Library Includes
#include <cstdint>

// Include QT components
#include <QtCore>

class QSynapse : public QObject
{
    Q_OBJECT

public:
    QSynapse(); //< Default constructor for QSynapse type
    QSynapse(int32_t weight, uint32_t delay);

public slots:
    /**
     * Slot which is connected to a presynaptic qneuron (queued). This function
     * receives spikes from the presynaptic neuron and passes them along to the
     * post-synaptic qneuron's Update function (direct connection).
     */
    void ReceiveSpike();

    /**
     * Slot which is invoked for a synapse delay. This slot is invoked each
     * time with delay-1 so that it is requeued for the next timestep and
     * is only delivered when delay reaches zero.
     */
    void DelaySpike(uint32_t delay_remaining);

signals:
    void SpikeReceived(int32_t weighted_voltage);

private:
    int32_t _weight; //< Synapse weight
    uint32_t _delay; //< Synapse delay in timesteps
    
};


// End include guard
#endif //_QSYNAPSE_HPP
