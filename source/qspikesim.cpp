/* -*- mode: C++; tab-width: 4; -*- */

/**
 * @file qspikesim.cpp
 *
 * @brief This source file contains the function definitions for the QSpikeSim
 * class.
 *
 * @author      Liam Bucci
 * @date        7/24/2013
 */

QSpikeSim::QSpikeSim()
{
    this->_global_clock = new QClock();
    this->_neurons = new QList<QNeuron>;
    this->_synapses = new QList<QSynapse>;
}
