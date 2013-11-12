#include "WPILib.h"
#include "Compressor.h"
#include <DigitalInput.h>
/**
 * This is a demo program showing the use of the RobotBase class.
 * The SimpleRobot class is the base of a robot application that will automatically call your
 * Autonomous and OperatorControl methods at the right time as controlled by the switches on
 * the driver station or the field controls.
 */ 
class RobotDemo : public SimpleRobot
{
	RobotDrive myRobot;// 9 7 8 6 
		Joystick stick1, stick2; 
		Victor DriveLF, DriveLR, DriveRF, DriveRR;
		
		
		
		//DigitalInput Photo_Eye;
		DriverStation *ds;
		DriverStationLCD *dsLCD;
	
       
public:
	RobotDemo(void):// these must be initialized in the same order as they are declared above.
		myRobot(10, 10),	
		stick1(1),
		stick2(2),
		DriveLF(9),
		DriveLR(7),
		DriveRF(8), 
		DriveRR(6),
		//Photo_Eye(3),
		ds(DriverStation::GetInstance()),
		dsLCD(DriverStationLCD::GetInstance())
		
	
	{
		myRobot.SetExpiration(0.1);
	}
/*	void tank_Logitech_gamepad()
			{	
				static const int threshold=5;// thresholds prevent unwanted sensitivity that may cause perpetual motion 
				
				//define right joystick for tank
				float stick1_left_Y = stick1.GetRawAxis(2);//joy1_y1
				//float stick1_left_X = stick1.GetRawAxis(1);//joy1_x1
				//float stick1_left_Z = stick1.GetRawAxis(3);//joy1_Z1
				
				//define left joystick for tank
				float stick1_right_Y = stick1.GetRawAxis(4);//joy1_y2
				//float stick1_right_X = stick1.GetRawAxis(3);//joy1_x2	
				//float stick1_right_Z = stick1.GetRawAxis(5);//joy1_Z2
			
				stick1_left_Y;//speed on left scaled to half 
				 stick1_right_Y;//speed on right scaled to half 
				//joystick scaling -- scales the value of the joystcks to remove play 
				double scaledL_Y=((stick1_left_Y*100)/127);
				double scaledR_Y=((stick1_right_Y*100)/127);
				//speed scaling 
				double speedL= (scaledL_y);//unscaled... for now
				double speedR= (scaledR_y);//unscaled... for now
				//drive left motor
				if(abs(scaledL)>threshold)
				{
					DriveLF.Set(speedL);
					DriveLR.Set(speedL);
				}else
					{
					DriveLF.Set(0.00);	// stops the motor
					DriveLF.Set(0.00);	// stops the motor
					}
				// drive right motor 
				if(abs(scaledR)>threshold)
				{
				DriveRF.Set(speedL);
				DriveRR.Set(speedL);
				}else
					{
						DriveRF.Set(0.00);//stop right motor
						DriveRR.Set(0.00);//stop right motor 
						 
					}
				
			}*/
			void tank_two_joysticks()
			{	
			static const int threshold=10;// thresholds prevent unwanted sensitivity that may cause perpetual motion 
			//----right joystick
			float stick1_Y = stick1.GetRawAxis(2);//joy1_y1
			//float stick1_X = stick1.GetRawAxis(1);//joy1_x1
			//float stick1_Z = stick1.GetRawAxis(3);//joy1_Z1//twist 
			//----left joystick
			float stick2_Y = stick2.GetRawAxis(2);//joy2_y1
			//float stick2_X = stick2.GetRawAxis(1);//joy2_x1
			//float stick2_Z = stick2.GetRawAxis(3);//joy2_Z1//twist	
			double speedL= (stick1_Y);//speed on left 
			double speedR= (stick2_Y);//speed on right
			//driving portion 
			
			//left joystick
				if(stick1_Y>threshold)
				{
					DriveLF.Set(speedL);
					DriveLR.Set(speedL);
				}else
				{
					DriveLF.Set(0.00);
					DriveLR.Set(0.00);
				}
				//right joystick 
				if(stick2_Y>threshold)
				{
					DriveRF.Set(speedR);
					DriveRR.Set(speedR);
				}else
				{
					DriveRF.Set(0.00);
					DriveRR.Set(0.00);	
				}
			}
//			void Read_PE()//most likly will not work...
//			{
//				while(true)
//				{
//				dsLCD->PrintfLine(DriverStationLCD::kUser_Line2, "Photo-Eye: %d", Photo_Eye.Get());//print out digital output 
//				dsLCD->UpdateLCD();
//				Wait(0.5);// frequency of update time
//				}
//			}
	/**
	 * Drive left & right motors for 2 seconds then stop
	 */
	void Autonomous(void)
	{

	}

	/**
	 * Runs the motors with arcade steering. 
	 */
	void OperatorControl(void)
	{
		myRobot.SetSafetyEnabled(true);
		while (IsOperatorControl())
		{
			tank_two_joysticks();
			//tank_Logitech_gamepad();
			//myRobot.ArcadeDrive(stick1); // drive with arcade style (use right stick)
			Wait(0.005);				// wait for a motor update time
		}
	}
};

START_ROBOT_CLASS(RobotDemo);

