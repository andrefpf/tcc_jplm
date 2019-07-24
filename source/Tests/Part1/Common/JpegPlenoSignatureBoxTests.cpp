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

/** \file     JpegPlenoSignatureBoxTest.cpp
 *  \brief    
 *  \details  
 *  \author   Ismael Seidel <i.seidel@samsung.com>
 *  \date     2019-07-23
 */


#include <iostream>
#include "Lib/Part1/Common/JpegPlenoSignatureBox.h"
#include "gtest/gtest.h"


TEST(JpegPlenoSignatureBoxBasic, Initialization) {
	EXPECT_NO_THROW(JpegPlenoSignatureBox());
}


TEST(JpegPlenoSignatureBoxBasic, CorrectLBoxValue) {
	auto pleno_signature_box = JpegPlenoSignatureBox();
	EXPECT_EQ(pleno_signature_box.get_lbox().get_value(), 12);
}


TEST(JpegPlenoSignatureBoxBasic, XLBoxDoNotExist) {
	auto pleno_signature_box = JpegPlenoSignatureBox();
	EXPECT_FALSE(pleno_signature_box.get_xlbox());
}


TEST(JpegPlenoSignatureBoxBasic, TBoxValueNotOne) {
	auto pleno_signature_box = JpegPlenoSignatureBox();
	EXPECT_NE(pleno_signature_box.get_tbox().get_value(), 1);
}


TEST(JpegPlenoSignatureBoxBasic, CorrectTBoxValue) {
	auto pleno_signature_box = JpegPlenoSignatureBox();
	EXPECT_EQ(pleno_signature_box.get_tbox().get_value(), 0x6a706c20);
}


TEST(JpegPlenoSignatureBoxBasic, CorrectDBoxValue) {
	auto pleno_signature_box = JpegPlenoSignatureBox();
	auto dbox = pleno_signature_box.get_dbox();
	auto contents = dbox->get_ref_to_contents();
	auto& vec = std::any_cast<std::vector<unsigned char>&>(contents);
	EXPECT_EQ(vec.at(0), 0x0d);
	EXPECT_EQ(vec.at(1), 0x0a);
	EXPECT_EQ(vec.at(2), 0x87);
	EXPECT_EQ(vec.at(3), 0x0a);
}


int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}