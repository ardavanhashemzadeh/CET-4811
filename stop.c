#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <softPwm.h>

#define RANGE   100
#define INITIAL_VALUE 0

int MLS = 2; // Motor Left Speed
int MLD = 3; // Motor Left Direction
int MRS = 4; // Motor Right Speed
int MRD = 5; // Motor Right Direction

int main()
{
  wiringPiSetup();
  softPwmCreate(MLS, INITIAL_VALUE, RANGE);
  softPwmWrite(MLS, 0);
  pinMode(MLD, OUTPUT);
  digitalWrite(MLD, LOW);
  softPwmCreate(MRS, INITIAL_VALUE, RANGE);
  softPwmWrite(MRS, 0);
  pinMode(MRD, OUTPUT);
  digitalWrite(MRD, LOW);
  return 0;
}
