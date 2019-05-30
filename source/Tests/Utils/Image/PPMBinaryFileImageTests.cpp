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

/** \file     PPMBinaryFileImageTests.cpp
 *  \brief    Test of PPM Binary File reader/writer.
 *  \details  
 *  \author   Ismael Seidel <i.seidel@samsung.com>
 *  \date     2019-05-29
 */

#include <iostream>
#include "Image.h"
#include "PPMBinaryFile.h"
#include "PixelMapFileIO.h"
#include "gtest/gtest.h"

std::string resources_path = "../resources";

struct PatternImageRead : testing::Test {
 protected:
  std::unique_ptr<PixelMapFile> file;
  PatternImageRead() {
    file = PixelMapFileIO::open({resources_path + "/rgb_pattern/pattern.ppm"});
  }
  ~PatternImageRead() = default;
};


TEST_F(PatternImageRead, ImageType) {
  auto image_readed = file->read_full_image();
  std::visit([](auto& image) { EXPECT_EQ(image->get_type(), ImageType::RGB); },
      image_readed);
}


TEST_F(PatternImageRead, Width) {
  auto image_readed = file->read_full_image();
  std::visit(
      [](auto& image) { EXPECT_EQ(image->get_width(), 13); }, image_readed);
}

TEST_F(PatternImageRead, Height) {
  auto image_readed = file->read_full_image();
  std::visit(
      [](auto& image) { EXPECT_EQ(image->get_height(), 13); }, image_readed);
}


TEST_F(PatternImageRead, Bpp) {
  auto image_readed = file->read_full_image();
  std::visit(
      [](auto& image) { EXPECT_EQ(image->get_bpp(), 10); }, image_readed);
}


TEST_F(PatternImageRead, WhiteAtTheCenter) {
  auto image_readed = file->read_full_image();
  std::visit(
      [](auto& image) {
        EXPECT_EQ(image->get_pixel_at(0, 6, 6), 1023);
        EXPECT_EQ(image->get_pixel_at(1, 6, 6), 1023);
        EXPECT_EQ(image->get_pixel_at(2, 6, 6), 1023);
      },
      image_readed);
}


TEST_F(PatternImageRead, CountWhites) {
  auto image_readed = file->read_full_image();
  std::visit(
      [](auto& image) {
        auto white_counter = 0;
        for (auto i = decltype(image->get_height()){0}; i < image->get_height();
             ++i) {
          for (auto j = decltype(image->get_width()){0}; j < image->get_width();
               ++j) {
            auto white = true;
            for (auto c = 0; c < 3; ++c) {
              if (image->get_pixel_at(c, i, j) != 1023) {
                white = false;
              }
            }
            if (white) {
              white_counter++;
            }
          }
        }
        EXPECT_EQ(white_counter, 49);
      },
      image_readed);
}


TEST_F(PatternImageRead, CountBlacks) {
  auto image_readed = file->read_full_image();
  std::visit(
      [](auto& image) {
        auto black_counter = 0;
        for (auto i = decltype(image->get_height()){0}; i < image->get_height();
             ++i) {
          for (auto j = decltype(image->get_width()){0}; j < image->get_width();
               ++j) {
            auto black = true;
            for (auto c = 0; c < 3; ++c) {
              if (image->get_pixel_at(c, i, j) != 0) {
                black = false;
              }
            }
            if (black) {
              black_counter++;
            }
          }
        }
        EXPECT_EQ(black_counter, 16);
      },
      image_readed);
}


TEST_F(PatternImageRead, CountGrays) {
  auto image_readed = file->read_full_image();
  std::visit(
      [](auto& image) {
        auto gray_counter = 0;
        for (auto i = decltype(image->get_height()){0}; i < image->get_height();
             ++i) {
          for (auto j = decltype(image->get_width()){0}; j < image->get_width();
               ++j) {
            auto gray = true;
            for (auto c = 0; c < 3; ++c) {
              if (image->get_pixel_at(c, i, j) != 511) {
                gray = false;
              }
            }
            if (gray) {
              gray_counter++;
            }
          }
        }
        EXPECT_EQ(gray_counter, 8);
      },
      image_readed);
}


TEST_F(PatternImageRead, CountReds) {
  auto image_readed = file->read_full_image();
  std::visit(
      [](auto& image) {
        auto red_counter = 0;
        for (auto i = decltype(image->get_height()){0}; i < image->get_height();
             ++i) {
          for (auto j = decltype(image->get_width()){0}; j < image->get_width();
               ++j) {
            if ((image->get_pixel_at(0, i, j) == 1023) &&
                (image->get_pixel_at(1, i, j) == 0) &&
                (image->get_pixel_at(2, i, j) == 0)) {
              red_counter++;
            }
          }
        }
        EXPECT_EQ(red_counter, 24);
      },
      image_readed);
}


TEST_F(PatternImageRead, CountGreens) {
  auto image_readed = file->read_full_image();
  std::visit(
      [](auto& image) {
        auto green_counter = 0;
        for (auto i = decltype(image->get_height()){0}; i < image->get_height();
             ++i) {
          for (auto j = decltype(image->get_width()){0}; j < image->get_width();
               ++j) {
            if ((image->get_pixel_at(0, i, j) == 0) &&
                (image->get_pixel_at(1, i, j) == 1023) &&
                (image->get_pixel_at(2, i, j) == 0)) {
              green_counter++;
            }
          }
        }
        EXPECT_EQ(green_counter, 32);
      },
      image_readed);
}


TEST_F(PatternImageRead, CountBlues) {
  auto image_readed = file->read_full_image();
  std::visit(
      [](auto& image) {
        auto blue_counter = 0;
        for (auto i = decltype(image->get_height()){0}; i < image->get_height();
             ++i) {
          for (auto j = decltype(image->get_width()){0}; j < image->get_width();
               ++j) {
            if ((image->get_pixel_at(0, i, j) == 0) &&
                (image->get_pixel_at(1, i, j) == 0) &&
                (image->get_pixel_at(2, i, j) == 1023)) {
              blue_counter++;
            }
          }
        }
        EXPECT_EQ(blue_counter, 40);
      },
      image_readed);
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  //this is to enable ctest to run the test passing the path to the resources
  if (argc > 1) {
    resources_path = std::string(argv[1]);
  }
  return RUN_ALL_TESTS();
}