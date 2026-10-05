from conan import ConanFile
from conan.tools.cmake import CMake, CMakeToolchain, CMakeDeps


class gcsllConan(ConanFile):
    name = "gcsll"
    package_type = "static-library"
    settings = "os", "arch", "compiler", "build_type"

    exports_sources = (
        "CMakeLists.txt",
        "cmake/*",
        "gcsll/*",
        "include/*",
        "example/*",
    )

    def generate(self):
        CMakeToolchain(self).generate()
        CMakeDeps(self).generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        CMake(self).install()

    def package_info(self):
        self.cpp_info.libs = ["gcsll", "gcsll_utils"]
        self.cpp_info.set_property("cmake_find_mode", "none")
        self.cpp_info.builddirs = ["lib/cmake/gcsll"]
