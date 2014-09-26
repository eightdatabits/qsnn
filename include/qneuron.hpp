/* -*- mode: C++; tab-width: 4; -*- */

/**
 * @file qneuron.hpp
 *
 * @brief This header specifies the qneuron class and provides prototypes for
 * its functions and variables.
 *
 * @author      Liam Bucci
 * @date        7/13/2013
 */

// Include guard
#ifndef _QNEURON_HPP
#define _QNEURON_HPP

// Standard Library Includes
#include <cstdint>

// QT Library Includes
#include <QList>

// QSpike Library Includes
#include <QSynapse>
#include <QClock>


class QNeuron : public QObject
{
    Q_OBJECT

public:
    QNeuron(); //< Default constructor for QNeuron type
    QNeuron(const QClock *clock, int32_t voltage, int32_t threshold, int32_t reset_voltage); //< Constructor
    
    /**
     * Grows a new local synapse using the passed QSynapse as a template.
     */
    QSynapse & GrowSynapse(const QSynapse & synapse);

    /**
     * Get the current voltage.
     */
    int32_t GetVoltage() { return this->_voltage; };

    /**
     * Get the spike threshold.
     */
    int32_t GetThreshold() { return this->_threshold; };

    /**
     * Get the reset voltage.
     */
    int32_t GetResetVoltage() { return this->_reset_voltage; };

    /**
     * Get last spike tick.
     */
    uint64_t GetSpikeTime() { return this->_last_spike_time; };

    /**
     * Set the current voltage.
     */
    int32_t SetVoltage(int32_t voltage) { return this->_voltage = voltage; };

    /**
     * Set the spike threshold.
     */
    int32_t SetThreshold(int32_t threshold) { return this->_threshold = threshold; };

    /**
     * Set the reset voltage.
     */
    int32_t SetResetVoltage(int32_t reset_voltage) { return this->_reset_voltage = reset_voltage; };

public slots:
    void UpdateVoltage(int32_t weighted_voltage);

signals:
    /**
     * This signal is emitted when the neuron spikes. It should be connected to
     * any synapses which will receive a spike from this neuron. The connection
     * should be a Queued type so that it will not be sent out of order.
     */
    void SendSpike();

    /**
     * Signal that the voltage has changed.
     */
    void VoltageChanged(int32_t voltage);

private:
    /**
     * Decay function used to update the neuron's voltage.
     */
    int32_t VoltageDecay(int32_t v_init, uint64_t delta_t);
    
    QList<QSynapse> _local_synapses; //< List of qsynapse objects
    const QClock *_clock; //< Simulation clock
    int32_t _voltage; //< Last calculated membrane voltage
    int32_t _threshold; //< The threshold voltage at which the neuron will spike
    int32_t _reset_voltage; //< Reset voltage after a spike
    uint64_t _last_spike_time; //< Last tick at which a spike occurred
    uint64_t _last_voltage_update; //< Last tick at which the voltage was updated

};
    

// End include guard
#endif //_QNEURON_HPP
