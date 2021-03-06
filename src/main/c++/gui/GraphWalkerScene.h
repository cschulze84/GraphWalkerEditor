#ifndef DIAGRAMSCENE_H
#define DIAGRAMSCENE_H

#include <QtGui>
#include "VertexItem.h"

class GraphWalkerScene : public QGraphicsScene {
    Q_OBJECT

  public:
    enum Mode { InsertItem, InsertLine, InsertText, MoveItem };

    GraphWalkerScene ( QObject* parent = 0 );
    QFont font() const {
      return myFont;
    }
    QColor textColor() const {
      return myTextColor;
    }
    QColor itemColor() const {
      return myItemColor;
    }
    QColor lineColor() const {
      return myLineColor;
    }
    void setLineColor ( const QColor& color );
    void setTextColor ( const QColor& color );
    void setItemColor ( const QColor& color );
    void setFont ( const QFont& font );

  public slots:
    void setMode ( Mode mode );

  signals:
    void itemInserted ( VertexItem* item );
    void itemSelected ( QGraphicsItem* item );

  protected:
    void mousePressEvent ( QGraphicsSceneMouseEvent* mouseEvent );
    void mouseMoveEvent ( QGraphicsSceneMouseEvent* mouseEvent );
    void mouseReleaseEvent ( QGraphicsSceneMouseEvent* mouseEvent );

  private:
    bool isItemChange ( int type );
    void loadGraph();
    void loadGraph ( const QFileInfo& );

    Mode myMode;
    bool leftButtonDown;
    QPointF startPoint;
    QGraphicsLineItem* line;
    QFont myFont;
    QColor myTextColor;
    QColor myItemColor;
    QColor myLineColor;
};

#endif
