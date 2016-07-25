/**
 * Keys.h
 *
 * @author Raul Butuc
 * @version 1.0.0 - 23/07/2016
 */

#pragma once

#include "stdafx.h"

namespace KeyLoggerPro {

  typedef std::map<int, KeyPair> KEY_MAP;

  class Keys {

    private:
      static KEY_MAP m_Keys;

    public:
      static KEY_MAP getKeys(void);

  };

}
