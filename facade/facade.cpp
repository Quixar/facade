#include <iostream>
using namespace std;

__interface IsSwitchable {
	virtual void TurnOn() = 0;
	virtual void TurnOff() = 0;
};

class Lighting : public IsSwitchable{
public:
	void TurnOn() {
		cout << "Lighting is on\n";
	}
	void TurnOff() {
		cout << "Lighting is off\n";
	}
	void SetBrightness(int level) {
		cout << "Brightness is set to level: " << level << "\n";
	}
};

class ClimateControl : public IsSwitchable {
public:
	void TurnOn() {
		cout << "Air conditioner is on\n";
	}
	void TurnOff() {
		cout << "Air conditioner is off\n";
	}
	void SetTemperature(int temperature) {
		cout << "Temperature is set to: " << temperature << "\n";
	}
};

class SecuritySystem : public IsSwitchable {
public:
	void TurnOn() {
		cout << "Security system is on\n";
	}
	void TurnOff() {
		cout << "Security system is off\n";
	}
	void StatusCheck() {
		cout << "Checking status of the security system\n";
	}
};

class Multimedia : public IsSwitchable {
public:
	void TurnOn() {
		cout << "Multimedia is on\n";
	}
	void TurnOff() {
		cout << "Multimedia is off\n";
	}
	void SetVolume(int volume) {
		cout << "Volume is set to: " << volume << "\n";
	}
};

class SmartHomeFacade {
	Lighting lighting;
	ClimateControl climate_control;
	SecuritySystem security_system;
	Multimedia multimedia;
public:
	void GoodMorning(int level, int temperature) {
		lighting.TurnOn();
		lighting.SetBrightness(level);
		climate_control.TurnOn();
		climate_control.SetTemperature(temperature);
		security_system.TurnOff();
		multimedia.TurnOn();
		multimedia.SetVolume(25);
	}
	void GoodNight(int temperature) {
		lighting.TurnOff();
		climate_control.TurnOn();
		climate_control.SetTemperature(temperature);
		security_system.TurnOff();
		multimedia.TurnOff();
	}
	void LeaveHome() {
		lighting.TurnOff();
		climate_control.TurnOff();
		security_system.TurnOff();
		multimedia.TurnOff();

	}
	void ReturnHome(int level, int temperature) {
		lighting.TurnOn();
		lighting.SetBrightness(level);
		climate_control.TurnOn();
		climate_control.SetTemperature(temperature);
		security_system.TurnOff();
		multimedia.TurnOn();
		multimedia.SetVolume(40);
	}
};

int main() {
	SmartHomeFacade facade;
	facade.GoodMorning(50, 22);
	facade.GoodNight(18);
	facade.LeaveHome();
	facade.ReturnHome(75, 22);
}