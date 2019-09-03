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

/** \file     JpegPlenoCodestreamBox.h
 *  \brief    
 *  \details  
 *  \author   Ismael Seidel <i.seidel@samsung.com>
 *  \date     2019-07-25
 */

#ifndef JPLM_LIB_PART1_COMMON_BOXES_JPEGPLENOCODESTREAMBOX_H__
#define JPLM_LIB_PART1_COMMON_BOXES_JPEGPLENOCODESTREAMBOX_H__

//the ideia is to be the base for
// JpegPlenoLightFieldBox
// JpegPlenoPointCloudBox
// JpegPlenoHologramBox
//

#include "Lib/Common/Boxes/GenericBox.h"

// enum class JpegPlenoCodestreamBoxTypes : t_box_id_type {
//   LightField = 0x6a706c66,
//   PointCloud = 0x6a707063,
//   Hologram = 0x6a70686f,
// };


class JpegPlenoCodestreamBox : public Box {
 public:
  JpegPlenoCodestreamBox(TBox t_box, const DBox& d_box) : Box(t_box, d_box) {
  }


  JpegPlenoCodestreamBox(TBox t_box, std::unique_ptr<DBox>&& d_box)
      : Box(t_box, std::move(d_box)) {
  }

  virtual ~JpegPlenoCodestreamBox() = default;
};


// template<JpegPlenoCodestreamBoxTypes box_id, class T>
// class JpegPlenoCodestreamBox
//     : public GenericBox<static_cast<t_box_id_type>(box_id), T> {
//  public:
//   using GenericBox<static_cast<t_box_id_type>(box_id), T>::GenericBox;

//   virtual ~JpegPlenoCodestreamBox() = default;
// };

#endif /* end of include guard: JPLM_LIB_PART1_COMMON_BOXES_JPEGPLENOCODESTREAMBOX_H__ */