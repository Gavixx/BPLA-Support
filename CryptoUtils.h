// CryptoUtils.h
#ifndef CRYPTOUTILS_H
#define CRYPTOUTILS_H

#include <string>
#include <vector>
#include <stdexcept>
#include <windows.h>
#include <wincrypt.h>
//#include <atlenc.h> // Для функцій CryptBinaryToStringA та CryptStringToBinaryA

namespace CryptoUtils {
    // Функція хешування пароля за допомогою SHA-256
    std::string HashPassword(const std::string& password);

    // Функція конвертації байтів у Base64
    std::string BytesToBase64(const std::vector<BYTE>& data);

    // Функція конвертації Base64 у байти
    std::vector<BYTE> Base64ToBytes(const std::string& base64Str);
}

#endif // CRYPTOUTILS_H

