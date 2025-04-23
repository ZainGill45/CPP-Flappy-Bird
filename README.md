# Flappy C++ Raylib

This repository contains a **Flappy Bird**–style game implemented in modern C++ using the minimalistic [Raylib](http://www.raylib.com) library for graphics and input. It leverages **CMake** as a cross-platform build system and **vcpkg** for seamless dependency management via a `vcpkg.json` manifest. The codebase demonstrates a classic game loop, tile-based rendering, keyboard input, and simple collision detection with Raylib’s built-in functions.

## Description
You control a bird sprite that ascends when you press **SPACE** and otherwise falls under gravity, navigating through pairs of pipes that scroll from right to left. The background and ground textures are tiled across the window using Raylib’s `DrawTextureRec()` with repeat wrapping. Collisions against pipes, ceiling, and ground are detected via Raylib’s `CheckCollisionCircleRec()` helper.

## Motivation
This project was made to reinforce hands-on learning of **C++17**, **CMake**, and **vcpkg** by building a small but complete game. It also serves as a practical introduction to using Raylib for graphics, audio, and input in a game-development context.

## Prerequisites
- **CMake** (version ≥ 3.15)
- **vcpkg** cloned and bootstrapped
- A C++ compiler with **C++17** support (e.g., MSVC, GCC, Clang)
- **Git** for cloning the repository

## Getting Started
Please keep in mind this project requires that you one have cmake, vcpkg, and some c++ compiliar installed in order for it work.

1. **Clone this repo**
   ```bash
   git clone https://github.com/yourusername/flappy-cpp-raylib.git
   cd flappy-cpp-raylib
   ```
2. **Install dependencies** via manifest mode
   ```bash
   ./vcpkg/vcpkg install
   ```
3. **Configure & build** with CMake
   ```bash
   cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=./vcpkg/scripts/buildsystems/vcpkg.cmake
   cmake --build build --config Release
   ```
4. **Run the game**
   ```bash
   # Linux/macOS
   ./build/Release/FlappyCppRaylib
   # Windows
   .\build\Release\FlappyCppRaylib.exe
   ```

## Controls
- **SPACE** — make the bird flap (jump)
- **ESC** — quit the game