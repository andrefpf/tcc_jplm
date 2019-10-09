#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include "Lib/Common/JPLMCodecFactory.h"
#include "Lib/Common/JPLMConfigurationFactory.h"


int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[]) {
  auto configuration =
      JPLMConfigurationFactory::get_encoder_configuration(argc, argv);
  std::ofstream of_stream(
      configuration->get_output_filename(), std::ofstream::binary | std::ofstream::out | std::ofstream::trunc );
  if (!of_stream.is_open()) {
    std::cerr << "Error opening output file" << std::endl;
    exit(EXIT_FAILURE);
  }


  auto encoder = JPLMCodecFactory::get_encoder(
      std::move(std::unique_ptr<JPLMEncoderConfiguration>(
          static_cast<JPLMEncoderConfiguration*>(configuration.release()))));
  // encoder->run();
  auto& jpl_file = encoder->get_ref_to_jpl_file();
  std::cout << "writing to file" << std::endl;
  of_stream << jpl_file;
  of_stream.close();

  exit(EXIT_SUCCESS);
}