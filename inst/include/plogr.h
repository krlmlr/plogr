#ifndef plogr_plogr_H
#define plogr_plogr_H

#include "plog/Log.h"
#include "plog/Formatters/FuncMessageFormatter.h"

#include <R.h>

namespace plog {

template<class Formatter>
class RAppender : public IAppender
{
public:
  virtual void write(const Record& record)
  {
    util::nstring str = Formatter::format(record); // Use the formatter to get a string from a record.
    REprintf("%s", str.c_str());
  }
};

inline Logger<0>& init_r(Severity maxSeverity = none) {
  static RAppender<FuncMessageFormatter> appender;
  init(maxSeverity, &appender);
}

}

#endif // #ifndef plogr_plogr_H
