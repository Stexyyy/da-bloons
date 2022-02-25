#include <SFML/Graphics.hpp>
#include <vector>
#include<iostream>
using namespace std;

//create a struct: structs are like classes, but no functions (just variables)
struct point {
    int x;
    int y;
};


class bloon {
private:
    int xpos;
    int ypos;
    int currPath;
public:
    bloon(int x, int y);
    void move(vector<point>myPath);
    void draw(sf::RenderWindow& window);


};


int main()
{
    //set up path points using the struct we made
    struct point p1;
    p1.x = 100;
    p1.y = 400;
    struct point p2;
    p2.x = 100;
    p2.y = 400;
    struct point p3;
    p3.x = 900;
    p3.y = 400;
    struct point p4;
    p4.x = 900;
    p4.y = 600;
    struct point p5;
    p5.x = 800;
    p5.y = 600;
    struct point p6;
    p6.x = 700;
    p6.y = 500;
    struct point p7;
    p7.x = 600;
    p7.y = 600;
    struct point p8;
    p8.x = 500;
    p8.y = 500;
    struct point p9;
    p9.x = 400;
    p9.y = 600;
    struct point p10;
    p10.x = 300;
    p10.y = 500;
    struct point p11;
    p11.x = 200;
    p11.y = 600;
    struct point p12;
    p12.x = 100;
    p12.y = 500;
    struct point p13;
    p13.x = 50;
    p13.y = 500;
    struct point p14;
    p14.x = 50;
    p14.y = 750;
    struct point p15;
    p15.x = 1000;
    p15.y = 750;



    //set up vector to hold path points, push path points into it
    vector <point> pathPoints;
    pathPoints.push_back(p1);
    pathPoints.push_back(p2);
    pathPoints.push_back(p3);
    pathPoints.push_back(p4);
    pathPoints.push_back(p5);
    pathPoints.push_back(p6);
    pathPoints.push_back(p7);
    pathPoints.push_back(p8);
    pathPoints.push_back(p9);
    pathPoints.push_back(p10);
    pathPoints.push_back(p11);
    pathPoints.push_back(p12);
    pathPoints.push_back(p13);
    pathPoints.push_back(p14);
    pathPoints.push_back(p15);
 


    // create game window
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "bloons"); 

    // add by 50 each time
    bloon b1(-50, 400);
    bloon b2(-100, 400);
    bloon b3(-150, 400);
    bloon b4(-200, 400);
    bloon b5(-250, 400);
    bloon b6(-300, 400);
    bloon b7(-350, 400);

    //balloon variables
    float xpos = -50; //start off screen
    float ypos = 400;
    sf::CircleShape bloon(25);
    bloon.setFillColor(sf::Color(250, 0, 0));
    bloon.setPosition(xpos, ypos);
    int currPath = 0; //begin heading towards the first point in the pathing vector
    int ticker = 0;



    // GAME LOOP----------------------------------------------------------------------------------------
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }





        //pathing algorithm*******************************************************************
        //this works by moving the x and y coord of our baloon towards the (x,y) of the next point in the path
        //the path is stored as a series of points in a vector called "pathPoints"

        ticker++; //slow dem bloons down
        if (ticker % 30 == 0) { //make 30 bigger to slow down baloon more

            //first check if you're at the turning point, move to next point if you are
            if ((xpos == pathPoints[currPath].x) && (ypos == pathPoints[currPath].y))
                if (currPath < pathPoints.size() - 1) //don't walk off end of vector!
                    currPath++; //iterate to next point

            //if not there yet, move our x towards x position of next junction
            if (xpos < pathPoints[currPath].x)
                xpos += 1;
            if (xpos > pathPoints[currPath].x)
                xpos -= 1;
            //and move our y towards y position of next junction
            if (ypos < pathPoints[currPath].y)
                ypos += 1;
            if (ypos > pathPoints[currPath].y)
                ypos -= 1;

            b1.move(pathPoints);
            b2.move(pathPoints);
            b3.move(pathPoints);
            b4.move(pathPoints);
            b5.move(pathPoints);
            b6.move(pathPoints);
            b7.move(pathPoints);

        }//end pathing algorithm**************************************************************


        //move da bloon
        bloon.setPosition(xpos, ypos);

        // Render section----------------------------------------------------------------
        window.clear(sf::Color::Black);
        b1.draw(window);
        b2.draw(window);
        b3.draw(window);
        b4.draw(window);
        b5.draw(window);
        b6.draw(window);
        b7.draw(window);
        window.display();
    }

    return 0;//buh bye
}

//class functions and stuff ig

bloon::bloon(int x, int y) {
    xpos = x;
    ypos = y;
    currPath = 0;
}

void bloon::move(vector<point>myPath) {
    if ((xpos == myPath[currPath].x) && (ypos == myPath[currPath].y))
        if (currPath < myPath.size() - 1)
            currPath++;

    //x and y position stuff
    if (xpos < myPath[currPath].x)
        xpos += 1;
    if (xpos > myPath[currPath].x)
        xpos -= 1;
    //and move our y toward the y or sum
    if (ypos < myPath[currPath].y)
        ypos += 1;
    if (ypos > myPath[currPath].y)
        ypos -= 1;

}

void bloon::draw(sf::RenderWindow& window) { 
    sf::CircleShape baloon(25);
    baloon.setFillColor(sf::Color(250, 0, 0));
    baloon.setPosition(xpos, ypos);
    window.draw(baloon);//draws to the gamescreen
}
