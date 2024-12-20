#include "FixedBlockMemoryResource.h"
#include <stdexcept>
#include <algorithm>

FixedBlockMemoryResource::FixedBlockMemoryResource(std::size_t block_size)
    : block_size_(block_size), current_pos_(0), memory_block_(std::make_unique<std::byte[]>(block_size)) {}

FixedBlockMemoryResource::~FixedBlockMemoryResource() {
    // Освобождение памяти не требуется, так как мы используем std::unique_ptr
}

void* FixedBlockMemoryResource::do_allocate(std::size_t bytes, std::size_t alignment) {
    if (current_pos_ + bytes <= block_size_) {
        void* ptr = memory_block_.get() + current_pos_;
        allocated_blocks_.emplace_back(ptr, bytes);
        current_pos_ += bytes;
        return ptr;
    } else {
        throw std::bad_alloc();
    }
}

void FixedBlockMemoryResource::do_deallocate(void* p, std::size_t bytes, std::size_t alignment) {
    allocated_blocks_.remove_if([p](const std::pair<void*, std::size_t>& block) {
        return block.first == p;
    });
}

bool FixedBlockMemoryResource::do_is_equal(const std::pmr::memory_resource& other) const noexcept {
    return this == &other;
}
