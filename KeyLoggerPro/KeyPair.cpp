/**
 * KeyPair.cpp
 *
 * @author Raul Butuc
 * @version 1.0.0 - 23/07/2016
 */

#include "stdafx.h"

KeyPair::KeyPair(const std::string& vKey = "",
                 const std::string& name = "")
    : m_vKey(vKey), m_Name(name) { }

std::string KeyPair::getVKey(void) {
  return m_vKey;
}

std::string KeyPair::getName(void) {
  return m_Name;
}

void KeyPair::setVKey(const std::string& vKey = "") {
  this->m_vKey = vKey;
}

void KeyPair::setName(const std::string& name = "") {
  this->m_Name = name;
}
