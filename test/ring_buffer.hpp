// ring_buffer.hpp - ring_buffer copy from webrtc

// Date   : 2020/12/14
#ifndef RING_BUFFER_HPP
#define RING_BUFFER_HPP
#include <cstddef>
#include <cassert>


template<typename T, size_t kSize>
class RingBuffer {
public:
    RingBuffer(): current_index_(0) {}

    size_t BufferSize() const {return kSize;}

    size_t CurrentIndex() const {return current_index_;}

    // Return ture if a value was saved to index |n|.
    bool IsFilledIndex(size_t n) const {
        return IsFilledIndexByBufferIndex(BufferIndex(n));
    }

    // Returns the element at index |n| (% |kSize|).
    //
    //  n = 0 return the oldest value and
    //  n = bufferSize() - 1 return the most recent value.
    const T&ReadBuffer(size_t n) const {
        const size_t buffer_index = BufferIndex(n);
        assert(IsFilledIndexByBufferIndex(buffer_index) == true);
        return buffer_[buffer_index];
    }

    T* MutableReadBuffer(size_t n) {
        const size_t buffer_index = BufferIndex(n);
        assert(IsFilledIndexByBufferIndex(buffer_index) == true);
        return &buffer_[buffer_index];
    }

    void SaveToBuffer(const T& value) {
        buffer_[BufferIndex(0)] = value;
        current_index_ ++;
    }

    void Clear() { current_index_ = 0;}

    //  Iterator has const access to the RingBuffer it got retrieved from.
    class Iterator {
    public:
        size_t index() const { return index_;}

        const T* operator->() const {return &buffer_.ReadBuffer(index_);}
        const T* operator*() const {return &buffer_.ReadBuffer(index_);}

        Iterator& operator++() {
            index_++;
            if (index_ == kSize)
                out_of_range_ = true;
            return *this;
        }

        Iterator& operator--() {
            if (index_ == 0)
                out_of_range_ = true;
            index_--;
            return *this;
        }

        operator bool() const {
            return !out_of_range_ && buffer_.IsFilledIndex(index_);
        }
    private:
        Iterator(const RingBuffer<T, kSize>& buffer, size_t index)
            : buffer_(buffer), index_(index), out_of_range_(false) {}

        const RingBuffer<T, kSize>& buffer_;
        size_t index_;
        bool out_of_range_;
        friend class RingBuffer<T,kSize>;
    };

    // Returns an Iterator pointing to the oldest value in the buffer.
    // Example usage (iterate from oldest to newest value):
    //  for (RingBuffer<T, kSize>::Iterator it = ring_buffer.Begin():it; ++it){}
    Iterator Begin() const {
        if (current_index_ < kSize)
            return Iterator(*this, kSize - current_index_);
        return Iterator(*this, 0);
    }

    // Returns an Iterator pointing to the newest value in the buffer.
    // Example usage (iterate backwards from newest to oldest value);
    //  for  (RingBuffer<T, kSize>::Iterator it = ring_buffer.End(); it; --it){}
    Iterator End() const {return Iterator(*this, kSize - 1);}

private:
    inline size_t BufferIndex(size_t n) const {
        return (current_index_ + n) % kSize;
    }

    // This specialization of |IsFilledIndex| is a micro-optimization that
    // enables us to do e.g. `CHECK(IsFilledIndex(n))` without calling
    // |BufferIndex| twice. Since |BufferIndex| involves a % operation, it's not
    // quite micro-scale.
    inline bool IsFilledIndexByBufferIndex(size_t buffer_index) const {
        return buffer_index < current_index_;
    }

    T buffer_[kSize];
    size_t current_index_;

    RingBuffer(const RingBuffer &) = delete;
    RingBuffer &operator=(const RingBuffer&) = delete;
};

#endif
