#ifndef SQUARE_H
#define SQUARE_H
#include "Shape.h"

namespace bavykin
{
  class Square : public Shape
  {
  public:
    Square(point_t leftCorner, double sideLength);

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
