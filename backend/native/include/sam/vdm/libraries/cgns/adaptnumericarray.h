#ifndef ADAPTNUMERICARRAY_DEF
#define ADAPTNUMERICARRAY_DEF

#include "sam/base/basedefs.h"
#include "sam/vdm/vdmdefs.h"

/* A dynamically allocated numeric array that minimizes memory usage by selecting
the smallest integer type capable of storing the. used to build PolyData arrays */
class adaptNumericArray {
  public:
    enum class ArrayKind { Int, Long, Uint, Ulong };
    adaptNumericArray();
    adaptNumericArray(size_t size, bool isUnsigned);
    ~adaptNumericArray();

    void
    alloc(size_t size, bool isUnsigned);
    void
    realloc(size_t newLength);
    void
    zero();

    Vlong
    get(size_t i) const;
    size_t
    getUnsigned(size_t i) const;

    void
    set(size_t i, Vlong value);
    void
    setUnsigned(size_t i, size_t value);

  private:
    void* m_data;
    ArrayKind m_kind;
    size_t m_length;
};

#ifdef __cplusplus
extern "C" {
}
#endif

#endif
