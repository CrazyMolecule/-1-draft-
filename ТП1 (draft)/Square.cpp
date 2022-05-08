#include "Square.h"

namespace bavykin
{
  Square::Square(point_t leftCorner, double sideLength)
  {
    if (sideLength <= 0)
    {
      throw std::logic_error("Length can't be negative.");
    }
    double length = sideLength;

    m_Rect.m_Width = length;
    m_Rect.m_Height = length;
    m_Rect.m_Pos.m_X = leftCorner.m_X + length / 2;
    m_Rect.m_Pos.m_Y = leftCorner.m_Y + length / 2;
  }

  double Square::getArea() const
  {
    return m_Rect.m_Width * m_Rect.m_Height;
  }

  rectangle_t Square::getFrameRect() const
  {
    return m_Rect;
  }

  void Square::move(const point_t& centre)
  {
    m_Rect.m_Pos = centre;
  }

  void Square::move(double x, double y)
  {
    m_Rect.m_Pos.m_X += x;
    m_Rect.m_Pos.m_Y += y;
  }

  void Square::scale(double scale)
  {
    if (scale < 0)
    {
      throw std::logic_error("Scale can't be negative.");
    }

    m_Rect.m_Width *= scale;
    m_Rect.m_Height *= scale;
  }
}
