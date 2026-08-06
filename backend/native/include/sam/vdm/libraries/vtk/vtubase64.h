#pragma once
#include "sam/base/stdcontainers.h"
//==================================================================================================
//
// base64 encoding in incremental way for representing binary data in an ASCII string
//
//==================================================================================================
class base64 {
  public:
    base64();

    void
    reset();
    bool
    encodeInBase64(const unsigned char* data, size_t length, vsy::string& outEncoded);
    void
    finalize(vsy::string& outEncoded);

  private:
    // Number of un-encoded bytes left in Buffer from last call to encodeInBase64.
    size_t m_BufferLength;
    unsigned char m_Buffer[2];
    static constexpr size_t m_maxBufferLength = 2;
};
