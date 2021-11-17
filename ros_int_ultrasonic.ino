#include <ros.h>
#include <SoftwareSerial.h>
#include <std_msgs/Int32.h>


ros::NodeHandle  nh;
std_msgs::Int32 int_msg;
ros::Publisher chatter("/chatter", &int_msg);

SoftwareSerial BT(12, 11);
int a=0;
void setup() {
  nh.initNode();
  nh.advertise(chatter);
  BT.begin(9600);

}

void loop() {
  if (BT.available()) {
      int_msg.data=BT.parseInt();
      
      chatter.publish( &int_msg );
      nh.spinOnce();
    }
   
    else
      nh.spinOnce();
  }
