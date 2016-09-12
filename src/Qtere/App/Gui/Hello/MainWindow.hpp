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
///   File: MainWindow.hpp
///
/// Author: $author$
///   Date: 9/12/2016
///////////////////////////////////////////////////////////////////////
#ifndef _QTERE_APP_GUI_HELLO_MAINWINDOW_HPP
#define _QTERE_APP_GUI_HELLO_MAINWINDOW_HPP

#include "Qtere/App/Gui/Hello/MainSignals.hpp"

namespace Qtere {
namespace App {
namespace Gui {
namespace Hello {

typedef QMainWindow MainWindowExtends;
///////////////////////////////////////////////////////////////////////
///  Class: MainWindow
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS MainWindow: public MainWindowExtends {
Q_OBJECT
public:
    typedef MainWindowExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    MainWindow(MainSlots& mainSlots);
    virtual ~MainWindow();

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool beforeShow();
    virtual bool beforeDestroy();

protected slots:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void byePressed();
    virtual void byeReleased();

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void closeEvent(QCloseEvent *event);

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    MainSlots& m_mainSlots;
    QString m_hello, m_bye;
    QPushButton* m_byeButton;

signals:
    void onBye();
};

} // namespace Hello 
} // namespace Gui 
} // namespace App 
} // namespace Qtere 

#endif // _QTERE_APP_GUI_HELLO_MAINWINDOW_HPP 
