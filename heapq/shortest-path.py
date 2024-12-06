import heapq
import sys
import os

map = """\
.......X..
.......X..
.X.XXXXX..
..........
..X.....X.
"""


def parse_map(map):
    lines = map.splitlines()
    origin = 0, 0
    destination = len(lines[-1]) - 1, len(lines) - 1
    return lines, origin, destination


def is_valid(lines, position):
    x, y = position
    if not (0 <= y < len(lines) and 0 <= x < len(lines[y])):
        return False
    if lines[y][x] == "X":
        return False
    return True


def get_neighbors(lines, current):
    x, y = current
    for dx in [-1, 0, 1]:
        for dy in [-1, 0, 1]:
            if dx == 0 and dy == 0:
                continue
            position = x + dx, y + dy
            if is_valid(lines, position):
                yield position


def get_shorter_paths(tentative, positions, through):
    print("Enter function get_shorter_paths: ")
    path = tentative[through] + [through]
    print(f"Path: {path}")
    print(f"Tentative: {tentative}")
    for position in positions:
        print(f"Position: {position}")
        if position in tentative and len(tentative[position]) <= len(path):
            continue
        yield position, path


def find_path(map):
    lines, origin, destination = parse_map(map)
    tentative = {origin: []}
    candidates = [(0, origin)]
    certain = set()
    while destination not in certain and len(candidates) > 0:
        _ignored, current = heapq.heappop(candidates)
        if current in certain:
            continue
        certain.add(current)
        neighbors = set(get_neighbors(lines, current)) - certain
        shorter = get_shorter_paths(tentative, neighbors, current)

        print("Shorter paths:")
        for neighbor, path in shorter:
            # Print shorter paths
            print(f"  {neighbor}: {path}")
            tentative[neighbor] = path
            heapq.heappush(candidates, (len(path), neighbor))

        # Print internal states
        print("Current:", current)
        print("Tentative:")
        for point, path in tentative.items():
            print(f"  {point}: {path}")
        print("Candidates:")
        for priority, point in candidates:
            print(f"  {point} (priority {priority})")
        print("Certain:", certain)
        print("Neighbors:", neighbors)


        # Show path at each step
        if current in tentative:
            print("Current path:")
            print(show_path(tentative[current] + [current], map))

    if destination in tentative:
        return tentative[destination] + [destination]
    else:
        raise ValueError("no path")


def show_path(path, map):
    lines = map.splitlines()
    for x, y in path:
        lines[y] = lines[y][:x] + "@" + lines[y][x + 1 :]
    return "\n".join(lines) + "\n"

if __name__ == "__main__":
    dirname = os.path.dirname(__file__)
    filename = os.path.join(dirname, 'output.txt')
    with open(filename, 'w') as file:
        # Save the original stdout so you can restore it later
        original_stdout = sys.stdout
        # Redirect stdout to the file
        sys.stdout = file

        path = find_path(map)
        print(show_path(path, map))

        # Restore the original stdout
        sys.stdout = original_stdout