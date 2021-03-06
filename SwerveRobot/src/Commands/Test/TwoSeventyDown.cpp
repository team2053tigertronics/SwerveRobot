#include <Commands/Test/TwoSeventyDown.h>

TwoSeventyDown::TwoSeventyDown() {
	Requires(Robot::swerveSubsystem.get());
	testsPassed = false;
}

void TwoSeventyDown::Initialize() {
	testsPassed = false;
}

void TwoSeventyDown::Execute() {
	//test rotations
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(0), true);
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(270), true);
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(180), true);
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(90), true);
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(0), true);
	}
	testsPassed = true;
}

bool TwoSeventyDown::IsFinished() {
	return testsPassed;
}

void TwoSeventyDown::End() {
	std::cout << "ended" << std::endl;
}

void TwoSeventyDown::Interrupted() {

}
