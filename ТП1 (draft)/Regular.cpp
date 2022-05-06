#include <stdexcept>
#include <cmath>
#include "Regular.h"
#include <iostream>

namespace bavykin
{
  Regular::Regular(const point_t& firstPoint, const point_t& secondPoint, const point_t& thirdPoint)
  {
    m_Rect.m_Pos = firstPoint;

    double firstSideWidth = std::abs(firstPoint.m_X - secondPoint.m_X);
    double firstSideHeight = std::abs(firstPoint.m_Y - secondPoint.m_Y);
    double firstSide = std::sqrt(std::pow(firstSideWidth, 2) + std::pow(firstSideHeight, 2));

    double secondSideWidth = std::abs(firstPoint.m_X - thirdPoint.m_X);
    double secondSideHeight = std::abs(firstPoint.m_Y - thirdPoint.m_Y);
    double secondSide = std::sqrt(std::pow(secondSideWidth, 2) + std::pow(secondSideHeight, 2));

    double thirdSideWidth = std::abs(secondPoint.m_X - thirdPoint.m_X);
    double thirdSideHeight = std::abs(secondPoint.m_Y - thirdPoint.m_Y);
    double thirdSide = std::sqrt(std::pow(thirdSideWidth, 2) + std::pow(thirdSideHeight, 2));

    m_CathetOppositeTheCenter = thirdSide;

    if (std::sqrt(std::pow(thirdSide, 2) + std::pow(secondSide, 2)) == firstSide)
    {
      m_BigRadius = firstSide;
      m_SmallRadius = secondSide;
    }
    else if (std::sqrt(std::pow(thirdSide, 2) + std::pow(firstSide, 2)) == secondSide)
    {
      m_BigRadius = secondSide;
      m_SmallRadius = firstSide;
    }
    else
    {
      throw std::logic_error("Invalid arguments, it is not a right triangle.");
    }

    size_t n = getTheNumberOfCorners();
    double PI = std::acos(-1);
    double angle = (static_cast<double>(n) - 2) / static_cast<double>(n) * 180;
    if (angle - std::round(std::asin(m_SmallRadius / m_BigRadius) * 180 / PI * 2) > 0.0001)
    {
      throw std::logic_error("Not a triangle");
    }

    m_Rect.m_Pos = { firstPoint.m_X, firstPoint.m_Y };

    bool isParallelToY = thirdPoint.m_Y == firstPoint.m_Y;
    bool isParallelToX = thirdPoint.m_X == firstPoint.m_X;
    if (isParallelToY)
    {
      m_Rect.m_Height = firstSideHeight * 2;
      m_Rect.m_Width = secondSideWidth * 2;
    }
    else if (isParallelToX)
    {
      m_Rect.m_Width = firstSideWidth * 2;
      m_Rect.m_Height = secondSideHeight * 2;
    }
    else
    {
      m_Rect.m_Width = secondSideWidth * 2;
      m_Rect.m_Height = secondSideHeight * 2;
    }

    double maxSide = std::max(m_Rect.m_Width, m_Rect.m_Height);
    m_Rect.m_Width = m_Rect.m_Height = maxSide;

  }

  double Regular::getArea() const
  {
    double PI = std::acos(-1);
    double R = m_BigRadius;
    int n = getTheNumberOfCorners();

    return n * std::pow(R, 2) / 2 * std::sin(2 * PI / n);
  }

  size_t Regular::getTheNumberOfCorners() const
  {
    double PI = std::acos(-1);
    double side = m_CathetOppositeTheCenter * 2;
    double R = m_BigRadius;

    return std::round(PI / std::asin(side / (2 * R)));
  }

  rectangle_t Regular::getFrameRect() const
  {
    return m_Rect;
  }

  void Regular::move(const point_t& centre)
  {
    m_Rect.m_Pos = centre;
  }

  void Regular::move(double x, double y)
  {
    m_Rect.m_Pos.m_X += x;
    m_Rect.m_Pos.m_Y += y;
  }

  void Regular::scale(double scale)
  {
    if (scale < 0)
    {
      throw std::logic_error("Scale can't be negative.");
    }

    m_BigRadius *= scale;
    m_SmallRadius *= scale;
    m_CathetOppositeTheCenter *= scale;

    m_Rect.m_Width = m_Rect.m_Width * scale;
    m_Rect.m_Height = m_Rect.m_Height * scale;
  }
}
