## @file qspike.pri
# @brief This file is used by qmake to include the qspike library in other QT applications.
# @author       Liam Bucci
# @date         7/24/2013
#
# @note The variable QSPIKE_ROOT must define the path (either absolute or relative from the main .pro file) to the root folder of the qspike library.
#


INCLUDEPATH += $${QSPIKE_ROOT}/include

SOURCES += $${QSPIKE_ROOT}/source/qneuron.cpp \
           $${QSPIKE_ROOT}/source/qsynapse.cpp

HEADERS += $${QSPIKE_ROOT}/include/QNeuron \
           $${QSPIKE_ROOT}/include/qneuron.hpp \
           $${QSPIKE_ROOT}/include/QSynapse \
           $${QSPIKE_ROOT}/include/qsynapse.hpp \
           $${QSPIKE_ROOT}/include/QClock \
           $${QSPIKE_ROOT}/include/qclock.hpp


