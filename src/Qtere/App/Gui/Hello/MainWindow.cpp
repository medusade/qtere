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
///   File: MainWindow.cpp
///
/// Author: $author$
///   Date: 9/12/2016
///////////////////////////////////////////////////////////////////////
#include "Qtere/App/Gui/Hello/MainWindow.hpp"
#include "Qtere/Io/Logger.hpp"

namespace Qtere {
namespace App {
namespace Gui {
namespace Hello {

///////////////////////////////////////////////////////////////////////
///  Class: MainWindow
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
MainWindow::MainWindow(MainSlots& mainSlots)
: m_mainSlots(mainSlots),
  m_hello("Hello"), m_bye("Bye"),
  m_byeButton(0) {
}
MainWindow::~MainWindow() {
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
bool MainWindow::beforeShow() {
    LOG_DEBUG("this->setWindowTitle(m_hello)...");
    this->setWindowTitle(m_hello);

    LOG_DEBUG("new QPushButton(m_bye, this)...");
    if ((m_byeButton = new QPushButton(m_bye, this))) {
        LOG_DEBUG("connect (m_byeButton, SIGNAL(pressed()), this, SLOT(byePressed()))...");
        connect (m_byeButton, SIGNAL(pressed()), this, SLOT(byePressed()));

        LOG_DEBUG("connect (m_byeButton, SIGNAL(released()), this, SLOT(byeReleased()))...");
        connect (m_byeButton, SIGNAL(released()), this, SLOT(byeReleased()));

        LOG_DEBUG("connect (this, SIGNAL(onBye()), &m_mainSlots, SLOT(onBye()))...");
        connect (this, SIGNAL(onBye()), &m_mainSlots, SLOT(onBye()));

        LOG_DEBUG("this->setCentralWidget(m_byeButton)...");
        this->setCentralWidget(m_byeButton);
    }
    return true;
}
bool MainWindow::beforeDestroy() {
    if ((m_byeButton)) {
        LOG_DEBUG("disconnect (this, SIGNAL(onBye()), &m_mainSlots, SLOT(onBye()))...");
        disconnect (this, SIGNAL(onBye()), &m_mainSlots, SLOT(onBye()));

        LOG_DEBUG("disconnect (m_byeButton, SIGNAL(released()), this, SLOT(byeReleased()))...");
        disconnect (m_byeButton, SIGNAL(released()), this, SLOT(byeReleased()));

        LOG_DEBUG("disconnect (m_byeButton, SIGNAL(pressed()), this, SLOT(byePressed()))...");
        disconnect (m_byeButton, SIGNAL(pressed()), this, SLOT(byePressed()));
    }
    return true;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
void MainWindow::byePressed() {
    LOG_DEBUG("...");
}
void MainWindow::byeReleased() {
    LOG_DEBUG("emit onBye()...");
    emit onBye();
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
void MainWindow::closeEvent(QCloseEvent *event) {
    LOG_DEBUG("event->accept()...");
    event->accept();
}

} // namespace Hello
} // namespace Gui 
} // namespace App 
} // namespace Qtere 


        

