#ifndef SRC_UTIL_TIGERSWERVE_SWERVEMODULE_H_
#define SRC_UTIL_TIGERSWERVE_SWERVEMODULE_H_

#include <math.h>
#include <Util/Math/Rotation2D.h>
#include "ctre/Phoenix.h"
#include "CTREMagEncoder.h"

class SwerveModule {
public:
	SwerveModule(std::shared_ptr<WPI_TalonSRX> driveController, std::shared_ptr<WPI_TalonSRX> rotateController);
	virtual ~SwerveModule();

	Rotation2D GetAngle() const;
	void SetAngle(Rotation2D angle, bool doOptimization);
	void Set(double speed, Rotation2D angle, bool doOptimization);
	void Stop();
private:
	std::shared_ptr<WPI_TalonSRX> _driveController;
	std::shared_ptr<WPI_TalonSRX> _rotateController;
	std::shared_ptr<CTREMagEncoder> _angleEncoder;
	bool isOptimizedAngle;
};

#endif
