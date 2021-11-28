#pragma once
#include <boost/align/aligned_allocator.hpp>
#include <cstdint>
#include <nlohmann/json.hpp>
#include <vector>

#include "DatatypeEnum.hpp"

namespace dai {

// to match CV_MALLOC_ALIGN
template <typename T, int ALIGN_BYTES = 64>
using aligned_vector = std::vector<T, boost::alignment::aligned_allocator<T, ALIGN_BYTES>>;

/// RawBuffer structure
struct RawBuffer {
    virtual ~RawBuffer() = default;
    dai::aligned_vector<std::uint8_t> data;

    virtual void serialize(std::vector<std::uint8_t>& metadata, DatatypeEnum& datatype) const {
        (void)metadata;
        datatype = DatatypeEnum::Buffer;
    };

    // NLOHMANN_DEFINE_TYPE_INTRUSIVE(RawBuffer);
};

}  // namespace dai
