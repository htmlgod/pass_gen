#pragma once

#include <iostream>
#include <password.hpp>
#include <boost/program_options.hpp>

namespace po = boost::program_options;

namespace Passgen {
	void init(const int& argc, const char* argv[]);
}

