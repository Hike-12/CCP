#!/usr/bin/env bash
set -e

DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$DIR"

PASS=0
FAIL=0

run_program() {
    local num="$1"
    local src="$2"
    local bin="./${src%.cpp}.exe"

    echo "============================================================"
    echo " Q${num}: ${src%.cpp}"
    echo "============================================================"

    if g++ -std=c++17 -O2 -o "$bin" "$src" 2>&1; then
        "$bin" && PASS=$((PASS + 1)) || { echo "  [RUNTIME ERROR (exit $?)]"; FAIL=$((FAIL + 1)); }
    else
        echo "  [COMPILE ERROR]"
        FAIL=$((FAIL + 1))
    fi
    echo ""
}

run_program  1  q01_reverse_k_group.cpp
run_program  2  q02_detect_remove_loop.cpp
run_program  3  q03_sort_stack_recursion.cpp
run_program  4  q04_generate_binary_queue.cpp
run_program  5  q05_next_greater_element.cpp
run_program  6  q06_topo_sort_kahn.cpp
run_program  7  q07_bipartite_bfs.cpp
run_program  8  q08_connected_components.cpp
run_program  9  q09_avl_tree.cpp
run_program 10a q10_coin_change_greedy.cpp
run_program 10b q10_coin_change_dp.cpp
run_program 11  q11_kmp.cpp
run_program 12  q12_lru_cache.cpp
run_program 13  q13_longest_substring.cpp
run_program 14  q14_search_rotated_array.cpp
run_program 15  q15_sliding_window_max.cpp

echo "============================================================"
echo " SUMMARY: ${PASS} passed, ${FAIL} failed"
echo "============================================================"
