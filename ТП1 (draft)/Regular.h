#ifndef REGULAR_H
#define REGULAR_H
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <cmath>
#include "Shape.h"

namespace bavykin
{
  class Regular : public Shape
  {
  public:
    Regular() = default;
    Regular(const point_t& firstPoint, const point_t& secondPoint, const point_t& thirdPoint);
    ~Regular() override = default;

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& centre) override;
    void move(double x, double y) override;
    void scale(double scale) override;

  private:
    double m_BigRadius;
    double m_SmallRadius;
    double m_CathetOppositeTheCenter;
    rectangle_t m_Rect;

    size_t getTheNumberOfCorners() const;
  };
}

#endif
