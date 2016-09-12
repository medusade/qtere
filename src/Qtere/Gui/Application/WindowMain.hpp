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
///   File: WindowMain.hpp
///
/// Author: $author$
///   Date: 9/11/2016
///////////////////////////////////////////////////////////////////////
#ifndef _QTERE_GUI_APPLICATION_WINDOWMAIN_HPP
#define _QTERE_GUI_APPLICATION_WINDOWMAIN_HPP

#include "Qtere/Gui/Application/Main.hpp"

namespace Qtere {
namespace Gui {
namespace Application {

typedef Application::MainImplements WindowMainImplements;
typedef Application::Main WindowMainExtends;
///////////////////////////////////////////////////////////////////////
///  Class: WindowMainT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = WindowMainImplements, class TExtends = WindowMainExtends>
class _EXPORT_CLASS WindowMainT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    WindowMainT(): m_qMainWindow(0) {
    }
    virtual ~WindowMainT() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual QMainWindow* createMainWindow
    (QApplication& qApplication, int argc, char_t** argv, char_t** env) {
        QMainWindow* qMainWindow = 0;
        LOG_DEBUG("new QMainWindow())...");
        if ((qMainWindow = new QMainWindow())) {
            return qMainWindow;
        } else {
            LOG_ERROR("...failed on new QMainWindow()");
        }
        return 0;
    }
    virtual bool beforeCreateMainWindow
    (QApplication& qApplication, int argc, char_t** argv, char_t** env) {
        return true;
    }
    virtual bool afterCreateMainWindow
    (QMainWindow* qMainWindow, QApplication& qApplication,
     int argc, char_t** argv, char_t** env) {
        return true;
    }
    virtual bool destroyMainWindow
    (QMainWindow* qMainWindow, QApplication& qApplication,
     int argc, char_t** argv, char_t** env) {
        if ((qMainWindow) && (qMainWindow == (m_qMainWindow))) {
            LOG_DEBUG("delete qMainWindow...");
            delete qMainWindow;
            return true;
        } else {
            LOG_ERROR("...unexpected (!qMainWindow) || (qMainWindow != (m_qMainWindow))");
        }
        return false;
    }
    virtual bool beforeDestroyMainWindow
    (QMainWindow* qMainWindow, QApplication& qApplication,
     int argc, char_t** argv, char_t** env) {
        return true;
    }
    virtual bool afterDestroyMainWindow
    (QApplication& qApplication, int argc, char_t** argv, char_t** env) {
        return true;
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool showMainWindow
    (QMainWindow* qMainWindow, QApplication& qApplication,
     int argc, char_t** argv, char_t** env) {
        if ((qMainWindow)) {
            LOG_DEBUG("m_qMainWindow->show()...");
            qMainWindow->show();
            return true;
        }
        return false;
    }
    virtual bool beforeShowMainWindow
    (QMainWindow* qMainWindow, QApplication& qApplication,
     int argc, char_t** argv, char_t** env) {
        return true;
    }
    virtual bool afterShowMainWindow
    (QMainWindow* qMainWindow, QApplication& qApplication,
     int argc, char_t** argv, char_t** env) {
        return true;
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int beforeExec
    (QApplication& qApplication, int argc, char** argv, char** env) {
        int err = 0;
        LOG_DEBUG("beforeCreateMainWindow()...");
        if ((beforeCreateMainWindow(qApplication, argc, argv, env))) {

            LOG_DEBUG("createMainWindow()...");
            if ((m_qMainWindow = createMainWindow(qApplication, argc, argv, env))) {

                LOG_DEBUG("after_create_main_indow()...");
                if ((afterCreateMainWindow(m_qMainWindow, qApplication, argc, argv, env))) {

                    LOG_DEBUG("beforeShowMainWindow()...");
                    if ((beforeShowMainWindow(m_qMainWindow, qApplication, argc, argv, env))) {

                        LOG_DEBUG("show_main_indow()...");
                        if ((showMainWindow(m_qMainWindow, qApplication, argc, argv, env))) {

                            LOG_DEBUG("afterShowMainWindow()...");
                            if ((afterShowMainWindow(m_qMainWindow, qApplication, argc, argv, env))) {
                                return err = 0;
                            } else {
                                LOG_ERROR("...failed on afterShowMainWindow()");
                            }
                        } else {
                            LOG_ERROR("...failed on showMainWindow()");
                        }
                    } else {
                        LOG_ERROR("...failed on beforeShowMainWindow()");
                    }
                } else {
                    LOG_ERROR("failed on afterCreateMainWindow()");
                }
                LOG_DEBUG("destroyMainWindow()...");
                if (!(destroyMainWindow(m_qMainWindow, qApplication, argc, argv, env))) {
                    LOG_ERROR("...failed on destroyMainWindow()");
                }
                m_qMainWindow = 0;
            } else {
                LOG_ERROR("...failed on createMainWindow()");
            }
        } else {
            LOG_ERROR("...failed on beforeMainWindow()");
        }
        return err;
    }
    virtual int afterExec
    (QApplication& qApplication, int argc, char** argv, char** env) {
        int err = 0;
        if ((m_qMainWindow)) {
            LOG_DEBUG("beforeDestroyMainWindow()...");
            if (!(beforeDestroyMainWindow(m_qMainWindow, qApplication, argc, argv, env))) {
                LOG_ERROR("...failed on beforeDestroyMainWindow()");
                if (!err) err = 1;
            }
            LOG_DEBUG("destroyMainWindow()...");
            if (!(destroyMainWindow(m_qMainWindow, qApplication, argc, argv, env))) {
                LOG_ERROR("...failed on destroyMainWindow()");
                if (!err) err = 1;
            }
            m_qMainWindow = 0;
            LOG_DEBUG("afterDestroyMainWindow()...");
            if (!(afterDestroyMainWindow(qApplication, argc, argv, env))) {
                LOG_ERROR("...failed on afterDestroyMainWindow()");
                if (!err) err = 1;
            }
        } else {
            LOG_ERROR("...unexpected 0 = m_qMainWindow");
            if (!err) err = 1;
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    QMainWindow* m_qMainWindow;
};
typedef WindowMainT<> WindowMain;

} // namespace Application 
} // namespace Gui 
} // namespace Qtere 

#endif // _QTERE_GUI_APPLICATION_WINDOWMAIN_HPP 
