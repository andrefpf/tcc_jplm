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

/** \file     JpegPlenoThumbnailContents.h
 *  \brief    
 *  \details  
 *  \author   Ismael Seidel <i.seidel@samsung.com>
 *  \date     2019-08-21
 */

#ifndef JPLM_LIB_PART1_COMMON_BOXES_JPEGPLENOTHUMBNAILCONTENTS_H__
#define JPLM_LIB_PART1_COMMON_BOXES_JPEGPLENOTHUMBNAILCONTENTS_H__

#include <algorithm>
#include <numeric>
#include "Lib/Common/Boxes/Generic/BitsPerComponentBox.h"
#include "Lib/Common/Boxes/Generic/ChannelDefinitionBox.h"
#include "Lib/Common/Boxes/Generic/ColourSpecificationBox.h"
#include "Lib/Common/Boxes/Generic/ContiguousCodestreamBox.h"
#include "Lib/Common/Boxes/Generic/ImageHeaderBox.h"
#include "Lib/Common/Boxes/Generic/ImageHeaderContents.h"
#include "Lib/Common/Boxes/InMemoryDBox.h"


class JpegPlenoThumbnailContents : public InMemoryDBox {
 protected:
  ImageHeaderBox ihdr;  //image header box
  std::optional<BitsPerComponentBox> bpcc;
  std::vector<ColourSpecificationBox> colr;
  std::optional<ChannelDefinitionBox> cdef;
  std::optional<ContiguousCodestreamBox> jpc2;

 public:
  JpegPlenoThumbnailContents(const ImageHeaderBox& ihdr,
      const std::optional<BitsPerComponentBox>& bpcc,
      const std::vector<ColourSpecificationBox>& colr,
      const std::optional<ChannelDefinitionBox>& cdef,
      const std::optional<ContiguousCodestreamBox>& jpc2)
      : ihdr(ihdr), bpcc(bpcc), colr(colr), cdef(cdef), jpc2(jpc2) {
  }


  JpegPlenoThumbnailContents(const JpegPlenoThumbnailContents& other)
      : ihdr(other.ihdr), bpcc(other.bpcc), colr(other.colr), cdef(other.cdef),
        jpc2(other.jpc2) {
  }


  JpegPlenoThumbnailContents(JpegPlenoThumbnailContents&& other)
      : ihdr(std::move(other.ihdr)), bpcc(std::move(other.bpcc)),
        colr(std::move(other.colr)), cdef(std::move(other.cdef)),
        jpc2(std::move(other.jpc2)) {
  }


  // void add_image_header_box(const ImageHeaderBox& ihdr) {
  //   this->ihdr = ihdr;
  // }


  // void add_image_header_box(ImageHeaderBox&& ihdr) {
  //   this->ihdr = std::move(ihdr);
  // }


  // void add_bits_per_component_box(const BitsPerComponentBox& bpcc) {
  //   this->bpcc = bpcc;
  // }


  // void add_bits_per_component_box(BitsPerComponentBox&& bpcc) {
  //   this->bpcc = std::move(bpcc);
  // }


  // void add_colour_specification_boxes(
  //     const std::vector<ColourSpecificationBox>& colr) {
  //   this->colr = colr;
  // }


  // void add_colour_specification_boxes(
  //     std::vector<ColourSpecificationBox>&& colr) {
  //   this->colr = std::move(colr);
  // }


  // void add_channel_definition_box(const ChannelDefinitionBox& cdef) {
  //   this->cdef = cdef;
  // }


  // void add_channel_definition_box(ChannelDefinitionBox&& cdef) {
  //   this->cdef = std::move(cdef);
  // }


  // void add_contiguous_codestream_box(const ContiguousCodestreamBox& jpc2) {
  //   this->jpc2 = jpc2;
  // }


  // void add_contiguous_codestream_box(ContiguousCodestreamBox&& jpc2) {
  //   this->jpc2 = std::move(jpc2);
  // }


  virtual JpegPlenoThumbnailContents* clone() const override;


  virtual uint64_t size() const noexcept override;


  virtual bool is_equal(const DBox& other) const override;


  bool operator==(const JpegPlenoThumbnailContents& other) const;


  bool operator!=(const JpegPlenoThumbnailContents& other) const;
};


#endif /* end of include guard: JPLM_LIB_PART1_COMMON_BOXES_JPEGPLENOTHUMBNAILCONTENTS_H__ */