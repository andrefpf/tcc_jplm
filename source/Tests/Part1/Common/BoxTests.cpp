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

/** \file     BoxTests.cpp
 *  \brief    Test of Box.
 *  \details  
 *  \author   Ismael Seidel <i.seidel@samsung.com>
 *  \date     2019-07-23
 */

#include <iostream>
#include "Lib/Part1/Common/Box.h"
#include "gtest/gtest.h"


TEST(BoxBasicTest, BoxInitializationDoesNotThrow) {
	EXPECT_NO_THROW(Box(TBox(0x00000000), EmptyDBox()));
}

TEST(BoxBasicTest, BoxInitializationDefaultDoesNotThrow) {
	EXPECT_NO_THROW(Box(TBox(0x00000000)));
}


TEST(BoxBasicTest, ExpectedValueInBoxType) {
	auto box = Box(TBox(0x00000000));
	EXPECT_EQ(box.get_tbox(), TBox(0x00000000));
}


TEST(BoxBasicTest, ExpectedValueInBoxData) {
	auto box = Box(TBox(0x00000000));
	EXPECT_EQ(*box.get_dbox(), EmptyDBox());
}


TEST(BoxBasicTest, ExpectedBoxSize8) {
	auto box = Box(TBox(0x00000000));
	EXPECT_EQ(box.size(), 8);
}


TEST(BoxBasicTest, ExpectedNoXLFieldForSmallBox) {
	auto box = Box(TBox(0x00000000));
	EXPECT_FALSE(box.get_xlbox());
}


TEST(BoxBasicTest, ExpectedBoxLBoxDifferentFrom1) {
	auto box = Box(TBox(0x00000000));
	EXPECT_NE(box.get_lbox(), LBox(1));
}


TEST(BoxBasicTest, ExpectedBoxLenghtEqualSize) {
	auto box = Box(TBox(0x00000000));
	EXPECT_EQ(box.get_lbox().get_value(), box.size());
}


int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}