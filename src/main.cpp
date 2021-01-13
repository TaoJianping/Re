#include <iostream>

#include <glog/logging.h>
#include "Utils.h"

int main(int argc, char** argv) {
    FLAGS_alsologtostderr = 1;
    google::InitGoogleLogging(argv[0]);

    return 0;
}