#ifndef FIGURES_H
#define FIGURES_H

#include <QtWidgets>

#include "workarea.h"

//Abstract class
class Figure : public WorkArea
{
public:
  virtual void drawFigure(QPainter &painter, QPoint &startPoint, QPoint &endPoint) = 0;
  virtual ~Figure() {}
};

class Rectangle : public Figure
{
public:
  void drawFigure(QPainter &painter, QPoint &startPoint, QPoint &endPoint) override;
};

class Ellipse : public Figure
{
public:
  void drawFigure(QPainter &painter, QPoint &startPoint, QPoint &endPoint) override;
};

class Triangle : public Figure
{
public:
  void drawFigure(QPainter &painter, QPoint &startPoint, QPoint &endPoint) override;
};

//Factory
class FigureFactory
{
public:
  Figure* build(int figType)
  {
    switch(figType)
    {
      case(1):
      {
        return new class Rectangle();
        break;
      }
      case(2):
      {
        return new class Ellipse();
        break;
      }
      case(3):
      {
        return new class Triangle();
        break;
      }
    }
   return nullptr;
  }
};

class MakeFigure
{
public:
  MakeFigure() {pFigure = nullptr;}

  void BuildFigure(int figType);

  ~MakeFigure()
  {
    if (pFigure)
    {
      delete pFigure;
       pFigure = NULL;
    }
  }

  Figure* getFigure() {return pFigure;}

private:
  Figure* pFigure;
};

#endif // FIGURES_H
