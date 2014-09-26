/* -*- mode: C++; tab-width: 4; -*- */

/**
 * @file qneuron.cpp
 *
 * @brief This source file defines the qneuron class functions.
 *
 * @author      Liam Bucci
 * @date        7/21/2013
 */

// Include class header
#include <QNeuron>


/**
 * Default QNeuron class constructor
 */
QNeuron::QNeuron()
{
    this->_voltage = 0;
    this->_threshold = 0;
    this->_reset_voltage = 0;
    this->_last_spike_time = 0;
    this->lastvoltageupdate = 0;
}

QNeuron::QNeuron(const QClock *clock, int32_t voltage, int32_t threshold, int32_t reset_voltage)
{
    this->_clock = clock;
    this->_voltage = voltage;
    this->_threshold = threshold;
    this->_reset_voltage = reset_voltage;
    this->_last_spike_time = 0;
    this->_last_voltage_update = 0;
}

QSynapse & QNeuron::GrowSynapse(const QSynapse & synapse)
{
    localsynapses.append(synapse);
    return localsynapses.last();
}

void QNeuron::UpdateVoltage(int32_t weighted_voltage)
{
    // Back calculate new voltage using VoltageDecay()
    this->_voltage = VoltageDecay(this->_voltage, (this->_clock->GetTime() - this->_last_voltage_update));
    this->_last_voltage_update = this->_clock->GetTime();

    // Add weighted voltage from synapse to newly calculated voltage
    this->_voltage += weighted_voltage;

    // If new voltage is above threshold then spike and reset voltage
    if( this->_voltage >= this->_threshold )
    {
        emit SendSpike();
        this->_voltage = this->_reset_voltage;
        this->_last_spike_time = this->_clock->GetTime();
    }

    emit VoltageChanged(this->_voltage);
}

int32_t VoltageDecay(int32_t v_init, uint64_t delta_t)
{
    static const uint32_t tau = 10; //ms

    return (int32_t)(v_init*exp((float)(-1*delta_t/tau)));
}
