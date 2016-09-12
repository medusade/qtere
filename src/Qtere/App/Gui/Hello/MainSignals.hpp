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
///   File: MainSignals.hpp
///
/// Author: $author$
///   Date: 9/12/2016
///////////////////////////////////////////////////////////////////////
#ifndef _QTERE_APP_GUI_HELLO_MAINSIGNALS_HPP
#define _QTERE_APP_GUI_HELLO_MAINSIGNALS_HPP

#include "Qtere/Base/Qt.hpp"

namespace Qtere {
namespace App {
namespace Gui {
namespace Hello {

///////////////////////////////////////////////////////////////////////
///  Class: MainSignals
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS MainSignals {
public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void onBye() {}
};

///////////////////////////////////////////////////////////////////////
///  Class: MainSlots
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS MainSlots: public QObject {
    Q_OBJECT
public:
    typedef QObject Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    MainSlots(MainSignals& mainSignals);
    virtual ~MainSlots();

public slots:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void onBye();

protected:
    MainSignals& m_mainSignals;
};

} // namespace Hello 
} // namespace Gui 
} // namespace App 
} // namespace Qtere 

#endif // _QTERE_APP_GUI_HELLO_MAINSIGNALS_HPP 
