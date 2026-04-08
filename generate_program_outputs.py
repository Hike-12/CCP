import subprocess
from pathlib import Path
from PIL import Image, ImageDraw, ImageFont

BASE_DIR = Path(__file__).parent

PROGRAMS = [
    {
        "order": 1,
        "title": "Reverse Linked List in Groups of K",
        "exe": "12_ll_reverse_in_groups_k.exe",
        "input": "8\n1 2 3 4 5 6 7 8\n3\n",
    },
    {
        "order": 2,
        "title": "Detect and Remove Loop in Linked List",
        "exe": "13_ll_detect_and_remove_loop.exe",
        "input": "6\n1 2 3 4 5 6\n3\n",
    },
    {
        "order": 3,
        "title": "Reorder Linked List",
        "exe": "14_ll_reorder_list.exe",
        "input": "6\n1 2 3 4 5 6\n",
    },
    {
        "order": 4,
        "title": "Reverse Linked List Iterative and Recursive",
        "exe": "15_ll_reverse_iterative_recursive.exe",
        "input": "5\n10 20 30 40 50\n",
    },
    {
        "order": 5,
        "title": "Sort a Stack Using Recursion",
        "exe": "16_stack_sort_using_recursion.exe",
        "input": "5\n3 1 4 2 5\n",
    },
    {
        "order": 6,
        "title": "Generate Binary Numbers from 1 to N",
        "exe": "17_queue_generate_binary_1_to_n.exe",
        "input": "10\n",
    },
    {
        "order": 7,
        "title": "Next Greater Element Using Stack",
        "exe": "18_stack_next_greater_element.exe",
        "input": "5\n4 5 2 25 7\n",
    },
    {
        "order": 8,
        "title": "Priority Queue Using Heap",
        "exe": "19_priority_queue_using_heap.exe",
        "input": "6\n10 3 14 1 9 20\n",
    },
    {
        "order": 9,
        "title": "Stack with getMin O1",
        "exe": "20_stack_with_getmin_o1.exe",
        "input": "9\n1 5\n1 2\n4\n1 1\n4\n2\n3\n2\n4\n",
    },
    {
        "order": 10,
        "title": "Topological Sort Using BFS Kahn Algorithm",
        "exe": "21_graph_topological_sort_kahn.exe",
        "input": "6 6\n5 2\n5 0\n4 0\n4 1\n2 3\n3 1\n",
    },
    {
        "order": 11,
        "title": "Check Graph Bipartite Using BFS",
        "exe": "22_graph_check_bipartite_bfs.exe",
        "input": "4 4\n0 1\n1 2\n2 3\n3 0\n",
    },
    {
        "order": 12,
        "title": "Find Connected Components",
        "exe": "23_graph_connected_components.exe",
        "input": "7 4\n0 1\n1 2\n3 4\n5 6\n",
    },
    {
        "order": 13,
        "title": "Cycle Detection Directed and Undirected Graph",
        "exe": "24_graph_cycle_detection_directed_undirected.exe",
        "input": "5 5\n0 1\n1 2\n2 3\n3 4\n4 1\n4 4\n0 1\n1 2\n2 3\n3 1\n",
    },
    {
        "order": 14,
        "title": "Shortest Path in Unweighted Graph Using BFS",
        "exe": "25_graph_shortest_path_unweighted_bfs.exe",
        "input": "6 7\n0 1\n0 2\n1 3\n2 3\n3 4\n4 5\n1 5\n0\n",
    },
]


def slugify(text: str) -> str:
    filtered = []
    for ch in text.lower():
        if ch.isalnum():
            filtered.append(ch)
        elif ch in {" ", "-"}:
            filtered.append("_")
    slug = "".join(filtered)
    while "__" in slug:
        slug = slug.replace("__", "_")
    return slug.strip("_")


def text_to_image(text: str, image_path: Path) -> None:
    font = ImageFont.load_default()
    temp_img = Image.new("RGB", (10, 10), "white")
    draw = ImageDraw.Draw(temp_img)

    lines = text.splitlines() if text else [""]
    max_width = 0
    line_height = 16

    for line in lines:
        bbox = draw.textbbox((0, 0), line, font=font)
        line_width = bbox[2] - bbox[0]
        max_width = max(max_width, line_width)

    width = max(900, max_width + 40)
    height = max(600, 40 + line_height * max(1, len(lines)))

    img = Image.new("RGB", (width, height), "white")
    draw = ImageDraw.Draw(img)
    draw.multiline_text((20, 20), text, fill="black", font=font, spacing=4)
    img.save(image_path)


def main() -> None:
    created = []

    for p in PROGRAMS:
        exe_path = BASE_DIR / p["exe"]
        if not exe_path.exists():
            print(f"SKIPPED (missing exe): {p['exe']}")
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
        base_name = f"{p['order']:02d}_{slug}"
        txt_path = BASE_DIR / f"{base_name}.txt"
        png_path = BASE_DIR / f"{base_name}.png"

        content = []
        content.append(f"Program {p['order']}: {p['title']}")
        content.append("")
        content.append("Sample Input:")
        content.append(p["input"].rstrip("\n"))
        content.append("")
        content.append("Sample Output:")
        content.append(result.stdout.rstrip("\n"))

        if result.stderr.strip():
            content.append("")
            content.append("stderr:")
            content.append(result.stderr.rstrip("\n"))

        final_text = "\n".join(content) + "\n"
        txt_path.write_text(final_text, encoding="utf-8")
        text_to_image(final_text, png_path)

        created.append((txt_path.name, png_path.name))
        print(f"CREATED: {txt_path.name} | {png_path.name}")

    print(f"DONE: {len(created)} program outputs generated.")


if __name__ == "__main__":
    main()
