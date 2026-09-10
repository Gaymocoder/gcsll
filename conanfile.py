from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMakeDeps

class gcstConan(ConanFile):
    settings = "os", "arch", "compiler", "build_type"

    def generate(self):
        CMakeToolchain(self).generate()
        CMakeDeps(self).generate()