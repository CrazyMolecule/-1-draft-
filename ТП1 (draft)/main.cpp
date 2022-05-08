#include "Rectangle.h"
#include "Regular.h"
#include "ShapesUtils.h"
#include "Square.h"
#include <iomanip>
#include <iostream>

using namespace bavykin;

int main()
{
  std::string command;

  shapeArray_t shapesToScale;
  size_t shapesCount = 0;

  std::shared_ptr< double[] > args;
  shapePtr_t tmp;

  while (!std::cin.eof() && command != "SCALE")
  {
    try
    {
      std::cin >> command;

      if (command == "RECTANGLE")
      {
        args = getArgsFromConsole(4);

        point_t leftCorner = { args[0], args[1] };
        point_t rightCorner = { args[2], args[3] };

        tmp = shapePtr_t(new Rectangle(leftCorner, rightCorner));
        addShape(shapesToScale, shapesCount++, tmp);
      }
      else if (command == "REGULAR")
      {
        args = getArgsFromConsole(6);

        point_t firstPoint = { args[0], args[1] };
        point_t secondPoint = { args[2], args[3] };
        point_t thirdPoint = { args[4], args[5] };

        addShape(shapesToScale, shapesCount++, shapePtr_t(new Regular(firstPoint, secondPoint, thirdPoint)));
      }
      else if (command == "SQUARE")
      {
        args = getArgsFromConsole(3);

        point_t leftCorner = { args[0], args[1] };
        double sideLength = args[2];

        addShape(shapesToScale, shapesCount++, shapePtr_t(new Square(leftCorner, sideLength)));
      }
      else if (command == "SCALE")
      {
        if (shapesCount == 0)
        {
          std::cerr << "Nothing To Scale." << std::endl;
          return 2;
        }

        args = getArgsFromConsole(3);

        point_t dot = { args[0], args[1] };
        double scaleCoefficient = args[2];

        if (scaleCoefficient < 0)
        {
          std::cerr << "Scale can't be negative." << std::endl;
          return 1;
        }

        printShapesAreaAndFrame(shapesToScale, shapesCount);

        for (size_t i = 0; i < shapesCount; i++)
        {
          (*shapesToScale[i]).scale(scaleCoefficient);

          rectangle_t frameRect = (*shapesToScale[i]).getFrameRect();

          double newCentreX = dot.m_X - (dot.m_X - frameRect.m_Pos.m_X) * scaleCoefficient;
          double newCentreY = dot.m_Y - (dot.m_Y - frameRect.m_Pos.m_Y) * scaleCoefficient;
          (*shapesToScale[i]).move({ newCentreX, newCentreY });
        }

        printShapesAreaAndFrame(shapesToScale, shapesCount);
      }
    }
    catch (const std::exception& e)
    {
      std::cerr << e.what() << std::endl;
    }
  }

  if (command != "SCALE")
  {
    std::cerr << "Wasn't scaled." << std::endl;
    return 1;
  }

  return 0;
}
