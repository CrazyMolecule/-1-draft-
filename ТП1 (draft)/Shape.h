#ifndef SHAPE_H
#define SHAPE_H
#include "base-types.h"

namespace bavykin
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t& centre) = 0;
    virtual void move(double x, double y) = 0;
    virtual void scale(double scale) = 0;
  };
}

#endif
