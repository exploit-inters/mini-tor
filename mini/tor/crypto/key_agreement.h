#pragma once
#include <mini/crypto/big_integer.h>
#include <mini/crypto/provider.h>
#include <mini/crypto/random.h>

#include <mini/stack_buffer.h>

#include <cstdint>

namespace mini::tor {

static constexpr size_t DH_LEN = 128;

//
// tor-spec 0.3
//
// As an optimization, implementations SHOULD choose DH private keys (x) of
// 320 bits.
//

static constexpr size_t DH_SEC_LEN = 40;

static const crypto::big_integer DH_P({
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc9, 0x0f, 0xda, 0xa2, 0x21, 0x68, 0xc2, 0x34,
  0xc4, 0xc6, 0x62, 0x8b, 0x80, 0xdc, 0x1c, 0xd1, 0x29, 0x02, 0x4e, 0x08, 0x8a, 0x67, 0xcc, 0x74,
  0x02, 0x0b, 0xbe, 0xa6, 0x3b, 0x13, 0x9b, 0x22, 0x51, 0x4a, 0x08, 0x79, 0x8e, 0x34, 0x04, 0xdd,
  0xef, 0x95, 0x19, 0xb3, 0xcd, 0x3a, 0x43, 0x1b, 0x30, 0x2b, 0x0a, 0x6d, 0xf2, 0x5f, 0x14, 0x37,
  0x4f, 0xe1, 0x35, 0x6d, 0x6d, 0x51, 0xc2, 0x45, 0xe4, 0x85, 0xb5, 0x76, 0x62, 0x5e, 0x7e, 0xc6,
  0xf4, 0x4c, 0x42, 0xe9, 0xa6, 0x37, 0xed, 0x6b, 0x0b, 0xff, 0x5c, 0xb6, 0xf4, 0x06, 0xb7, 0xed,
  0xee, 0x38, 0x6b, 0xfb, 0x5a, 0x89, 0x9f, 0xa5, 0xae, 0x9f, 0x24, 0x11, 0x7c, 0x4b, 0x1f, 0xe6,
  0x49, 0x28, 0x66, 0x51, 0xec, 0xe6, 0x53, 0x81, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
});

static const crypto::big_integer DH_G({
  2
});

class key_agreement
{
  public:
    key_agreement(
      size_t private_key_bytes = DH_SEC_LEN
      );

    const crypto::big_integer&
    get_public_key(
      void
      ) const;

    const crypto::big_integer&
    get_private_key(
      void
      ) const;

    crypto::big_integer
    get_shared_secret(
      const crypto::big_integer& other_public_key
      ) const;

  private:
    void
    generate_key_pair(
      size_t private_key_bytes
      );

    crypto::big_integer _public_key;
    crypto::big_integer _private_key;
};

}
