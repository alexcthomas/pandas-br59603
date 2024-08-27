#include <iostream>
#include <pybind11/pybind11.h>
#include <mutex>

namespace py = pybind11;

void create_mutex() {
    py::gil_scoped_release release;
    std::cout << "Creating mutex\n";
    std::mutex local_mutex;
    std::cout << "Mutex created\n";
    {
        std::cout << "Attempting to lock mutex\n";
        std::lock_guard<std::mutex> lock(local_mutex);
        std::cout << "Mutex locked and unlocked\n";
    }
    std::cout << "Exiting create_mutex\n";
}

PYBIND11_MODULE(TestModule, m) {
    m.doc() = "Test Module";
    m.def("create_mutex", &create_mutex, "Create mutex");
}
