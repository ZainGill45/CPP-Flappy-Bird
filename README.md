![Image of Flappy Bird made in C++]("./assets/C++ Flappy Bird.png")

# Flappy C++ Raylib
This repository contains a **Flappy Bird**–style game implemented in modern C++ using the minimalistic [Raylib](http://www.raylib.com) library for graphics and input. It leverages **CMake** as a cross-platform build system and **vcpkg** for seamless dependency management via a `vcpkg.json` manifest. The codebase demonstrates a classic game loop, tile-based rendering, keyboard input, and simple collision detection with Raylib’s built-in functions.

## Description
You control a bird sprite that ascends when you press **SPACE** and otherwise falls under gravity, navigating through pairs of pipes that scroll from right to left. The background and ground textures are tiled across the window using Raylib’s `DrawTextureRec()` with repeat wrapping. Collisions against pipes, ceiling, and ground are detected via Raylib’s `CheckCollisionCircleRec()` helper.

## Motivation
This project was made to reinforce hands-on learning of **C++17**, **CMake**, and **vcpkg** by building a small but complete game. It also serves as a practical introduction to using Raylib for graphics, audio, and input in a game-development context.

## Prerequisites
- **CMake** (version ≥ 4.0.1)
- **CMake Extension** found under VS Code and extensions 
- **vcpkg** cloned and bootstrapped
- A C++ compiler with **C++17** support (e.g., MSVC, GCC, Clang)
- **Git** for cloning the repository

## Getting Started
Please keep in mind this project requires that you one have CMake, VS Code CMake extension, vcpkg, and some C++ compiliar installed in order for it work.

1. **Clone this repo**
   ```bash
   git clone https://github.com/yourusername/flappy-cpp-raylib.git
   cd flappy-cpp-raylib
   ```
2. **Install dependencies** via manifest mode
   ```bash
   vcpkg install
   ```
3. **Configure & build** with CMake  
With the VS Code CMake extension set target preset to one that comes with the project and then click build all projects button under the project outline.

4. **Run the game**  
To play the game go to the /out/build/cpp-flappy-bird directory and run the exe called cpp-flappy-bird.exe.

## Controls
- **SPACE** — make the bird flap (jump)
- **ESC** — quit the game
