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

/** \file     JPLM4DTransformModeLightFieldEncoder.h
 *  \brief    
 *  \details  
 *  \author   Ismael Seidel <i.seidel@samsung.com>
 *  \date     2019-09-09
 */

#ifndef JPLM_LIB_PART2_ENCODER_JPLM4DTRANSFORMMODELIGHTFIELDENCODER_H__
#define JPLM_LIB_PART2_ENCODER_JPLM4DTRANSFORMMODELIGHTFIELDENCODER_H__

#include "Lib/Part2/Encoder/JPLMLightFieldEncoder.h"
#include "Lib/Part2/Common/TransformMode/JPLM4DTransformModeLightFieldCodec.h"
#include "Lib/Common/JPLMEncoderConfigurationLightField4DTransformMode.h"


template<typename T = uint16_t>
class JPLM4DTransformModeLightFieldEncoder : public JPLM4DTransformModeLightFieldCodec<T>, public JPLMLightFieldEncoder<T> {
 public:
  JPLM4DTransformModeLightFieldEncoder(
      std::unique_ptr<JPLMEncoderConfigurationLightField4DTransformMode>&&
          configuration)
      : JPLMLightFieldCodec<T>(std::make_unique<LightfieldFromPPMFile<T>>(
                 configuration->get_lightfield_io_configurations())),
      JPLMLightFieldEncoder<T>(std::move(configuration)) {
  }

  virtual ~JPLM4DTransformModeLightFieldEncoder() = default;


  virtual void run_for_block_4d() override {
  	std::cout << "running 4d block in encoder..." << std::endl;
  }

  // virtual void run() override {
  //   std::cout << "Run LF transfom mode encoder." << std::endl;
  //   //! \todo implement run method for jpl lightfield encoder
  // }
};

#endif /* end of include guard: JPLM_LIB_PART2_ENCODER_JPLM4DTRANSFORMMODELIGHTFIELDENCODER_H__ */

// JPLMLightFieldCodec<T>(std::make_unique<LightfieldFromPPMFile<T>>(
//                 configuration->get_lightfield_io_configurations()))