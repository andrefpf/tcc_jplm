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

/** \file     JPLMConfiguration.h
 *  \brief    General configuration data object
 *  \details  JPLMConfiguration is the most basic abstraction of configuration
 *            data object for being used by the JPLM Encoder and Decoders. It
 *            contains only the input and output paths extracted from the
 *            command line interface. All configuration objects are derived
 *            from JPLMConfiguration.
 *  \author   Pedro Garcia Freitas <pedro.gf@samsung.com>
 *  \date     2019-09-26
 */
#ifndef JPLM_JPLMConfiguration_H
#define JPLM_JPLMConfiguration_H

#include <algorithm>
#include <any>
#include <iostream>
#include <string>
#include "CLI/CLI.hpp"
#include "CppConsoleTable/CppConsoleTable.hpp"
#include "Lib/Common/CLIArgument.h"
#include "Lib/Common/JPLMConfigurationExceptions.h"
#include "Lib/Part2/Common/Boxes/CompressionTypeLightField.h"
#include "Lib/Utils/Image/ColorSpaces.h"
#include "nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;
using Type = CompressionTypeLightField;

enum class JpegPlenoPart {
  LightField = 2,
};


class JPLMConfiguration {
 public:
  JPLMConfiguration();
  JPLMConfiguration(int argc, char **argv);

  const std::string &get_input_filename() const;
  const std::string &get_output_filename() const;
  const bool &is_help_mode() const;

 protected:
  std::vector<CLIArgument> arguments;
  std::string input;
  std::string output;
  std::size_t hierarchy_level =
      0;  //<! the hierarchy level used for printing help
  void run_help() const;
  void parse_cli(int argc, char **argv);
  bool validate_param(std::string param);
  bool validate_value(unsigned int size, unsigned int pos, char **argv);
  JPLMConfiguration(int argc, char **argv, std::size_t level);
  std::string message = std::string("");

 private:
  bool help_mode_flag = false;
  std::size_t current_hierarchy_level = 0;
  std::string executable_name;
};


#endif  //JPLM_JPLMConfiguration_H
