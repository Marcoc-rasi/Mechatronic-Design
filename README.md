# Mechatronic-Design
I worked together with a team of engineers on a robot that picks up tennis balls,the robot was made to function autonomously through the following systems
1- the power was supplied by a battery
2- the advance of the robot was carried out with direct current motors connected to a gear system to increase its torque, the speed and direction of rotation were controlled with an H bridge
3.- The blades work with a direct current motor, the rotation of the blades is activated through an infrared sensor, which detects when a ball enters the ramp and makes it rotate. This same sensor also helps us to stop the ramp in the starting position to insert a new ball.
4.- the robot has ultrasonic sensors which are used to detect obstacles and avoid them
5.- The color sensor located in the lower part of the car is used to determine the area of operation of the robot, we take samples of the colors of the interior of the tennis court, the lines of the court and the exterior of the court.
6.- to locate the balls and go to them, the robot uses an automatic vision system, which divides the view of the camera (cell phone) into two planes, if it finds a circular shape of the color of the tennis ball, in In one of these two planes, left or right, the robot will turn until it leaves the ball in the center of the division, in this way it always goes to a ball centering the entrance of the blades.

Two microcontrollers were used mainly due to two reasons, the first is regarding the ultrasonic sensors, since we had more than one, and these need a certain time to measure the distance, which left all the other processes pending. the vision and the ultrasonic sensors, these two were controlled by the esp32, and the vision was executed in OpenCV on the cell phone, sending a signal via bluetooth to the esp32 which communicated with Arduino through serial communication to generate the rotation of the robot

