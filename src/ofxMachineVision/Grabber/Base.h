#pragma once

#include <string>

#include "ofxMachineVision/Device/Blocking.h"
#include "ofxMachineVision/Device/Updating.h"
#include "ofxMachineVision/Device/Types.h"

#include "ofxMachineVision/Specification.h"
#include "ofxMachineVision/Utils/ActionQueueThread.h"
#include "ofxMachineVision/Constants.h"

#include "ofxLiquidEvent.h"

#define CHECK_OPEN if(!this->getIsDeviceOpen()) { \
	OFXMV_ERROR << " Method cannot be called whilst device is not open"; \
	return; \
}

#define CHECK_OPEN_SILENT if(!this->getIsDeviceOpen()) { \
	return; \
}

#define REQUIRES(feature) if(!this->specification.supports(feature)) { \
	OFXMV_WARNING << " Device requires " << ofxMachineVision::toString(feature) << " to use this function."; \
	return; \
}

namespace ofxMachineVision {
	namespace Grabber {
		/**
		\brief Base class for grabbers
		Grabbers are fully implemented classes used to operate abstract Device classes
		*/
		class Base {
		public:
			Base();
			virtual ~Base();

			void setDevice(DevicePtr);
			void clearDevice();
			DevicePtr getDevice() const;
			string getDeviceTypeName() const;

			virtual bool open(shared_ptr<Device::Base::InitialisationSettings> = nullptr) = 0;
			virtual void close() = 0;

			virtual void startCapture() = 0;
			virtual void stopCapture() = 0;

			virtual void syncToDevice(AbstractParameter &) = 0;
			virtual void syncFromDevice(AbstractParameter &) = 0;

			/**
			\name Product specification
			Some of the members of Device::Specification are exposed.
			*/
			//@{
			const Specification & getDeviceSpecification() const { return this->specification; }
			int getDeviceID() const { return this->getDeviceSpecification().getDeviceID(); }
			int getCaptureWidth() const { return this->getDeviceSpecification().getCaptureWidth(); }
			int getCaptureHeight() const { return this->getDeviceSpecification().getCaptureHeight(); }
			const string & getManufacturer() const { return this->getDeviceSpecification().getManufacturer(); };
			const string & getModelName() const { return this->getDeviceSpecification().getModelName(); };
			//@}

			const Device::Type & getDeviceType() const { return this->deviceType; }
			const DeviceState & getDeviceState() const { return this->deviceState; }
			bool getIsDeviceExists() const { return this->getDeviceState() & DeviceState::ExistsBit; }
			bool getIsDeviceOpen() const { return this->getDeviceState() & DeviceState::OpenBit; }
			bool getIsDeviceRunning() const { return this->getDeviceState() & DeviceState::RunningBit; }

			ofxLiquidEvent<shared_ptr<Frame>> onNewFrameReceived;
		protected:
			void setSpecification(const Specification & specification) { this->specification = specification; }

			Specification specification;
			DeviceState deviceState;

			unique_ptr<Utils::ActionQueueThread> thread;
		private:
			DevicePtr baseDevice; // why is this private and not protected?
			Device::Type deviceType;
		};
	}

	typedef shared_ptr<Grabber::Base> GrabberPtr;
}