/* The copyright in this software is being made available under the BSD
 * License, included below. This software may be subject to other third party
 * and contributor rights, including patent rights, and no such rights are
 * granted under this license.
 *
 * Copyright (c) 2010-2019, ITU/ISO/IEC
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  * Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *  * Neither the name of the ITU/ISO/IEC nor the names of its contributors may
 *    be used to endorse or promote products derived from this software without
 *    specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

/** \file     EnumCS.h
 *  \brief    
 *  \details  
 *  \author   Ismael Seidel <i.seidel@samsung.com>
 *  \date     2019-09-05
 */

#ifndef JPLM_LIB_COMMON_BOXES_GENERIC_ENUMCS_H__
#define JPLM_LIB_COMMON_BOXES_GENERIC_ENUMCS_H__

#include <cstdint>

/**
 * Defines the type of EnumCs field
 */
using enum_cs_field_type = uint32_t;

// /**
//  * \brief      Enum class to represent EnumCS values.
//  */
// enum class EnumCS : enum_cs_field_type {


//   // other values are reserved for other ISO uses
// };

enum class EnumCS : enum_cs_field_type {
  BiLevel = 0,
  YCbCr_1 = 1,
  YCbCr_2 = 3,
  YCbCr_3 = 4,
  PhotoYCC = 9,
  CMY = 11,
  CMYK = 12,
  YCCK = 13,
  CIELab = 14,
  BiLevel_2 = 15,
  sRGB = 16,  //!< sRGB as defined by IEC 61966–2–1
  greyscale =
      17,  //!< greyscale: A greyscale space where image luminance is related to code values
  // using the sRGB non-linearity given in Eqs. (2) through (4) of IEC 61966–2–1
  // (sRGB) specification
  //
  sYCC = 18,
  CIEJab = 19,
  e_sRGB = 20,
  ROMM_RGB = 21,
  YPbPr_1125_60 = 22,
  YPbPr_1250_50 = 23,
  e_sYCC = 24,
};


#endif /* end of include guard: JPLM_LIB_COMMON_BOXES_GENERIC_ENUMCS_H__ */