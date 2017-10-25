#pragma once
 
namespace glib {
	template<typename T>
	bool const Save(const std::string &fileName, const T &p) {
		std::cout << "Saving: " << p << std::endl;
		std::ofstream ofs(fileName + ".txt");

		if (ofs << p) {
			ofs.close();
			return true;
		}
		else {
			ofs.close();
			return false;
		}
	}
	
	template<typename T>
	T Load(const std::string &fileName) {
		T tmp;

		try {
			std::ifstream ifs(fileName + ".txt");

			if (ifs >> tmp) {
				std::cout << "Loaded: " << tmp;
			}
			else {
				throw - 1;
			}
			ifs.close();
		}
		catch (int) {
			std::cout << "file could not load";
		}

		return tmp;

	}
}
