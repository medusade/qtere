///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2016 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: Main.cpp
///
/// Author: $author$
///   Date: 9/11/2016
///////////////////////////////////////////////////////////////////////
#include "Qtere/App/Gui/Hello/Main.hpp"

namespace Qtere {
namespace App {
namespace Gui {
namespace Hello {

///////////////////////////////////////////////////////////////////////
///  Class: Main
///////////////////////////////////////////////////////////////////////
static Main theMain;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
Main::Main()
: m_mainSlots(*this), m_mainWindow(0) {
}
Main::~Main() {
}
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
void Main::onBye() {
    LOG_DEBUG("QApplication::quit()...");
    QApplication::quit();
}
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
bool Main::beforeShowMainWindow
(QMainWindow* qMainWindow, QApplication& qApplication,
 int argc, char_t** argv, char_t** env) {
    if ((m_mainWindow)) {
        return m_mainWindow->beforeShow();
    }
    return true;
}
bool Main::beforeDestroyMainWindow
(QMainWindow* qMainWindow, QApplication& qApplication,
 int argc, char_t** argv, char_t** env) {
    if ((m_mainWindow)) {
        return m_mainWindow->beforeDestroy();
    }
    return true;
}
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
QMainWindow* Main::createMainWindow
(QApplication& qApplication, int argc, char_t** argv, char_t** env) {
    LOG_DEBUG("new MainWindow()...");
    if ((m_mainWindow = new MainWindow(m_mainSlots))) {
        return m_mainWindow;
    } else {
        LOG_ERROR("...failed on new MainWindow()");
    }
    return 0;
}
bool Main::afterDestroyMainWindow
(QApplication& qApplication, int argc, char_t** argv, char_t** env) {
    m_mainWindow = 0;
    return true;
}

} // namespace Hello 
} // namespace Gui 
} // namespace App 
} // namespace Qtere 
