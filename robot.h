#ifndef ROBOT_H
#define ROBOT_H

#include "Physics/pworld.h"
#include "Physics/pcylinder.h"
#include "Physics/pbox.h"
#include "Physics/pball.h"

#include "config.h"


class Robot
{
    PWorld* w;
    PBall* m_ball;
    float m_x,m_y,m_z;
    float m_r,m_g,m_b;
public:
    dSpaceID space;
    PCylinder* chassis;
    PBox* boxes[3];
    class Wheel
    {
      public:
        Wheel(Robot* robot,float ang,float ang2);
        void step();
        dJointID joint;
        PCylinder* cyl;
        float speed;
        Robot* rob;
    } *wheels[4];
    class Kicker
    {
      private:
        bool kicking,rolling;
        int kickstate;
        float m_kickspeed,m_kicktime;
      public:
        Kicker(Robot* robot);
        void step();
        void kick(float kickspeed,bool chip=false);
        void setRoller(bool roller);
        bool getRoller();
        void toggleRoller();
        bool isTouchingBall();
        dJointID joint;
        PBox* box;
        Robot* rob;
    } *kicker;

    Robot(PWorld* world,PBall* ball,float x,float y,float z,float r,float g,float b,int rob_id);
    ~Robot();
    void step();
    void setSpeed(int i,float s); //i = 0,1,2,3
    float getSpeed(int i);
    void incSpeed(int i,float v);
    void resetSpeeds();
    void resetRobot();
    void getXY(float& x,float& y);
    float getDir();
    void setXY(float x,float y);
    PBall* getBall();
};

#endif // ROBOT_H