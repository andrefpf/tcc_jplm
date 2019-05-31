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

/** \file     ImageIO.h
 *  \brief    Test of PPM Binary File reader/writer.
 *  \details  
 *  \author   Ismael Seidel <i.seidel@samsung.com>
 *  \date     2019-05-29
 */

#ifndef JPLM_LIB_UTILS_IMAGE_IMAGEIO_H__
#define JPLM_LIB_UTILS_IMAGE_IMAGEIO_H__

#include "PPMBinaryFile.h"
#include "PixelMapFile.h"
#include "PixelMapFileIO.h"

namespace ImageIO {

void write_image_to_file(
    const std::variant<Image<uint8_t>, Image<uint16_t>>& image,
    const std::string& filename);

template<typename T>
void write_image_to_file(const Image<T>& image, const std::string& filename);

void write_image_to_file(
    const Image<uint16_t>& image, const std::string& filename);
void write_image_to_file(
    const Image<uint8_t>& image, const std::string& filename);


template<typename T>
void write(const Image<T>& image, const std::string& filename,
    const bool overwrite = false) {
  namespace fs = std::filesystem;
  using fpath = fs::path;
  auto name = fpath(filename);

  if (!overwrite && fs::exists(filename)) {
    throw ImageIOExceptions::FileAlreadyExistsException();
  }

  if (name.extension() == fpath(".ppm")) {
    auto max_value =
        static_cast<std::size_t>(std::pow(2.0, image.get_bpp())) - 1;
    auto oppened_image = PixelMapFileIO::open(filename, PixelMapType::P6,
        image.get_width(), image.get_height(), max_value);
    auto oppened_image_as_rgb = std::unique_ptr<PPMBinaryFile>(
        static_cast<PPMBinaryFile*>(oppened_image.release()));
    oppened_image_as_rgb->write_image_to_file(image);
  }
}

template<typename T>
void write(const Image<T>& patch_image, const std::string& filename,
    std::pair<std::size_t, std::size_t> origin) {
  using fpath = std::filesystem::path;
  auto name = fpath(filename);

  if (name.extension() == fpath(".ppm")) {
    auto oppened_image =
        PixelMapFileIO::open(filename);  //should test if exists...

    auto oppened_image_as_rgb = std::unique_ptr<PPMBinaryFile>(
        static_cast<PPMBinaryFile*>(oppened_image.release()));
    oppened_image_as_rgb->write_image_patch_to_file(patch_image, origin);
  }
}


}  // namespace ImageIO

#endif /* end of include guard: JPLM_LIB_UTILS_IMAGE_IMAGEIO_H__ */