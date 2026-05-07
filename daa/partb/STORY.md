# Part B Story for Algorithms

This story explains the algorithms in `/daa/part b` as if you were telling it to a child.
It also gives you easy words and a mnemonic to remember how the code flows.

---

## 1. Stable Marriage: The Proposal Game

Once upon a time, there were three princes and three princesses.
Each prince had a list of princesses he liked, and each princess had a list of princes she liked.

The princes walked around and asked the princesses one by one, starting with the one they liked most.
If a princess was free, she said yes and held his hand.
If she already had a partner, she thought, "Who do I like more?"
If she liked the new prince better, she switched hands and sent the old prince back to ask the next princess.

The game kept going until every prince had a princess.
In the end, everyone was with a partner they liked as much as possible.

### Story words to remember
- Propose
- Prefer
- Pair
- Repeat

### Mnemonic for code flow
**P-P-P-R**: Propose, Prefer, Pair, Repeat.

---

## 2. BFS: The Bread Crumb Walker

Imagine a little explorer in a maze.
The explorer drops a crumb every time they step into a new room.
They always walk to the nearest new room first, using the crumbs to remember where they came from.

When the explorer reaches a room, they look at all the doors.
If a door leads to a new room, they put a crumb there and add it to the list.
Then they go to the next room in the list and do it again.

This way, they visit every room in the maze in neat rounds, from the nearest to the farthest.

### Story words to remember
- Start
- Visit
- Queue
- Neighbors

### Mnemonic for code flow
**S-V-Q-N**: Start, Visit, Queue, Neighbors.

---

## 3. Merge Sort: The Split and Mix Party

There was a pile of toys that needed to be sorted from smallest to biggest.
First, the toys split themselves into two smaller piles.
Then each smaller pile split again, until each pile had only one toy.

Now the toys started a mixing party.
Two tiny piles joined together, with the smaller toy first.
The new pile grew in order, one toy at a time.

At the end, all the toys were back in one big tidy line.

### Story words to remember
- Split
- Sort
- Merge

### Mnemonic for code flow
**S-S-M**: Split, Sort, Merge.

---

## 4. Inversion Count: The Song Playlist Checker

Imagine a playlist of songs where each song has a number.
If a bigger number comes before a smaller number, it is an inversion.

We use the same split-and-mix idea as the party.
When two piles mix, we count how many songs are out of order.
Every time a song from the right pile jumps ahead of a song from the left pile, we add one to the count.

In the end, the playlist is sorted and we know how many inversions were there.

### Story words to remember
- Count
- Compare
- Merge

### Mnemonic for code flow
**C-C-M**: Count, Compare, Merge.

---

## 5. Bipartite Check: The Color Friends Game

Think of friends standing in a circle.
We want to color them with red and blue so that every friend is next to only the opposite color.

One friend starts with red.
Then we color all of that friend’s neighbors blue.
Then we color the neighbors of those blue friends red.

If two friends who are connected are ever the same color, the game fails.
If we can color everyone properly, the graph is bipartite.

### Story words to remember
- Color
- Queue
- Switch

### Mnemonic for code flow
**C-Q-S**: Color, Queue, Switch.

---

## 6. Dijkstra: The Shortest Path Race

There is a town with roads between places.
One traveler wants to reach every place using the shortest path.

The traveler always goes to the nearest unvisited place first.
Then from that place, they see if they can reach other places faster.
If they can, they update the best known route.

They keep doing this until every place has a shortest road from the start.

### Story words to remember
- Distance
- Closest
- Relax
- Repeat

### Mnemonic for code flow
**D-C-R-R**: Distance, Closest, Relax, Repeat.

---

## The big Part B story rhythm

Each algorithm is like a little adventure.
Use these simple stories to remember the shape of the code:

- Stable Marriage: **P-P-P-R**
- BFS: **S-V-Q-N**
- Merge Sort: **S-S-M**
- Inversion Count: **C-C-M**
- Bipartite Check: **C-Q-S**
- Dijkstra: **D-C-R-R**

When you think of the code, picture the story first.
Then use the easy phrase to write the code flow from memory.
