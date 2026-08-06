#pragma once

namespace cae::core {

#define PIMPL_MOVE_ONLY(ClassName)                    \
    ClassName();                                      \
    ~ClassName();                                     \
    ClassName(const ClassName &) = delete;            \
    ClassName &operator=(const ClassName &) = delete; \
    ClassName(ClassName &&) noexcept;                 \
    ClassName &operator=(ClassName &&) noexcept;      \
    template <typename ClassName, typename CType>     \
    friend class cae::core::Accessor;                 \
    template <typename ClassName>                     \
    friend class cae::core::TemplateAccessor;

#define ACCESSOR_DECL                             \
    namespace cae::core {                         \
    template <typename ClassName, typename CType> \
    class Accessor;                               \
    template <typename ClassName>                 \
    class TemplateAccessor;                       \
    }

} // namespace cae::core
