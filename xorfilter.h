// xorfilter.h
#pragma once
#include <vector>
#include <cstdint>

class XORFilter {
private:
    std::vector<uint16_t> filter;
    size_t size;

public:
    XORFilter(size_t n) : size(n) {
        filter.resize(n, 0);
    }

    void add(uint64_t item) {
        size_t index = item % size;
        filter[index] ^= (uint16_t)(item >> 48);
    }

    bool mayContain(uint64_t item) const {
        size_t index = item % size;
        return (filter[index] & (uint16_t)(item >> 48)) == (uint16_t)(item >> 48);
    }
};
