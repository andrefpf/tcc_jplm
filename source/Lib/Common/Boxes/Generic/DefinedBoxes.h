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

/** \file     DefinedBoxes.h
 *  \brief    
 *  \details  
 *  \author   Ismael Seidel <i.seidel@samsung.com>
 *  \date     2019-09-02
 */

#ifndef JPLM_LIB_COMMON_BOXES_GENERIC_DEFINEDBOXES_H__
#define JPLM_LIB_COMMON_BOXES_GENERIC_DEFINEDBOXES_H__

#include "Lib/Common/Boxes/GenericBox.h"
#include "Lib/Common/Boxes/Generic/CharArrayContents.h"
#include "Lib/Common/Boxes/Generic/ChannelDefinitionContents.h"
#include "Lib/Common/Boxes/Generic/ColourSpecificationContents.h"
#include "Lib/Common/Boxes/Generic/ContiguousCodestreamContents.h"
#include "Lib/Common/Boxes/Generic/DataEntryURLContents.h"
#include "Lib/Common/Boxes/Generic/ImageHeaderContents.h"
#include "Lib/Common/Boxes/Generic/UndefinedContents.h"
#include "Lib/Common/Boxes/Generic/UUIDContents.h"
#include "Lib/Common/Boxes/Generic/UUIDListContents.h"
#include "Lib/Common/Boxes/Generic/UUIDInfoContents.h"


using BitsPerComponentBox = GenericBox<0x62706363, CharArrayContents>; //this is from jpeg2000 part 1

using ChannelDefinitionBox = GenericBox<0x63646566, ChannelDefinitionContents>; //this is from jpeg2000 part 1

using ColourSpecificationBox = GenericBox<0x636F6C72, ColourSpecificationContents>; //this is from jpeg2000 part 1

using ContiguousCodestreamBox = GenericBox<0x6A703263, ContiguousCodestreamContents>;  //this is from jpeg2000 part 1  

using ImageHeaderBox = GenericBox<0x69686472, ImageHeaderContents>; //this is from jpeg2000 part 2 (extensions)  

using IntellectualPropertyBox = GenericBox<0x6A703269, UndefinedContents>; //this is from jpeg2000 part 1

using UUIDBox = GenericBox<0x75756964, UUIDContents>; //this is from jpeg2000 part 1





#endif /* end of include guard: JPLM_LIB_COMMON_BOXES_GENERIC_DEFINEDBOXES_H__ */