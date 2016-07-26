/**
 * Logger.h
 *
 * @author Raul Butuc
 * @version 1.0.0 - 26/07/2016
 */

#pragma once

#include "stdafx.h"
#include <fstream>

namespace KeyLoggerPro {

  class Logger {

    private:
      std::fstream log;

    public:
      Logger();

      void write(const std::string&);

  };

}
