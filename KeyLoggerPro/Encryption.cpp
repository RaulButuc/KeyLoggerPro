/**
 * Encryption.cpp
 *
 * @author Raul Butuc
 * @version 1.0.0 - 28/07/2016
 */

#include "stdafx.h"
#include "Encryption.h"

namespace KeyLoggerPro {

  Block::Block(unsigned int l = 0, unsigned int r = 0) : m_uil(l), m_uir(r) { }

  Block::Block(const Block &_block) : m_uil(_block.m_uil), m_uir(_block.m_uir) { }

  Block& Block::operator^=(Block &_block) {
    m_uil ^= _block.m_uil;
    m_uir ^= _block.m_uir;
    return *this;
  }

  // TODO: Complete the implementation of the encryption/decryption algorithms.

}
