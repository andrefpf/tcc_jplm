#ifndef JPLM_LIB_PART2_COMMON_COMPRESSIONTYPELIGHTFIELD_H__
#define JPLM_LIB_PART2_COMMON_COMPRESSIONTYPELIGHTFIELD_H__

#include "Lib/Common/Boxes/Generic/CompressionType.h"

enum class CompressionTypeLightField : compression_type_data {
	transform_mode = 0, //the 4D transform mode is used
	prediction_mode = 1, //the 4D prediction mode is used
	//all other values are reserved for ISO use
};

#endif /* end of include guard: JPLM_LIB_PART2_COMMON_COMPRESSIONTYPELIGHTFIELD_H__ */