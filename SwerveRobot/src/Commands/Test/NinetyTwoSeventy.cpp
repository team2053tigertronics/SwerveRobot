#include <Commands/Test/NinetyTwoSeventy.h>

NinetyTwoSeventy::NinetyTwoSeventy() {
	Requires(Robot::swerveSubsystem.get());
	testsPassed = false;
}

void NinetyTwoSeventy::Initialize() {
	testsPassed = false;
}

void NinetyTwoSeventy::Execute() {
	//test rotations
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(0), true);
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 4; j++) {
			Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(90), true);
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
		for(int j = 0; j < 4; j++) {
			Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(270), true);
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(90), true);
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));

	for(int j = 0; j < 4; j++) {
		Robot::swerveSubsystem->GetSwerveStuff()->GetModules()->at(j).Set(0, Rotation2D::fromDegrees(0), true);
	}
	testsPassed = true;
}

bool NinetyTwoSeventy::IsFinished() {
	return testsPassed;
}

void NinetyTwoSeventy::End() {
	std::cout << "ended" << std::endl;
}

void NinetyTwoSeventy::Interrupted() {

}
