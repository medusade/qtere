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
#ifndef _QTERE_CONSOLE_MAIN_HPP
#define _QTERE_CONSOLE_MAIN_HPP

#include "Qtere/Console/MainOpt.hpp"
#include "Qtere/Io/Logger.hpp"

namespace Qtere {
namespace Console {

typedef xos::base::getopt::main_implement MainImplements;
typedef xos::base::getopt::main MainExtends;
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
    MainT(): loggerLevels_(0) {
    }
    virtual ~MainT() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int beforeRun(int argc, char** argv, char** env) {
        int err = 0;
        QTERE_GET_LOGGER_LEVELS (loggerLevels_);
        QTERE_SET_LOGGER_LEVELS (QTERE_LOGGER_LEVELS_DEFAULT);
        return err;
    }
    virtual int afterRun(int argc, char** argv, char** env) {
        int err = 0;
        QTERE_SET_LOGGER_LEVELS (loggerLevels_);
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int before_run(int argc, char** argv, char** env) {
        int err = 0;
        if (!(err = Extends::before_run(argc, argv, env))) {
            err = this->beforeRun(argc, argv, env);
        }
        return err;
    }
    virtual int after_run(int argc, char** argv, char** env) {
        int err = 0, err2 = 0;
        err = this->afterRun(argc, argv, env);
        if ((err2 = Extends::after_run(argc, argv, env))) {
            if (!err) err = err2;
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    QTERE_LOGGER_LEVELS loggerLevels_;
};
typedef MainT<> Main;

} // namespace Console

namespace App {
namespace Console {

typedef Qtere::Console::MainImplements MainImplements;
typedef Qtere::Console::Main Main;

} // namespace Console
} // namespace App

} // namespace Qtere


#endif // _QTERE_CONSOLE_MAIN_HPP 
