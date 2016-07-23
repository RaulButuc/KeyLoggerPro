/**
 * KeyPair.h
 *
 * @author Raul Butuc
 * @version 1.0.0 - 23/07/2016
 */

#pragma once

class KeyPair {

  private:
    std::string m_vKey;
    std::string m_Name;

  public:
    KeyPair(const std::string&, const std::string&);

    std::string getVKey(void);
    std::string getName(void);
    void setVKey(const std::string&);
    void setName(const std::string&);

};
