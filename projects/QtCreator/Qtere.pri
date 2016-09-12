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
#   File: Qtere.pri
#
# Author: $author$
#   Date: 9/10/2016
########################################################################
QTERE_PKG = ../../../../..
QTERE_BLD = ../..
QTERE_PRJ = $${QTERE_PKG}
QTERE_BIN = $${QTERE_BLD}/bin
QTERE_LIB = $${QTERE_BLD}/lib
QTERE_SRC = $${QTERE_PKG}/src

CONFIG(debug, debug|release) {
QTERE_CONFIG = Debug
} else {
QTERE_CONFIG = Release
}

########################################################################
# nadir
NADIR_PKG = $${QTERE_PKG}/../nadir
NADIR_PRJ = $${NADIR_PKG}
NADIR_SRC = $${NADIR_PKG}/src

nadir_INCLUDEPATH += \
$${NADIR_SRC} \

nadir_DEFINES += \

########################################################################

Qtere_INCLUDEPATH += \
$${QTERE_SRC} \
$${nadir_INCLUDEPATH} \

Qtere_DEFINES += \
$${nadir_DEFINES} \

Qtere_LIBS += \
-L$${QTERE_LIB}/libQtere \
-lQtere \

