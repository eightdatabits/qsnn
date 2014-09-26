/* -*- mode: C++; tab-width: 4 -*- */

/**
 * @file qspikesim.hpp
 *
 * @brief This header specifies the QSpikeSim class which contains all the
 * components for a QSpike simulation, including QNeurons, QSynapses, a global
 * clock, and input and timestep functions.
 *
 * @author      Liam Bucci
 * @date        7/24/2013
 */

// Include guard
#ifndef _QSPIKESIM_HPP
#define _QSPIKESIM_HPP

// Standard Library Includes
#include <cstdint>

// Include QT Components
#include <QtCore>

// Include QSpike components
#include <QClock>
#include <QNeuron>
#include <QSynapse>

class QSpikeSim : public QObject
{
    Q_OBJECT

public:
    QSpikeSim(); //< Default constructor

    QNeuron & GetNeuron(uint32_t index) { if(_neurons->length() <= index) return NULL; else return _neurons[index]; };
    QSynapse & GetSynapse(uint32_t index) { if(_synapses->length() <= index) return NULL; else return _synapses[index]; };
    QNeuron & AddNeuron(uint32_t index, const QNeuron & neuron) { _neurons->insert(index, neuron); return _neurons[index]; };
    QSynapse & AddSynapse(uint32_t index, const QNeuron & synapse) { _synapses->insert(index, synapse); return _synapses[index]; };

public slots:
    /**
     * Slot which denotes the boundary between timesteps. It ticks the global
     * clock, sends the next set of input spikes, then requeues itself for the
     * next timestep.
     */
    void TimeStep() { _global_clock->Tick(); emit InputReady(_global_clock->GetTime()); QMetaObject::invokeMethod(this,"TimeStep",Qt::QueuedConnection); };

signals:
    /**
     * The input signal allows the user to hook into the event queue and send
     * input spikes to the network.
     */
    void InputReady(uint64_t time);

private:
    QClock *_global_clock;
    QList<QNeuron> *_neurons;
    QList<QSynapse> *_synapses;
};
