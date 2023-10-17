#include <cmath>
#include "figures.h"
#define PI 3.14159265

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

void Triangle::drawFigure(QPainter &painter, QPoint &startPoint, QPoint &endPoint)
{
  QPoint p1, p2;

  int deltX = endPoint.rx()-startPoint.rx();
  int deltY =endPoint.ry()-startPoint.ry();

  //Moving around startPoint by 120 and 240 degrees
  p1.setX(startPoint.rx()+deltX*cos(2*PI/3)-deltY*sin(2*PI/3));
  p1.setY(startPoint.ry()+deltX*sin(2*PI/3)+deltY*cos(2*PI/3));
  p2.setX(startPoint.rx()+deltX*cos(4*PI/3)-deltY*sin(4*PI/3));
  p2.setY(startPoint.ry()+deltX*sin(4*PI/3)+deltY*cos(4*PI/3));

  painter.drawLine(endPoint, p1);
  painter.drawLine(p1, p2);
  painter.drawLine(p2, endPoint);
}

void MakeFigure::BuildFigure(int figType)
{
  FigureFactory* pFF = new FigureFactory();
  pFigure = pFF->build(figType);
  delete pFF;
}


