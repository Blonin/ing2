/**
 * @ name: fileName
 * @ access: public
 * @ Path: filePath
 * @ Author: Richter Gustave
 * @ Create Time: 19-03-2024 15:05:31
 * @ email: richtergustave@gmail.com
 * @ description:
 * @ argument: NULL
 * @ input: NULL
 * @ output: NULL
 * @ return: NULL
 * @ copyright: Richter Gustave
 * @ Modified by: Name
 * @ Modified time: 19-03-2024
 */

#ifndef __ROBOT_HPP__
#define __ROBOT_HPP__
#include <iostream>
#include <fstream>
#include <stdlib.h>


class Robot
{
protected:
    int type;
    std::string word;
    int prix;

public:
    Robot();
    ~Robot();

    friend ostream& operator<< (ostream& out,const Robot& r);
    friend istream& operator>> (istream& in,Robot& r);
};

Robot::Robot(/* args */)
{
}

Robot::~Robot()
{
}




#endif