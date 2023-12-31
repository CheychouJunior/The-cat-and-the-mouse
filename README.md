# The cat and the mouse

		PROBLEM
Surviving in a competitive environment


This is the game of life in which we consider two types of entities: the mouse and the cat. The mouse and the
cat forage, fight and bargain their way through procedurally generated environments to outcompete other mice
and cats trying to do the same. We consider in this game that the world has a beginning and an end that can
be parameterized during the game initialization. At its end, a dashboard presenting the entities and their rest of
life. The goal is to simulate populations of agents in procedurally generated virtual worlds. It is inspired by
classic massively multiagent online role-playing games. We consider that:

● The game starts with a map made up of NxN tiles (parameterized at the beginning of the game);
● In each tile, only one agent can be present. In some cases, two agents of the same species can be
present only if one is a male and another one a female. In this case, in a certain number of times, these
agents give birth to babies and all the agents move to the adjacent tiles, leaving the female in the
current tile.
● The maize appear randomly on the tiles
● The mice and the cats should eat to survive
● The cats eat the mice and the mice eat maize
● If a cat and a mouse meet in a tile, the cat will kill the mouse and if the cat is not full, it will eat him
● If any entity did not eat for a certain time, it will die
● Two entity of the same sex should not meet in the same tile
● Each entity can make multiple actions: move, eat, reproduce.
● Each entity can observe NxN tiles around him
● If an entity move out the map, it will die
