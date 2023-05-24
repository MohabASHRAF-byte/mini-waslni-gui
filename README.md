# Mini Waslni Project

This is a data structure project developed in C++ with a GUI implemented using Qt5. The project is designed for Ain Shams University and aims to provide functionality for navigating and editing a map of cities. It utilizes various algorithms such as optimized BFS, optimized DFS, Dijkstra, and Floyd-Warshall to find the shortest paths between cities.

## Features

The Mini Waslni project consists of two main menus:

1. Navigate Menu: This menu allows the user to find the shortest path between a source city and a destination city using different algorithms. The program visualizes the path on a grid and displays its cost. The following algorithms are available:
   - Optimized BFS (Breadth-First Search)
   - Optimized DFS (Depth-First Search)
   - Dijkstra
   - Floyd-Warshall

2. Edit Menu: This menu provides functionality for editing the map of cities. The following operations are supported:
   - Add City: The user can add a new city by entering a unique name and its position in the x and y axes.
   - Add Edge: This allows the user to add a road between two cities. The user can specify if the road is one-way or bi-directional.
   - Delete City: The user can select a city from a combo box and delete it along with its connections to other cities.
   - Delete Edge: This operation removes a road between two cities.

## Saving Updates

The program ensures that any updates made to the map are saved using files. This means that the changes made by the user, such as adding or deleting cities and roads, will be persisted and can be loaded the next time the program runs.

## Dependencies

To build and run the Mini Waslni project, the following dependencies are required:

- C++ compiler that supports C++11 or later
- Qt6 library

## Build Instructions

1. Ensure that the required dependencies are installed on your system.
2. Clone the Mini Waslni project repository.
3. Open the project in your preferred C++ IDE or editor.
4. Build the project using the C++ compiler, linking against the Qt5 library.
5. Run the compiled executable.

## Usage

Upon launching the Mini Waslni program, you will be presented with a graphical user interface that contains the two main menus: Navigate and Edit.

- In the Navigate menu, select the source city and destination city to find the shortest path between them using the desired algorithm.
- The program will display the shortest path on the grid and provide information about its cost.
- In the Edit menu, you can add new cities, add or delete roads between cities, and delete existing cities.
- Any updates made to the map will be saved automatically.

Please refer to the in-app help or documentation for more detailed instructions on how to use the Mini Waslni project.

## Acknowledgments

This project was developed as a part of the data structure course at Ain Shams University.

