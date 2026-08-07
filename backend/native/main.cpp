#include "include/samcpp/access/access.h"
#include "include/samcpp/core/core.h"
#include "include/sam/hoops_license.h"
#include <iostream>

int main(int argc, char **argv) {

    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <inputfile>\n" << std::endl;
        return 1;
    }

    cae::core::license::validate(HOOPS_LICENSE);

    cae::access::DataSource dataSource;
    cae::core::Status status = dataSource.openFile(argv[1], nullptr);

    if (!status) {
        std::cout << "Error while opening file : " << argv[1] << std::endl;
        return 1;
    }

    cae::core::Model model ;
    dataSource.loadModel(&model);

    std::cout << "Success ! <3" << std::endl;
    return 0;
}