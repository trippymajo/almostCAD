#ifndef WORKAREA_H
#define WORKAREA_H

#include <QWidget>
//#include <QColor>
//#include <QPoint>

#include "mainwindow.h"

class WorkArea : public QWidget
{
  Q_OBJECT
public:
  WorkArea(QWidget *parent = nullptr);
  ~WorkArea();

private:
  const QColor lineColor = Qt::black;
  const int lineWidth = 1;

  QPoint      startPoint;
  QPoint      endPoint;
  QImage      image;

  void        mousePressEvent(QMouseEvent *event) override;
  void        mouseReleaseEvent(QMouseEvent *event) override;
  void        paintEvent(QPaintEvent *event) override;
  void        resizeEvent(QResizeEvent *event) override;

  void        resizeImage(QImage *image, const QSize &newSize);
  void        draw();

};

#endif // WORKAREA_H
