#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

struct point_t
{
  double m_X;
  double m_Y;
};

struct rectangle_t
{
  double m_Width;
  double m_Height;
  point_t m_Pos;
};

#endif
