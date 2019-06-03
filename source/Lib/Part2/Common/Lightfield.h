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

/** \file     Lightfield.h
 *  \brief    
 *  \details  
 *  \author   Ismael Seidel <i.seidel@samsung.com>
 *  \date     2019-05-31
 */

#ifndef JPLM_LIB_PART2_COMMON_LIGHTFIELD_H__
#define JPLM_LIB_PART2_COMMON_LIGHTFIELD_H__

#include "Generic2DStructure.h"
#include "View.h"
#include "LightfieldDimension.h"


template<typename T>
class Lightfield : public Generic2DStructure<View<T>> {
 public:
  Lightfield(std::size_t width, std::size_t height)
      : Generic2DStructure<View<T>>(width, height){
        this->alloc_resources();
      };


  Lightfield(const Lightfield& other) : Generic2DStructure<View<T>>(other) {
    //FIXME
  }


  ~Lightfield() = default;


  View<T>& get_view_at(
      const std::pair<std::size_t, std::size_t>& coordinate) const {
    return this->get_element_reference_at(coordinate);
  }


  View<T>& get_view_copy_at(
      const std::pair<std::size_t, std::size_t>& coordinate) const {
    return this->get_element_reference_at(coordinate);
  }


  void set_view_at(const View<T>& view,
      const std::pair<std::size_t, std::size_t>& coordinate) {
    this->set_element_at(view, coordinate);
  }


  void set_view_at(
      View<T>&& view, const std::pair<std::size_t, std::size_t>& coordinate) {
    this->set_element_at(std::move(view), coordinate);
  }


  auto get_views_width() const {
    if (!this->elements) {
      //Throws
    }
    return this->elements[0].get_width();
  }


  auto get_views_height() const {
    if (!this->elements) {
      //Throws
    }
    return this->elements[0].get_height();
  }


  auto get_views_bpp() const {
    if (!this->elements) {
      //Throws
    }
    return this->elements[0].get_bpp();
  }


  


  auto get_dimensions() const {
    return LightfieldDimension(this->get_width(), this->get_height(), this->get_views_width(), this->get_views_height());
  }


  inline View<T>* operator[](const int i) {
    return this->elements_for_2d_access[i];
  }


  inline const View<T>* operator[](const int i) const {
    return this->elements_for_2d_access[i];
  }


  virtual Lightfield* generate_ptr_to_clone() const override {
    return new Lightfield(*this);
  };
};

#endif /* end of include guard: JPLM_LIB_PART2_COMMON_LIGHTFIELD_H__ */