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
///   File: Logger.hpp
///
/// Author: $author$
///   Date: 9/11/2016
///////////////////////////////////////////////////////////////////////
#ifndef _QTERE_IO_LOGGER_HPP
#define _QTERE_IO_LOGGER_HPP

#include "Qtere/Base/Qt.hpp"
#include "xos/io/logger.hpp"

#define QTERE_LOG_ANY XOS_LOG_ANY
#define QTERE_LOG_FATAL XOS_LOG_FATAL
#define QTERE_LOG_ERROR XOS_LOG_ERROR
#define QTERE_LOG_WARN XOS_LOG_WARN
#define QTERE_LOG_INFO XOS_LOG_INFO
#define QTERE_LOG_DEBUG XOS_LOG_DEBUG
#define QTERE_LOG_TRACE XOS_LOG_TRACE

#define QTERE_LOG_ANYF XOS_LOG_ANYF
#define QTERE_LOG_FATALF XOS_LOG_FATALF
#define QTERE_LOG_ERRORF XOS_LOG_ERRORF
#define QTERE_LOG_WARNF XOS_LOG_WARNF
#define QTERE_LOG_INFOF XOS_LOG_INFOF
#define QTERE_LOG_DEBUGF XOS_LOG_DEBUGF
#define QTERE_LOG_TRACEF XOS_LOG_TRACEF

#define QTERE_LOG_MESSAGE_ANY XOS_LOG_MESSAGE_ANY
#define QTERE_LOG_MESSAGE_FATAL XOS_LOG_MESSAGE_FATAL
#define QTERE_LOG_MESSAGE_ERROR XOS_LOG_MESSAGE_ERROR
#define QTERE_LOG_MESSAGE_WARN XOS_LOG_MESSAGE_WARN
#define QTERE_LOG_MESSAGE_INFO XOS_LOG_MESSAGE_INFO
#define QTERE_LOG_MESSAGE_DEBUG XOS_LOG_MESSAGE_DEBUG
#define QTERE_LOG_MESSAGE_TRACE XOS_LOG_MESSAGE_TRACE

#define QTERE_LOG_MESSAGE_ANYF XOS_LOG_MESSAGE_ANYF
#define QTERE_LOG_MESSAGE_FATALF XOS_LOG_MESSAGE_FATALF
#define QTERE_LOG_MESSAGE_ERRORF XOS_LOG_MESSAGE_ERRORF
#define QTERE_LOG_MESSAGE_WARNF XOS_LOG_MESSAGE_WARNF
#define QTERE_LOG_MESSAGE_INFOF XOS_LOG_MESSAGE_INFOF
#define QTERE_LOG_MESSAGE_DEBUGF XOS_LOG_MESSAGE_DEBUGF
#define QTERE_LOG_MESSAGE_TRACEF XOS_LOG_MESSAGE_TRACEF

#define QTERE_LOG_MESSAGE_ANYFV XOS_LOG_MESSAGE_ANYFV
#define QTERE_LOG_MESSAGE_FATALFV XOS_LOG_MESSAGE_FATALFV
#define QTERE_LOG_MESSAGE_ERRORFV XOS_LOG_MESSAGE_ERRORFV
#define QTERE_LOG_MESSAGE_WARNFV XOS_LOG_MESSAGE_WARNFV
#define QTERE_LOG_MESSAGE_INFOFV XOS_LOG_MESSAGE_INFOFV
#define QTERE_LOG_MESSAGE_DEBUGFV XOS_LOG_MESSAGE_DEBUGFV
#define QTERE_LOG_MESSAGE_TRACEFV XOS_LOG_MESSAGE_TRACEFV

#define QTERE_LOG_MESSAGE_ANYMFV XOS_LOG_MESSAGE_ANYMFV
#define QTERE_LOG_MESSAGE_FATALMFV XOS_LOG_MESSAGE_FATALMFV
#define QTERE_LOG_MESSAGE_ERRORMFV XOS_LOG_MESSAGE_ERRORMFV
#define QTERE_LOG_MESSAGE_WARNMFV XOS_LOG_MESSAGE_WARNMFV
#define QTERE_LOG_MESSAGE_INFOMFV XOS_LOG_MESSAGE_INFOMFV
#define QTERE_LOG_MESSAGE_DEBUGMFV XOS_LOG_MESSAGE_DEBUGMFV
#define QTERE_LOG_MESSAGE_TRACEMFV XOS_LOG_MESSAGE_TRACEMFV

///////////////////////////////////////////////////////////////////////

#define QTERE_LOGGER_LEVELS_TRACE \
    (XOS_LOGGING_LEVELS_TRACE_MESSAGE | XOS_LOGGING_LEVELS_ERROR)

#define QTERE_LOGGER_LEVELS_DEBUG \
    (XOS_LOGGING_LEVELS_DEBUG_MESSAGE | XOS_LOGGING_LEVELS_ERROR)

#define QTERE_LOGGER_LEVELS_ERROR \
    (XOS_LOGGING_LEVELS_ERROR_MESSAGE | XOS_LOGGING_LEVELS_ERROR)

#define QTERE_LOGGER_LEVELS_DEFAULT QTERE_LOGGER_LEVELS_DEBUG

///////////////////////////////////////////////////////////////////////

#define QTERE_LOGGER_LEVELS XOS_LOGGING_LEVELS
#define QTERE_SET_LOGGER_LEVELS(levels) XOS_SET_LOGGING_LEVEL(levels)
#define QTERE_GET_LOGGER_LEVELS(levels) XOS_GET_LOGGING_LEVEL(levels)

#define LOG_TRACE(args) QTERE_LOG_MESSAGE_TRACE(__FUNCTION__ << ": " << args)
#define LOG_DEBUG(args) QTERE_LOG_MESSAGE_DEBUG(__FUNCTION__ << ": " << args)
#define LOG_ERROR(args) QTERE_LOG_MESSAGE_ERROR(__FUNCTION__ << ": " << args)

namespace Qtere {
namespace Io {

} // namespace Io 
} // namespace Qtere 

#endif // _QTERE_IO_LOGGER_HPP 
