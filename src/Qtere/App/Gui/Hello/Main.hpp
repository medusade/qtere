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
///   File: Main.hpp
///
/// Author: $author$
///   Date: 9/11/2016
///////////////////////////////////////////////////////////////////////
#ifndef _QTERE_APP_GUI_HELLO_MAIN_HPP
#define _QTERE_APP_GUI_HELLO_MAIN_HPP

#include "Qtere/Gui/Application/WindowMain.hpp"
#include "Qtere/App/Gui/Hello/MainWindow.hpp"
#include "Qtere/App/Gui/Hello/MainSignals.hpp"

namespace Qtere {
namespace App {
namespace Gui {
namespace Hello {

typedef Qtere::Gui::Application::WindowMainImplements MainImplements;
typedef Qtere::Gui::Application::WindowMain MainExtends;
///////////////////////////////////////////////////////////////////////
///  Class: Main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Main:
virtual public MainSignals,
virtual public MainImplements, public MainExtends {
public:
    typedef MainImplements Implements;
    typedef MainExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Main();
    virtual ~Main();

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool beforeShowMainWindow
    (QMainWindow* qMainWindow, QApplication& qApplication,
     int argc, char_t** argv, char_t** env);
    virtual bool beforeDestroyMainWindow
    (QMainWindow* qMainWindow, QApplication& qApplication,
     int argc, char_t** argv, char_t** env);

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual QMainWindow* createMainWindow
    (QApplication& qApplication, int argc, char_t** argv, char_t** env);
    virtual bool afterDestroyMainWindow
    (QApplication& qApplication, int argc, char_t** argv, char_t** env);

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void onBye();

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    MainSlots m_mainSlots;
    MainWindow* m_mainWindow;
};

} // namespace Hello 
} // namespace Gui 
} // namespace App 
} // namespace Qtere 

#endif // _QTERE_APP_GUI_HELLO_MAIN_HPP 
