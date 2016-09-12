########################################################################
# Copyright (c) 1988-2016 $organization$
#
# This software is provided by the author and contributors ``as is''
# and any express or implied warranties, including, but not limited to,
# the implied warranties of merchantability and fitness for a particular
# purpose are disclaimed. In no event shall the author or contributors
# be liable for any direct, indirect, incidental, special, exemplary,
# or consequential damages (including, but not limited to, procurement
# of substitute goods or services; loss of use, data, or profits; or
# business interruption) however caused and on any theory of liability,
# whether in contract, strict liability, or tort (including negligence
# or otherwise) arising in any way out of the use of this software,
# even if advised of the possibility of such damage.
#
#   File: QtereHello.pri
#
# Author: $author$
#   Date: 9/10/2016
########################################################################

QtereHello_INCLUDEPATH += \
$${Qtere_INCLUDEPATH} \

QtereHello_DEFINES += \
$${Qtere_DEFINES} \

########################################################################
QtereHello_HEADERS += \
$${QTERE_SRC}/Qtere/App/Gui/Hello/Main.hpp \
$${QTERE_SRC}/Qtere/App/Gui/Hello/MainWindow.hpp \
$${QTERE_SRC}/Qtere/App/Gui/Hello/MainSignals.hpp \
$${QTERE_SRC}/Qtere/Gui/Application/WindowMain.hpp \
$${QTERE_SRC}/Qtere/Gui/Application/Main.hpp \
$${QTERE_SRC}/Qtere/Gui/Main.hpp \
$${QTERE_SRC}/Qtere/Console/Main.hpp \
$${QTERE_SRC}/Qtere/Console/MainOpt.hpp \
$${QTERE_SRC}/Qtere/Console/Main_main.hpp \

QtereHello_SOURCES += \
$${QTERE_SRC}/Qtere/App/Gui/Hello/Main.cpp \
$${QTERE_SRC}/Qtere/App/Gui/Hello/MainWindow.cpp \
$${QTERE_SRC}/Qtere/App/Gui/Hello/MainSignals.cpp \
$${QTERE_SRC}/Qtere/Gui/Application/WindowMain.cpp \
$${QTERE_SRC}/Qtere/Console/MainOpt.cpp \
$${QTERE_SRC}/Qtere/Console/Main_main.cpp \

########################################################################
QtereHello_LIBS += \
$${Qtere_LIBS} \
