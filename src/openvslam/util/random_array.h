#ifndef OPENVSLAM_UTIL_RANDOM_ARRAY_H
#define OPENVSLAM_UTIL_RANDOM_ARRAY_H

#include "openvslam/openvslam_exports.h"
#include <vector>
#include <random>
#include <memory>
#include <cassert>

namespace openvslam {
namespace util {

// Create random_engine. If use_fixed_seed is true, a fixed seed value is used.
OPENVSLAM_API std::mt19937 create_random_engine(bool use_fixed_seed = false);


template<typename T>
std::vector<T> create_random_array(const size_t size, const T rand_min, const T rand_max,
                                   std::mt19937& random_engine) {
    assert(rand_min <= rand_max);
    assert(size <= static_cast<size_t>(rand_max - rand_min + 1));

    std::uniform_int_distribution<T> uniform_int_distribution(rand_min, rand_max);

    // Create a random sequence slightly larger than the 'size' (because duplication possibly exists)
    const auto make_size = static_cast<size_t>(size * 1.2);

    // Iterate until the output vector reaches the 'size'
    std::vector<T> v;
    v.reserve(size);
    while (v.size() != size) {
        // Add random integer values
        while (v.size() < make_size) {
            v.push_back(uniform_int_distribution(random_engine));
        }

        // Sort to remove duplicates so that the last iterator of the deduplicated sequence goes into 'unique_end'
        std::sort(v.begin(), v.end());
        auto unique_end = std::unique(v.begin(), v.end());

        // If the vector size is too large, change it to an iterator up to the 'size'
        if (size < static_cast<size_t>(std::distance(v.begin(), unique_end))) {
            unique_end = std::next(v.begin(), size);
        }

        // Delete the portion from the duplication to the end
        v.erase(unique_end, v.end());
    }

    // Shuffle because they are in ascending order
    std::shuffle(v.begin(), v.end(), random_engine);

    return v;
}

// template specialization
template std::vector<int> create_random_array(size_t, int, int, std::mt19937&);
template std::vector<unsigned int> create_random_array(size_t, unsigned int, unsigned int, std::mt19937&);

} // namespace util
} // namespace openvslam

#endif // OPENVSLAM_UTIL_RANDOM_ARRAY_H
