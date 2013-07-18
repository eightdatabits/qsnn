/* -*- mode: C++; tab-width: 4; -*- */

/**
 * @file qneuron.hpp
 *
 * @brief This header specifies the qneuron class and provides prototypes for
 * its classes and variables.
 *
 * @author      Liam Bucci
 * @date        7/13/2013
 */

// Include guard
#ifndef _QNEURON_HPP
#define _QNEURON_HPP

#include <QSynapse>


class QNeuron : public QObject
{
    Q_OBJECT

public:
    QNeuron(); //< Default constructor for QNeuron type
    
    /**
     * Grows a new local synapse copying the parameters from the synapse pointed to by synapse.
     */
    void GrowSynapse(const QSynapse *synapse);

    /**
     * Grows a synapse using the type of synapse passed as a parameter. Also automatically connects
     * the synapse to the QNeuron pointed to by presynaptic_neuron.
     */
    void GrowSynapse(const QSynapse *synapse, const QNeuron *presynaptic_neuron);

public slots:
    void Update();

signals:
    void Spike(uint64_t globaltimestamp); //< Queue a spike in all connected QSynapse slots

private:
    QSynapse localsynapses[]; //< Array of qsynapse objects

};
    

// End include guard
#endif //_QNEURON_HPP
