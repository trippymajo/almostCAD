#include <cmath>
#include "figures.h"

void Rectangle::drawFigure(QPainter &painter, QPoint &startPoint, QPoint &endPoint)
{
  QRect rect(startPoint, endPoint);
  painter.drawRect(rect);
}

void Ellipse::drawFigure(QPainter &painter, QPoint &startPoint, QPoint &endPoint)
{
  QRect rect(startPoint, endPoint);
  painter.drawEllipse(rect);
}

void Line::drawFigure(QPainter &painter, QPoint &startPoint, QPoint &endPoint)
{
  painter.drawLine(startPoint, endPoint);
}

void MakeFigure::BuildFigure(int figType)
{
  FigureFactory* pFF = new FigureFactory();
  pFigure = pFF->build(figType);
  delete pFF;
}


