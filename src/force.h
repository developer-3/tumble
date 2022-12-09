#pragma once

#include <iostream>

#include "component.h"

namespace tumble {
	class Force : public Component {
	public:
        Force() {
            std::cout << "force created." << std::endl;
        };

        Force(Vector3 force) { 
            std::cout << "force created." << std::endl;
        };

        ~Force() { };
	};
};
