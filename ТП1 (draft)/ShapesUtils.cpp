#include "ShapesUtils.h"
#include <iostream>
#include <memory>
#include <iomanip>

namespace bavykin
{
  template< class T >
  void add(std::shared_ptr< T[] >& array, size_t count, T newElement)
  {
    std::shared_ptr< T[] > newArray = std::shared_ptr< T[] >(new T[count + 1]);

    for (size_t i = 0; i < count; i++)
    {
      newArray[i] = array[i];
    }
    newArray[count] = newElement;

    array = newArray;
  }

  void addShape(shapeArray_t& array, size_t count, shapePtr_t newElement)
  {
    shapeArray_t newArray = shapeArray_t(new shapePtr_t[count + 1]);

    for (size_t i = 0; i < count; i++)
    {
      newArray[i] = array[i];
    }
    newArray[count] = newElement;

    array = newArray;
  }

  std::shared_ptr< double[] > getArgsFromConsole(size_t argsCount)
  {
    double arg;
    std::shared_ptr< double[] > args;

    for (size_t currentCount = 0; currentCount < argsCount; currentCount++)
    {
      std::cin >> arg;
      add(args, currentCount, arg);
    }

    return args;
  }

  double getShapesSumArea(const shapeArray_t& shapes, size_t count)
  {
    double sumArea = 0;

    for (size_t i = 0; i < count; i++)
    {
      sumArea += (*shapes[i]).getArea();
    }

    return sumArea;
  }

  void printShapesAreaAndFrame(const shapeArray_t& shapes, size_t count)
  {
    std::cout << std::setprecision(1) << std::fixed << getShapesSumArea(shapes, count);

    for (size_t i = 0; i < count; i++)
    {
      rectangle_t shapeFrame = (*shapes[i]).getFrameRect();

      point_t leftCorner = { shapeFrame.m_Pos.m_X - shapeFrame.m_Width / 2, shapeFrame.m_Pos.m_Y - shapeFrame.m_Height / 2 };
      point_t rightCorner = { shapeFrame.m_Pos.m_X + shapeFrame.m_Width / 2, shapeFrame.m_Pos.m_Y + shapeFrame.m_Height / 2 };

      std::cout << std::setprecision(1) << std::fixed << " " << leftCorner.m_X << " " << leftCorner.m_Y;
      std::cout << std::setprecision(1) << std::fixed << " " << rightCorner.m_X << " " << rightCorner.m_Y;
    }
    std::cout << std::endl;
  }
}
