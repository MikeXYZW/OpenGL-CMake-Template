# OpenGL CMake Template

## Intro

This repository contains CMake project files configured for starting out with OpenGL;
They automatically fetch and store necessary dependencies (`GLFW`, `glad` and `glm`);

## Prerequisites 

Available from shell: 

1. C++ compiler (g++, c++)
2. Make
3. CMake (ver >= 3.12)

If you're on Windows, make sure these are in your PATH;

## Installation

1. Automatic (for Windows)

	./run.bat


2. Manual 
		
	cmake . -B build -G "MinGW Makefiles"
	cmake --build build
	./demo.exe

The resulting executable should open an empty window with green background. 
From there you can start building your own cool stuff :)