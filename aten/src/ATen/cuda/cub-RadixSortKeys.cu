#define TORCH_ASSERT_NO_OPERATORS
#include <ATen/cuda/CUDAConfig.h>
#include <ATen/cuda/cub.cuh>

namespace at {
namespace cuda {
namespace cub {

template <typename key_t>
void radix_sort_keys(
    const key_t* keys_in,
    key_t* keys_out,
    int64_t n,
    bool descending,
    int64_t begin_bit,
    int64_t end_bit) {
  TORCH_CHECK(
      n <= std::numeric_limits<int>::max(),
      "cub sort does not support sorting more than INT_MAX elements");
  using key_t_ = typename detail::cuda_type<key_t>::type;

  const key_t_* keys_in_ = reinterpret_cast<const key_t_*>(keys_in);
  key_t_* keys_out_ = reinterpret_cast<key_t_*>(keys_out);

  if (descending) {
    CUB_WRAPPER(
        NO_ROCM(at_cuda_detail)::cub::DeviceRadixSort::SortKeysDescending,
        keys_in_,
        keys_out_,
        n,
        begin_bit,
        end_bit,
        c10::cuda::getCurrentCUDAStream());
  } else {
    CUB_WRAPPER(
        NO_ROCM(at_cuda_detail)::cub::DeviceRadixSort::SortKeys,
        keys_in_,
        keys_out_,
        n,
        begin_bit,
        end_bit,
        c10::cuda::getCurrentCUDAStream());
  }
}

template <typename scalar_t>
void unique(
    const scalar_t* input,
    scalar_t* output,
    int64_t* num_selected_out,
    int64_t num_items) {
  TORCH_CHECK(
      num_items <= std::numeric_limits<int>::max(),
      "cub unique does not support more than INT_MAX elements");
  CUB_WRAPPER(
      NO_ROCM(at_cuda_detail)::cub::DeviceSelect::Unique,
      input,
      output,
      num_selected_out,
      num_items,
      at::cuda::getCurrentCUDAStream());
}

template <typename scalar_t>
void run_length_encode(
    const scalar_t* input,
    scalar_t* output,
    int64_t* counts_out,
    int64_t* length_out,
    int64_t num_items) {
  TORCH_CHECK(
      num_items <= std::numeric_limits<int>::max(),
      "cub run_length_encode does not support more than INT_MAX elements");
  CUB_WRAPPER(
      NO_ROCM(at_cuda_detail)::cub::DeviceRunLengthEncode::Encode,
      input,
      output,
      counts_out,
      length_out,
      num_items,
      at::cuda::getCurrentCUDAStream());
}

#define AT_INSTATIATE_CUB_TEMPLATES(scalar_t, ScalarType) \
  template void radix_sort_keys(                          \
      const scalar_t* keys_in,                            \
      scalar_t* keys_out,                                 \
      int64_t n,                                          \
      bool descending,                                    \
      int64_t begin_bit,                                  \
      int64_t end_bit);                                   \
  template void unique(                                   \
      const scalar_t* input,                              \
      scalar_t* output,                                   \
      int64_t* num_selected_out,                          \
      int64_t num_items);                                 \
  template void run_length_encode(                        \
      const scalar_t* input,                              \
      scalar_t* output,                                   \
      int64_t* counts_out,                                \
      int64_t* length_out,                                \
      int64_t n);

AT_FORALL_SCALAR_TYPES_AND2(Bool, Half, AT_INSTATIATE_CUB_TEMPLATES)

} // namespace cub
} // namespace cuda
} // namespace at
