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
///   File: Base.hpp
///
/// Author: $author$
///   Date: 9/10/2016
///////////////////////////////////////////////////////////////////////
#ifndef _QTERE_BASE_BASE_HPP
#define _QTERE_BASE_BASE_HPP

#include "xos/base/base.hpp"
#include "xos/base/array.hpp"
#include "xos/base/string.hpp"
#include "xos/base/date.hpp"
#include "xos/base/types.hpp"
#include "xos/base/opened.hpp"
#include "xos/base/opener.hpp"
#include "xos/base/created.hpp"
#include "xos/base/creator.hpp"
#include "xos/base/attached.hpp"
#include "xos/base/attacher.hpp"
#include "xos/base/wrapped.hpp"
#include "xos/base/to_string.hpp"
#include "xos/base/argv.hpp"

namespace Qtere {

typedef xos::base::implement_base ImplementBase;
typedef xos::base::base Base;

typedef xos::base::byte_array ByteArray;
typedef xos::base::word_array WordArray;

typedef xos::base::string String;
typedef xos::base::tstring TString;
typedef xos::base::wstring WString;

typedef xos::base::bool_to_string boolToString;
typedef xos::base::char_to_string charToString;
typedef xos::base::chars_to_string charsToString;
typedef xos::base::pointer_to_string pointerToString;

} // namespace Qtere

#endif // _QTERE_BASE_BASE_HPP 
