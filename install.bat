@echo off
setlocal enabledelayedexpansion

call build.bat %*
if errorlevel 1 (
    exit /b 1
)

cd build
cmake --install .
if errorlevel 1 (
    cd ..
    exit /b 1
)

cd ..
