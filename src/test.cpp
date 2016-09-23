#include <plogr.h>

void plogr_demo() {
  plog::init_r(plog::info);
  LOG_INFO << "shown";
  LOG_DEBUG << "not shown";
}
