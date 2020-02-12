#pragma once

// @generated by aten/src/ATen/gen.py

#include <c10/core/TensorOptions.h>
#include <c10/core/Scalar.h>
#include <c10/core/QScheme.h>
#include <c10/core/MemoryFormat.h>
#include <c10/util/ArrayRef.h>
#include <c10/util/intrusive_ptr.h>
#include <torch/csrc/WindowsTorchApiMacro.h>
#include <ATen/Dimname.h>



namespace c10 {
struct Storage;
}

namespace at {

class Tensor;
using TensorList = ArrayRef<Tensor>;

class Context;
struct Generator;

struct Quantizer;
// This is temporary typedef to enable Quantizer in aten native function API
// we'll remove them when we are actually exposing Quantizer class
// to frontend
using ConstQuantizerPtr = const c10::intrusive_ptr<Quantizer>&;

namespace QuantizedCPUType {
  Tensor as_strided(const Tensor & self, IntArrayRef size, IntArrayRef stride, c10::optional<int64_t> storage_offset);
  Tensor clamp(const Tensor & self, c10::optional<Scalar> min, c10::optional<Scalar> max);
  Tensor _empty_affine_quantized(IntArrayRef size, c10::optional<ScalarType> dtype, c10::optional<Layout> layout, c10::optional<Device> device, c10::optional<bool> pin_memory, double scale, int64_t zero_point, c10::optional<MemoryFormat> memory_format);
  Tensor _empty_per_channel_affine_quantized(IntArrayRef size, const Tensor & scales, const Tensor & zero_points, int64_t axis, c10::optional<ScalarType> dtype, c10::optional<Layout> layout, c10::optional<Device> device, c10::optional<bool> pin_memory, c10::optional<MemoryFormat> memory_format);
  Tensor quantized_max_pool2d(const Tensor & self, IntArrayRef kernel_size, IntArrayRef stride, IntArrayRef padding, IntArrayRef dilation, bool ceil_mode);
  Tensor mean(const Tensor & self, c10::optional<ScalarType> dtype);
  Tensor mean(const Tensor & self, IntArrayRef dim, bool keepdim, c10::optional<ScalarType> dtype);
  Tensor & mean_out(Tensor & out, const Tensor & self, IntArrayRef dim, bool keepdim, c10::optional<ScalarType> dtype);
  Tensor relu(const Tensor & self);
  Tensor & relu_(Tensor & self);
  Tensor sigmoid(const Tensor & self);
  Tensor tanh(const Tensor & self);
  Tensor clone(const Tensor & self, c10::optional<MemoryFormat> memory_format);
  Tensor dequantize(const Tensor & self);
  double q_scale(const Tensor & self);
  int64_t q_zero_point(const Tensor & self);
  Tensor q_per_channel_scales(const Tensor & self);
  Tensor q_per_channel_zero_points(const Tensor & self);
  int64_t q_per_channel_axis(const Tensor & self);
  Tensor int_repr(const Tensor & self);
  QScheme qscheme(const Tensor & self);
  Tensor & set_(Tensor & self, Storage source, int64_t storage_offset, IntArrayRef size, IntArrayRef stride);
  Tensor & set_quantizer_(Tensor & self, ConstQuantizerPtr quantizer);
  Tensor view(const Tensor & self, IntArrayRef size);
  Tensor & ne_out(Tensor & out, const Tensor & self, Scalar other);
  Tensor ne(const Tensor & self, Scalar other);
  Tensor & ne_out(Tensor & out, const Tensor & self, const Tensor & other);
  Tensor ne(const Tensor & self, const Tensor & other);
  Tensor & eq_out(Tensor & out, const Tensor & self, Scalar other);
  Tensor eq(const Tensor & self, Scalar other);
  Tensor & eq_out(Tensor & out, const Tensor & self, const Tensor & other);
  Tensor eq(const Tensor & self, const Tensor & other);
  Tensor & ge_out(Tensor & out, const Tensor & self, Scalar other);
  Tensor ge(const Tensor & self, Scalar other);
  Tensor & ge_out(Tensor & out, const Tensor & self, const Tensor & other);
  Tensor ge(const Tensor & self, const Tensor & other);
  Tensor & le_out(Tensor & out, const Tensor & self, Scalar other);
  Tensor le(const Tensor & self, Scalar other);
  Tensor & le_out(Tensor & out, const Tensor & self, const Tensor & other);
  Tensor le(const Tensor & self, const Tensor & other);
  Tensor & gt_out(Tensor & out, const Tensor & self, Scalar other);
  Tensor gt(const Tensor & self, Scalar other);
  Tensor & gt_out(Tensor & out, const Tensor & self, const Tensor & other);
  Tensor gt(const Tensor & self, const Tensor & other);
  Tensor & lt_out(Tensor & out, const Tensor & self, Scalar other);
  Tensor lt(const Tensor & self, Scalar other);
  Tensor & lt_out(Tensor & out, const Tensor & self, const Tensor & other);
  Tensor lt(const Tensor & self, const Tensor & other);
  Tensor min(const Tensor & self);
  Tensor max(const Tensor & self);
  std::tuple<Tensor,Tensor> sort(const Tensor & self, int64_t dim, bool descending);
  std::tuple<Tensor,Tensor> topk(const Tensor & self, int64_t k, int64_t dim, bool largest, bool sorted);
  bool equal(const Tensor & self, const Tensor & other);
  Tensor _cat(TensorList tensors, int64_t dim);
  Tensor & _cat_out(Tensor & out, TensorList tensors, int64_t dim);
  Tensor & leaky_relu_out(Tensor & out, const Tensor & self, Scalar negative_slope);
  Tensor leaky_relu(const Tensor & self, Scalar negative_slope);
  Tensor & leaky_relu_(Tensor & self, Scalar negative_slope);
  Tensor _adaptive_avg_pool2d(const Tensor & self, IntArrayRef output_size);
  Tensor avg_pool2d(const Tensor & self, IntArrayRef kernel_size, IntArrayRef stride, IntArrayRef padding, bool ceil_mode, bool count_include_pad, c10::optional<int64_t> divisor_override);
  Tensor upsample_bilinear2d(const Tensor & self, IntArrayRef output_size, bool align_corners, c10::optional<double> scales_h, c10::optional<double> scales_w);
  Tensor upsample_nearest2d(const Tensor & self, IntArrayRef output_size, c10::optional<double> scales_h, c10::optional<double> scales_w);
}

} // namespace at
