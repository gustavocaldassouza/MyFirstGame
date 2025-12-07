# MyFirstGame

A simple 2D stick figure shooter game built with C++ and Raylib.

## Description

This project is a beginner-friendly introduction to game development using C++. It features two stick figures facing off in a duel. The player controls the blue stick figure on the right and can shoot at the enemy on the left.

## Features

- **2D Graphics:** Simple stick figure rendering using Raylib's drawing primitives.
- **Physics:** Basic bullet movement and collision detection.
- **Animation:** Character rotation upon defeat.
- **Controls:** Keyboard input for shooting.

## Prerequisites

Before you begin, ensure you have the following installed:

- **C++ Compiler:** A compiler supporting C++17 (e.g., Clang, GCC, MSVC).
- **CMake:** Version 3.10 or higher.
- **Raylib:** The game development library.

### Installing Dependencies (macOS)

```bash
brew install cmake raylib
```

### Installing Dependencies (Windows)

1.  **C++ Compiler:** Install [Visual Studio Community](https://visualstudio.microsoft.com/vs/community/) and select the "Desktop development with C++" workload.
2.  **CMake:** Download and install from [cmake.org](https://cmake.org/download/).
3.  **Raylib:** The easiest way is using [vcpkg](https://github.com/microsoft/vcpkg):
    ```powershell
    git clone https://github.com/microsoft/vcpkg
    .\vcpkg\bootstrap-vcpkg.bat
    .\vcpkg\vcpkg install raylib
    ```
    _Note: When configuring with CMake, you may need to specify the toolchain file provided by vcpkg._

## Build and Run

1.  **Clone the repository:**

    ```bash
    git clone https://github.com/gustavocaldassouza/MyFirstGame.git
    cd MyFirstGame
    ```

2.  **Create a build directory:**

    ```bash
    mkdir -p build
    cd build
    ```

3.  **Configure and Build:**

    ```bash
    # Configure
    cmake ..
    # If using vcpkg on Windows, add: -DCMAKE_TOOLCHAIN_FILE=[path/to/vcpkg]/scripts/buildsystems/vcpkg.cmake

    # Build (Cross-platform)
    cmake --build .
    ```

4.  **Run the Game:**
    - **macOS/Linux:**
      ```bash
      ./MyFirstGame
      ```
    - **Windows:**
      ```powershell
      .\Debug\MyFirstGame.exe
      # or just .\MyFirstGame.exe depending on the generator
      ```

## Controls

- **SPACE:** Shoot gun (Player)
- **ESC:** Exit game

## Project Structure

```
MyFirstGame/
├── CMakeLists.txt       # CMake build configuration
├── src/
│   └── main.cpp         # Main game source code
├── .github/
│   └── copilot-instructions.md # Instructions for AI agents
└── README.md            # Project documentation
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
