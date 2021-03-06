#ifndef TF_SEAL_CC_KERNELS_KEY_VARIANTS_H_
#define TF_SEAL_CC_KERNELS_KEY_VARIANTS_H_

#include <string>

#include "tensorflow/core/framework/op.h"
#include "tensorflow/core/framework/op_kernel.h"
#include "tensorflow/core/framework/shape_inference.h"
#include "tensorflow/core/framework/variant.h"
#include "tensorflow/core/framework/variant_encode_decode.h"
#include "tensorflow/core/framework/variant_op_registry.h"
#include "tensorflow/core/framework/variant_tensor_data.h"

#include "seal/seal.h"

namespace tf_seal {

using tensorflow::VariantTensorData;

using seal::GaloisKeys;
using seal::KeyGenerator;
using seal::PublicKey;
using seal::RelinKeys;
using seal::SecretKey;

class PublicKeysVariant {
 public:
  PublicKeysVariant() = default;
  PublicKeysVariant(const PublicKeysVariant& other) = default;

  static const char kTypeName[];

  std::string TypeName() const { return kTypeName; }

  void Encode(VariantTensorData* data) const;

  bool Decode(const VariantTensorData& data);

  std::string DebugString() const { return "PublicKeyVariant"; }

  PublicKey public_key;
  RelinKeys relin_keys;
  GaloisKeys galois_keys;
};

class SecretKeyVariant {
 public:
  explicit SecretKeyVariant(SecretKey key) : key(key) {}
  SecretKeyVariant(const SecretKeyVariant& other) = default;

  static const char kTypeName[];

  std::string TypeName() const { return kTypeName; }

  void Encode(VariantTensorData* data) const;

  bool Decode(const VariantTensorData& data);

  std::string DebugString() const { return "SecretKeyVariant"; }

  SecretKey key;
};

}  // namespace tf_seal

#endif  // TF_SEAL_CC_KERNELS_KEY_VARIANTS_H_
