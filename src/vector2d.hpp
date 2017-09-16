#pragma once

#include <point2d.hpp>

class vector2d
{
public:
  using type = point2d;
  
  vector2d(const type& first, const type& second)
    : first_(first)
    , second_(second)
  {
  }

  vector2d()
    : vector2d({ 0, 0 }, { 0, 0 })
  {
  }

  vector2d(const std::pair<type, type>& other)
    : vector2d(other.first, other.second)
  {
  }

  void move_to(const type& point)
  {
    second_ += first_ - point;
    first_ = point;
  }

private:
  type first_;
  type second_;  
};
