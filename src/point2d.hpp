#pragma once

#include <ostream>

class point2d
{
public:
  using type = long double;

  point2d(type x, type y)
    : x_(x)
    , y_(y)
  { }

  point2d(const std::pair<type, type>& other)
    : point2d(other.first, other.second)
  { }

  point2d()
    : point2d(0, 0)
  { }

  type get_x() const
  {
    return x_;
  }

  type get_y() const
  {
    return y_;
  }

  bool operator==(const point2d& other) const
  {
    return get_x() == other.get_x() && get_y() == other.get_y();
  }

  bool operator!=(const point2d& other) const
  {
    return !(*this == other);
  }

  point2d& operator+=(const point2d& other)
  {
    x_ += other.x_;
    y_ += other.y_;
    return *this;
  }

  point2d& operator-=(const point2d& other)
  {
    x_ -= other.x_;
    y_ -= other.y_;
    return *this;
  }

  point2d operator+(const point2d& other) const
  {
    point2d tmp(*this);
    tmp += other;
    return tmp;
  }

  point2d operator-(const point2d& other) const
  {
    point2d tmp(*this);
    tmp -= other;
    return tmp;
  }

private:
  type x_;
  type y_;
};

inline std::ostream& operator<<(std::ostream& strm, const point2d& point)
{
  strm << "x = " << point.get_x() << " y = " << point.get_y() << std::endl;
  return strm;
}
