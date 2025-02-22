#include "Plotter.h"
using namespace std;

void runPlotterScript(istream& input) {
    bool penup = 1;
    double x1 = 0.0, y1 = 0.0, x2, y2;
    PenStyle style =  {1, "black"};

    for (string line; getline(input, line); ) {
        Vector<string> command = stringSplit(line, " ");
        command[0] = toLowerCase(command[0]);

        if (command[0] == "penup") {
            penup = 1;
        }
        else if (command[0] == "pendown") {
            penup = 0;
        }
        else if (command[0] == "moverel") {
            x2 = stringToReal(command[1]) + x1;
            y2 = stringToReal(command[2]) + y1;
            if (penup == 0){
                drawLine(x1,y1,x2,y2,style);
            }
            x1 = x2;
            y1 = y2;
        }
        else if (command[0] == "moveabs") {
            x2 = stringToReal(command[1]);
            y2 = stringToReal(command[2]);
            if (penup == 0){
                drawLine(x1,y1,x2,y2,style);
            }
            x1 = x2;
            y1 = y2;
        }
        else if(command[0] == "penwidth") {
            style.width = stringToReal(command[1]);
        }
        else if(command[0] == "pencolor") {
            style.color = command[1];
        }
    }
}
