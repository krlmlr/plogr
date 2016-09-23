#pragma once
#include <plog/Logger.h>
#include <plog/Severity.h>
#include <plog/Appenders/IAppender.h>

#ifndef PLOG_NO_FILE_APPENDERS
#include <plog/InitFile.h>
#endif // #ifndef PLOG_NO_FILE_APPENDERS

namespace plog
{
    //////////////////////////////////////////////////////////////////////////
    // Empty initializer / one appender

    template<int instance>
    inline Logger<instance>& init(Severity maxSeverity = none, IAppender* appender = NULL)
    {
        static Logger<instance> logger(maxSeverity);
        return appender ? logger.addAppender(appender) : logger;
    }

    inline Logger<0>& init(Severity maxSeverity = none, IAppender* appender = NULL)
    {
        return init<0>(maxSeverity, appender);
    }
}
