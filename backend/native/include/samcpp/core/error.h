#pragma once

#include "samcpp/core/base_types.h"

namespace cae::core {

/// Error codes returned by API functions.
enum class ErrorCode {
    NONE = SYS_ERROR_NONE,              ///< No error
    VALUE = SYS_ERROR_VALUE,            ///< Invalid value
    ENUM = SYS_ERROR_ENUM,              ///< Invalid enumeration
    OBJECTTYPE = SYS_ERROR_OBJECTTYPE,  ///< Invalid object type
    MEMORY = SYS_ERROR_MEMORY,          ///< Memory allocation error
    NULLOBJECT = SYS_ERROR_NULLOBJECT,  ///< Null object reference
    FILE = SYS_ERROR_FILE,              ///< File operation error
    COMPUTE = SYS_ERROR_COMPUTE,        ///< Computation error
    OPERATION = SYS_ERROR_OPERATION,    ///< Invalid operation
    OVERFLOWERR = SYS_ERROR_OVERFLOW,   ///< Overflow error
    UNDERFLOWERR = SYS_ERROR_UNDERFLOW, ///< Underflow error
    UNKNOWN = SYS_ERROR_UNKNOWN,        ///< Unknown error
    FORMAT = SYS_ERROR_FORMAT,          ///< Format error
    LOAD = SYS_ERROR_LOAD,              ///< Load error
    SEVERE = SYS_ERROR_SEVERE,          ///< Severe error
    LICENSE = SYS_ERROR_LICENSE         ///< License error
};

} // namespace cae::core
