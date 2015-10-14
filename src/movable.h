#ifndef MOVABLE_H
#define MOVABLE_H

#include <QObject>

class Movable : public QObject
{
		Q_OBJECT
	public:
		explicit Movable(QObject *parent = 0);

	signals:

	public slots:

};

#endif // MOVABLE_H
