/**
 * KeyPair.h
 *
 * @author Raul Butuc
 * @version 1.0.0 - 23/07/2016
 */

#pragma once

#include "stdafx.h"
#include <string>

namespace KeyLoggerPro {

  class KeyPair {

    private:
      std::string m_vKey;
      std::string m_Name;

    public:
      KeyPair(const std::string&, const std::string&);

      std::string getVKey(void) const;
      std::string getName(void) const;
      void setVKey(const std::string&);
      void setName(const std::string&);

  };

}
