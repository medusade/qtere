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
///   Date: 9/10/2016
///////////////////////////////////////////////////////////////////////
#ifndef _QTERE_GUI_APPLICATION_MAIN_HPP
#define _QTERE_GUI_APPLICATION_MAIN_HPP

#include "Qtere/Gui/Main.hpp"

namespace Qtere {
namespace Gui {
namespace Application {

typedef Gui::MainImplements MainImplements;
typedef Gui::Main MainExtends;
///////////////////////////////////////////////////////////////////////
///  Class: MainT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = MainImplements, class TExtends = MainExtends>
class _EXPORT_CLASS MainT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    MainT() {
    }
    virtual ~MainT() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int exec
    (QApplication& qApplication, int argc, char** argv, char** env) {
        int err = 0;
        LOG_DEBUG("qApplication.exec()...");
        if ((err = qApplication.exec())) {
            LOG_ERROR("failed err = " << err << " on qApplication.exec()...");
        }
        return err;
    }
    virtual int beforeExec
    (QApplication& qApplication, int argc, char** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int afterExec
    (QApplication& qApplication, int argc, char** argv, char** env) {
        int err = 0;
        return err;
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int eventLoop(int argc, char** argv, char** env) {
        int err = 0;
        QApplication qApplication(argc, argv);

        LOG_DEBUG("beforeExec()...");
        if (!(err = beforeExec(qApplication, argc, argv, env))) {
            int err2 = 0;

            LOG_DEBUG("exec()...");
            if ((err = exec(qApplication, argc, argv, env))) {
                LOG_ERROR("...failed " << err << " on exec()");
            }

            LOG_DEBUG("afterExec()...");
            if ((err2 = afterExec(qApplication, argc, argv, env))) {
                LOG_ERROR("...failed " << err2 << " on afterExec()");
                if (!err) err = err2;
            }
        } else {
            LOG_ERROR("...failed " << err << " on beforeExec()");
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef MainT<> Main;

} // namespace Application 
} // namespace Gui 
} // namespace Qtere 

#endif // _QTERE_GUI_APPLICATION_MAIN_HPP 
