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

        LOG_DEBUG("connect (&m_thread, SIGNAL(tick()), this, SLOT(onTick()))...");
        connect (&m_thread, SIGNAL(tick()), this, SLOT(onTick()));

        LOG_DEBUG("m_thread.start()...");
        m_thread.start();
    }
    return true;
}
bool MainWindow::beforeDestroy() {
    if ((m_byeButton)) {
        LOG_DEBUG("enit m_thread.done()...");
        emit m_thread.done();

        LOG_DEBUG("m_thread.wait()...");
        m_thread.wait();

        LOG_DEBUG("disconnect (&m_thread, SIGNAL(tick()), this, SLOT(onTick()))...");
        disconnect (&m_thread, SIGNAL(tick()), this, SLOT(onTick()));

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
void MainWindow::onTick() {
    unsigned long sleepSeconds = 1;
    LOG_DEBUG("sleepSeconds = ((emit m_thread.sleepSeconds()) + 1)...");
    sleepSeconds = ((emit m_thread.sleepSeconds()) + 1);

    LOG_DEBUG("emit m_thread.setSleepSeconds( " << sleepSeconds << ")...");
    emit m_thread.setSleepSeconds(sleepSeconds);
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
void MainWindow::closeEvent(QCloseEvent *event) {
    LOG_DEBUG("event->accept()...");
    event->accept();
}

///////////////////////////////////////////////////////////////////////
///  Class: Thread
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
Thread::Thread(unsigned long sleepSeconds)
: m_sleepSeconds(sleepSeconds), m_done(false) {
}
Thread::~Thread() {
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
void Thread::run() {
    LOG_DEBUG("connect (this, SIGNAL(done()), this, SLOT(onDone()))...");
    connect (this, SIGNAL(done()), this, SLOT(onDone()));

    LOG_DEBUG("connect (this, SIGNAL(setSleepSeconds(unsigned long)), this, SLOT(onSetSleepSeconds(unsigned long)))...");
    connect (this, SIGNAL(setSleepSeconds(unsigned long)), this, SLOT(onSetSleepSeconds(unsigned long)));

    LOG_DEBUG("connect (this, SIGNAL(sleepSeconds()), this, SLOT(onSleepSeconds()))...");
    connect (this, SIGNAL(sleepSeconds()), this, SLOT(onSleepSeconds()));

    LOG_DEBUG("for (m_done = false; !m_done; )...");
    for (m_done = false; !m_done; ) {
        int sleepMilliSeconds = m_sleepSeconds*1000;

        LOG_DEBUG("m_sem.tryAcquire(1, sleepMilliSeconds = " << sleepMilliSeconds << ")...");
        m_sem.tryAcquire(1, sleepMilliSeconds);

        LOG_DEBUG("emit tick()...");
        emit tick();
    }
    LOG_DEBUG("disconnect (this, SIGNAL(sleepSeconds()), this, SLOT(onSleepSeconds()))...");
    disconnect (this, SIGNAL(sleepSeconds()), this, SLOT(onSleepSeconds()));

    LOG_DEBUG("disconnect (this, SIGNAL(setSleepSeconds(unsigned long)), this, SLOT(onSetSleepSeconds(unsigned long)))...");
    disconnect (this, SIGNAL(setSleepSeconds(unsigned long)), this, SLOT(onSetSleepSeconds(unsigned long)));

    LOG_DEBUG("disconnect (this, SIGNAL(done()), this, SLOT(onDone()))...");
    disconnect (this, SIGNAL(done()), this, SLOT(onDone()));
}
void Thread::onDone() {
    LOG_DEBUG("m_done = true...");
    m_done = true;

    LOG_DEBUG("m_sem.release(1)...");
    m_sem.release(1);
}
void Thread::onSetSleepSeconds(unsigned long to) {
    LOG_DEBUG("m_sleepSeconds = " << to << "...");
    m_sleepSeconds = to;
}
unsigned long Thread::onSleepSeconds() {
    LOG_DEBUG("return " << m_sleepSeconds << "...");
    return m_sleepSeconds;
}

} // namespace Hello
} // namespace Gui 
} // namespace App 
} // namespace Qtere 
