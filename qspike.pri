## @file CarlLib.pri
# @brief This file is used by qmake to include the CarlLib library in other QT applications.
# @author {Liam Bucci}
# @date {5/29/2012}
# @project {Carl Platform}
# @subproject {CarlComm}
# @version {0.2.0}
#
# @note Requires the variable CARLLIB_DIR be set by the including .pro file.
#

INCLUDEPATH += $${CARLLIB_DIR} \
               $${CARLLIB_DIR}/qt

SOURCES += $${CARLLIB_DIR}/qt/carlmessage.cpp \
           $${CARLLIB_DIR}/qt/carlinterface.cpp

HEADERS += $${CARLLIB_DIR}/qt/carlmessage.hpp \
           $${CARLLIB_DIR}/qt/carlinterface.hpp \
           $${CARLLIB_DIR}/CarlComm
