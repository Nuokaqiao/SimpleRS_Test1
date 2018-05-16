#ifndef SCROLLPICVIEW_H
#define SCROLLPICVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QImage>
#include <QPen>
#include <QScrollBar>

class ScrollPicView : public QGraphicsView
{
    Q_OBJECT
public:
    ScrollPicView(QWidget* parent = Q_NULLPTR);
    ~ScrollPicView();

    QGraphicsView* scene;
    int setting[2] = {100,100};
    double ratio[2] = {1,1};
    bool grid = false;
};

#endif // SCROLLPICVIEW_H
