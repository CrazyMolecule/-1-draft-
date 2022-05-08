#ifndef SHAPES_UTILS_H
#define SHAPES_UTILS_H
#include <memory>
#include <iostream>
#include <memory>
#include <iomanip>
#include "base-types.h"
#include "Shape.h"

namespace bavykin
{
  using shapePtr_t = std::shared_ptr< Shape >;
  using shapeArray_t = std::shared_ptr< shapePtr_t[] >;

  template< class T >
  void add(std::shared_ptr< T[] >& array, size_t count, T newElement);

  void addShape(shapeArray_t& array, size_t count, shapePtr_t newElement);

  std::shared_ptr< double[] > getArgsFromConsole(size_t argsCount);

  double getShapesSumArea(const shapeArray_t& shapes, size_t count);

  void printShapesAreaAndFrame(const shapeArray_t& shapes, size_t count);
}
#endif
