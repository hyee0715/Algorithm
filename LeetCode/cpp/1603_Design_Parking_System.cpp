﻿class ParkingSystem {
public:
	int big, medium, small;

	ParkingSystem(int big, int medium, int small) {
		this->big = big;
		this->medium = medium;
		this->small = small;
	}

	bool addCar(int carType) {
		if (carType == 1) {
			if (this->big > 0) {
				this->big--;
				return true;
			}
			else
				return false;
		}
		else if (carType == 2) {
			if (this->medium > 0) {
				this->medium--;
				return true;
			}
			else
				return false;
		}
		else {
			if (this->small > 0) {
				this->small--;
				return true;
			}
			else
				return false;
		}
	}
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */