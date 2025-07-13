# SFML Setup Guide

The best way to learn C++ is not by reading books or following
tutorials. The best way to learn is to come up with a project idea and
build it. And my favorite type of projects are video games!

In this video, we will go over how to set up a C++ project with SFML.
the Simple Fast Multimedia Library. This is an open source C++ library
that makes it easy to build games, simulations, and interactive tools.

It is used by popular YouTubers like Pezzza for their AntSimulator, and
Hopson97 for their MineCraft clone. And since I spent an entire weekend
learning how to set it up, I figured I could help anyone else trying to
do the same thing.

Keep in mind that we will go over how to setup SFML on Intel Macs, but
the steps are almost identical to get it running on Macs with Apple
silicon.

And of course, if you like this type of content, all I ask in return is
a like for the YouTube algorithm. With that out of the way, let's get
started.

## SFML Homebrew Setup Tutorial

Note that there are many different ways to setup and run SFML, this is
just the approach that helped me get things running very quickly. It boils
down to 4 simple steps.

1. Install homebrew and SFML (via homebrew).
2. Create `main.cpp` file with sample SFML code.
3. Run clang to compile + link the SFML library with the code in `main.cpp`.
4. Run the executable.

### 1. Install homebrew and SFML (via homebrew).

```bash
# install homebrew, the package manager for MacOS
# if you don't have this already, you're cooked fam
# (e.g. apt for Ubuntu)

# install SFML onto MacOS with homebrew
brew install sfml

# On Intel chips, SFML is stored here...
# /usr/local/Cellar/sfml/3.0.1/             # Actual files
# /usr/local/opt/sfml/                      # Symlink to current version

# On Apple silicon, SFML is stored here...
# /opt/homebrew/Cellar/sfml/3.0.1/         # Actual files
# /opt/homebrew/opt/sfml/                  # Symlink to current version
```

### 2. Create `main.cpp` file with sample SFML code.

```cpp
#include <SFML/Graphics.hpp>

// the following are included transitively in <SFML/Graphics.hpp>
// #include <SFML/System.hpp>
// #include <SFML/Window.hpp>

int main() {
  sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML with Homebrew Setup Guide");
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);

  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent())
      if (event->is<sf::Event::Closed>())
        window.close();

    window.clear();
    window.draw(shape);
    window.display();
  }

  return 0;
}
```

### 3. Run clang to compile + link SFML library with the code in `main.cpp`.

```bash
# on Intel Macs
clang++ -std=c++17 main.cpp -o sfml-app \
 -I/usr/local/opt/sfml/include \
 -L/usr/local/opt/sfml/lib \
 -lsfml-graphics -lsfml-window -lsfml-system

# on Apple Silicon Macs (haven't tested, but should work...)
# clang++ -std=c++17 main.cpp -o sfml-app \
#  -I/opt/homebrew/opt/sfml/include \
#  -L/opt/homebrew/opt/sfml/lib \
#  -lsfml-graphics -lsfml-window -lsfml-system

```

### 4. Run the executable.

```bash
./sfml-app
```

## Conclusion

And that's how you get SFML up and running on Intel Macs.

And now, I have some questions for you. Have you ever struggled with getting
C++ projects up and running? Should I go over how to do this with CMake next?
What about setting up ImGui for handling user input and uniform data? Leave
anything related to SFML, C++, or computer graphics down in the comments below.

Thanks for watching, and I'll catch you guys next time.
