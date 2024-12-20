#ifndef FIXEDBLOCKMEMORYRESOURCE_H
#define FIXEDBLOCKMEMORYRESOURCE_H

#include <memory_resource>
#include <list>
#include <memory>

class FixedBlockMemoryResource : public std::pmr::memory_resource {
public:
    FixedBlockMemoryResource(std::size_t block_size);
    ~FixedBlockMemoryResource();

    void* do_allocate(std::size_t bytes, std::size_t alignment) override;
    void do_deallocate(void* p, std::size_t bytes, std::size_t alignment) override;
    bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override;

private:
    std::size_t block_size_;
    std::size_t current_pos_;
    std::unique_ptr<std::byte[]> memory_block_;
    std::list<std::pair<void*, std::size_t>> allocated_blocks_;
};

#endif // FIXEDBLOCKMEMORYRESOURCE_H
