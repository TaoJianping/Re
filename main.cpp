#include <iostream>

#include <glog/logging.h>

int main(int argc, char** argv) {
    FLAGS_alsologtostderr = 1;
    google::InitGoogleLogging(argv[0]);

//    LOG(INFO) << "I am INFO!";
//    LOG(WARNING) << "I am WARNING!";
//    LOG(ERROR) << "I am ERROR!";
//    LOG(FATAL) << "I am FATAL!";
    int x = 10;
    int* y = &x;
    int& z = x;
    int* xx = &z;
    LOG(INFO) << *y;
    LOG(INFO) << *xx;
    return 0;
}