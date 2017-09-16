#pragma once

#include <ipolygon2d.hpp>

class convex_polygon2d
  : public ipolygon2d
{
  virtual bool contain(const type& point) const override
  {
    return true;
  }
};
