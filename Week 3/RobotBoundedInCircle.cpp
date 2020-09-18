// ROBOT BOUNDED IN CIRCLE

/*  PROBLEM:
    On an infinite plane, a robot initially stands at (0, 0) and faces north.

    The robot can receive one of three instructions:

    "G": go straight 1 unit;
    "L": turn 90 degrees to the left;
    "R": turn 90 degress to the right.

    The robot performs the instructions given in order, and repeats them forever.
    Return true if and only if there exists a circle in the plane such that the 
    robot never leaves the circle.
    */

/*  EXAMPLES:

    Input: "GGLLGG"
    Output: true
    Explanation: 
    The robot moves from (0,0) to (0,2), turns 180 degrees, and then returns to (0,0).
    When repeating these instructions, the robot remains in the circle of radius 2 centered at the origin.

    Input: "GG"
    Output: false
    Explanation: 
    The robot moves north indefinitely.

    Input: "GL"
    Output: true
    Explanation: 
    The robot moves from (0, 0) -> (0, 1) -> (-1, 1) -> (-1, 0) -> (0, 0) -> ...
*/

/*  APPROACH: Iterative - O(n)
    1. Initialize an unordered map with the possible outcomes from a direction change for each cardinal direction.
    2. Initialize an unordered map with the possible coordinates after displacement through a change of direction for each cardinal direction.
    3. Initialize the current direction to be north and the current x-coordinate and y-coordinate to be 0.
    4. Iterate through each instruction in the string and update the direction and vector coordinate for every move made by the robot.
    5. Return true if the robot has returned back to the origin, where x = 0 and y = 0, or the direction that it currently faces is not north, which means that it did not travel north indefinitely.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isRobotBounded(string instructions) {
        // North + Left = West, North + Right = East
        // South + Left = East, South + Right = West
        // East + Left = North, East + Right = South
        // West + Left = South, West + Right = North
        unordered_map<char, string> directionChange{{'N', "WE"},{'S', "EW"},{'E', "NS"},{'W', "SN"}};
        // Moving one step forward in each cardinal direction
        unordered_map<char, pair<int, int>> displacement{{'N', {1, 0}}, {'S', {-1, 0}}, {'E', {0, 1}}, {'W', {0, -1}}};
        int x = 0, y = 0;
        char currentDirection = 'N';
        // Update the direction and vector coordinate for each movement
        for(char instruction : instructions){
            if(instruction == 'L')
                currentDirection = directionChange[currentDirection][0];
            if(instruction == 'R')
                currentDirection = directionChange[currentDirection][1];
            if(instruction == 'G')
                x += displacement[currentDirection].first;
                y += displacement[currentDirection].second;
        }
        // Returned back to the origin and doesn't move north indefinitely
        if(x == 0 && y == 0 || currentDirection != 'N') {
            return true;
        }
        return false;
    }
};
