#pragma once

#include <point2d.hpp>
#include <cmath>

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

  vector2d& operator+=(const vector2d& other)
  {
    auto vector_coordinater = other.get_vector_coordinate();
    second_ = type(second_.get_x() + vector_coordinater.get_x(),
                   second_.get_y() + vector_coordinater.get_y());
    return *this;
  }

  vector2d operator+(const vector2d& other) const
  {
    vector2d tmp = *this;
    tmp += other;
    return tmp;
  }

  vector2d& operator-=(vector2d other)
  {
    *this += other * -1.0;
    return *this;
  }

  vector2d operator-(const vector2d& other) const
  {
    vector2d tmp = *this;
    tmp += other * -1.0;
    return tmp;
  }

  vector2d& operator*=(typename type::type other)
  {
    first_ = type(first_.get_x() * other, first_.get_y() * other);
    second_ = type(second_.get_x() * other, second_.get_y() * other);
    return *this;
  }

  vector2d operator*(typename type::type other) const
  {
    vector2d tmp = *this;
    tmp *= other;
    return tmp;
  }

  bool operator==(const vector2d& other) const
  {
    return get_vector_coordinate() == other.get_vector_coordinate();
  }

  bool operator!=(const vector2d& other) const
  {
    return !(*this == other);
  }

  void move_to(const type& point)
  {
    second_ += first_ - point;
    first_ = point;
  }

  type get_vector_coordinate() const
  {
    return type(second_.get_x() - first_.get_x(),
                second_.get_y() - first_.get_y());
  }

  typename type::type length() const
  {
    return sqrt(pow(second_.get_x() - first_.get_x(), 2) +
                pow(second_.get_y() - first_.get_y(), 2));

  }

  typename type::type dot(const vector2d& other) const
  {
    const auto c1 = get_vector_coordinate();
    const auto c2 = other.get_vector_coordinate();
    return c1.get_x() * c2.get_x() + c1.get_y() * c2.get_y();
  }

  typename type::type pseudo_dot(const vector2d& other) const
  {
    const auto c1 = get_vector_coordinate();
    const auto c2 = other.get_vector_coordinate();
    return c1.get_x() * c2.get_y() - c1.get_y() * c2.get_x();
  }

  typename type::type angle(const vector2d& other) const
  {
    const auto dot_value = dot(other);
    const auto pseudo_dot_value = pseudo_dot(other);

    if (dot_value == 0 && pseudo_dot_value > 0) {
      return M_PI / 2.0;
    }

    if (dot_value == 0 && pseudo_dot_value < 0) {
      return M_PI / -2.0;
    }

    if (dot_value > 0) {
      return std::atan(pseudo_dot_value / dot_value);
    }

    if (dot_value < 0 && pseudo_dot_value >= 0) {
      return std::atan(pseudo_dot_value / dot_value) + M_PI;
    }

    if (dot_value < 0 && pseudo_dot_value < 0) {
      return std::atan(pseudo_dot_value / dot_value) - M_PI;
    }

    return 0.0;
  }

  typename type::type square(const vector2d& other)
  {
    return std::abs(pseudo_dot(other));
  }

  bool is_positive_orientation(const vector2d& other) const
  {
    return pseudo_dot(other) > 0.0;
  }

  bool is_negative_orientation(const  vector2d& other) const
  {
    return pseudo_dot(other) <= 0.0;
  }


private:
  type first_;
  type second_;
};
