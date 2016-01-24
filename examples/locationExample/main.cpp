#include <QCoreApplication>
#include <QDebug>
#include <QTextStream>
#include "coord.h"
#include "euclideandistancefunction.h"
#include "diagonaldistancefunction.h"
#include "manhattandistancefunction.h"
#include "squaredeuclideandistancefunction.h"

int main()
{
    //Used to get input from stdin
    QTextStream qIn(stdin);

    int choiche;
    //used to store values gets from stdin
    int temp, temp2;
    //coord of the example
    Coord c1(0,0);

    qDebug() << "In this example you see how to use the class coord to handle a point with GRIDB";
    qDebug() << "c1 is the coordinate";

    //Repeat the menu until the choiche is 0
    do
    {
        //menu
        qDebug() << "What do you want to do?";
        qDebug() << "0) EXIT";
        qDebug() << "1) PRINT c1 info";
        qDebug() << "2) SET x position of c1";
        qDebug() << "3) SET y position of c1";
        qDebug() << "4) SET the position of c1";
        qDebug() << "5) MOVE c1 by offset";
        qDebug() << "6) MOVE c1 by direction";
        qDebug() << "7) DISTANCE between c1 and 0";
        qIn >> choiche;


        switch (choiche)
        {
            case 0: //0) EXIT
                qDebug() << "Exiting";
                break;
            case 1: //1) PRINT info
                qDebug() << "[c1.x(), c1.y()] --> [" << c1.x() << ", " << c1.y() << "]";
                break;
            case 2: //2) SET x
                qDebug() << "Insert new x: ";
                qIn >> temp;
                qDebug() << "c1.setX(" << temp << ")";
                c1.setX(temp);
                break;
            case 3: //3) SET Y
                qDebug() << "Insert new y: ";
                qIn >> temp;
                qDebug() << "c1.setY(" << temp << ")";
                c1.setY(temp);
                break;
            case 4: //4) SET
                qDebug() << "Insert new x and y: ";
                qIn >> temp >> temp2;
                qDebug() << "c1.setMovable(" << temp << ", " << temp2  << ")";
                c1.setMovable(temp, temp2);
                break;
            case 5: //5) MOVE by offset
                qDebug() << "Insert offset x and y";
                qIn >> temp >> temp2;
                qDebug() << "c1.move(" << temp << ", " << temp2  << ")";
                c1.move(temp,temp2);
                break;
            case 6: //6) MOVE by direction
                qDebug() << "Insert direction coefficent x and y";
                qIn >> temp >> temp2;
                qDebug() << "Insert offset";
                int temp3;
                qIn >> temp3;
                qDebug() << "c1.move(direction(" << temp << ", " << temp2  << "), " << temp3 << ")";
                c1.move(Direction(temp, temp2), temp3);
                break;
            case 7: //7) DISTANCE [0,0]...c1
                qDebug() << "DiagonalDistanceFunction()(0, 0, c1.x(), c1.y()) --> "
                         << DiagonalDistanceFunction()(0, 0, c1.x(), c1.y());
                qDebug() << "EuclideanDistanceFunction()(0, 0, c1.x(), c1.y()) --> "
                         << EuclideanDistanceFunction()(0, 0, c1.x(), c1.y());
                qDebug() << "ManhattanDistanceFunction()(0, 0, c1.x(), c1.y()) --> "
                         << ManhattanDistanceFunction()(0, 0, c1.x(), c1.y());
                qDebug() << "SquaredEuclideanDistanceFunction()(0, 0, c1.x(), c1.y()) --> "
                         << SquaredEuclideanDistanceFunction()(0, 0, c1.x(), c1.y());
                break;
        }

    }
    while (choiche != 0); /* choiche 0 == EXIT*/

    qDebug() << "Goodbye";
}
