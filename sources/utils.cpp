#include <utils.hpp>

void Passgen::init(const int& argc, const char* argv[]) {
	int default_length = 8;
	int default_count  = 1;

	po::options_description desc("pass_gen options");
    desc.add_options()
            ("help,h", "Help screen")
            ("length,l", po::value<int>(), "Set password's length (default - 8)")
            ("count,c", po::value<int>(), "Set amount of passwords generated (default - 1)")
			("style,s", "Set style of a password(default, 5block,4block)");
    po::variables_map vm;
    po::store(po::parse_command_line(argc,argv,desc), vm);
    po::notify(vm);

	if (argc == 1) {
        std::cout << desc << "\n";
	}
	if (vm.count("help")) {
        std::cout << desc << "\n";
    }
	if (vm.count("length")) {
		default_length = vm["length"].as<int>();
	} 
	if (vm.count("count")) {
		default_count  = vm["count"].as<int>();
	}
	
	for (int i = 0; i < default_count; i++) {
		if (argc != 1)
	        Password(default_length).print();
	}
}

