# FileZipper

## Overview

FileZipper is a powerful and efficient C++ GUI application for compressing and decompressing files. Built with modern C++20 standards and utilizing CMake for its build system and Qt for its GUI, FileZipper aims to provide an easy-to-use and high-performance file compression tool.

## Features

- **High Performance:** Optimized for fast compression and decompression.
- **User-Friendly Interface:** Intuitive GUI built with Qt.
- **Modern C++:** Utilizes C++20 features and best practices.

## Getting Started

### Prerequisites

Ensure you have the following installed:

- C++20 compatible compiler (e.g., GCC, Clang, MSVC)
- CMake 3.16 or higher
- Qt 6.7 or higher
- Git (optional, for cloning the repository)

### Building the Project

1. **Clone the repository:**

    ```sh
    git clone git@github.com:Darleanow/FileZipper.git
    cd FileZipper
    ```

2. **Create a build directory:**

    ```sh
    mkdir build
    cd build
    ```

3. **Generate the build files:**

    ```sh
    cmake ..
    ```

4. **Build the project:**

    ```sh
    cmake --build .
    ```

### Running the Application

After building the project, you can run the `filezipper` executable:

```sh
./filezipper
```

### Usage

To use the app, simply add files using the `Add Files` button:
![addfiles](/icons/Files%20Added.png)
Then, you can Zip them using the `Zip Files` button:
![zipfiles](/icons/Zipped%20Files.png)
Lastly, you can unzip it using the `Unzip Files` button:
![unzip](/icons/UnZippedFiles.png)

## Contributing

We welcome contributions to FileZipper! Please follow these steps to contribute:

1. Fork the repository.
2. Create a new branch for your feature or bugfix.
3. Commit your changes.
4. Push the branch to your forked repository.
5. Create a pull request.

## Acknowledgements

- [Qt](https://www.qt.io/) for the GUI framework.
- The CMake and C++ communities for their valuable resources and support.

## Contact

For any questions or suggestions, feel free to open an issue or reach out at [contact@darleanow.com](mailto:your-email@example.com).

---

*Happy Zipping!*
