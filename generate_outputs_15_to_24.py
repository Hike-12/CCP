import subprocess
from pathlib import Path
from PIL import Image, ImageDraw, ImageFont

BASE_DIR = Path(__file__).parent

PROGRAMS = [
    {
        "num": 15,
        "title": "Reverse Linked List Iterative and Recursive",
        "exe": "15_ll_reverse_iterative_recursive.exe",
        "input": "5\n10 20 30 40 50\n",
    },
    {
        "num": 16,
        "title": "Sort a Stack Using Recursion",
        "exe": "16_stack_sort_using_recursion.exe",
        "input": "5\n3 1 4 2 5\n",
    },
    {
        "num": 17,
        "title": "Generate Binary Numbers from 1 to N",
        "exe": "17_queue_generate_binary_1_to_n.exe",
        "input": "10\n",
    },
    {
        "num": 18,
        "title": "Next Greater Element Using Stack",
        "exe": "18_stack_next_greater_element.exe",
        "input": "5\n4 5 2 25 7\n",
    },
    {
        "num": 19,
        "title": "Priority Queue Using Heap",
        "exe": "19_priority_queue_using_heap.exe",
        "input": "6\n10 3 14 1 9 20\n",
    },
    {
        "num": 20,
        "title": "Stack with getMin O1",
        "exe": "20_stack_with_getmin_o1.exe",
        "input": "9\n1 5\n1 2\n4\n1 1\n4\n2\n3\n2\n4\n",
    },
    {
        "num": 21,
        "title": "Topological Sort Using BFS Kahn Algorithm",
        "exe": "21_graph_topological_sort_kahn.exe",
        "input": "6 6\n5 2\n5 0\n4 0\n4 1\n2 3\n3 1\n",
    },
    {
        "num": 22,
        "title": "Check Graph Bipartite Using BFS",
        "exe": "22_graph_check_bipartite_bfs.exe",
        "input": "4 4\n0 1\n1 2\n2 3\n3 0\n",
    },
    {
        "num": 23,
        "title": "Find Connected Components",
        "exe": "23_graph_connected_components.exe",
        "input": "7 4\n0 1\n1 2\n3 4\n5 6\n",
    },
    {
        "num": 24,
        "title": "Cycle Detection Directed and Undirected Graph",
        "exe": "24_graph_cycle_detection_directed_undirected.exe",
        "input": "5 5\n0 1\n1 2\n2 3\n3 4\n4 1\n4 4\n0 1\n1 2\n2 3\n3 1\n",
    },
    {
        "num": 25,
        "title": "Shortest Path in Unweighted Graph Using BFS",
        "exe": "25_graph_shortest_path_unweighted_bfs.exe",
        "input": "6 7\n0 1\n0 2\n1 3\n2 3\n3 4\n4 5\n1 5\n0\n",
    },
]


def slugify(text: str) -> str:
    out = []
    for ch in text.lower():
        if ch.isalnum():
            out.append(ch)
        elif ch in {" ", "-"}:
            out.append("_")
    s = "".join(out)
    while "__" in s:
        s = s.replace("__", "_")
    return s.strip("_")


def save_text_as_png(text: str, path: Path) -> None:
    font = ImageFont.load_default()
    temp = Image.new("RGB", (1, 1), "white")
    d = ImageDraw.Draw(temp)

    lines = text.splitlines() if text else [""]
    max_w = 0
    for line in lines:
        box = d.textbbox((0, 0), line, font=font)
        max_w = max(max_w, box[2] - box[0])

    width = max(1000, max_w + 60)
    height = max(700, 40 + len(lines) * 18)

    img = Image.new("RGB", (width, height), "white")
    draw = ImageDraw.Draw(img)
    draw.multiline_text((20, 20), text, fill="black", font=font, spacing=4)
    img.save(path)


def main() -> None:
    count = 0
    for p in PROGRAMS:
        exe_path = BASE_DIR / p["exe"]
        if not exe_path.exists():
            print(f"SKIPPED missing: {p['exe']}")
            continue

        result = subprocess.run(
            [str(exe_path)],
            input=p["input"],
            text=True,
            capture_output=True,
            cwd=BASE_DIR,
            check=False,
        )

        slug = slugify(p["title"])
        txt_name = f"output_{p['num']}_{slug}.txt"
        png_name = f"output_{p['num']}_{slug}.png"

        report = []
        report.append(f"Program {p['num']}: {p['title']}")
        report.append("")
        report.append("Sample Input:")
        report.append(p["input"].rstrip("\n"))
        report.append("")
        report.append("Sample Output:")
        report.append(result.stdout.rstrip("\n"))

        if result.stderr.strip():
            report.append("")
            report.append("stderr:")
            report.append(result.stderr.rstrip("\n"))

        text = "\n".join(report) + "\n"

        txt_path = BASE_DIR / txt_name
        png_path = BASE_DIR / png_name
        txt_path.write_text(text, encoding="utf-8")
        save_text_as_png(text, png_path)

        print(f"CREATED: {txt_name} | {png_name}")
        count += 1

    print(f"DONE: {count} files (txt+png pairs) generated for programs 15-24")


if __name__ == "__main__":
    main()
