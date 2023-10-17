#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "workarea.h"


  //enum drawFigure {Rect, Ellipse, Line};
  class WorkArea;

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private:
  WorkArea  *workArea;

  QMenu     *drawMenu;
  QAction   *drawRect;
  QAction   *drawCircle;
  QAction   *drawTriangle;

  void      createActions();
  void      createMenu();

private slots:
  void      changeToRect(){m_curFigure = 1;};
  void      changeToCircle(){m_curFigure = 2;};
  void      changeToTriangle(){m_curFigure = 3;};

public:
  static int m_curFigure;
};
#endif // MAINWINDOW_H
