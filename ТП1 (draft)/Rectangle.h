#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <stdexcept>
#include "Shape.h"

namespace bavykin
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(const point_t& leftCorner, const point_t& rightCorner);
    ~Rectangle() = default;

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& centre) override;
    void move(double x, double y) override;
    void scale(double scale) override;

  private:
    rectangle_t m_Rect;
  };
}

#endif
