#include <QtWidgets>
#include <memory>

#include <QtPrintSupport/qtprintsupportglobal.h>

#include "workarea.h"
#include "figures.h"

WorkArea::WorkArea(QWidget *parent) : QWidget(parent)
{
  setAttribute(Qt::WA_StaticContents);
}

WorkArea::~WorkArea()
{

}
void WorkArea::resizeEvent(QResizeEvent *event)
{
    if (width() > image.width() || height() > image.height())
    {
        int newWidth = qMax(width() + 128, image.width());
        int newHeight = qMax(height() + 128, image.height());
        resizeImage(&image, QSize(newWidth, newHeight));
        update();
    }
    QWidget::resizeEvent(event);
}

void WorkArea::resizeImage(QImage *image, const QSize &newSize)
{
    if (image->size() == newSize)
        return;

    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(qRgb(255, 255, 255));
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), *image);
    *image = newImage;
}

void WorkArea::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
      startPoint = event->pos();
      //scribbling = true;
    }
}

void WorkArea::mouseReleaseEvent(QMouseEvent *event)
{
  if (event->button() == Qt::LeftButton)
    {
      endPoint = event->pos();
    }
  draw();
}

void WorkArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, image, dirtyRect);
}

void WorkArea::draw()
{
  QPainter painter(&image);
  painter.setPen(QPen(lineColor, lineWidth, Qt::SolidLine, Qt::RoundCap));

  auto ptrMakeFigure {std::make_unique<MakeFigure>()};
  ptrMakeFigure->BuildFigure(MainWindow::m_curFigure);
  ptrMakeFigure->getFigure()->drawFigure(painter, startPoint, endPoint);

  update();
}
