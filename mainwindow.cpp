#include <QtWidgets>

#include "mainwindow.h"

int MainWindow::m_curFigure = 1;


MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent), workArea(new WorkArea(this))
{
  //workArea = new WorkArea();
  setCentralWidget(workArea);

  createMenu();
  menuBar()->addMenu(drawMenu);

  setWindowTitle(tr("almostCAD"));
  setMinimumSize(500, 500);

}

void MainWindow::createActions()
{
  drawRect = new QAction(tr("Rectangle"));
  drawCircle = new QAction(tr("Circle"));
  drawTriangle = new QAction(tr("Triangle"));

  connect(drawRect,&QAction::triggered, this, &MainWindow::changeToRect);
  connect(drawCircle,&QAction::triggered, this, &MainWindow::changeToCircle);
  connect(drawTriangle,&QAction::triggered, this, &MainWindow::changeToTriangle);
}

void MainWindow::createMenu()
{
  drawMenu = new QMenu(tr("&Draw"));
  createActions();
  drawMenu->addAction(drawRect);
  drawMenu->addAction(drawCircle);
  drawMenu->addAction(drawTriangle);
}

MainWindow::~MainWindow()
{

}

