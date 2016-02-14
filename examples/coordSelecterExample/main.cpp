#include <QCoreApplication>
#include <QDebug>
#include <QTextStream>
#include "coordselecter.h"
#include "gridcoordselecter.h"
#include "listcoordselecter.h"

int main()
{
    //Used to get input from stdin
    QTextStream qIn(stdin);

    int choiche;
    //used to store values gets from stdin
    int temp, temp2;
    //Current coord selecter
    CoordSelecter* selecter = new GridCoordSelecter(-10,-10,20,20);


    qDebug() << "In this example you see how to use the selecters and store a list of coords";

    //Repeat the menu until the choiche is 0
    do
    {
        //menu
        qDebug() << "What do you want to do?";
        qDebug() << "0) EXIT";
        qDebug() << "1) PRINT all coords selected";
        qDebug() << "2) SELECT a coord";
        qDebug() << "3) DESELECT a coord";
        qDebug() << "4) CHECK if a coord is selected";
        qDebug() << "5) CHANGE selecter";
        qIn >> choiche;

        switch (choiche)
        {
            case 0: //0) EXIT
                qDebug() << "Exiting";
                break;
            case 1: //1) PRINT all coords selected
            {
                const QLinkedList<Coord> list = selecter->getSelection();

                qDebug() << "getSelection()";

                foreach (Coord item, list)
                    qDebug() << "* [" << item.x() << "; " << item.y() << "]";

                break;
            }
            case 2: //2) SELECT a coord
                qDebug() << "Insert x and y: ";
                qIn >> temp;
                qIn >> temp2;

                qDebug() << "select(" << temp << ", " << temp2  << ")";
                selecter->select(temp,temp2);
                break;
            case 3: //3) DESELECT a coord
                qDebug() << "Insert x and y: ";
                qIn >> temp;
                qIn >> temp2;

                qDebug() << "deSelect(" << temp << ", " << temp2  << ")";
                selecter->deSelect(temp,temp2);
                break;
            case 4: //4) CHECK if the coord is selected
                qDebug() << "Insert x and y: ";
                qIn >> temp;
                qIn >> temp2;

                qDebug() << "isSelected(" << temp << ", " << temp2  << ") --> "
                         << selecter->isSelected(temp,temp2);
                break;
            case 5: //5) CHANGE selecter
                qDebug() << "Selecter type? 1-GridCoordSelecter(-10,-10,20,20)";
                qDebug() << "               2-ListCoordSelecter";
                qIn >> temp;
                delete selecter;
                if (temp == 1)
                    selecter = new GridCoordSelecter(-10,-10,20,20);
                else if (temp == 2)
                    selecter = new ListCoordSelecter();
            }

    }
    while (choiche != 0); /* choiche 0 == EXIT*/

    qDebug() << "Goodbye";
}
