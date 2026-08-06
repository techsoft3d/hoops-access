#pragma once

#include "sam/vdm/vdmdefs.h"
#include "samcpp/core/coredefs.h"

namespace cae::access {
class DataSource;
class Options;
class UnrecognizedData;

using DataSourcePtr = cae::core::Pointer<DataSource>;
using OptionsPtr = cae::core::Pointer<Options>;
using UnrecognizedDataPtr = cae::core::Pointer<UnrecognizedData>;
} // namespace cae::access
