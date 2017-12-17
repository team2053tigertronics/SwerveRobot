#include "WheelModuleTest.h"

WheelModuleTest::WheelModuleTest() {
	Requires(Robot::swerveSubsystem.get());
	testsPassed = false;
}

void WheelModuleTest::Initialize() {
	testsPassed = false;
}

void WheelModuleTest::Execute() {
	//test rotations
	/*for(int i = 0; i < 2 * M_PI; i = i + 45) {
		for(int j = 0; j < (signed) Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->size(); j++) {
			Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(i * (M_PI / 180), 0);
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	}*/

	std::cout << "Hi" << std::endl;
	Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(0).Set(0, 0);

	/*//test drive motors
	for(int i = 0; i < (signed) Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->size(); i++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(i).Set(0, .2);
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(1));
	for(int i = 0; i < (signed) Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->size(); i++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(i).Set(0, 0);
	}*/
	testsPassed = true;
}

bool WheelModuleTest::IsFinished() {
	return testsPassed;
}

void WheelModuleTest::End() {

}

void WheelModuleTest::Interrupted() {

}