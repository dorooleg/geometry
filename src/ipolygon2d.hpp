#pragma once

#include <point2d.hpp>
#include <vector>

class ipolygon2d
{
public:
  using type = point2d;

  ipolygon2d() = default;

  ipolygon2d(const std::vector<type>& points)
    : points_(points)
  { }

  virtual ~ipolygon2d() = default;

  virtual bool contain(const type& point) const = 0;

  bool empty() const
  {
    return points_.empty();
  }
  
  size_t size() const
  {
    return points_.size();
  }

private:
  std::vector<type> points_;
};
