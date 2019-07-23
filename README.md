
# JPEG Pleno Model RC

The aim is to be recognized by ISO/IEC as JPEG Pleno Reference Software (JPEG Pleno Part 4).

## Scope of the project


### JPEG Pleno
JPEG Pleno aims to provide a standard framework for representing new imaging modalities, such as texture-plus-depth, [light field](https://jpeg.org/jpegpleno/lightfield.html), [point cloud](https://jpeg.org/jpegpleno/pointcloud.html), and [holographic imaging](https://jpeg.org/jpegpleno/holography.html). Such imaging should be understood as light representations inspired by the plenoptic function, regardless of which model captured or created all or part of the content. [Read more]([https://jpeg.org/jpegpleno/index.html](https://jpeg.org/jpegpleno/index.html))

## Licence

[![badge-license]][link-license]


## Current Status



## Known issues and limitations
Initially, only Lightfield images are supported in JPLM (JPEG Pleno Model).


## Prerequisites

#### Compiler
Tested with gcc 8
Must support CXX 17

#### Cmake
Minimum version: 3.10


## Quick start 
After building this project, you can use the provided software to encode and decode plenoptic images. 

### Lightfield (Part 2)

#### Encoding
Example:
  ```bash
  ~/jplm/build/$ ../bin/TAppEncoder --cfg ../cfg/config.json --input ~/RAW/Greek/ --output ~/output.lf
  ```  
#### Decoding
Example:
  ```bash
  ~/jplm/build/$ ../bin/TAppDecoder --input ~/output.lf --output ~/decoded/greek/
  ```  


## Architecture overview
TODO

## Build instructions
  ```bash
  ~$ cd jplm
  ~/jplm/$ mkdir build; cd build
  ~/jplm/build/$ cmake ..
  ~/jplm/build/$ make -j
  ```
## Testing instructions

  ```bash
  ~/jplm/build/$ ctest
  ```  
  
###  Other usefull commands
#### Colorfull output
```bash
  ~/jplm/build/$ export GTEST_COLOR=1
  ```

#### To show all tests
```bash
  ~/jplm/build/$ ctest --verbose
  ```

#### To run again only failed tests

```bash
  ~/jplm/build/$ ctest --rerun-failed
  ```
or
```bash
  ~/jplm/build/$ ctest --verbose --rerun-failed
  ```

## Deployment instructions
TODO (check if applicable)
##  Contribution instructions
TODO
## Directory layout
For an illustration, see docs/diagrams/PacketDiagram.pdf
  - JPLM
    - cfg
    - doc
      - diagrams
    - bin
    - build
    - source
      - App
            - Common
            - Encoder
            - Decoder
       - Lib
	       - Part1
		       - Common
		       - Encoder
		       - Decoder
	       - Part2
		       - Common
		       - Encoder
		       - Decoder
	       - PartX
		       - Common
		       - Encoder
		       - Decoder



[badge-license]: https://img.shields.io/badge/license-BSD--3--Clause-blue.svg "BSD 3-clause license"
[link-license]: https://gitlab.com/smtlightfieldsteam/jplm/blob/master/LICENSE "BSD 3-clause license"