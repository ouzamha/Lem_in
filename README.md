# Lem_in
Find the shortest path to get n ants across a colony (comprised of rooms and tunnels).


At the beginning of the game, all the ants are in the room ##start. The goal is to bring them to the room ##end with as few moves as possible.

Each room can only contain one ant at a time (except at ##start and ##end which can contain as many ants as necessary).

The shortest path isn't necessarily the simplest.
Some maps will have many rooms and many links, but no path between start and end.
Some maps will have rooms that link to themselves, sending your path-search spinning in circles.
Some maps will have too many/too few ants, no start or end, duplicate rooms, links to unknown rooms,
rooms with invalid coordinates, and a variety of other invalid or poorly-formatted input.
Ants will also need to avoid traffic jams (walking all over their fellow ants).

# The project
Create the program lem-in.
lem-in will read the map (describing the ants and the colony) from the sdtin.

Upon successfully finding the shortest path, lem-in will display the parsed input, and each ant's move from room to room.
![lemin](https://user-images.githubusercontent.com/58828332/107134618-04fe0f80-68f4-11eb-94ae-99a160fdd76a.png)

# Approach
The map was similar to an undirected graph with unit vertex capacities. First i created the equivalent directed graph with unit edge capacities then starting from 1 i continued to augment the flow and count the score (number of lines to get all the ants from start to end) until i found an optimal solution.
I used [The Ford–Fulkerson method](https://en.m.wikipedia.org/wiki/Ford%E2%80%93Fulkerson_algorithm) for finding augmenting paths and i implemented it using [BFS](https://en.m.wikipedia.org/wiki/Breadth-first_search).

# Usage
Run ``make`` 

``$>./lem-in < map``
