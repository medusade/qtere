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
///   File: MainOpt.hpp
///
/// Author: $author$
///   Date: 9/11/2016
///////////////////////////////////////////////////////////////////////
#ifndef _QTERE_CONSOLE_MAINOPT_HPP
#define _QTERE_CONSOLE_MAINOPT_HPP

#include "Qtere/Base/Qt.hpp"
#include "xos/base/getopt/main.hpp"

#define QTERE_MAIN_LOGGING_OPTVAL_C XOS_MAIN_LOGGING_OPTVAL_C
#define QTERE_MAIN_LOGGING_OPTARG XOS_MAIN_LOGGING_OPTARG
#define QTERE_MAIN_LOGGING_OPTUSE XOS_MAIN_LOGGING_OPTUSE

#define QTERE_MAIN_HELP_OPTVAL_C XOS_MAIN_HELP_OPTVAL_C
#define QTERE_MAIN_HELP_OPTARG XOS_MAIN_HELP_OPTARG
#define QTERE_MAIN_HELP_OPTUSE XOS_MAIN_HELP_OPTUSE

#define QTERE_MAIN_OPTIONS_CHARS XOS_MAIN_OPTIONS_CHARS
#define QTERE_MAIN_OPTIONS_OPTIONS XOS_MAIN_OPTIONS_OPTIONS

enum {
    QTERE_MAIN_OPT_ARGUMENT_NONE     = XOS_MAIN_OPT_ARGUMENT_NONE,
    QTERE_MAIN_OPT_ARGUMENT_REQUIRED = XOS_MAIN_OPT_ARGUMENT_REQUIRED,
    QTERE_MAIN_OPT_ARGUMENT_OPTIONAL = XOS_MAIN_OPT_ARGUMENT_OPTIONAL
};

namespace Qtere {
namespace Console {

typedef int main_opt_argument_t;
enum {
    MAIN_OPT_ARGUMENT_NONE     = QTERE_MAIN_OPT_ARGUMENT_NONE,
    MAIN_OPT_ARGUMENT_REQUIRED = QTERE_MAIN_OPT_ARGUMENT_REQUIRED,
    MAIN_OPT_ARGUMENT_OPTIONAL = QTERE_MAIN_OPT_ARGUMENT_OPTIONAL
};

} // namespace Console

namespace App {
namespace Console {

typedef Qtere::Console::main_opt_argument_t main_opt_argument_t;
enum {
    MAIN_OPT_ARGUMENT_NONE     = Qtere::Console::MAIN_OPT_ARGUMENT_NONE,
    MAIN_OPT_ARGUMENT_REQUIRED = Qtere::Console::MAIN_OPT_ARGUMENT_REQUIRED,
    MAIN_OPT_ARGUMENT_OPTIONAL = Qtere::Console::MAIN_OPT_ARGUMENT_OPTIONAL
};

} // namespace Console
} // namespace App

} // namespace Qtere

#endif // _QTERE_CONSOLE_MAINOPT_HPP 
